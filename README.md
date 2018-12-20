# Traveling Salesman Problem

Fair warning - only the third or fourth program in not-Python I ever wrote, and written over top of my first Intro to Algorithms class. 

The original requirements stipulated achieving a Q of .8 in no more than 60 seconds per 1000-vertex graph. This program achieves that in about 2s with one core of an AMD FX-8350 running in the Bash for Windows VM, so maybe it's not all bad.

### Algorithm

Two methods of iteration - 

* tempPathsToTry sets the number of initial paths to try, all distinct and randomly shuffled. Their costs are measured and the best one is sent to the next step.

* numIters sets the number of single, randomized intersection swaps to make. Keeps or discards the change if it was faster.

### Performance

Time is measured per 1000-vertex graph.

Q is calculated with 
> Wmin/Wmax = Theoretical minimum/maximum path costs (num vertices * min/max edge weight)
> 
> Q = 1 - ( costOfPath - Wmin) / (Wmax - Wmin)

| Singles | Paths | Time   |   Q   |
|:-------:|:-----:|:------:|:-----:|
| 250     | 50    | ~6.8s  | ~.91  |
| 50      | 10    | ~2.51s | ~.875 |
| 50      | 250   | ~2.55s | ~.875 |
| 10      | 2500  | ~2.0s  | ~.817 |
| 2500    | 10    | <1min  | ~.935 |
| 250     | 10000 | ~8.8s  | ~.91  |

### Conclusion

Potentially useful as a case study in shotgun-pattern vs. quasi-directed pathfinding:
* Testing more paths typically produces very little performance gain but also very little time addition. Luck-based.
* Making more single random changes dominates performance both in terms of quality of path achieved and time taken. Brute force.

###### TODO
* Set iter variables from cmd line (duh)
* Threading
* Format/Populate edge weights for more standard TSP algo behavior
* Revisit in Adv Algorithms