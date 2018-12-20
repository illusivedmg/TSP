#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>

class Graph {
public:
    Graph( int n );
    ~Graph();

    void addEdge(int v0, int v1, double w);
    double getBestCost();
    const std::vector<int>& getBestPath() const;
    double MeasurePathCost(std::vector<int>& fullPath);
    void FindSolution_HillClimb();

protected:
    std::vector< std::vector< double > > mEdgeWeights;
    int mNumVertices;
    std::vector<int> mBestPath;
    double mBestCost;
};

#endif