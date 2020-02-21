#include <iostream>
using namespace std;

#include "board.h"
#include <vector>
#include <cmath>

board::board(){

}

board::board(board* newBoard){

  for(int i = 0 ; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      this->arr[i][j] = newBoard->arr[i][j];
    }
    
  }
  this->depth = newBoard->depth +1;
  this->row = newBoard->row;
  this->col = newBoard->col;
}

void board :: display(){
  for(int i = 0 ; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      cout << this->arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
return; 
}

bool board :: validMove(char c){
  bool checkMove = false; //default is false
  if(c == 'w'){ //move up
    if(row == 0){ //row 0 is the top 
      checkMove = false;
    }
    else{
      checkMove = true;
    }
  }
  else if(c == 's'){ //move down
    if(row ==  2){ //row 2 is bottom
      checkMove = false;
    }
    else{
      checkMove = true;
    }
  }
  else if(c == 'a'){ //move left
    if(col == 0){ //col 0 is left
      checkMove = false;
    }
    else{
      checkMove = true;
    }
  }
  else if(c == 'd'){ //move right
    
    if(col == 2){ // col 2 is right
      checkMove = false;
    }
    else{
      checkMove = true;
    }
  }

  return checkMove;
}

void board :: moveUp(){
  if(!validMove('w')){
  }
    else{ 
    --row;
    int temp = this->arr[row][col];
    arr[row][col] = 0;
    arr[row+1][col] = temp;
  }
}

void board :: moveDown(){
  if(!validMove('s')){
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
  }
  else{
    ++col;
    int temp = arr[row][col];
    arr[row][col] = 0;
    arr[row][col-1] = temp;
  }
}

vector<char> board :: legalMoves(){
  vector<char> c;
  if(row != 0){
    c.push_back('w');
  }
  if(row != 2){
    c.push_back('s');
  }
  if(col != 0){
    c.push_back('a');
  }
  if(col != 2){
    c.push_back('d');
  }
  return c;
}

board board :: operator = (const board& b){
  for(int i = 0 ; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      this->arr[i][j] = b.arr[i][j];
    }
    
  }
  this->row = b.row;
  this->col = b.col;
  return *this;
}

void board :: addScore(int h, int d){
  int tempH = heuristics(h);
  //cout<<"heuristic: "<<tempH<<endl;
  this->score = tempH + d;
  return;
}

int board:: heuristics(int h){
  if(h==1){ //Uniform Cost
  }
  else if(h==2){ //Misplaced Tile
    for(int i=0; i<3; ++i){
      for(int j=0; j<3; ++j){
        if((arr[i][j] != goal[i][j])){
          ++count;
        }
      }
    }
  }
  else if(h==3){ //Manhattan Distance
  for(int i=0; i<3; ++i){
      for(int j=0; j<3; ++j){
        if((arr[i][j] != goal[i][j])){
          int r = 0; 
          int c = 0; 
          int tempr;
          int tempc;
          findManDist(arr[i][j],r,c);
          tempr = abs(r - i);
          tempc = abs(c - j);
          count = tempr + tempc; // finds distance to goal
          return count;
        }
      }
    }
  }
  return count;
}


string board :: getHash(){
  string hash;
  
  for(int i=0; i< 3; ++i){
    for(int j=0; j<3; ++j){
      hash += ('0' + this->arr[i][j]);
    }
  }

  return hash;

}
string board :: getHashGoal(){
  string hash;
  
  for(int i=0; i< 3; ++i){
    for(int j=0; j<3; ++j){
      hash += ('0' + this->goal[i][j]);
    }
  }

  return hash;

}

void board :: findManDist(int a, int &temprow, int &tempcol) { // finds distance
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