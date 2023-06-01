#include "world.h"
#include "ball.h"
#include "block.h"
#include "player.h"
#include "vector.h"
#include <iostream>
#include <vector>

enum GameState {
  BEGIN = 0,
  RUNNING,
  END,
};

int main() {
  World world;

  auto & ball = world.addObject<Ball>(100, 200);
  auto & player = world.addObject<Player>(world.width / 2, 0.85*world.height);

  for (size_t i{}; i < world.width / (1.2 * Block::width); ++i) {
    auto & block = world.addObject<Block>(i * Block::width * 1.2, 0);
  }

  world.run();
}
