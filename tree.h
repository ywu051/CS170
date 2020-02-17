#ifndef __TREE_H__
#define __TREE_H__
#include "board.h"

using namespace std;

class tree{
  private:

  vector <board*> problems; //holds all nodes to traverse it

  public:
  
  tree();
  void goUp();
  void goDown();
  void goLeft();
  void goRight();

};


#endif