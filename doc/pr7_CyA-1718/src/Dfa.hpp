#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include "State.hpp"


using namespace std;

class Dfa {

  private:
    unsigned int nstates_;//número de estados
    set<State> q_;	    //colección de estados
    unsigned int s_;		  //estado inicial
    State current_;        //estado actual
    unsigned int sizealphabet_ = 2;

  public:
  
    /**
    * Constructor por defecto de la clase Dfa
    */
    Dfa();
    
    /**
    * Destructor de la clase Dfa
    */
    ~Dfa();
    
    /**
    * Leer dfa de un fichero
    * @param nombre fichero
    * @return fichero leído o no
    */
    bool read_dfa(const string&);
    
    /**
    * Obtener un vector con todos los estados del dfa
    * @return vector de estados
    */
    const set<State>& getallstates();

    /**
    * Sobrecarga operador de salida
    */
    friend ostream& operator << (ostream& os, const Dfa& dfa);

};
