
#pragma once
#include <vector>
#include <string>
#include "Direction.hpp"
namespace ariel{
    class Board{
    private:
          std::vector<std::string> board;
            unsigned int cor[4]={0,INT32_MAX,0,INT32_MAX};
            void update(unsigned int row, unsigned int col, bool flag, unsigned int num);
    public:
        Board() {
            board=std::vector<std::string>(0, "_");
        };
        void post(unsigned int horizontal, unsigned int vertical, Direction d, const std::string &message);
        std::string read(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int length);
        void show();
    };
}