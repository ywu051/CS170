#include <iostream>
using namespace std;

#include "tree.h"
#include "board.h"

tree :: tree(){
  root = new board();
  curr = root;
  curr->prev = 0; // set pointer to 0, no previous node in new board
}

void tree :: createBoard(){
  int userInput;  
  cout<< "Enter your puzzle, use a zero to represent the blank" << endl;
  for(int i =0; i<3; ++i){
    if(i == 0){
      cout << "Enter the first row:";
    }
    if(i == 1){
      cout << "Enter the second row:";
    }
    if(i == 2){
      cout << "Enter the last row:";
    }
    for(int j =0; j<3; ++j){
      cin >> userInput;
      if(userInput == 0){
          root->row = i;
          root->col = j;
        }
      root->arr[i][j] = userInput;
    }
  }
  cout << endl;
  displayBoard();
  cout << "Enter your choice of algroithm" <<endl;
  cout << "1. Uniform Cost Search" <<endl;
  cout << "2. A* with the Misplaced Tile heuristic" <<endl;
  cout << "3. A* with the Manhattan distance heuristic." <<endl << endl;
}

void tree :: goUp(){


}


void tree :: goDown(){


}

void tree :: goLeft(){


}

void tree :: goRight(){


}

void tree :: displayBoard(){
  cout << "Displaying chart:" << endl;
  root->display();
}