#ifndef Rule_H
#define Rule_H

#include <vector>
#include "Production.hpp"


class Rule {
    
  private:
    std::vector< Production > productions_;//vector de produciones
    
  public:
    Rule();
    std::vector< Production > getproductions() const;
    void push_back( Production& );
    
    friend std::ostream& operator << ( std::ostream& os, const Rule& rule );
};

#endif