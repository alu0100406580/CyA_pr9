#pragma once

#include "Rule.hpp"
#include "Dfa.hpp"

using namespace std;

class Grammar {
    
    private:
        set<char> nt_;//coleccion de símbolos no terminales
        //char s_;//no terminal llamado símbolo inicial o de arranque
        vector<Rule> productions_;  //colección de reglas de sustitución denominadas producciones
        set<char> alphabet_;//alfabeto
        vector<char> labels_ = {'S','A','B','C','D','E','F','G','H','I','J','K','L'};//etiquetas de estado
        int endingSymbols_; //Estados de aceptación (contienen la cadena vacía)
    
    public:
        /**
        * Contructor por defecto clase State
        */
        Grammar();
        
        /**
        * Contructor por clase State para crear Gramática a partir de un DFA
        * @param dfa
        */
        Grammar(Dfa&);
        
        /**
        * Definir reglas y producciones a partir del dfa
        * @param dfa
        */
        void define_productions(Dfa&);//definir producciones
        
        /**
        * Exportar DFA a fichero
        * @param nombre fichero
        */
        void to_file(string);//exportar gramática a fichero
        
    /**
    * Sobrecarga operador de salida
    */
    friend ostream& operator << (ostream& os, const Grammar& g);
};