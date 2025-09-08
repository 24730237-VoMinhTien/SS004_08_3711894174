#pragma once
#include <cstdlib>
#include <ctime>

struct ToaDo {
    int x;
    int y;
};

class ThucAn {
public:
    ToaDo vitri;

    ThucAn(int rong, int cao) {
        boardW = rong;
        boardH = cao;
        std::srand((unsigned)std::time(nullptr));
        taoMoi();
    }

    void taoMoi() {
        vitri.x = std::rand() % boardW;
        vitri.y = std::rand() % boardH;
    }

private:
    int boardW;
    int boardH;
};
