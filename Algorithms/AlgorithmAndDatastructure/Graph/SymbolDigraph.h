//
// Created by windyear_office on 18-1-31.
//

#ifndef SORTALGORITHM_SYMBOLDIDigraph_H
#define SORTALGORITHM_SYMBOLDIDigraph_H

#include <string>
#include <map>
#include <vector>
#include "Digraph.h"

class SymbolDigraph {
private:
    map<string, int> index_table;
    vector<string> index;
    Digraph* g;
public:
    SymbolDigraph(string filename, char* sp);
    ~SymbolDigraph();
    int Index(string s);
    string Name(int index_);
    bool Contains(string s);
    Digraph G();
};


#endif //SORTALGORITHM_SYMBOLDIDigraph_H
