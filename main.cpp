#include <iostream>
#include "board.h"
#include "tree.h"
using namespace std;




int main() {
  tree t = tree();
  cout << "Welcome to 861283489's 8-puzzle solver." << endl;
  t.createBoard();
  board b = board();
  b.moveDown();
  b.display();
return 0;
}
