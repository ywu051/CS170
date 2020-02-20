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
 if(!validMove('w')){ // check if it can move up
    cout << "Not a Valid Move" <<endl;
    }
    else{ //swap places
      --row;
      int temp = this->arr[row][col]; // swap
      arr[row][col] = 0; // new blank
      arr[row+1][col] = temp;
    }
}

void board :: moveDown(){
  if(!validMove('s')){
    cout << "Not a Valid Move" <<endl;
    }
  else{
      ++row;
      int temp = arr[row][col]; 
      arr[row][col] = 0;
      arr[row-1][col] = temp;
    
  }

}

void board :: moveLeft(){
  if(!validMove('a')){
    cout << "Not a Valid Move" <<endl;
    }
  else{
      --col;
      int temp = arr[row][col]; 
      arr[row][col] = 0;
      arr[row][col+1] = temp;
    
  }
}

void board :: moveRight(){
  if(!validMove('d')){
    cout << "Not a Valid Move" <<endl;
  }
  else{
    ++col;
    int temp = arr[row][col];
    arr[row][col] = 0;
    arr[row][col-1] = temp;
  }
}

