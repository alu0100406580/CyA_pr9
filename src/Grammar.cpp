#include "Grammar.hpp"


Grammar::Grammar() {}

Grammar::Grammar( char const *infile, char const *outfile ) {
  
  Read( infile );
  std::string fileout = outfile;
  convertG2CNF( outfile );
}

Grammar::Grammar( const Grammar &g ) {
    nt_ = g.getnt_();//coleccion de símbolos no terminales
    s_ = g.gets_();//no terminal llamado símbolo inicial o de arranque
    productions_ = g.getproductions_();  //colección de reglas de sustitución denominadas producciones
    alphabet_ = g.getalphabet_();//alfabeto
    endingSymbols_ = g.getendingSymbols_(); //Estados de aceptación (contienen la cadena vacía)
}

void Grammar::Read( char const *filein ) {

  std::string str1;
  std::ifstream infile( filein );

  auto commentlambda = []( std::ifstream &infile, std::string &a ) {
    if ( a[0] && a[1] == '/' ) {
      while ( a[0] && a[1] == '/' ) {
        std::getline( infile, a );
      }
      return a;
    }
    else {
      return a;
    }
  };

  if ( infile.is_open() ) {

    bool defineFile = false;

    while ( !infile.eof() ) {
      if ( defineFile == true ) {
        std::cout << "Está mal definido el fichero";
        while ( !infile.eof() ){
          std::getline(infile, str1);
        }
      }
      else {

        std::getline( infile, str1 );
        std::string totalAlphabeth = commentlambda( infile, str1 );
        for ( int i = 0; i < ( (int)totalAlphabeth[0] - 48) ; i++ ) {
          std::getline( infile, str1 );
          std::string symbol = commentlambda( infile, str1 );
          alphabet_.insert( str1[0] );
        }
        std::getline( infile, str1 );
        std::string totalStates = commentlambda( infile, str1 );
        for ( int i = 0; i < ( (int)totalStates[0] - 48) ; i++ ) {
          std::getline( infile, str1 );
          std::string label = commentlambda( infile, str1 );
          nt_.insert( label[0] );
        }

        std::getline( infile, str1 );
        s_ = commentlambda( infile, str1 )[0];
        std::getline( infile, str1 );
        std::string totalProductions = commentlambda( infile, str1 );
        for ( int i = 0; i < ( std::stoi( totalProductions ) ) ; i++ ) {
          
          std::getline( infile, str1 );
          std::stringstream ss( str1 );
          std::istream_iterator<std::string> begin( ss );
          std::istream_iterator<std::string> end;
          std::vector<std::string> vstrings( begin, end ), vectorToLang;
          int index = 0;
          //Rule RuleAux;
          char State;
          std::string strAux, productionsAux;
          for ( std::vector<std::string>::iterator it = vstrings.begin();
                it != vstrings.end(); ++it, ++index ) {
            if ( index == 0 ) {
              strAux = *it;
              State = strAux[0];
            }
            else if ( index == 1 ) {
              strAux = *it;
            }
            else if ( index == 2 ) {
              productionsAux = *it;
            }
          }
          Production p1;

          if( productionsAux.size() == 1 && nt_.count(productionsAux[0]) ) { // tamaño 1 y simbolo terminal
            p1.set_state( State );
            auto it = productionsAux.begin();
            it = productionsAux.insert(it, '~');
            p1.set_production( productionsAux );
          }
          else {
            p1.set_state( State );
            p1.set_production( productionsAux );
          }
          
          productions_.push_back( p1 );
        }
      }
      defineFile = true;
    }
  }
}

void Grammar::convertG2CNF( std::string fileout ) {

  Grammar GrammarBackup;
  GrammarBackup = *this;

  int countLabel = 0;
  Production productionAux;
  int sizeProductions = productions_.size();
  std::string productionStringAux;
  std::vector< char > terminalMarked;
  std::vector< std::string > noTerminalMarked;

  for( int i = 0; i < sizeProductions; i++ ) {
    
    productionAux = productions_[i];
    productionStringAux = productions_[i].get_production();

    if( productionStringAux.size() > 1 ) {
      for( int j = 0; j < productionStringAux.size(); j++ ) {
        if( !nt_.count( productionStringAux[j] ) ) {
          
          std::vector<char>::iterator itr = std::find(terminalMarked.begin(), terminalMarked.end(),
                                                      productionStringAux[ j ]);
          if( itr != terminalMarked.cend() ) {
            int index = std::distance(terminalMarked.begin(), itr);
            productionStringAux[ j ] = labels_[ index ];
            productions_[i].set_production( productionStringAux );
          }

          else {
            terminalMarked.push_back( productionStringAux[ j ] );
            std::string copyString( 1, productionStringAux[ j ] );
            productionStringAux[ j ] = labels_[ countLabel ];
            productions_[i].set_production( productionStringAux );
            productionAux.set_state( labels_[ countLabel ] );            
            productionAux.set_production( copyString );
            nt_.insert( labels_[ countLabel ] );
            ++countLabel;
            productions_.push_back( productionAux );
          }
        }
      }
    }
  }
  //ACABANDO LA TRANSFORMACIÓN EN SÍMBOLOS TERMINALES A NO TERMINALES EN MÁS DE UNA PRODUCCIÓN

  for( auto c: terminalMarked ){
    std::string aux;
    aux.push_back( c );
    noTerminalMarked.push_back( aux );
  }


  for( int i = 0; i < sizeProductions; i++ ) {
    
    productionAux = productions_[i];
    productionStringAux = productions_[i].get_production();
    int sizeEvalThisProduction = productionStringAux.size();
      

    if( productionStringAux.size() > 2 ) {
      while ( sizeEvalThisProduction > 1 ) {
        
        std::string evalString;
        evalString = productionStringAux.substr ( productionStringAux.size() - 2, productionStringAux.size() - 1 );
        std::vector<std::string>::iterator itr2 = std::find(noTerminalMarked.begin(), noTerminalMarked.end(),
                                                        evalString);
        if( itr2 != noTerminalMarked.cend() ) {
          int index = std::distance( noTerminalMarked.begin(), itr2);
          productionStringAux.erase( productionStringAux.size() - 2, 2 );
          productionStringAux.push_back( labels_[index] );
          productions_[i].set_production( productionStringAux );        
        }

        else {
          
          noTerminalMarked.push_back( evalString );
          std::string copyString = evalString; //( 2, productionStringAux[ sizeEvalThisProduction - 2 ] );
          productionStringAux.erase( productionStringAux.size() - 2, 2 );
          productionStringAux.push_back(labels_[ countLabel ] );
          productions_[i].set_production( productionStringAux );
          productionAux.set_state( labels_[ countLabel ] );            
          productionAux.set_production( copyString );
          nt_.insert( labels_[ countLabel ] );
          ++countLabel;
          productions_.push_back( productionAux );
        }

        sizeEvalThisProduction -= 2;
      }
    }

  }
  //ACABANDO FNC

  to_file( fileout );

  // REVIRTIENDO A LA GRAMÁTICA ORIGINAL
  nt_ = GrammarBackup.getnt_();
  productions_ = GrammarBackup.getproductions_();
  alphabet_ = GrammarBackup.getalphabet_();
  s_ = GrammarBackup.gets_();
  endingSymbols_ = GrammarBackup.getendingSymbols_();
  
  for (int i = 0; i < productions_.size(); i++)
    std::cout << productions_[ i ] << std::endl;
  std::cout << productions_.size();
  for( auto i : nt_)
    std::cout << i;

}



void Grammar::to_file( string filename ) {
    
  ofstream file;
  string realfilename = filename + ".gra";
  file.open(realfilename, ios::trunc);
  string line = "";

  //linea 1 nº de símbolos terminales
  file << alphabet_.size() << std::endl;
  
  //linea 2 símbolos terminales
  for(auto s: alphabet_) {
    file << s << std::endl;
  }

  // nº de símbolos no terminales
  file << nt_.size() << endl;
  
  // simbolos no terminales
  for(auto s: nt_) {
    file << s << std::endl;
  }
  
  // Simbolo de arranque
  file << s_ << std::endl;

  //Número de producciones
  file << productions_.size() << std::endl;

  //lineas de producciones
  for(int i=0; i<productions_.size(); i++) {
    file << productions_[i] << std::endl;
  }
    
  file.close();
}

set< char > Grammar::getnt_( void ) const {
  return nt_;
}

char Grammar::gets_( void ) const {
  return s_;
}

vector< Production > Grammar::getproductions_( void ) const {
  return productions_;
}

set< char > Grammar::getalphabet_( void ) const {
  return alphabet_;
}

int Grammar::getendingSymbols_( void ) const {
  return endingSymbols_;
}

ostream& operator << ( ostream& os, const Grammar& g ) {
    
  for(int i=0; i<g.productions_.size(); i++) {
    os << g.productions_[i] << endl;
  }

  return os;
}