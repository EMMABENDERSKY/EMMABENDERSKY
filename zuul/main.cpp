#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"
#include "room.h"

using namespace std;

//winning condition: player has to collect all items and put them in the victory room.

//function prototypes
void setUpRooms(vector<room*> & rooms, vector<item*> & items);
void displayRoom(room* room);
room* move(room* currentRoom, char* direction);
bool checkWinCondition(vector<item*> & invetory, room* vectoryRoom);

int main()
{
  vector<room*> rooms;
  vector<item*> items;
  vector<item*> inventory;

  setUpRooms(rooms, items);

  room* currentRoom = room[0];
  room* ictoryRoom = room[15];

  bool gameRunning = true;
  while(gameRunning)
    {
      displayRoom(currentRoom);

      char command[10];
      cout << "Enter command (NORTH/SOUTH/EAST/WEST/PICKUP/DROP/QUIT): " << endl;
      cin.get(command, 10);
      cin.get();

      if(strcmp(command, "QUIT") == 0)
	gameRunning = false;

      else if(strcmp(command, "NORTH") == 0 || strcmp(command, "SOUTH") == 0 || strcmp(command, "EAST") == 0 || strcmp(command, "WEST") == 0)
	room* nextRoom = move(currentRoom, command);

      else if(strcpy(command, "PICKUP") == 0)
	{
	  if(!currentRoom->getItems().empty())
	    {
	    item* item = currentRoom->getItems().back();
	    inventory.push_back(item);
	    currentRoom->removeItem(item);
	    cout << "Picked up: " << item->getName() << endl;
	    }
	  else
	    cout << "No items to pick up." << endl;
	}

      else if(strcmp(command, "DROP") == 0)
	{
	  if(!inventory.empty())
	    {
	      item* item = inventory.back();
	      inventory.pop_back();
	      currentRoom->addItem(item);
	      cout << "Dropped: " << item -> getName() << endl;
	    }
	  else
	    cout << "No items to drop." << endl;
	}
    }
  
  return 0;
}

void setUpRooms(vector<room*> & rooms, vector<item*> & items)
{
  rooms.push_back(new room("Starting room with exits in all directions."));//#1
  rooms.push_back(new room("1 Hall"));//#2
  rooms.push_back(new room("Library"));//#3
  rooms.push_back(new room("Classroom"));//#4
  rooms.push_back(new room("Gym"));//#5
  rooms.push_back(new room("Science lab"));//#6
  rooms.push_back(new room("2 Hall"));//#7
  rooms.push_back(new room("Cafeteria"));//#8
  rooms.push_back(new room("Bathroom"));//#9
  rooms.push_back(new room("Art room"));//#10
  rooms.push_back(new room("Auditorium"));//#11
  rooms.push_back(new room("3 Hall"));//#12
  rooms.push_back(new room("Band room"));//#13
  rooms.push_back(new room("Choir room"));//#14
  rooms.push_back(new room("Computer lab (VICTORY ROOM!!!!!)- drop all items here to win."));//#15
}

void displayRoom(room* room)
{

}

room* move(room* currentRoom, char* direction)
{

}

bool checkWinCondition(vector<item*> & invetory, room* vectoryRoom)
{

}
