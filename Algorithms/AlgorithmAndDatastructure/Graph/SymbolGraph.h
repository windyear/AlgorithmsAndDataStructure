//
// Created by windyear_office on 18-1-30.
//

#ifndef SORTALGORITHM_SYMBOLGRAPH_H
#define SORTALGORITHM_SYMBOLGRAPH_H

#include <string>
#include <map>
#include <vector>
#include "Graph.h"

using namespace std;
//符号图是表示实际应用中节点是由字符串或者其他形式表示的。思路是做一个映射和反向索引，
//将字符串和索引对应起来

class SymbolGraph {
private:
    map<string, int> index_table;
    vector<string> index;
    Graph* g;
public:
    SymbolGraph(string filename, char* sp);
    ~SymbolGraph();
    int Index(string s);
    string Name(int index_);
    bool Contains(string s);
    Graph G();

};


#endif //SORTALGORITHM_SYMBOLGRAPH_H
