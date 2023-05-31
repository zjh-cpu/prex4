#include <vector>
#include <cstdlib>
#include "Spot.h"
#include "Snare.h"
#include "Persona.h"
#include "Assists.h"

class Play {
public:
    Play() {}

    std::vector<Spot*>& getMatrix() { return matrix; }

    void initPlay(int numPersonas, int numSnares, int matrixWidth, int matrixHeight) {
        for (int i = 0; i < numPersonas; i++) {
            std::tuple<int, int> randomLoc = Assists::createRandomLoc(matrixWidth, matrixHeight);
            Persona* persona = new Persona(std::get<0>(randomLoc), std::get<1>(randomLoc));
            matrix.push_back(persona);
        }
        for (int i = 0; i < numSnares; i++) {
            std::tuple<int, int> randomLoc = Assists::createRandomLoc(matrixWidth, matrixHeight);
            Snare* snare = new Snare(std::get<0>(randomLoc), std::get<1>(randomLoc));
            matrix.push_back(snare);
        }
    }

    void playCycle(int maxCycles, double snareTriggerDistance) {
        for (int cycle = 0; cycle < maxCycles; cycle++) {
            for (Spot* spot : matrix) {
                if (spot->getCategory() == 'P') {
                    Persona* persona = static_cast<Persona*>(spot);
                    persona->shift(1, 0);
                    for (Spot* otherSpot : matrix) {
                        if (otherSpot->getCategory() == 'S') {
                            Snare* snare = static_cast<Snare*>(otherSpot);
                            if (snare->isOperative() && Assists::evaluateDistance(persona->getLoc(), snare->getLoc()) <= snareTriggerDistance) {
                                snare->implement(*persona);
                            }
                        }
                    }
                    if (std::get<0>(persona->getLoc()) >= matrixWidth || std::get<1>(persona->getLoc()) >= matrixHeight) {
                        std::cout << "Persona has won the game!\n";
                        return;
                    }
                }
            }
        }
        std::cout << "Maximum number of cycles reached. Game over.\n";
    }

private:
    std::vector<Spot*> matrix;
    int matrixWidth;
    int matrixHeight;
};
