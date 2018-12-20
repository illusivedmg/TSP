#include "graph.h"

Graph::Graph( int num )
  : mNumVertices( num ) {
    mEdgeWeights.resize(num);
	for(int i = 0; i < num; i++) {
        mEdgeWeights[i].resize(num);
    } 
}

Graph::~Graph() {
    mEdgeWeights.clear();
    std::vector< std::vector< double > > NewVector;
    NewVector.swap(mEdgeWeights);
}

void Graph::addEdge( int v0, int v1, double w ) {
    mEdgeWeights[v0 - 1][v1 - 1] = w;
}

double Graph::getBestCost() {
    return mBestCost;
}

const std::vector<int>& Graph::getBestPath() const {
    return mBestPath;
}

double Graph::MeasurePathCost(std::vector<int>& fullPath) {
    double pathCost = 0.0;
    int v0, v1, i, e;
    e = static_cast<int>(fullPath.size());
    for(i = 0; i < e; i++) {
        v0 = fullPath[i];
        if( i == (e-1) ) {
            v1 = fullPath[0];
        } else {
            v1 = fullPath[i+1];
        }
        pathCost += mEdgeWeights[v0][v1];
    }
    return pathCost;
}

void Graph::FindSolution_HillClimb() {

    int numIters = 250;
    int tempPathsToTry = 10000;

    int bestTempPath = 0;
    double bestTempPathCost = 1000000000.0;

    mBestCost = 1000000000.0;
    double currentCost = 0.0;
    double tempCost = 0.0;
    std::vector<int> citiesExceptZero;
    std::vector<int> fullPath;
    std::vector<int> tempPath;

    std::vector<std::vector<int>> tempPaths;

    tempPaths.resize(tempPathsToTry);
    
    int d, e, i, t, u, v, n = 0;
    size_t j;

    // generate citiesExceptZero path to shuffle without disrupting position of first city
    for(i = 1; i < mNumVertices; i++) {
        citiesExceptZero.push_back(i);
    }

    // completely shuffle a number of paths, pick best
    for(i = 0; i < tempPathsToTry; i++) {
        std::random_shuffle( citiesExceptZero.begin(), citiesExceptZero.end() );
    
        tempPaths[i].push_back(0);
        for( j = 0; j < citiesExceptZero.size(); j++) {
            tempPaths[i].push_back(citiesExceptZero[j]);
        }

        tempCost = MeasurePathCost(tempPaths[i]);
        if(tempCost < bestTempPathCost) {
            bestTempPath = i;
            bestTempPathCost = tempCost;
        }
        std::cerr << "bestcost = " << tempCost << std::endl;
    }

    tempPath.swap(tempPaths[bestTempPath]);
    currentCost = bestTempPathCost;
    
    while( currentCost < mBestCost ) {
        mBestCost = currentCost;
        mBestPath = fullPath;
        while( n < mNumVertices * numIters ) {
            //set temporary cycle as randomly selected neighbor cycle of best cycle
            t = (rand() % (mNumVertices - 3)) + 1;
            d = ( mNumVertices - 2 ) - t;
            if( d > 1 ) {
                e = (rand() % d ) + 1;
            } else {
                e = d;
            }
            u = tempPath[t];
            v = tempPath[t+e];
            tempPath[t] = v;
            tempPath[t+e] = u;
            tempCost = MeasurePathCost( tempPath );
            if( tempCost < currentCost ) {
                currentCost = tempCost;
                fullPath = tempPath;
            } else {
                // GO BACK ABORT ABORT
                tempCost = currentCost;
                tempPath[t] = u;
                tempPath[t+e] = v;
            }
            n++;
        }
    }
}