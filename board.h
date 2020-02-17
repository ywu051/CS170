#ifndef __BOARD_H__
#define __BOARD_H__

using namespace std;
#include <vector>

class board{
  friend class tree;
  private:
    int arr[3][3] = {1, 2, 3,
                     4, 5, 6, 
                     7, 0, 8}; // test

    int goal[3][3] = {1, 2, 3, 
                      4, 5, 6, 
                      7, 8, 0}; //goal state

    bool validMove(char c); //check if it is valid
    int row=0;
    int col=0;
    int depth = 0;

public:
    board(); // creates the board
    board(board*);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();


};

#endif