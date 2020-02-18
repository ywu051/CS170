#include <iostream>
using namespace std;

#include "board.h"
#include <vector>

board::board(){
  // empty board
}

board::board(board* newBoard){
  for(int i = 0 ; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      this->arr[i][j] = newBoard->arr[i][j];
    }
    
  }
  this->row = newBoard->row;
  this->col = newBoard->row;
  this->depth = newBoard->depth;
}

void board :: display(){
  for(int i = 0 ; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      cout << this->arr[i][j] << " ";
    }
    cout << endl;
  }
return; 
}

bool board :: validMove(char c){

}

void board :: moveUp(){

}

void board :: moveDown(){

}

void board :: moveLeft(){

}

void board :: moveRight(){

}
