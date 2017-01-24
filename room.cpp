#include "room.h"
#include <iostream>
#include<vector>
#include "item.h"

using namespace std;

//sets room name
room::room(const char* name){
  this->name= strdup(name);
}

//gets roomName (command)
char* room::getName(){
  return name;
}

//gets roomDescription (command)
char* room::getDescription(){
  return description;
}

//sets appropriate exits depending on user input
void room::setExits(room* north, room* east, room* south, room* west){
  exits[1]=north;
  exits[2]=east;
  exits[3]=south;
  exits[4]=west;

}

room* room::getExits(int x){
  map<int, room*>::iterator it = exits.find(x);
  if(it != exits.end()){
    return it->second;
  }
}

room* room::getNorth(){
  
}

room* room::getWest(){
  
}
room* room::getSouth(){
  
}


room* room::getEast(){

}

//prints out exits available
void room::printExits(){
  for(map<int,room*>::iterator it = exits.begin(); it != exits.end();it++){
    if((*it).second!=NULL&&(*it).first==1){
      cout<<"NORTH:"<<(*it).second->getName()<<endl;
    }
    if((*it).second!=NULL&&(*it).first==2){
      cout<<"WEST:"<<(*it).second->getName()<<endl;
    }
    if((*it).second!=NULL&&(*it).first==3){
      cout<<"SOUTH:"<<(*it).second->getName()<<endl;
    }
    if((*it).second!=NULL&&(*it).first==4){
      cout<<"EAST:"<<(*it).second->getName()<<endl;
    }
  }
}

//prints out items in room
void room::printItem(){
  for(vector<item*>::iterator it = roomItems.begin();it != roomItems.end();it++){
    cout<<(*it)->getName()<<endl;
  }
}

//adds item to room
void room::dropItem(item* item){
  roomItems.push_back(item);
}

//takes item 
void room::grabItem(const char* itemName,vector<item*>* inventory){
  for(vector<item*>::iterator it = roomItems.begin(); it != roomItems.end();it++){
    if(strcmp((*it)->getName(),itemName)==0){
      roomItems.erase(it);
      inventory->push_back(*it);
      cout<<"You have added "<<itemName<<" to your inventory"<<endl;     
      break;
    }
  }
}

//checks if the item is in the room
bool room::checkItem(char* itemName){
  for(vector<item*>::iterator it = roomItems.begin(); it != roomItems.end();it++){
    if(strcmp((*it)->getName(),itemName)==0){
      return true;
      break;
    }
    else{
      return false;
    } 
  }
}

void room::setItem(item* item){
  roomItems.push_back(item);
}