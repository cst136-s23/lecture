#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class World;

class GameObject {
public:
  GameObject(World & w, float x = 0, float y = 0);
  virtual ~GameObject() = default;
  virtual void update(float dt);
  virtual void render(sf::RenderWindow & window);
  virtual sf::FloatRect getBBox() const = 0;
  virtual bool collidesWith(GameObject & obj) {
    return getBBox().intersects(obj.getBBox());
  }

protected:
  World & world;
  float x, y;
  float vx, vy;

public:
  bool shouldRemove{};
};
