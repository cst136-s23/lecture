#include <iostream>
#include <vector>

struct Vector2f {
  float x, y;

  Vector2f operator+(const Vector2f & other) {
    x += other.x;
    y += other.y;
  }

  Vector2f operator-(const Vector2f & other) {
    x -= other.x;
    y -= other.y;
  }
};

class World;

class GameObject {
public:
  bool remove{};
  Vector2f bbox;
  Vector2f position;
  Vector2f velocity;
  float rotation;
  float scale;
  World & world;

  GameObject(World & world) : world{world} {}

  virtual void update() {}
  virtual void render() {}

  virtual ~GameObject() {}

  virtual bool collides(const GameObject & other) {
    // bbox here
  }
};

class Alien : public GameObject {
public:
  void update() {
    world.forEach([&](GameObject * object) {
      if (object != this) {
        if (object->intersects(*this)) {
          // set some stuff
        }

      }
    });

    // shoot some bullets
  }

  void render() {}
};

class Bullet : public GameObject {
public:
  void update() {
    
  }

  void render() {}
};

class Player : public GameObject {
public:
  void update() {
    static int timer = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      // spawn bullet (creating it)
      // add it to the world
    }
  }

  void render() {}
};

class World {
public:
  std::vector<std::unique_ptr<GameObject> > objects;

  World() {
    //objects.push_back(alien);
    //objects.push_back(alien);
    //objects.push_back(alien);
  }

  void render() {
  }

  void update() {
  }

  void loop() {
  }
};

int main() {
  World world;
  world.loop();
}
