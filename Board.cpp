
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;
#include "Board.hpp"
#include "Direction.hpp"
#include<array>
using ariel::Direction;


namespace  ariel{

const char DefultLine='_';

void Board::update(unsigned int row, unsigned int col, bool flag, unsigned int num){

        //first time we update the board
        if(this->cor[0]==0 && this->cor[1]==INT32_MAX && this->cor[2]==0 && this->cor[3]==INT32_MAX){
             if (flag){
                this->cor[1]=row+1;
                this->cor[3]=col+num;
                this->cor[0]=row;
                this->cor[2]=col;
             }
             else{
                this->cor[1]=row+num;
                this->cor[3]=col+1;
                this->cor[0]=row;
                this->cor[2]=col;
             }
        }
        else{
            this->cor[2]=min(this->cor[2], col);
            this->cor[0]=min(this->cor[0], row);

            if(flag){
                this->cor[3]= max(this->cor[3], col+num+1);
                this->cor[1]=max(this->cor[1], row+1);
            }
            else{
                this->cor[3]=max(this->cor[3], col+1);
                this->cor[1]=max(this->cor[1], row+num+1);
            }
           

        }
        this-> board.resize(this->cor[1]);
             for(unsigned int i=0; i < this->cor[1]; i++){
                board.at(i).resize(this->cor[3],DefultLine);
             }
        
    }

void ariel::Board::post(unsigned int horizontal, unsigned int vertical, Direction d, const std::string &message){
    bool flag=d == Direction::Horizontal;

    update(horizontal,vertical,flag,message.size());
    if(d == Direction::Horizontal){
        for(unsigned int i=0;i<message.length();i++){
            unsigned int index=vertical+i;
            board.at(horizontal).at(index)=message.at(i);
        }
    }
    else{
        for(unsigned int j=0;j<message.length();j++){
            unsigned int index=horizontal+j;
            board.at(index).at(vertical)=message.at(j);
        }
    }
}

std::string ariel::Board::read(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int length) {

   
    bool flag=d == Direction::Horizontal;
    update(horizontal,vertical,flag,length);
    string word;
    if(d == Direction::Horizontal){
        for(unsigned  i=0;i<length;i++){
            unsigned int index=vertical+i;
            word=word+board.at(horizontal).at(index);
        }
    }
    else{
        for(unsigned int j=0;j<length;j++){
            unsigned int index=horizontal+j;
            word=word+board.at(index).at(vertical);
        }
    }
 return word;
}

void ariel::Board::show() {
   for (unsigned int i = this->cor[0]; i < this->cor[1]; i++) {
            cout << i << ": ";
           
            for (unsigned int j = this->cor[2]; j < this->cor[3]; j++) {
                    cout << this->board.at(i).at(j);
            }
            cout<< "\n";
        }
        cout << "\n" << endl;
    }
}
