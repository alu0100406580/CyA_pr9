#include "Grammar.hpp"


Grammar::Grammar() {}

Grammar::Grammar(Dfa& dfa) {
    define_productions(dfa);
}

void Grammar::define_productions(Dfa& dfa) {
    int i=0;
    Rule rule;
    for(auto q: dfa.getallstates()) {
        Production production;
        production.set_state(labels_[i]);
        nt_.insert(labels_[i]);
        
        for(auto t: q.gettransitions()) {//una transción = una producción
            char t_symbol = t.getsymbol();
            production.set_terminal(t_symbol);
            production.set_nt(labels_[t.gettostate()]);
            alphabet_.insert(t_symbol);
            
            rule.push_back(production);
        
            
        }
        
        if(q.gettype() == 1) {
            Production e_prod;
            e_prod.set_state(labels_[i]);
            char epsilon = '~';
            char nt_epsilon = ' ';
            e_prod.set_terminal(epsilon);
            e_prod.set_nt(nt_epsilon);
            rule.push_back(e_prod);
            endingSymbols_++;
        }
        
        
        i++;
    }
    productions_.push_back(rule);
    
}

void Grammar::to_file(string filename) {
    
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
    

ostream& operator << (ostream& os, const Grammar& g) {
    
    for(int i=0; i<g.productions_.size(); i++) {
        os << g.productions_[i] << endl;
    }
    
    return os;
}
