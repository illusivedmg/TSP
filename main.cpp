#include "graph.h"
#include <iostream>
#include <fstream>

int main() {
    /* INPUT */

    Graph *graph;
    int n, v1, v2;
    double w, min = 1000000.0, max = 0.0, q;
    int e, s;
    std::srand ( unsigned ( std::time(0) ) );


    std::cin >> n;
    graph = new Graph( n );

    std::cin >> v1 >> v2 >> w;
    while (std::cin) {
        graph->addEdge(v1, v2, w);
        if ( w < min ) {
            min = w;
        } else if ( w > max ) {
            max = w;
        }
        std::cin >> v1 >> v2 >> w;
    }

    /* OUTPUT */

    graph->FindSolution_HillClimb();

    e = static_cast<int>(graph->getBestPath().size());
    for(s = 0; s < e; s++) {
        std::cout << graph->getBestPath()[s] + 1 << " ";
    }

    min = n * min;
    max = n * max;
    q = 1 - ( graph->getBestCost() - min) / (max - min);

    std::cout << graph->getBestCost() << " " << q << std::endl;

    /* END */

    delete graph;
    return 0;
}