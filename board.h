#ifndef __BOARD_H__
#define __BOARD_H__
#include <string>
using namespace std;
#include <vector>

class board{
  friend class tree;
  private:
    int arr[3][3] = {1, 2, 3,
                     4, 5, 6, 
                     7, 0, 8};
    int goal[3][3] = {1, 2, 3, 
                      4, 5, 6, 
                      7, 8, 0}; //goal state
    bool validMove(char c);
    int row=0;
    int col=0;
    int depth = 0;
    int score;
    int count = 0;
    board operator= (const board& b);
    board* up;
    board* down;
    board* left;
    board* right;
    
    

  public:
    board();
    board(board* );
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void display();
    vector<char> legalMoves();
    int heuristics(int heuristic);
    void findManDist(int currNum, int &temprow, int &tempcol);
    board* prev;
    void addScore(int h, int d);
    string getHash();
    string getHashGoal();
};






#endif