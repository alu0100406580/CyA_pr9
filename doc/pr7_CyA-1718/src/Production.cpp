#include "Production.hpp"

Production::Production() {}

char Production::get_state() const{
    return state_;
}

char Production::get_terminal() const{
    return terminal_;
}

char Production::get_nt() const{
    return nt_;
}


void Production::set_state(char& state) {
    state_ = state;
}

void Production::set_terminal(char& terminal) {
    terminal_ = terminal;
}

void Production::set_nt(char& nt) {
    nt_ = nt;
}


ostream& operator << (ostream& os, const Production& production) {
    os << production.terminal_ << production.nt_;
    return os;
}