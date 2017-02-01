//item header file
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

class item{
  
 public:
 //initiate methods
  item(const char* name);
  char* getName(); // gets name
  char* getDescription(); // gets description
 private:
 //initiate variables
  char* name;
  char* description;
  
};
#endif
