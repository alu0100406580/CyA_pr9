/*****************************************************************

                    DARIO AFONSO RODRIGUEZ

CyA | Práctica #07: Gramática regular a partir de un DFA

*****************************************************************/

/**
 * @file   Main.cpp
 * @Author Darío Afonso Rodríguez (alu0100406580@ull.edu.es)
 * @date   Noviembre, 2017
 * @brief  Fichero que contiene la función main del programa
 * 
 */

#include "Dfa.hpp"
#include "Grammar.hpp"

/*
*   Función principal
*/
int main(int argc, char *argv[]) { //

    
    if (argc == 3) {
        Dfa dfa;
        dfa.read_dfa(argv[1]);
        
        Grammar grammar(dfa);
        grammar.to_file(argv[2]);
        
    }
    else {
        cout << "El programa necesita dos parámetros, nombre_fichero_dfa nombre_ficher_gramatica" << endl;
    }
    
    return 0;
}
