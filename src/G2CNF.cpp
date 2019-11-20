/******************************************************************************
* Asignatura: Computabilidad y Algoritmia (CyA)
* Curso: 2º 
* Práctica #09: Forma Normal de Chomsky de una Gramática Independiente del Contexto
* Autor: Darío Afonso Rodríguez
* Correo: alu0100406580@ull.edu.es
* Fecha: 21/11/2019
* Archivo main.cpp: programa cliente. Contiene la función main del proyecto
                     que usa la clase ER2tree que realizan el trabajo de leer el
                     fichero de entrada para trabajar creando la gramática para 
                     luego generar un NFA
                    Tiene también la función Help() para dar ayuda al cliente al
                     saber como se ejecutará el programa si lo inicializa mal.
* Referencias: 
*                    Enunciado de la práctica:
*                    doc/CYA_1920_Practica_9.pdf
*                    Bibliografia:
******************************************************************************/


#include <iostream>
#include <string>
#include <iomanip>
#include "Grammar.hpp"

void Help() {
  std::setw( 70 );
  std::cout << "Este es un programa que lee un fichero de texto en el que figura" << std::endl; 
  std::cout << "La especificación de una Gramática Independiente del Contexto y genera" << std::endl;
  std::cout << "Un fichero de texto en el que se especifique una gramática equivalente " << std::endl;
  std::cout << "(L(G in ) = L(G out )) a la de entrada, escrita en Forma Normal de Chomsky." << std::endl;
  std::cout << "Modo de empleo: './G2CNF [input.gra] [output.gra]'" << std::endl;
}

int main(int argc, char const *argv[]) {

  if (argc == 2 && ( argv[1] == (std::string)"--help" ||  argv[1] == (std::string)"-h" ) )
    Help();

  else if (argc == 3)
    Grammar G1 ( argv[1], argv[2] );

  else{
    std::cout << "Modo de empleo: './G2CNF [input.gra] [output.nfa]'" << std::endl;
    std::cout << "Pruebe 'G2CNF --help ó -h' para más información." << std::endl;
  }
  return 0;
}