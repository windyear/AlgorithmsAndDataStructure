//
// Created by windyear_office on 18-2-3.
//

#include <iostream>
#include <sstream>
#include "Edge.h"

Edge::Edge(int v, int w, double weight) : v(v), w(w), weight(weight){

};

int Edge::Either() const {
    return v;
}

int Edge::Other(int vertex) const {
    if(vertex == v){
        return w;
    }else if(vertex == w){
        return v;
    }else{
        cout << "no exist!" << endl;
        return 0;
    }
}

double Edge::Weight() const {
    return weight;
}

int Edge::CompareTo(Edge that) const {
    if(weight > that.Weight()){
        return 1;
    }else if(weight < that.Weight()){
        return -1;
    }else{
        return 0;
    }
}

string Edge::ToString() const {
    //格式化字符串输出，用stringstream流
    stringstream ss;
    ss << v << "-" << w << " " << weight;
    return ss.str();
}

Edge::~Edge() {

}