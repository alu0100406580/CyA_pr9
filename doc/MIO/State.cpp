#include "State.hpp"


State::State() {}

State::~State() {}

State::State( const State& p ) {
    *this = p;
}

State::State( std::string a ) {
  id_ = a;
}

std::string State::get_id() {
  return id_;
}

bool State::get_acceptation() {
  return acceptation_;
}

bool State::get_initial() {
  return initialstateS_;
}

std::set<Transition> State::get_transitions() {
  return trans_;
}

void State::set_id( std::string id ){
  id_ = id;
}

void State::set_acceptation() {
  acceptation_ = true;
}

void State::set_initial() {
  initialstateS_ = true;
}

void State::set_transitions(Transition transi1) {
  trans_.insert(transi1);
}

int State::size() {
  return trans_.size();
}

int State::operator==( const State &pp ) const {

  if( this->id_ != pp.id_ ) return 0;
  return 1;
}

int State::operator<( const State &pp ) const {

  if( this->id_ == pp.id_) return 1;
  if( this->id_ < pp.id_) return 1;
  return 0;
}

std::ostream& operator << ( std::ostream& os, const State& state ) {

  os << state.id_ << " " << state.initialstateS_ << " " << state.acceptation_ << " " << state.trans_.size() << " " ;
  for (auto t: state.trans_) {
    os << t;
  }
  return os;
}
