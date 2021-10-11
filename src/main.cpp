
#include <SDL.h>
#include <libtcod.h>
#include "Yaml2Puzzle.h"
#include "Room.h"

#include <cstdlib>

int main(int argc, char** argv) {
  TCOD_ContextParams params = {TCOD_COMPILEDVERSION};
  params.argc = argc;
  params.argv = argv;
  params.vsync = true;
  params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
  params.window_title = "PPG-ROOMS";

  tcod::ConsolePtr console = tcod::new_console(80, 25);
  params.columns = console->w;
  params.rows = console->h;

  tcod::ContextPtr context = tcod::new_context(params);

  Yaml2Puzzle y2p;

  auto P = y2p.generatePuzzleByFile("universe1.yaml");
  PPG::Vec<PPG::GraphNode*> rootNode = P->getGraphRepresentation();



  Room r1{console};

  // Game loop.
  while (true) {
    // Update
    r1.update();

    // Rendering.
    TCOD_console_clear(console.get());
    r1.draw();
    context->present(*console);

    // Handle input.
    SDL_Event event;
    SDL_WaitEvent(nullptr);
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          std::exit(EXIT_SUCCESS);
          break;
      }
    }
  }
  return 0;
}
