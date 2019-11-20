#include "Grammar.hpp"


Grammar::Grammar() {}

Grammar::Grammar( char const *infile, char const *outfile ) {
  Read( infile );
}

void Grammar::Read ( char const *filein ) {

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
          Rule RuleAux;
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
            std::vector< string > vectProductionsAux = { productionsAux };
            p1.set_productions( vectProductionsAux );
            RuleAux.push_back( p1 );
          }
          else {
            p1.set_state( State );
            std::vector< string > vectProductionsAux = { productionsAux };
            p1.set_productions( vectProductionsAux );
            RuleAux.push_back( p1 );
          }
          
          productions_.push_back( RuleAux );
        }
      }
      for (int i = 0; i < productions_.size(); i++)
            std::cout << productions_[ i ];
      defineFile = true;
    }
  }
}

void Grammar::to_file( string filename ) {
    
    ofstream file;
    string realfilename = filename + ".grammar";
    file.open(realfilename, ios::trunc);
    string line = "";

    //linea 1 nº de símbolos terminales
    file << alphabet_.size() << endl;
    
    //linea 2 símbolos terminales
    for(auto s: alphabet_) {
        file << s << " ";
    }
    file << endl;
    
    //linea 3 nº de símbolos del alfabeto
    file << nt_.size() << endl;
    
    
    //linea 4
    for(auto s: nt_) {
        file << s << " ";
    }
    file << endl;
    
    //lineas de producciones
    for(int i=0; i<productions_.size(); i++) {
        //if(i<productions_.size() - 1) {
            file << productions_[i];
        //}
    }
      
    file.close();
}
    

ostream& operator << ( ostream& os, const Grammar& g ) {
    
    for(int i=0; i<g.productions_.size(); i++) {
        os << g.productions_[i] << endl;
    }
    
    return os;
}
