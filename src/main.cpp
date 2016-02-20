#include <iostream>

using namespace std;

int main() {
  char input;

  // Room 1
  cout << "You see a small, silver dagger on the floor." << endl;
  cout << "1. Take it" << endl;
  cout << "2. Leave it" << endl;
  cout << "> ";

  cin >> input;

  if (input == '1') {
    cout << "You take the silver dagger and move on to the next room." << endl;
  } else {
    cout << "You walk past the dagger to the next room." << endl;
  }

  // Room 2
  cout << "Room two description." << endl;

  return 0;
}
