#include <iostream>
#include <vector>

#define MAX_OBSERVERS 1024

enum Event {
  EVENT_ENTITY_FELL = 0,
};

// Nosy class, interested when there are object does something interesting

class Entity {
public:
  bool isHero() const { return class_id == 0; }

  std::string name_{};
  int class_id{};
};

// Subscribe function overload
class Observer {
public:
  virtual ~Observer() {}
  // parameters for OnNotify is arbitrary
  virtual void onNotify(const Entity &entity, Event event) = 0;
};

// Any class that implements this becomes observer
// hard coded
class Acheivements : public Observer {
  bool herofalling_{true};

  void unlock(Acheivements ach) {}

public:
  virtual void OnNotify(const Entity &entity, Event event) {
    switch (event) {
    case EVENT_ENTITY_FELL:
      if (entity.isHero() && herofalling_) {
        // unlock(acheivement)
      }

      break;

    default:
      break;
    }
  }
};

// The subject [Publisher]
// 1. Holds list of Observers
// 2. Sending notifications
class Subjects {
public:
  void addObserver(Observer &obs) { observers_.emplace_back(obs); }
  void removeObserver(Observer &obs) {}

protected:
  // calls the virtual function of the entity with the relevant event
  void notify(const Entity &entity, Event event) {
    for (auto &obs : observers_) {
      obs.onNotify(entity, event);
    }
  }

private:
  std::vector<Observer> observers_; // holds the list of observers
};

// makes physics class a publisher
class Physics : public Subjects {
public:
  void updateEntity(Entity &ent) {}
};

int main() {

  // physics.entityFell().addObserver(this);

  return 0;
}
