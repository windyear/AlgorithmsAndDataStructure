//
// Created by windyear_office on 18-2-7.
//

#include <sstream>
#include "DirectedEdge.h"

DirectedEdge::DirectedEdge(int v, int w, int weight) {
    this->v = v;
    this->w = w;
    this->weight = weight;
}

int DirectedEdge::From() {
    return v;
}

int DirectedEdge::To() {
    return w;
}

double DirectedEdge::Weight() {
    return weight;
}

string DirectedEdge::ToString() {
    stringstream ss;
    ss << v << "->" << w << " " << weight;
    return ss.str();
}