#include "Room.h"

void Room::draw() {
  tcod::print(*console, 0, 0, "I am a room!", &TCOD_white, nullptr, TCOD_BKGND_SET, TCOD_LEFT);
}

void Room::update() {
}
