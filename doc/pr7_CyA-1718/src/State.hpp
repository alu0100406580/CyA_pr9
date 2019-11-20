#pragma once

#include <set>
#include "Transition.hpp"

using namespace std;

class State {

    private:
        unsigned int n_;            //número de estado
        unsigned int type_;         //1 aceptación, 0 no aceptación
        unsigned int ntransitions_; //nº de transiciones
        set<Transition> transitions_; //transiciones

    public:
    
        /**
        * Contructor por defecto clase State
        */
        State();
        
        /**
        * Constructor de copia clase State
        * @param State
        */
        State(const State&);
        
        /**
        * Destructor clase State
        */
        ~State();

        /**
        * Obtener número de estado
        * @return n de estado
        */
        const unsigned int& getn();
        
        /**
        * Obtener tipo de estado 1 aceptación, 0 no aceptación
        * @return tipo de estado
        */
        const unsigned int& gettype() ;
        
        /**
        * Obtener nº de transiciones
        * @return nº de transiciones del estado
        */
        const unsigned int& getntransitions();
        
        /**
        * Obtener las transciones  
        * @return conjunto de transciones
        */
        const set<Transition>& gettransitions();

        /**
        * Establecer número de estados
        * @param nº de estados
        */
        void setn(unsigned int&);
        
        /**
        * Establecer tipo de estado
        * @param tipo de estado
        */
        void settype(unsigned int&);
        
        /**
        * Establecer nº de transiciones
        * @param nº de transiciones
        */
        void setntransitions(unsigned int&);
        
        /**
        * Insertar transición
        * @param Transicion
        */
        void inserttransitions(Transition&);

        /**
        * Estado de muerte
        * @return true estado de muerte
        */
        bool deadstate();//estado de muerte o no
        
        
        /**
        * Sobrecarga operador de comparación ==
        */
		int operator==(const State &rhs) const;
		
		/**
        * Sobrecarga operador de comparación <
        */
		int operator<(const State &rhs) const;

        
        /**
        * Sobrecarga operador de salida
        */
        friend ostream& operator << (ostream&, const State&);
};
