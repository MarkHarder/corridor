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
  cout << "You see a glass orb on a plinth." << endl;
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

    getline(cin, str);

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
    player.addItem("blue liquid");
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
    player.addItem("purple paper");
  } else if (input == '2') {
    cout << "You get a papercut and decide to just take the top sheet." << endl;
    player.addItem("purple paper");
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
  cout << "You see a begger hunched against the wall. Type done to stop talking to him." << endl;

  getline(cin, str);
  str = "";
  while (str != "done") {
    cout << "> ";

    getline(cin, str);

    if (str == "name") {
      cout << "My name is Telemachus. I have no money. I have no family." << endl;
    } else if (str == "quest") {
      cout << "Can you deliver this letter to Marcus? (yes/no)" << endl;
      cout << "> ";

      getline(cin, str);

      if (str == "yes") {
        if (!player.hasItem("letter for Marcus")) {
          cout << "Thank you! Here is my letter." << endl;
          player.addItem("letter for Marcus");
        }
      } else {
        cout << "Oh well. I'll try to find someone else." << endl;
      }
    } else if (str == "eegg") {
      cout << "He produces a wooden horse toy and plays with it." << endl;
    } else if (str == "give fruit") {
      if (player.hasItem("fruit")) {
        cout << "Thank you! That is very generous of you. Please, take this harpoon." << endl;
        player.removeItem("fruit");
        player.addItem("harpoon");
      }
    } else if (str == "blue liquid") {
      cout << "He shrugs his shoulders. Probably magical." << endl;
    } else if (str == "purple paper") {
      cout << "He shrugs. It probably has magical properties." << endl;
    }
  }

  // Room 11
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "There is a beam of sunlight in the middle of the room." << endl;
  cout << "1. Walk through it" << endl;
  cout << "2. Walk around it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "As you walk through the sunlight a dart flies out and hits you." << endl;
    player.addPoints(-5);
  } else {
    cout << "You skirt around the edge of the sunlight." << endl;
  }

  // Room 12
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a large key resting on a red cloth." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You better not take someone's key. You will take the cloth though." << endl;
    player.addItem("cloth");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 13
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "In front of you is a bubbling pot over a fire. Inside is some stew." << endl;
  cout << "1. Eat the stew" << endl;
  cout << "2. Don't eat it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You taste some stew. It's very hearty" << endl;
    player.addPoints(6);
  } else {
    cout << "You decide against eating unknown food." << endl;
  }

  // Room 14
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a delicate, gold cage laying on its side." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take the cage." << endl;
    player.addItem("cage");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 15
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "There is nothing in this room" << endl;
  cout << "1. Keep going" << endl;
  cout << "> ";

  cin >> input;

  cout << "You keep going." << endl;

  // Room 16
  shop.clear();
  shop.insert(pair<string, int>("gem", 20));
  shop.insert(pair<string, int>("bones", 8));
  shop.insert(pair<string, int>("torch", 12));
  shop.insert(pair<string, int>("gloves", 5));
  shop.insert(pair<string, int>("dagger", 8));
  shop.insert(pair<string, int>("blue liquid", 7));
  shop.insert(pair<string, int>("purple paper", 15));

  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a shop. Type the name of an item to buy or sell it. Type done to leave." << endl;
  cout << endl;

  printShop(shop);

  str = "";
  while (str != "done") {
    cout << "Score: " << player.getPoints() << endl;
    cout << "> ";

    getline(cin, str);

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

  // Room 17
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "In the center of the room is a pit." << endl;
  cout << "1. Walk around the pit" << endl;
  cout << "2. Look into the pit" << endl;
  cout << "3. Jump over the pit" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1' || input == '2') {
    cout << "In your care not to fall into the pit, you slip and bruise your shin." << endl;
    player.addPoints(-3);
  } else {
    cout << "You safely jump over the pit to the other side." << endl;
  }

  // Room 18
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see an envelope laying in a corner." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take the letter." << endl;
    player.addItem("letter");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 19
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a hole in the wall." << endl;
  cout << "1. Keep going" << endl;
  if (player.hasItem("blue liquid")) {
    cout << "2. Put the blue liquid in the hole." << endl;
    if (player.hasItem("gem")) {
      cout << "3. Put the gem in the hole." << endl;
    }
  } else if (player.hasItem("gem")) {
    cout << "2. Put the gem in the hole." << endl;
  }
  cout << "> ";

  cin >> input;

  if (input == '2' && (player.hasItem("blue liquid") || player.hasItem("gem"))) {
    if (player.hasItem("blue liquid")) {
      cout << "The hole eats your liquid." << endl;
      player.removeItem("blue liquid");
      player.addItem("glass bottle");
      player.addPoints(14);
    } else if (player.hasItem("gem")) {
      cout << "The hole eats your gem." << endl;
      player.removeItem("gem");
      player.addPoints(32);
    }
  } else if (input == '3' && player.hasItem("blue liquid") && player.hasItem("gem")) {
    cout << "The hole eats your gem." << endl;
    player.removeItem("gem");
    player.addPoints(32);
  } else {
    cout << "You keep going." << endl;
  }

  // Room 20
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a battered telescope on a tripod." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take it." << endl;
    player.addItem("telescope");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 21
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see an umbrella." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take it." << endl;
    player.addItem("umbrella");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 22
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a glass orb on a plinth." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "As you touch the glass, it explodes into many sharp shards. You go on." << endl;
    player.addPoints(-6);
  } else {
    cout << "You walk past the orb to the next room." << endl;
  }

  // Room 23
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a soldier resting on the dusty floor. When he sees you, he stands up." << endl;

  getline(cin, str);
  str = "";
  while (str != "done") {
    cout << "> ";

    getline(cin, str);

    if (str == "name") {
      cout << "My name is Arthus. I just can't wait to be king." << endl;
    } else if (str == "quest") {
      cout << "Can you spy on the monk? I am suspicious he doesn't like me. (yes/no)" << endl;
      cout << "> ";

      getline(cin, str);

      if (str == "yes") {
        cout << "Thank you! I'll see you later." << endl;
      } else {
        cout << "Oh well. I'll try to find someone else." << endl;
      }
    } else if (str == "eegg") {
      cout << "He pulls out his rune-etched sword and tosses it straight up, catching it again." << endl;
    } else if (str == "give fruit") {
      if (player.hasItem("fruit")) {
        cout << "Thank you! That is very generous of you." << endl;
        player.removeItem("fruit");
      }
    } else if (str == "umbrella") {
      cout << "It's not even raining." << endl;
    } else if (str == "bones") {
      cout << "Those look like humanoid bones to me." << endl;
    }
  }

  // Room 24
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a wooden cup on top of a table." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "3. Look under the table" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take the cup." << endl;
    player.addItem("cup");
  } else if (input == '2') {
    cout << "You leave it." << endl;
  } else {
    cout << "There is nothing but dust under the table." << endl;
  }

  // Room 25
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a box on a doily between two candle sticks." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "When you reach for it, a spider jumps out and bites you." << endl;
    player.addPoints(-7);
  } else {
    cout << "You leave it." << endl;
  }

  // Room 26
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "The room is very dark." << endl;
  cout << "1. Walk through the middle of the room" << endl;
  cout << "2. Walk around the edge of the room" << endl;
  cout << "3. Walk randomly through the room" << endl;
  cout << "> ";

  cin >> input;

  cout << "Nothing happens as you walk through the room." << endl;

  // Room 27
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a large machine in the middle of the room." << endl;
  cout << "1. Keep going" << endl;
  if (player.hasItem("gem")) {
    cout << "2. Put the gem into the machine" << endl;
  }
  cout << "> ";

  cin >> input;

  if (input == '2' && player.hasItem("gem")) {
    cout << "With a grinding sound, your gem is turned into dust." << endl;
    player.removeItem("gem");
    player.addItem("dust");
  } else {
    cout << "You keep going." << endl;
  }

  // Room 28
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a monk meditating. He looks up at you." << endl;

  getline(cin, str);
  str = "";
  while (str != "done") {
    cout << "> ";

    getline(cin, str);

    if (str == "name") {
      cout << "My name is Oogway. I am hungry for noodles." << endl;
    } else if (str == "quest") {
      cout << "Sorry, I don't have a quest for you." << endl;
    } else if (str == "eegg") {
      cout << "He tucks away his tortoise necklace and performs a number of kung fu moves." << endl;
    } else if (str == "give fruit") {
      if (player.hasItem("fruit")) {
        cout << "Thank you! That is very generous of you." << endl;
        player.removeItem("fruit");
        player.addPoints(18);
      }
    } else if (str == "dust") {
      cout << "Hmm. This is very valuable. Don't sell it." << endl;
    } else if (str == "telescope") {
      cout << "That looks good for seeing things far away." << endl;
    } else if (str == "soldier" || str == "Arthas") {
      cout << "Oh I like him. But I am worried. He is a troubled boy." << endl;
    }
  }

  // Room 29
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a leather bag on a plinth." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take the bag, it is full of powder." << endl;
    player.addItem("powder");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 30
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a black disk on a plinth." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take it, it feels full of energy." << endl;
    player.addItem("disk");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 31
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a rope stretched across this room." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "As you move the rope a heavy rock smashes into you." << endl;
    player.addPoints(-6);
  } else {
    cout << "You step over it." << endl;
  }

  // Room 32
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "A giant waterfall covers most of one wall." << endl;
  cout << "1. Look at it" << endl;
  cout << "2. Keep going" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "The water looks very clear and cold." << endl;
  } else {
    cout << "You keep going." << endl;
  }

  // Room 33
  shop.clear();
  shop.insert(pair<string, int>("needle and thread", 27));
  shop.insert(pair<string, int>("glasses", 34));
  shop.insert(pair<string, int>("dice", 14));
  shop.insert(pair<string, int>("dust", 104));
  shop.insert(pair<string, int>("glass bottle", 3));
  shop.insert(pair<string, int>("blue liquid", 13));
  shop.insert(pair<string, int>("umbrella", 1));
  shop.insert(pair<string, int>("telescope", 1));
  shop.insert(pair<string, int>("cup", 2));
  shop.insert(pair<string, int>("cloth", 12));
  shop.insert(pair<string, int>("disk", 17));

  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a shop. Type the name of an item to buy or sell it. Type done to leave." << endl;
  cout << endl;

  printShop(shop);

  str = "";
  while (str != "done") {
    cout << "Score: " << player.getPoints() << endl;
    cout << "> ";

    getline(cin, str);

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

  // Room 34
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a rowboat on the shore." << endl;
  cout << "1. Ride it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You realize that it is chained to the dock and there are no oars." << endl;
  } else {
    cout << "You leave it." << endl;
  }

  // Room 35
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see an acorn in the cracks of the floor." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take it." << endl;
    player.addItem("acorn");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 36
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a fountain." << endl;
  cout << "1. Drink the water" << endl;
  cout << "2. Keep going" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You lean down to take a drink and a spider bites your neck." << endl;
    player.addPoints(-10);
  } else {
    cout << "You leave it." << endl;
  }

  // Room 37
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see several coins on a cloth." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take the coins." << endl;
    player.addItem("coins");
  } else {
    cout << "You leave them." << endl;
  }

  // Room 38
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a chandelier suspended by a rope." << endl;
  cout << "1. Keep going" << endl;
  if (player.hasItem("dagger")) {
    cout << "2. Cut the rope" << endl;
  }
  cout << "> ";

  cin >> input;

  if (input == '2' && player.hasItem("dagger")) {
    cout << "The chandelier comes crashing down and scrapes your arm." << endl;
    player.addPoints(-3);
  } else {
    cout << "You keep going." << endl;
  }

  // Room 39
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "There is a thick fog here. You can't see anything." << endl;
  cout << "1. Keep going" << endl;
  cout << "> ";

  cin >> input;

  cout << "You keep going." << endl;

  // Room 40
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a witch leaning agains the wall with her broomstick." << endl;

  getline(cin, str);
  str = "";
  while (str != "done") {
    cout << "> ";

    getline(cin, str);

    if (str == "name") {
      cout << "My name is Myrtle. I am not very popular." << endl;
    } else if (str == "quest") {
      cout << "Can you please get potion ingredients? I need powder, newt, and eggs. (yes/no)" << endl;
      cout << "> ";

      getline(cin, str);

      if (str == "yes") {
        cout << "Thank you! I'll see you when you find them." << endl;
      } else {
        cout << "Oh well. I'll try to find someone else." << endl;
      }
    } else if (str == "eegg") {
      cout << "She sticks her hand through the wall and looks sadly at you." << endl;
    } else if (str == "acorn") {
      cout << "That could grow into a tree." << endl;
    } else if (str == "disk") {
      cout << "That looks dangerous. Do you know what it is?" << endl;
    }
  }

  // Room 41
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a box on a doily between two candle sticks." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take the box." << endl;
    player.addItem("box");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 42
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a giant treasure chest." << endl;
  cout << "1. Open it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You open the treasure chest. It is empty, but you feel better." << endl;
    player.addPoints(12);
  } else {
    cout << "You leave it." << endl;
  }

  // Room 43
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "There is a tree branch here." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take it." << endl;;
    player.addItem("branch");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 44
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "There are six crystal pillars in this room." << endl;
  cout << "1. Keep going" << endl;
  cout << "> ";

  cin >> input;

  cout << "You keep going." << endl;

  // Room 45
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "There is a yellow flower planted here." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You remove the flower from the ground." << endl;
    player.addItem("flower");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 46
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see a stiff mask on the ground." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take it." << endl;
    player.addItem("mask");
  } else {
    cout << "You leave it." << endl;
  }

  // Room 47
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see amouse running in a circle." << endl;
  cout << "1. Pet it" << endl;
  cout << "2. Take it" << endl;
  cout << "3. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '3') {
    cout << "You leave it." << endl;
  } else {
    cout << "It bites you." << endl;
    player.addPoints(-18);
  }

  // Room 48
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You see an empty plinth here." << endl;
  cout << "1. Keep going" << endl;
  cout << "> ";

  cin >> input;

  cout << "You keep going." << endl;

  // Room 49
  printItems(player.getItems());
  cout << "Score: " << player.getPoints() << endl;
  cout << "You are at a checkpoint. Checkpoint Code: BUBBLE" << endl;

  getline(cin, str);

  return 0;
}
