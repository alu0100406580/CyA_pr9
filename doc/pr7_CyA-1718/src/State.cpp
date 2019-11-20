#include "State.hpp"

State::State() {}

State::State(const State& state) {
//   n_= state.n_;
//   type_ = state.type_;
//   ntransitions_ = state.ntransitions_;
//   transitions_ = state.transitions_;
    *this = state;
}

State::~State() {
    transitions_.clear();
}

const unsigned int& State::getn() {
    return this->n_;
}

const unsigned int& State::gettype()  {
    return this->type_;
}

const unsigned int& State::getntransitions() {
    return this->ntransitions_;
}

const set<Transition>& State::gettransitions() {
    return this->transitions_;
}

void State::setn(unsigned int& n) {
    this->n_ = n;
}

void State::settype(unsigned int& type) {
    this->type_ = type;
}

void State::setntransitions(unsigned int& ntransitions) {
    this->ntransitions_ = ntransitions;
}

void State::inserttransitions(Transition& t) {
    this->transitions_.insert(t);
}

bool State::deadstate() {
    if (transitions_.size() == 0)
      return true;

    for(int i=0; i<this->transitions_.size(); i++) {
        set<Transition>::iterator it = transitions_.begin();
        advance(it, i);
        Transition x = *it;

        if(x.gettostate() != n_ || type_ == 1 )
            return false;

        // if(ntransitions_ == 0)
        //     return true;
    }
    return true;
}





int State::operator==(const State &rhs) const
{
   if( this->n_ != rhs.n_) return 0;
   
   return 1;
}


int State::operator<(const State &rhs) const
{
   if( this->n_ == rhs.n_) return 1;
   if( this->n_ < rhs.n_ ) return 1;
   return 0;
}


ostream& operator << (ostream& os, const State& state) {

    os << state.n_ << " " << state.type_ << " " << state.transitions_.size() << " ";

    for(auto t: state.transitions_) {
        os << t;
    }

    return os;
}
