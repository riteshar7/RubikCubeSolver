#include<bits/stdc++.h>
#include "RubiksCube.h"
#include "DFSSolver.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFS
#define RUBIKS_CUBE_SOLVER_IDDFS

template<typename T, typename H>
class IDDFSSolver {
    private:
    
        vector<RubiksCube::MOVE> moves;
        int max_search_depth;
    
    public:
        T rubiksCube;
    
        IDDFSSolver(T _rubiksCube, int _max_search_depth = 8) {
            rubiksCube = _rubiksCube;
            max_search_depth = _max_search_depth;
        }
    
//    Used DFSSolver with increasing max_search_depth
    vector<RubiksCube::MOVE> solve() {
        for (int i = 1; i <= max_search_depth; i++) {
            DFSSolver<T, H> dfsSolver(rubiksCube, i);
            moves = dfsSolver.solve();
            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }

};

#endif //RUBIKS_CUBE_SOLVER_IDDFS

/******************For notes purposes*******************
*IDDFS Solver is mixture of DFS and BFS. If solution is near root then searches easily
by applying DFS at varying max heights in increasing order of the cube graph structure.
* Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
* Typename H: Corresponding Hash function
*/
