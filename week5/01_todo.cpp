#include <iostream>
#include <string>
#include <vector>
#include <exception>

// PITA = Prefer Initialization To Assignment

class Todo {
public:
  std::string text;
  bool completed{true};

  Todo(std::string todoText = "", bool isCompleted = false) : text{todoText}, completed{isCompleted} {}

  void setCompleted(bool isCompleted) { completed = isCompleted; }
};

class TodoItems {
public:
  void addTodo(std::string text, bool completed = false) {
    items.push_back(Todo{text, completed});
  }

  // complete
  void completeAt(size_t index) {
    // guard pattern
    if (index >= items.size()) {
      throw std::exception{};
    }

    items[index].setCompleted(true);
  }

  void complete(size_t index) noexcept {
    items[index].setCompleted(true);
  }

private:
  std::vector<Todo> items;
};

int main() {
  Todo todo{};

  TodoItems items{};
  items.addTodo("pass my exam");
  items.addTodo("pass my exam", true);

  Todo * todo{};

  try {
    //todo = items.getAt(10);
  } catch (std::exception & e) {

  }
}
