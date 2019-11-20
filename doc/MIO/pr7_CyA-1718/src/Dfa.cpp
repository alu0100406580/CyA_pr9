#include "Dfa.hpp"


Dfa::Dfa() {}

Dfa::~Dfa() {
  q_.clear();
  nstates_ = 0;
  s_ = 0;
}

bool Dfa::read_dfa(const string& path) {
    string line;
    ifstream file(path);

    if(file.is_open()) {
        unsigned int nline = 0;

        while(getline(file, line)) {
            nline++;

            switch(nline) {
                case 1: //línea 1 número de estados
                    istringstream(line) >> this->nstates_;
                    break;
                case 2://línea 2 estado inicial
                    istringstream(line) >> this->s_;
                    break;
                default://línea 3 en adelante, transiciones
                    istringstream iss(line);
                    string token;
                    unsigned int ntoken = 0;
                    set<Transition> transitions;

                    int tfull = 0;
                    State s;

                    while(iss >> token) {//recorrer línea

                        Transition t;
                        unsigned int n;
                        char symbol; unsigned int tostate;
                        ntoken++;
                        switch(ntoken) {
                            case 1: //número de estado
                                unsigned int n;
                                istringstream(token) >> n;
                                s.setn(n);
                                break;
                            case 2: //estado de aceptación o no
                                unsigned int aceptation;
                                istringstream(token) >> aceptation;
                                s.settype(aceptation);
                                break;
                            case 3: //cantidad de transiciones
                                unsigned int ntransitions;
                                istringstream(token) >> ntransitions;
                                s.setntransitions(ntransitions);
                                break;
                            default://transiciones
                                if(ntoken%2 == 0) {//simbolo
                                  tfull++;
                                  istringstream(token) >> symbol;
                                }
                                else {//estado
                                  tfull++;
                                  istringstream(token) >> tostate;
                                }

                                break;

                        }//end switch(ntoken)

                        if (tfull == 2) {//transicion completa
                            t = Transition(symbol,tostate);
                            s.inserttransitions(t);
                            tfull = 0;
                        }



                    }//end while

                    this->q_.insert(s);
                    break;
            }//end switch(nlines)*/
        }//while(getline(file, line))

    }//end if(file.is_open())

    else {
        cout << "Error: no se puede leer el fichero" << endl;
        return false;
    }
    return true;
}


const set<State>& Dfa::getallstates() {
    return this->q_;
}



ostream& operator << (ostream& os, const Dfa& dfa) {

    os << dfa.nstates_ << endl;
    os << dfa.s_ << endl;

    for(auto q: dfa.q_) {
        os << q << endl;

    }
    os << endl << endl;
    return os;
}
