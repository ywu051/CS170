#ifndef __TREE_H__
#define __TREE_H__
#include "board.h"

using namespace std;

class tree{
  private:

  public:
  
  board* root;
  board* curr;
  board* prev;
  tree();
  void createBoard();
  void goUp();
  void goDown();
  void goLeft();
  void goRight();
  void displayBoard();

};


#endif