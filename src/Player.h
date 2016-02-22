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
    void addItem(const char *item);
    std::vector<std::string> getItems();
    bool hasItem(const char *item);
    void removeItem(const char *item);
};

#endif
