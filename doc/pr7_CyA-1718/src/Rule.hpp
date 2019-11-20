#pragma once

#include <vector>
#include "Production.hpp"


class Rule {
    
    private:
        vector<Production> productions_;//vector de produciones
    
    public:
        /**
        * Contructor por defecto clase Rule
        */
        Rule();
    
        /**
        * Obtener vector de producciones
        * @return vector de producciones
        */
        vector<Production> getproductions() const;
        
        /**
        * Insertar producción en el vector de producciones
        * @param producción
        */
        void push_back(Production&);
    
    /**
    * Sobrecarga operador de salida
    */
    friend ostream& operator << (ostream& os, const Rule& rule);
};