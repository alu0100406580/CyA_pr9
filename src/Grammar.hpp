#ifndef Grammar_H
#define Grammar_H

#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
//#include "Rule.hpp"
#include "Production.hpp"


using namespace std;

/**
 * @brief 
 * 
 */
class Grammar {
     
  private:
    set< char > nt_;                    //coleccion de símbolos no terminales
    char s_;                            //no terminal llamado símbolo inicial o de arranque
    vector< Production > productions_;  //colección de reglas de sustitución denominadas producciones
    set< char > alphabet_;              //alfabeto
    vector< char > labels_ = {'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    int endingSymbols_;                 //Estados de aceptación (contienen la cadena vacía)
    
  public:
    /**
     * @brief Constructor por defecto
     * 
     */
    Grammar();
    /**
     * @brief Constructor con el que inicializa el programa
     * 
     * @param filein 
     * @param fileout 
     */
    Grammar( char const *filein, char const *fileout );
    /**
     * @brief Constructor de Copia
     * 
     * @param g 
     */
    Grammar( const Grammar &g );
    /**
     * @brief Destructor por defecto
     * 
     */
    ~Grammar();
    void Read( char const * );
    /**
     * @brief Función que convierte una Gramática a Forma Normal de Chomsky
     * 
     */
    void convertG2CNF( std::string );
    /**
     * @brief Exportar gramática a fichero
     * 
     */
    void to_file( std::string );
    
    /**
     * @brief Obtiene los no terminales
     * 
     * @return set< char > 
     */
    set< char > getnt_( void ) const;
    /**
     * @brief Devuelve el estado de arranque
     * 
     * @return char 
     */
    char gets_( void ) const;
    /**
     * @brief devuelve el vector de Producciones
     * 
     * @return vector< Production > 
     */
    vector< Production > getproductions_( void ) const;
    /**
     * @brief nos devuelve el alfabeto
     * 
     * @return set< char > 
     */
    set< char > getalphabet_( void ) const;
    /**
     * @brief nos devuelve el numero de estados Terminales (Para convertir a DFA/NFA si hubiera sido el caso)
     * 
     * @return int 
     */
    int getendingSymbols_( void ) const;
    /**
     * @brief Sobrecarga del operador <<
     * 
     * @param os Flujo
     * @param g Gramática
     * @return ostream& 
     */
    friend ostream& operator << (ostream& os, const Grammar& g);
};

#endif