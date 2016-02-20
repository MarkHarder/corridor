#include "Player.h"

Player::Player() {
  points = 0;
}

void Player::addPoints(int x) {
  points += x;
}

int Player::getPoints() {
  return points;
}

void Player::addItem(std::string *item) {
  items.push_back( *item );
}

std::vector<std::string> Player::getItems() {
  return items;
}

bool Player::hasItem(std::string *item) {
  return (std::find(items.begin(), items.end(), *item) != items.end());
}

void Player::removeItem(std::string *item) {
  int i = std::find(items.begin(), items.end(), *item) - items.begin();

  if (i < items.size()) {
    items.erase(items.begin() + i);
  }
}
