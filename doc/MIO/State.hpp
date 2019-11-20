#ifndef State_H
#define State_H

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "Transition.hpp"


class State {

  private:
    std::string id_;
    bool acceptation_ = false;
    bool initialstateS_ = false;
    bool DeathState_ = false;
    bool ImportantState_ = false;
    std::set<Transition> trans_;

  public:

    State();
    ~State();
    State(const State& p);
    State( std::string );
    std::string get_id();
    std::set<Transition> get_transitions();
    bool get_acceptation();
    bool get_initial();
    void set_id(std::string);        
    void set_acceptation();
    void set_transitions(Transition transi1);
    void set_initial();
    int size();

    int operator==(const State &pp) const;
    int operator<(const State &pp) const;

    friend std::ostream& operator << (std::ostream&, const State&);
};

#endif