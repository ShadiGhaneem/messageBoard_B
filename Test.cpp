#include "doctest.h"
#include <string>
#include <experimental/random>
#include <unistd.h>
#include <algorithm>
using namespace std;
using namespace doctest;
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;
const int RANDOM_BOUNDERY=100 , word2 =2,word3=3,word4=4, word5=5,word12=12;

TEST_CASE("1") {
    Board board;
    board.post(0, 0, Direction::Horizontal, "shadishadila");
    CHECK(board.read(0, 0, Direction::Horizontal, word12) == "shadishadila");
}
TEST_CASE("2") {
    Board board;
    board.post(0, 0, Direction::Horizontal, "shadi");
    CHECK(board.read(0, 0, Direction::Horizontal, word5) == "shadi");
}
TEST_CASE("3") {
    Board board;
    board.post(0, 0, Direction::Horizontal, "door");
    CHECK(board.read(0, 0, Direction::Horizontal, word4) == "door");
}
TEST_CASE("4") {
    Board board;
    board.post(0, 0, Direction::Horizontal, "shadi");
    CHECK(board.read(0, 0, Direction::Horizontal, word3) == "sha");
}
TEST_CASE("5") {
    Board board;
    board.post(0, 0, Direction::Horizontal, "do");
    CHECK(board.read(0, 0, Direction::Horizontal, word2) == "do");
}
TEST_CASE("6") {
    Board board;
    string str= "aseel";
    board.post(2, 0, Direction::Horizontal, str);
    string new_str = "__"+str.substr(0,1)+"__";

    CHECK(board.read(0, 0, Direction::Vertical, word5) == new_str);
}
TEST_CASE("7") {
    Board board;
    string str= "car";
    board.post(2, 0, Direction::Horizontal, str);
    string new_str = "__"+str.substr(0,1)+"__";

    CHECK(board.read(0, 0, Direction::Vertical, word5) == new_str);
}
TEST_CASE("8") {
    Board board;
    string str= "plan";
    board.post(2, 0, Direction::Horizontal, str);
    string new_str = "__"+str.substr(0,1)+"__";

    CHECK(board.read(0, 0, Direction::Vertical, word5) == new_str);
}
TEST_CASE("9") {
    Board board;
    string str= "shadishadila";
    board.post(2, 0, Direction::Horizontal, str);
    string new_str = "__"+str.substr(0,1)+"_________";

    CHECK(board.read(0, 0, Direction::Vertical, word12) == new_str);
}
TEST_CASE("10"){
    Board board;
    string str = "house";
    board.post(0,2,Direction::Vertical,str);
    string new_str = "__"+str.substr(0,1)+"__";
    CHECK(board.read(0,0,Direction::Horizontal,word5)==new_str);
}
TEST_CASE("11"){
    Board board;
    unsigned int row = (unsigned int)std::experimental::randint(0,RANDOM_BOUNDERY);
    unsigned int col = (unsigned int)std::experimental::randint(0,RANDOM_BOUNDERY);
    CHECK(board.read(row,col,Direction::Horizontal,word5)==string("_____"));
    CHECK(board.read(row,col,Direction::Vertical,word5)==string("_____"));
}
TEST_CASE("12"){
    Board board;
        string str = "chees";
        board.post(0,0,Direction::Horizontal,str);
        str = "chees";
        board.post(0,0,Direction::Horizontal,str);
        CHECK(board.read(0,0,Direction::Horizontal,word5)==str);
    }
TEST_CASE("13"){
    Board board;
        string str = "shadishadila";
        board.post(0,0,Direction::Vertical,str);
        str = "shadishadila";
        board.post(0,0,Direction::Vertical,str);
        CHECK(board.read(0,0,Direction::Vertical,word12)==str);
    }
TEST_CASE("14"){
    Board board;
        string str ="shadishadila";
        board.post(0,0,Direction::Horizontal,str);
        string str2 = "shadi";
        board.post(0,0,Direction::Horizontal,str2);
        str.replace(0,str2.length(),str2);
        CHECK(board.read(0,0,Direction::Horizontal,word12)==str);
    }
TEST_CASE("15"){
    Board board;
        string str = "shadishadila";
        board.post(0,0,Direction::Vertical,str);
        string str2 = "fafao";
        board.post(0,0,Direction::Vertical,str2);
        str.replace(0,str2.length(),str2);
        CHECK(board.read(0,0,Direction::Vertical,word12)==str);
    }
TEST_CASE("16"){
    Board board;
        string long_str ="lolo";
        string short_str = "dodo";
        board.post(0,0,Direction::Horizontal,short_str);
        board.post(1,0,Direction::Horizontal,long_str);
        CHECK(board.read(1,0,Direction::Horizontal,word4)==long_str);
        CHECK(board.read(0,0,Direction::Horizontal,12)==short_str+"________");
    }
TEST_CASE("17"){
    Board board;
        unsigned int row = (unsigned int)std::experimental::randint(0,RANDOM_BOUNDERY);
        unsigned int col = (unsigned int)std::experimental::randint(0,RANDOM_BOUNDERY);
        string short_str = "shadi";
        board.post(row,col,Direction::Vertical,short_str);
        CHECK(board.read(row+word5,col,Direction::Vertical,word5)=="_____");
        CHECK(board.read(row,col+word5,Direction::Vertical,word5)=="_____");
    }
TEST_CASE("18"){
    Board board;
    string short_str = "dodoo";
    board.post(0,0,Direction::Vertical,short_str);
    unsigned int row = (unsigned int)std::experimental::randint(word5,RANDOM_BOUNDERY);
    unsigned int col = (unsigned int)std::experimental::randint(word5,RANDOM_BOUNDERY);
    CHECK(board.read(row,col,Direction::Vertical,0)=="");

}
TEST_CASE("19"){
    Board board;
        unsigned int row = (unsigned int)std::experimental::randint(0,RANDOM_BOUNDERY);
        unsigned int col = (unsigned int)std::experimental::randint(0,RANDOM_BOUNDERY);
        string short_str = "shadi";
        short_str = "ahmad";
        board.post(row,col,Direction::Horizontal,short_str);
        CHECK(board.read(row,col,Direction::Horizontal,word5)==short_str);
    }
TEST_CASE("20") {
    Board board;
        unsigned int row = (unsigned int) std::experimental::randint(0, RANDOM_BOUNDERY);
        unsigned int col = (unsigned int) std::experimental::randint(0, RANDOM_BOUNDERY);
        string short_str = "shadi";
        short_str = "shadi";
        board.post(row, col, Direction::Horizontal, short_str);
                CHECK(board.read(row + word5, col, Direction::Horizontal, word5) == "_____");
                CHECK(board.read(row, col + word5, Direction::Horizontal, word5) == "_____");
    }