#ifndef Production_H
#define Production_H
#include <iostream>
#include <vector>
#include <string>


class Production {
  private:
    char state_= '\0';
    std::string production_;
    
  public:
    /**
     * @brief Constructor por defecto de producciones
     * 
     */
    Production();
    /**
     * @brief Devuelve el estado de la producción
     * 
     * @return char 
     */
    char get_state() const;
    /**
     * @brief Devuelve la producción
     * 
     * @return std::string 
     */
    std::string get_production( void ) const;
    /**
     * @brief Devuelve el estado
     * 
     */
    void set_state( char& );
    /**
     * @brief Escribe la producción
     * 
     */
    void set_production( std::string& );
    /**
     * @brief Sobrecarga operador <<
     * 
     * @param os 
     * @param p Producción
     * @return std::ostream& 
     */
    friend std::ostream& operator << ( std::ostream& os, const Production& p);
};

#endif