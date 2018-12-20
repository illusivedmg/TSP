# Traveling Salesman Problem

Fair warning - only the third or fourth program in not-Python I ever wrote, and written over top of my first Intro to Algorithms class. 

The original requirements stipulated achieving a Q of .8 in no more than 60 seconds per 1000-vertex graph. This program achieves that in about 2s with one core of an AMD FX-8350 running in the Bash for Windows VM, so maybe it's not all bad.

### Algorithm

Two methods of iteration: 

* tempPathsToTry sets the number of initial paths to try, all distinct and randomly shuffled. Their costs are measured and the best one is sent to the next step.

* numIters sets the number of single, random vertex swaps to make per vertex in the graph. Keeps or discards the change if it was faster.

### Performance

Time is measured as per each 1000-vertex graph.

Q is calculated with 
```Wmin/Wmax = Theoretical minimum/maximum path costs (num vertices * min/max edge weight)
 
Q = 1 - ( costOfPath - Wmin) / (Wmax - Wmin)```

| Single | Path  | Time   |   Q   |
|:------:|:-----:|:------:|:-----:|
| **2500k**  | *10*    | ~60s   | **~.935** |
| 250k   | 250k  | ~41.3s | ~.91  |
| 250k   | 50    | ~6.8s  | ~.91  |
| 250k   | 10000 | ~8.8s  | ~.91  |
| 50000  | *10*    | ~2.51s | ~.875 |
| 50000  | 250   | ~2.55s | ~.875 |
| 10000  | 1000  | ~1.8s  | ~.82  |
| 10000  | 250k  | **~36.5s** | ~.82  |
| 10000  | 2500  | ~2.0s  | ~.817 |
| 1000   | 1000  | ~1.6s  | ~.71  |
| 1000   | 10000 | ~2.8s  | ~.71  |
| 1000   | 100   | ~1.5s  | ~.705 |
| *10*    | **250k** | **~35.5s**  | *~.64* |

####### Test with 2500k paths took over 5 minutes and 5GB of RAM for first graph.

### Conclusion

Potentially useful as a case study in shotgun-pattern vs. quasi-directed pathfinding:
* Testing more paths is luck-based and typically produces very little performance gain per extra time spent.
* Brute forcing more single random changes dominates performance both in terms of quality of path achieved.

###### TODO
* Set iter variables from cmd line (duh)
* Threading
* Format/populate edge weights for more standard TSP algo behavior
* Use number of and specific permutations to bracket best solution 
* Revisit in Adv Algorithms