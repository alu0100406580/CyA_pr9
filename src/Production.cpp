#include "Production.hpp"

Production::Production() {}

char Production::get_state() const{
  return state_;
}

std::string Production::get_production() const{
  return production_;
}

void Production::set_state( char& state ) {
  state_ = state;
}

void Production::set_production( std::string& production ) {
  production_.clear();
  production_ = production;
}

std::ostream& operator << ( std::ostream& os, const Production& Production) {
  
  os << Production.get_state() << " -> " << Production.get_production();
  return os;
}