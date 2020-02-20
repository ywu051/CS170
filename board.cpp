#include <iostream>
#include <cstdlib>
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

int board:: heuristics(int h){
  int count = 0;
  if(h == 1){ //Uniform Cost Search, h(n) = 0
    return 0;
  }
  else if(h == 2){ //Misplaced Tile
    for(int i=0; i<3; ++i){
      for(int j=0; j<3; ++j){
        if((arr[i][j] != goal[i][j])){
          ++count; // distance to goal
        }
      }
    }
  }
  else if(h==3){ //Manhattan Distance
    for(int i=0; i<3; ++i){
      for(int j=0; j<3; ++j){
        if((arr[i][j] != goal[i][j])){
          int r = 0; //find the distance to goal
          int c = 0; 
          int tempr;
          int tempc;
          findManDist(arr[i][j],r,c);
          tempr = abs(r - i);
          tempc = abs(c - j);
          count = tempr + tempc; // finds distance to goal
        }
      }
    }
  }
  cout << count;
  return count;
}

void board :: addCost(int h, int d){
  int tempH = heuristics(h);
  cout<< "heuristic: "<< tempH <<endl;
  this->cost = tempH + d; // add heuristic function
  return;
}

vector<char> board :: allMoves(){
  vector<char> moves;
  if(row != 0){ // check if it is top row, if not, push into allMoves
    cout << arr[row-1][col] <<endl;
    moves.push_back('w');
  }
  if(row != 2){ // check if it is last row, if not, push into allMoves
    cout << arr[row+1][col] <<endl;
    moves.push_back('s');
  }
  if(col != 0){ // check if it is left row, if not, push into allMoves
    cout << arr[row][col-1] <<endl;
    moves.push_back('a');
  }
  if(col != 2){ // check if it is right row, if not, push into allMoves
    cout << arr[row][col+1] <<endl;
    moves.push_back('d');
  }
  return moves;
}

void board :: findManDist(int a, int &temprow, int &tempcol) { // finds distance g(n) for Manhattan Distance
	for(int i = 0; i < 3; ++i) {					
		for(int j = 0; j < 3; ++j) {			
			if(goal[i][j] == a){
				temprow = i;
				tempcol = j;
				return;			
			}
		}
	}
}

