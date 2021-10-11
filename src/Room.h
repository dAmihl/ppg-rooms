#pragma once

#include <libtcod.h>

class Room {

public:
  Room(tcod::ConsolePtr& cons) : console{cons} {}

private:
  tcod::ConsolePtr& console;

public:
 void draw();
 void update();

};
