#pragma once

#include <iostream>

#include "game_object.h"
#include "world.h"

class Block : public GameObject {
public:
  static constexpr float width{80};

  Block(World & world, float x, float y) : GameObject{world, x, y} {

  }

  void update(float dt) override {

  }

  void render(sf::RenderWindow & window) override {
    shape.setPosition(x, y);
    window.draw(shape);
  }

  sf::FloatRect getBBox() const override {
    return shape.getGlobalBounds();
  }

  bool collidesWith(GameObject & obj) override {
    shouldRemove = GameObject::collidesWith(obj);
    return shouldRemove;
  }

private:
  sf::RectangleShape shape{{80, 40}};
};
