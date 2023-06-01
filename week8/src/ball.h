#pragma once

#include <iostream>

#include "game_object.h"
#include "world.h"

class Ball : public GameObject {
public:
  Ball(World & world, float x, float y) : GameObject{world, x, y} {
    vx = 20;
    vy = 60;
  }

  void update(float dt) override {
    for (auto it = world.begin(); it != world.end(); ++it) {
      auto & obj = *it;
      if (&obj == this) {
        continue;
      }

      if (obj.collidesWith(*this)) {
        vy *= -1;
      }
    }

    x += vx*dt;
    y += vy*dt;
  }

  void render(sf::RenderWindow & window) override {
    shape.setPosition(x, y);
    window.draw(shape);
  }

  sf::FloatRect getBBox() const override {
    return shape.getGlobalBounds();
  }

private:
  sf::RectangleShape shape{{15, 15}};
};
