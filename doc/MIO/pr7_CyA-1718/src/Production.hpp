#pragma once
#include <iostream>
using namespace std;

class Production {
    private:
        char state_;      //estado
        char terminal_;   //símbolo terminal
        char nt_;         //símbolo no terminal;
    
    public:
        /**
        * Contructor por defecto clase State
        */
        Production();
        
        /**
        * Obtener etiqueta del estado
        * @return etiqueta del estado
        */
        char get_state() const;
        
        /**
        * Obtener símbolo terminal
        * @return símbolo terminal
        */
        char get_terminal() const;
        
        /**
        * Obtener símbolo no terminal
        * @return símbolo no terminal
        */
        char get_nt() const;
        
        /**
        * Establecer etiqueta del estado
        * @param etiqueta del estado
        */
        void set_state(char&);
        
        /**
        * Establecer símbolo terminal
        * @param símbolo terminal
        */
        void set_terminal(char&);
        
        /**
        * Establecer símbolo no terminal
        * @param símbolo no terminal
        */
        void set_nt(char&);
    
    /**
    * Sobrecarga operador de salida
    */
    friend ostream& operator << (ostream& os, const Production& p);
};