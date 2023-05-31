#include <tuple>
#include <cstdlib>
#include <cmath>

class Assists {
public:
    static std::tuple<int, int> createRandomLoc(int matrixWidth, int matrixHeight) {
        int x = rand() % matrixWidth;
        int y = rand() % matrixHeight;
        return std::make_tuple(x, y);
    }

    static double evaluateDistance(std::tuple<int, int> loc1, std::tuple<int, int> loc2) {
        int x1 = std::get<0>(loc1);
        int y1 = std::get<1>(loc1);
        int x2 = std::get<0>(loc2);
        int y2 = std::get<1>(loc2);
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }
};
