#include "Rule.hpp"

Rule::Rule() {}

std::vector<Production> Rule::getproductions() const {
  return productions_;
}

void Rule::push_back(Production& p) {
  productions_.push_back(p);
}

std::ostream& operator << ( std::ostream& os, const Rule& rule) {
    
  for (int i=0; i<rule.productions_.size(); i++) {  
    if (i>0) {  
      if(rule.productions_[i-1].get_state() == rule.productions_[i].get_state()) {
        os << " | " << rule.productions_[i];
      }
      else {
        os << std::endl << rule.productions_[i].get_state() << " -> " << rule.productions_[i];
      }
    }

    else {
      os << rule.productions_[i].get_state() << " -> " << rule.productions_[i];
    }
  }
  os << std::endl;
  return os;
}