//
// Created by windyear_office on 18-1-30.
//

#include <iostream>
#include "DegreesOfSeparation.h"
#include "SymbolGraph.h"
#include "BreadthFirstPaths.h"

void DegreesOfSeparation::TestDegrees(char* sp, string filename, string source) {
    SymbolGraph symbol_graph(filename, sp);
    Graph g = symbol_graph.G();
    if(!symbol_graph.Contains(source)){
        cout << "this location is not in the database." << endl;
    }
    int s = symbol_graph.Index(source);
    //一个广度优先搜索类
    BreadthFirstPaths breadth_first_paths(g, s);
    //读取输入
    string destination;
    while(getline(cin,destination)){
        if(symbol_graph.Contains(destination)){
            int v = symbol_graph.Index(destination);
            if(breadth_first_paths.HasPathTo(v)){
                for(auto path: breadth_first_paths.PathTo(v)){
                    cout << " " << symbol_graph.Name(path) << endl;
                }
            }else{
                cout << "Not connected!" << endl;
            }
        }else{
            cout << "The location is not in the databases." << endl;
        }
    }
}
