#include <iostream>
#include <map>

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

void printShop(map<string, int> item_prices) {
  for (map<string, int>::iterator it = item_prices.begin(); it != item_prices.end(); it++) {
    cout << it->first;
    for (int i = 10 - it->first.size(); i > 0; i--) {
      cout << ".";
    }
    if (it->second < 10) {
      cout << ".";
    }
    cout << it->second << endl;
  }
}

int main() {
  char input;
  string str;
  map<string, int> shop;
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
  } else if (input == '2') {
    cout << "You walk past them." << endl;
  } else {
    cout << "You try to talk to them, but they just giggle." << endl;
  }

  // Room 5
  shop.clear();
  shop.insert(pair<string, int>("rope", 10));
  shop.insert(pair<string, int>("fruit", 8));
  shop.insert(pair<string, int>("gloves", 6));
  shop.insert(pair<string, int>("dagger", 10));
  shop.insert(pair<string, int>("orb", 44));
  shop.insert(pair<string, int>("statue", 10));

  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a shop. Type the name of an item to buy or sell it. Type done to leave." << endl;
  cout << endl;

  printShop(shop);

  str = "";
  while (str != "done") {
    cout << "Score: " << player.getPoints() << endl;
    cout << "> ";

    cin >> str;

    for (map<string, int>::iterator it = shop.begin(); it != shop.end(); it++) {
      if (str == it->first) {
        if (player.hasItem(it->first.c_str())) {
          cout << "Sold." << endl;
          player.addPoints(it->second);
          player.removeItem(it->first.c_str());
        } else {
          if (player.getPoints() >= it->second) {
            cout << "Bought." << endl;
            player.addItem(it->first.c_str());
            player.addPoints(-(it->second));
          } else {
            cout << "You don't have enough points for that." << endl;
          }
        }
      }
    }
  }

  // Room 6
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see some bricks scattered on the floor here." << endl;
  cout << "1. Stack them" << endl;
  cout << "2. Leave them" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "Everything looks much more orderly now." << endl;
    player.addPoints(2);
  } else {
    cout << "You leave them." << endl;
  }

  // Room 7
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a glass bottle filled with blue liquid on a plinth." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take the bottle." << endl;
    player.addItem("potion");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 8
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see stack of purple paper on a glass table." << endl;
  cout << "1. Take a sheet" << endl;
  cout << "2. Take the stack" << endl;
  cout << "3. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take a sheet of the paper." << endl;
    player.addItem("paper");
  } else if (input == '2') {
    cout << "You get a papercut and decide to just take the top sheet." << endl;
    player.addItem("paper");
    player.addPoints(-4);
  } else {
    cout << "You leave it." << endl;
  }

  // Room 9
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a metal grate in the wall." << endl;
  cout << "1. Look into it" << endl;
  cout << "2. Try to open it" << endl;
  cout << "3. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1' || input == '2') {
    cout << "When you get near the grate a spider jumps out and bites you." << endl;
    player.addPoints(-10);
  } else {
    cout << "You leave it." << endl;
  }

  // Room 10
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "Room 10" << endl;

  return 0;
}
