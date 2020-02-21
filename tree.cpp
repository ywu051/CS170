#include <iostream>
#include <list>
using namespace std;
#include "tree.h"
#include "board.h"

tree :: tree(){
  root = new board(); //intialize new board
  root->display();
  curr = root;
  curr->prev = 0;
  
}

void tree :: createBoard(){
  int userInput;  
  cout<< "Enter your puzzle, use a zero to represent the blank: " << endl;
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
      cin>>userInput;
      if(userInput == 0){
        root->row = i;
        root->col = j;
      }
      root->arr[i][j]=userInput;
    }
  }
  cout<<endl <<endl;
  cout << "1.	Uniform Cost Search" << endl;
  cout << "2.	A* with the Misplaced Tile heuristic" << endl;
  cout << "3.	A* with the Manhattan Distance heuristic." << endl;
}

void tree :: goUp(){
 if(curr->validMove('w')) {
    // Create child
    board* child = new board(curr);
    
    child->moveUp();//temp move up
    
    // Add child node to parent
    curr->up = child;
    
    // Set child's parent
    child->prev = curr;

 } 
}

void tree :: goDown(){
  if(curr->validMove('s')) {
    // Create child
    board* child = new board(curr);
    
    child->moveDown();
    
    // Add child node to parent
    curr->down = child;
    
    // Set child's parent
    child->prev = curr;
  }
}
void tree :: goLeft(){
  if(curr->validMove('a')) {
    // Create child
    board* child = new board(curr);
    
    child->moveLeft();
    // Add child node to parent
    curr->left = child;
    
    // Set child's parent
    child->prev = curr;
  }
}
void tree :: goRight(){
  if(curr->validMove('d')) {
    // Create child
    board* child = new board(curr);

    child->moveRight();
    // Add child node to parent
    curr->right = child;
    
    // Set child's parent
    child->prev = curr;
  }
}
void tree :: displayBoard(){
  //cout << "Display Board:"<<endl;
  root->display();
}


bool tree:: expand(board* r, vector <board*> &b, int heuristic){
  //r->display();
  vector <char> c = r->legalMoves(); // store all possible moves
  curr=r;
  
  //cout << endl << "current board" << endl;
  //r->display();

  board* check = new board(r);
  string checkTemp = check->getHash();

  if(r->getHashGoal() == checkTemp){ // goal check
    //cout << "GOAL!!" << endl;
    //check->display();
    return true;
  }
  cout<< "Expanding State"<<endl;
  ++countNodes;
  cout << "The best state to expand with a g(n) = " << r->depth << " and h(n) = " << r->count << " is... " << endl << endl;
  for(int i=0; i<c.size(); ++i){ //goes through the "queue"
    
    if(c.at(i)=='w'){ //check queue
      //curr->display();
      board* temp = new board(r); //set temp val of current node
      temp->moveUp(); 
      string sTemp = temp->getHash(); //get the hash of the node
      // cout << sTemp << endl;
      
      if(r->getHashGoal() == sTemp){//if that is the goal state then return
        // cout << "GOAL!!" << endl;
        temp->display();
        return true;
      }
      
      if(explored->find(sTemp) == explored->end()){//did not find hash of up
        this->goUp(); //move up
        curr->addScore(heuristic, curr->depth);
        b.push_back(curr->up);//push it back into problem
        if(b.size() > size){
          size = b.size();
        }
        //cout << "TEST" << curr << endl;
        // curr = curr->prev;
        //cout << "This Hash: " << sTemp << endl;
        explored->insert(pair<string,bool>(sTemp,true));
      
        //if(explored->find(sTemp) != explored->end()){
          //cout << endl << endl << "DONE" << endl << endl;
        //}
        //cout << "explored size: " << explored->size() << endl;
      }
    }
    if(c.at(i)=='s'){
      board* temp = new board(r); //set temp val;
      temp->moveDown();
      string sTemp = temp->getHash();
      // cout <<sTemp<<endl;
      if(r->getHashGoal() == sTemp){
        // cout << "GOAL!!" << endl;
        temp->display();
        return true;
      }
      if(explored->find(sTemp) == explored->end()){
        this->goDown(); //expanding state
        curr->addScore(heuristic, curr->depth);
        b.push_back(curr->down);
        if(b.size() > size){
          size = b.size();
        }
        // curr = curr->prev;
        // cout << "This Hash: " << sTemp << endl;
        explored->insert(pair<string,bool>(sTemp,true));
        //if(explored->find(sTemp) != explored->end()){
          //cout << endl << endl << "DONE" << endl << endl;
        //}
        //cout << "explored size: " << explored->size() << endl;
      }
    }
    if(c.at(i)=='a'){
      board* temp = new board(r); //set temp val;
      temp->moveLeft();
      string sTemp = temp->getHash();
      // cout << sTemp << endl;
      if(r->getHashGoal() == sTemp){ //checking the hash
        // cout << "GOAL!!" << endl;
        temp->display();
        return true;
      }
      if(explored->find(sTemp) == explored->end()){
        this->goLeft();
        curr->addScore(heuristic, curr->depth);
        b.push_back(curr->left);
        if(b.size() > size){
          size = b.size();
        }
        // curr = curr->prev;
        //cout << "This Hash: " << sTemp << endl;
        explored->insert(pair<string,bool>(sTemp,true));
        //if(explored->find(sTemp) != explored->end()){
          // cout << endl << endl << "DONE" << endl << endl;
        //}
        //cout << "explored size: " << explored->size() << endl;            
      }
    }
    if(c.at(i)=='d'){
      
      board* temp = new board(r); //set temp val;
      temp->moveRight();
      string sTemp = temp->getHash();
      // cout << sTemp << endl;
      if(r->getHashGoal() == sTemp){ //checking the hash
        // cout << "GOAL!!" << endl;
        temp->display();
        return true;
      }
      if(explored->find(sTemp) == explored->end()){
        this->goRight();
        curr->addScore(heuristic, curr->depth);

        b.push_back(curr->right);
        if(b.size() > size){
          size = b.size();
        }
        // curr = currc->prev;
        // cout << "This Hash: " << sTemp << endl;
        explored->insert(pair<string,bool>(sTemp,true));
        //if(explored->find(sTemp) != explored->end()){
          //cout << endl << endl << "DONE" << endl << endl;
        //}
        // cout << "explored size: " << explored->size() << endl;
      }
    }
  }
  
  return false;
}

void tree :: search(board* cur ,int heuristic){
    problem.push_back(cur); // make initial state "queue"
    board* lowestNode = NULL;
    board* tempNode;
    vector<board*> tempVector;
    int lowestScore;
    int lowestLocation =0;

    while(true){
      
      if( problem.empty() ){
        return;
      }
      
      for(int i = 0; i < problem.size(); ++i){
        tempNode = problem.at(i); //traverse through all nodes
        tempNode->addScore(heuristic, tempNode->depth); //get the score
          
        if(lowestNode == NULL){
          // cout << "lowest Node assigned" << endl;
          lowestNode = tempNode; //node with the lowest score, expand this 
          lowestLocation = 0;
        }
        else if( lowestNode->score > tempNode->score){ //get smallest score
          // cout << "new low" << endl;
          lowestLocation = i;
          lowestNode = tempNode; 
        }
      }
      
      //expanding lowest Node
      // find lowestNode
      //and put lowestNode in explored


      //cout << "expanding lowest Node: " << lowestLocation << endl;
      //lowestNode->display(); 
      string lowHash = lowestNode->getHash();
      
      //cout << "This Hash: " << lowHash << endl;
      
      explored->insert( pair<string,bool>(lowHash , true) );    
      //cout << "explored size: " << explored->size() << endl;
      
      //cout << "LOWEST NODE" << endl;
      //lowestNode->display();
      if(expand(lowestNode, problem, heuristic)){
        cout<<"done"<<endl;
        cout << "To solve this problem the search algroithm expanded a total of " << countNodes << " nodes." << endl;
        cout << "The maximum number of nodes in the queue at any one time was " << size << endl;
        return;
      }
      // else{
      //   cout << "IMPOSSIBLE" << endl;
      //   return;
      // }

      // for(int i =0; i<problem.size();++i){
      //   problem.at(i)->display();
      // }      
      problem.erase( problem.begin()+lowestLocation ); // removes node
      lowestNode = problem.at(0);
      curr = lowestNode;

      for(int i =0; i<problem.size();++i){
        problem.at(i)->display();
      }
    }
  }

  