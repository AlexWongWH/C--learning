#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Observer {
public:
  virtual ~Observer() {}

  // try make this perfect forwarding function
  virtual void OnNotify() = 0; // pure virtual function
  virtual const std::string &GetSysName() const = 0;
};

class AudioObserver : public Observer {
public:
  AudioObserver() = default;

  const std::string my_str_{"From AudioObserver observer"};
  const std::string sys_name{"Audio Observer"};

public:
  // implement own function here
  virtual void OnNotify() override { std::cout << my_str_ << std::endl; }
  virtual const std::string &GetSysName() const override { return sys_name; }
};

class CollisionObserver : public Observer {
public:
  CollisionObserver() = default;

  const std::string my_str_{"From CollisionObserver"};
  const std::string sys_name{"Collision Observer"};
  virtual const std::string &GetSysName() const override { return sys_name; }

  virtual void OnNotify() { std::cout << my_str_ << std::endl; }
};

class Publisher {
public:
  void AddObserver(std::unique_ptr<Observer> &obs) {
    list_of_observer_.emplace_back(std::move(obs));
  }

  void RemoveObserver(const std::string &str) {
    std::cout << "Calling remove observer\n";
    std::cout << "List of observer Size: " << list_of_observer_.size()
              << std::endl;

    // use std find and remove...
    auto iter = std::find_if(list_of_observer_.begin(), list_of_observer_.end(),
                             [&str](const std::unique_ptr<Observer> &p) {
                               std::cout << "Found, removing observer: " << str
                                         << std::endl;
                               return p->GetSysName() == str;
                             });
    if (iter != list_of_observer_.end()) {
      // iter->release();
      list_of_observer_.erase(iter);
    }
  }

  void Notify() {
    for (auto &obs : list_of_observer_) {
      obs->OnNotify();
    }
  }

private:
  std::vector<std::unique_ptr<Observer>> list_of_observer_;
};

class ActorSystemPublisher : public Publisher {
public:
private:
};

int main() {
  //
  ActorSystemPublisher asp{};

  std::unique_ptr<Observer> audiobaseptr = std::make_unique<AudioObserver>();
  std::unique_ptr<Observer> collisionbaseptr =
      std::make_unique<CollisionObserver>();

  asp.AddObserver(audiobaseptr);
  asp.AddObserver(collisionbaseptr);

  asp.Notify();

  asp.RemoveObserver("Collision Observer");

  asp.Notify();

  return 0;
}
