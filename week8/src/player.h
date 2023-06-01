#pragma once

#include <iostream>

#include "game_object.h"
#include "world.h"

class Player : public GameObject {
public:
  // we reuse the initialization code in the superclass
  // and then override/add anything we want
  Player(World & world, float x, float y) : GameObject{world, x, y} {

  }

  // handle any physics, keys/input here
  void update(float dt) override {
    static float timer{}; // use this to throttle our bullet (what happens if you don't?? try it!)

    // update *our* position, then sync it up with the drawable (shape/sprite) in our render
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      x -= 100*dt;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      x += 100*dt;
    }
  }

  void render(sf::RenderWindow & window) override {
    shape.setPosition(x, y);
    window.draw(shape);
  }

  sf::FloatRect getBBox() const override {
    return shape.getGlobalBounds();
  }

private:
  sf::RectangleShape shape{{100, 20}};
  // Everything will have a Sprite... maybe have that on the GameObject instead?
};
