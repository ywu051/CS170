#include <iostream>
#include "board.h"
#include "tree.h"
using namespace std;




int main() {
  int userH = 0; // User's choice of Heuristic function
  tree t = tree();
  cout << "Welcome to 861283489's 8-puzzle solver." << endl;
  t.createBoard();
  cin >> userH; 
  cout << userH << endl;

return 0;
}
