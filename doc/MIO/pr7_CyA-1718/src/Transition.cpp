#include "Transition.hpp"

Transition::Transition() {}

Transition::Transition(char symbol, unsigned int tostate) {
    symbol_ = symbol;
    tostate_ = tostate;
}


Transition::Transition(const Transition& t) {
    // this->symbol_ = t.symbol_;
    // this->tostate_ = t.tostate_;
    *this = t;
}




char Transition::getsymbol() const {
    return symbol_;
}

unsigned int Transition::gettostate() const {
    return tostate_;
}

void Transition::setsymbol(char& symbol) {
    symbol_ = symbol;
}

void Transition::settostate(int& tostate) {
    tostate_ = tostate;
}


Transition& Transition::operator=(const Transition &rhs)
{
   symbol_ = rhs.symbol_;
   tostate_ = rhs.tostate_;
   return *this;
}

int Transition::operator==(const Transition &rhs) const
{
   if( symbol_ != rhs.symbol_) return 0;
   if( tostate_ != rhs.tostate_) return 0;
   return 1;
}


int Transition::operator<(const Transition &rhs) const
{
   if( symbol_ == rhs.symbol_ && tostate_ < rhs.tostate_) return 1;
   if( symbol_ < rhs.symbol_ ) return 1;
   return 0;
}


ostream& operator << (ostream& os, const Transition& transition) {
    os << transition.symbol_ << " " << transition.tostate_ << " ";
    return os;
}
