#include "item.h"
#include <iostream>

using namespace std;

item::item(const char* name){
  this->name=strdup(name);
  
}
//gets description and name
char* item::getDescription(){
  return description;
}
char* item::getName(){
  return name;
}