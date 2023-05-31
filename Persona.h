#include "Spot.h"

class Persona : public Spot {
public:
    Persona(int x, int y) : Spot(x, y, 'P') {}

    void shift(int dx, int dy) {
        int newX = std::get<0>(getLoc()) + dx;
        int newY = std::get<1>(getLoc()) + dy;
        setLoc(newX, newY);
    }
};
