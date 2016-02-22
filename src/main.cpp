#include <iostream>

#include "Player.h"

using namespace std;

void printItems(vector<string> items) {
  if (items.size() > 0) {
    cout << "You have:" << endl;
    for (vector<string>::iterator it = items.begin(); it != items.end(); it++) {
      cout << "  " << *it << endl;
    }
  }
}

int main() {
  char input;
  Player player;

  // Room 1
  cout << "You see a small, silver dagger on the floor." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take the silver dagger and move on to the next room." << endl;
    player.addItem( "dagger" );
  } else {
    cout << "You walk past the dagger to the next room." << endl;
  }

  // Room 2
  printItems(player.getItems());
  cout << "You see a glass globe on a plinth." << endl;
  cout << "1> Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "As you touch the glass, it explodes into many sharp shards." << endl;
    player.addPoints(-8);
  } else {
    cout << "You walk past the orb to the next room." << endl;
  }

  // Room 3
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "Room 3 description" << endl;

  return 0;
}
