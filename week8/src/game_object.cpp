#include "game_object.h"
#include "world.h"

GameObject::GameObject(World & w, float x, float y) : world{w}, x{x}, y{y} {

}

void GameObject::update(float dt) {

}

void GameObject::render(sf::RenderWindow & window) {
  sf::CircleShape shape{15};
  shape.setFillColor(sf::Color::Blue);
  shape.setPosition(x, y);
  window.draw(shape);
}
