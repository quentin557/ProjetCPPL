#ifndef OBERSVERPATTERN_H
#define OBERSVERPATTERN_H
#include <vector>
class Observer;
class Subject {
    // 1. "independent" functionality
    std::vector < Observer * > views; // 3. Coupled only to "interface"
  public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void notify();
};

class Observer {
    // 2. "dependent" functionality
  public:
    Observer(Subject *mod) {
        // 4. Observers register themselves with the Subject
        model = mod;
        model->attach(this);
    }
    virtual void update() = 0;
  protected:
    Subject *model;
    Subject *getSubject() {
        return model;
    }
};

#endif // OBERSVERPATTERN_H
