#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

class Player {
  private:
    int points;
    std::vector<std::string> items;

  public:
    Player();
    void addPoints(int x);
    int getPoints();
    void addItem(std::string *item);
    std::vector<std::string> getItems();
    bool hasItem(std::string *item);
    void removeItem(std::string *item);
};

#endif
