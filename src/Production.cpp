#include "Production.hpp"

Production::Production() {}

char Production::get_state() const{
  return state_;
}

std::vector< std::string > Production::get_productions() const{
  return productions_;
}

void Production::set_state( char& state ) {
  state_ = state;
}

void Production::set_productions( std::vector< std::string > productions ) {
  productions_ = productions;
}

std::ostream& operator << ( std::ostream& os, const Production& Production) {
  
  for (int i = 0; i < Production.get_productions().size(); i++) {
    os << Production.get_productions()[i];
  }
  return os;
}