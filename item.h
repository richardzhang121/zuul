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
  char* getName();
  char* getDescription();
 private:
 //initiate variables
  char* name;
  char* description;
  
};
#endif