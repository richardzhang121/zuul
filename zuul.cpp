#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"
//includes similar to java imports
using namespace std;
void notRoom(){
    cout << "There isn't a room here" << endl;
}

int main(){
    bool running = true;
    cout << "Welcome to Richard's food adventure told through C++ yay!!" << endl;
    vector <item*> inventory;
    room* a = new room ("A. A is for apple");
    room* b = new room ("B. B is for bread");
    room* c = new room ("C. C is for caramel");
    room* d = new room ("D. D is for drumbone");
    room* e = new room ("E. E is for eggs");
    room* f = new room ("F. F is for fried chicken");
    room* g = new room ("G. G is for gummy bears");
    room* h = new room ("H. H is for honeydew melon");
    room* i = new room ("I. I is for ice cream");
    room* j = new room ("J. J is for jambalaya");
    room* k = new room ("K. K is for kiwi");
    room* l = new room ("L. L is for lamb");
    room* m = new room ("M. M is for milkshake");
    room* n = new room ("N. N is for noodles");
    room* o = new room ("O. O is for onions");
    
	//sets items
    item* Fork = new item ("Fork");
    item* Spoon = new item ("Spoon");
    item* Knife = new item ("Knife");
    item* Toothpick = new item ("Toothpick");
    item* Spork = new item ("Spork");
    item* Napkin = new item ("Napkin");
    
    inventory.push_back(Napkin);
	
	//places items to their room
    c->setItem(Fork);
    j->setItem(Spoon);
    m->setItem(Knife);
    n->setItem(Toothpick);
    o->setItem(Spork);
    
	//sets exits based on location(north, west, south, east)
    a->setExits(d, b, e, c);
    b->setExits(NULL, i, NULL, a);
    c->setExits(NULL, a, NULL, j);
    d->setExits(NULL, l, a, NULL);
    e->setExits(a, f, h, g);
    f->setExits(NULL, NULL, NULL, e);
    g->setExits(NULL, e, NULL, m);
    h->setExits(e, o, NULL, n);
    i->setExits(NULL, NULL, NULL, b);
    j->setExits(k, c, NULL, NULL);
    k->setExits(NULL, NULL, j, NULL);
    l->setExits(NULL, NULL, NULL, d);
    m->setExits(NULL, g, NULL, NULL);
    n->setExits(NULL, h, NULL, NULL);
    o->setExits(NULL, NULL, NULL, h);
    
    
    room* current = a;
	//game starts at room a
    char input[100];

  while(running){
    
	//sets general layout
    cout<<"You are currently in:"<<current->getName()<<endl;
    cout<<"Your exits options are:"<<endl;
    current->printExits();
    cout << "Would you like to go: \n NORTH \n WEST \n SOUTH \n EAST" <<endl;
    cout<<"Here are the items in the room: "<<endl;
    current->printItem();
    cin>>input;
	//sets win condition
    if(current==o){
      cout<< "You win!"<<endl;
      running=false;
    }
	
	//if user inputs a specific cardinal direction
    if(strcmp(input, "NORTH")==0){
      if((current->getExits(1))!=NULL){
      	current=current->getExits(1);
      }
      else{
	      notRoom();
      }
    }
    else if(strcmp(input, "WEST")==0){
      if((current->getExits(2))!=NULL){
	  current = current->getExits(2);
	  }
      else{
	      notRoom();
      }
    }
    else if(strcmp(input, "SOUTH")==0){
      if((current->getExits(3))!=NULL){
	      current=current->getExits(3);
	    }
      else{
	      notRoom();
      }
    }
    else if(strcmp(input, "EAST")==0){
      if((current->getExits(4))!=NULL){
	      current=current->getExits(4);
	    }
      else{
	      notRoom();
      }
    }
	
	//quits game
    else if(strcmp(input, "QUIT")==0){
      running=false;
    }
	
	//checks what is in the inventory through iterator and spitting out name
    else if(strcmp(input, "INVENTORY")==0){
      for(vector<item*>::iterator it = inventory.begin(); it != inventory.end();it++){
	      cout<<(*it)->getName()<<endl;
      }
    }
	
	//drops item
    else if(strcmp(input,"DROP")==0){
      cout<<"What item would you like to drop?"<<endl;
      cin>>input;
      for(vector<item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
      	if(strcmp((*it)->getName(),input)==0){
      	  current->dropItem((*it));
      	  *it = inventory.back();
      	  inventory.pop_back();
      	  break;
  	    }
      }
    }
	
	//takes an item
    else if(strcmp(input,"GRAB")==0){
      cout<<"What item would you like to grab?"<<endl;
      cin>>input;
      if(current->checkItem(input)==true){	
	      current->grabItem(input,&inventory);
      }
      else{
	      cout<<"Nothing meets this description"<<endl;
      }
    }
	
	//if user inputs a command that is not implemented
    else{
      cout<<"The only commands to move are: \n NORTH, WEST, SOUTH, EAST" << endl;
	  cout << "You can also use these: \n QUIT, DROP, GRAB and INVENTORY"<<endl;
    }
  }
}
