#ifndef Grammar_H
#define Grammar_H

#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Rule.hpp"


using namespace std;

class Grammar {
    
  private:
    set<char> nt_;//coleccion de símbolos no terminales
    char s_;//no terminal llamado símbolo inicial o de arranque
    vector<Rule> productions_;  //colección de reglas de sustitución denominadas producciones
    set<char> alphabet_;//alfabeto
    vector<char> labels_ = {'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };//etiquetas de estado
    int endingSymbols_; //Estados de aceptación (contienen la cadena vacía)
    
  public:
    Grammar();
    Grammar( char const *filein, char const *fileout );
    void Read( char const * );
    void to_file( string );//exportar gramática a fichero
        
    friend ostream& operator << (ostream& os, const Grammar& g);
};

#endif