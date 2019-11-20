#pragma once

#include <iostream>


using namespace std;

class Transition {

    private:
        char symbol_;           //símbolo entrante
        unsigned int tostate_;  //estado al que se transita

    public:
    
        /**
        * Contructor por defecto clase Transition
        */
        Transition();
        
        /**
        * Contructor de clase State
        * @param símbolo
        * @param estado al que transita
        */
        Transition(char, unsigned int);
        
        /**
        * Constructor de copia
        * @param transcición
        */
        Transition(const Transition& t);

        /**
        * Obtener símbolo
        * @return símbolo
        */
        char getsymbol() const;
        
        /**
        * Obtener nº de estado al que se transita
        * @return nº de estado
        */
        unsigned int gettostate() const;

        /**
        * Establecer símbolo
        * @param símbolo
        */
        void setsymbol(char&);
        
        /**
        * Establecer nº de estado al que se transita
        * @param nº de estado
        */
        void settostate(int&);
        
        /**
        * Sobrecarga operador de asignación
        */
        Transition& operator=(const Transition &rhs);
        
        /**
        * Sobrecarga operador de comparación ==
        */
		int operator==(const Transition &rhs) const;
		
		/**
        * Sobrecarga operador de comparación <
        */
		int operator<(const Transition &rhs) const;

        /**
        * Sobrecarga operador de salida
        */
        friend ostream& operator << (ostream&, const Transition&);
};
