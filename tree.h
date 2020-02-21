#ifndef __TREE_H__
#define __TREE_H__
#include "board.h"
#include <list>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm> 
using namespace std;

class tree{
  private:
  vector <board*> problem; //holds all nodes to traverse it basically a queue

  public:
  board* root;  
  board* curr;
  board* prevNode;
  int countNodes = 0; 
  int size = 0; 
  
  tree();
  void goUp();
  void goDown();
  void goLeft();
  void goRight();
  void displayBoard();
  bool expand(board* , vector<board*> &, int);
  void createBoard();


  string leafHash;
  map<string, bool> *explored = new map<string,bool>;
  void search(board* cur ,int heuristic);

};


#endif
