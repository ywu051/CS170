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
  bool checkMove = false; // checks if the move is valid
  if(c == 'w'){ // moves up
    if(row == 0){ 
      // cannot move up, checkMove still false
    }
    else{
    checkMove = true;
    }
  }
  else if(c == 's'){ // moves down
     if(row == 2){ 
      // cannot move down, checkMove still false
    }
    else{
    checkMove = true;
    }
  }
  else if(c == 'a'){ // moves left
    if(col == 0){ 
      // cannot move left, checkMove still false
    }
    else{
    checkMove = true;
    }
  }
  else if(c == 'd'){ // moves right
    if(col == 2){ 
      // cannot move right, checkMove still false
    }
    else{
    checkMove = true;
    }
  }
  return checkMove; 
}


void board :: moveUp(){

}

void board :: moveDown(){

}

void board :: moveLeft(){

}

void board :: moveRight(){

}
