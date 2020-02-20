#ifndef __BOARD_H__
#define __BOARD_H__

using namespace std;
#include <vector>
#include <cstdlib>

class board{
  friend class tree;
  private:
    int arr[3][3]  = {1, 2, 3,
                      4, 5, 6, 
                      7, 8, 0}; // test

    int goal[3][3] = {1, 2, 3, 
                      4, 5, 6, 
                      7, 8, 0}; //goal state

    bool validMove(char c); //check if it is valid
    int row=0;
    int col=0;
    int depth = 1; //creating board, root has depth 1
    int cost; // cost of the heurstic function
    board* up; // moves board state, use for adding child nodes
    board* down; // moves board state, use for adding child nodes
    board* left; // moves board state, use for adding child nodes
    board* right; // moves board state, use for adding child nodes

public:
    board* prev;
    board(); // creates the board
    board(board*);
    void display(); // shows current board
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int heuristics(int h);
    void addCost(int h, int d);
    vector<char> allMoves();
    void findManDist(int currNum, int &temprow, int &tempcol);

};

#endif