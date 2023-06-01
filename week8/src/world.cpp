#include "world.h"

World::World() {
  window.setVerticalSyncEnabled(true);
}

World::~World() {

}

/**
  * The main game loop. Runs until the window is closed.
  * 
  * For more info, see the following links:
  * - https://subscription.packtpub.com/book/game+development/9781849696845/1/ch01lvl1sec11/game-loops-and-frames
  * - https://gafferongames.com/post/fix_your_timestep/
  */
void World::run() {
  sf::Clock clock;
  sf::Time t{sf::Time::Zero}; // time
  sf::Time dt{sf::seconds(1.0f / 60.0f)}; // delta time (fixed to 60fps)

  while (window.isOpen()) {
    processEvents();
    t += clock.restart();

    while (t > dt) {
      t -= dt;
      processEvents();
      update(dt.asSeconds());
    }

    objects.removeIf([](std::unique_ptr<GameObject> & object) {
      return object->shouldRemove;
    });

    render();
  }
}

void World::forEach(std::function<void(GameObject &)> fn) {
  // I've typed the type here so you can see it (gross, right?)
  // it's one of the reasons "auto" was invented
  objects.forEach([&](std::unique_ptr<GameObject> & object) {
    // pass the underlying object by reference (so others don't have to use unique_ptrs)
    // that way it's of type: GameObject &
    fn(*object);
  });
}

// you can handle global type events in here (e.g. settings or UI type things)
// for movement, see player.h for an example
void World::processEvents() {
  for (sf::Event event; window.pollEvent(event);) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

// this logic should not change
void World::render() {
  // always clear
  window.clear();

  // draw whatever
  objects.forEach([&](std::unique_ptr<GameObject> & object) {
    object->render(window); // notice it's a pointer syntax with std::unique_ptr
  });

  // swap the buffer
  window.display();
}

// this logic should not change
void World::update(float dt) {
  objects.forEach([&](std::unique_ptr<GameObject> & object) {
    object->update(dt);
  });
}
