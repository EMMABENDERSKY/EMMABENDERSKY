#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"

using namespace std;

room::room(char* newDescription, bool newVictoryRoom)
{
  description = new char[80];
  strcpy(description, newDescription);
  isVictoryRoom = newVictoryRoom;
}

char* room::getDescription()
{
  return description;
}

void room::setExit(char* direction, room* neighbor)
{
  exits[direction] = neighbor;
}

room* room::getExit(char* direction)
{
  
}

vector<item*> room::getItems()
{
  return items;
}

void room::addItem(item* item)
{
  items.push_back(item);
}

void room::removeItem(item* item)
{
  item.erase(remove(items.begin(), items.end(), item), items.end());
}

void room::setVitoryRoom(bool victoryRoom);
{
  isVictoryRoom = victoryRoom();
}

bool room::isVictory();
{
  return isVictoryRoom();
}
