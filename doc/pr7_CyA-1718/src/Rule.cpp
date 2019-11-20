#include "Rule.hpp"

Rule::Rule() {}

vector<Production> Rule::getproductions() const {
    return productions_;
}

void Rule::push_back(Production& p) {
    productions_.push_back(p);
}

ostream& operator << (ostream& os, const Rule& rule) {
    
    for (int i=0; i<rule.productions_.size(); i++) {
        
        if (i>0) {
            
            if(rule.productions_[i-1].get_state() == rule.productions_[i].get_state()) {
                os << " | " << rule.productions_[i];
            }
            else {
                os << endl << rule.productions_[i].get_state() << " -> " << rule.productions_[i];
            }
        }
        else {
            os << rule.productions_[i].get_state() << " -> " << rule.productions_[i];
        }
    }
    os << endl;
    return os;
}