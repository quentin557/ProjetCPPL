/*!
 * \file observerpattern.hpp
 *
 * \brief the observer/subject design pattern.
 *
 * \author 39766 & 42586
 */

#ifndef OBERSVERPATTERN_H
#define OBERSVERPATTERN_H
#include <vector>
class Observer;
class Subject {
    std::vector < Observer * > views;
  public:
    /*!
     * \brief attaches an Observer to the subject.
     *
     * \param obs the Observer attached.
     *
     */
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    /*!
     * \brief notifies all the attached observers to update.
     */
    void notify();
};

class Observer {
  public:
    /*!
     * \brief creates a new Observer wich must observe a subject.
     *
     * \param mod the subject being observed.
     *
     */
    Observer(Subject *mod) {
        model = mod;
        model->attach(this);
    }
    /*!
     * \brief virtual function which each observer should reimplement to
     * suit its needs when a change happens in subject.
     */
    virtual void update() = 0;
  protected:
    Subject *model;
    Subject *getSubject() {
        return model;
    }
};

#endif // OBERSVERPATTERN_H
