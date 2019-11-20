#pragma once
#include <iostream>
#include <vector>
#include <string>


class Production {
  private:
    char state_= '\0';      //estado
    std::vector< std::string > productions_;
    
  public:
    Production();
    char get_state() const;
    std::vector< std::string > get_productions( void ) const;
    void set_state( char& );
    void set_productions( std::vector< std::string > );

  friend std::ostream& operator << ( std::ostream& os, const Production& p);
};