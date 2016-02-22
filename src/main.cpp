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
    player.addItem("dagger");
  } else {
    cout << "You walk past the dagger to the next room." << endl;
  }

  // Room 2
  printItems(player.getItems());
  cout << "You see a glass globe on a plinth." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "As you touch the glass, it explodes into many sharp shards. You go on." << endl;
    player.addPoints(-3);
  } else {
    cout << "You walk past the orb to the next room." << endl;
  }

  // Room 3
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a small statue of a fat monk resting on a red cushion." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take the statue." << endl;
    player.addItem("statue");
  } else {
    cout << "You leave the statue." << endl;
  }

  // Room 4
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see three blue imps climbing near a window." << endl;
  cout << "1. Take them" << endl;
  cout << "2. Leave them" << endl;
  cout << "3. Talk to them" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "The imps are not happy to see you try to take them." << endl;
    player.addPoints(-8);
  } else if (input =='2') {
    cout << "You walk past them." << endl;
  } else {
    cout << "You try to talk to them, but they just giggle." << endl;
  }

  // Room 5
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "Room 5" << endl;

  return 0;
}
