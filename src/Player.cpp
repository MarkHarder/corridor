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

void Player::addItem(const char *item) {
  std::string new_item( item );
  items.push_back( new_item );
}

std::vector<std::string> Player::getItems() {
  return items;
}

bool Player::hasItem(const char *item) {
  std::string new_item( item );
  return (std::find(items.begin(), items.end(), new_item) != items.end());
}

void Player::removeItem(const char *item) {
  std::string new_item( item );
  int i = std::find(items.begin(), items.end(), new_item) - items.begin();

  if (i < items.size()) {
    items.erase(items.begin() + i);
  }
}
