#ifndef RUBIKS_CUBE_SOLVER_LIB
#define RUBIKS_CUBE_SOLVER_LIB

#include <bits/stdc++.h>
using namespace std;


class RubiksCube {
    public:
        enum class FACE {
            UP,
            LEFT,
            FRONT,
            RIGHT,
            BACK,
            DOWN
        };
    
        enum class COLOR {
            WHITE,
            GREEN,
            RED,
            BLUE,
            ORANGE,
            YELLOW
        };
    
        enum class MOVE {
            L, LPRIME, L2,
            R, RPRIME, R2,
            U, UPRIME, U2,
            D, DPRIME, D2,
            F, FPRIME, F2,
            B, BPRIME, B2
        };
    
        
        virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;
    
        static char getColorLetter(COLOR color);
    
        virtual bool isSolved() const = 0;
    
        static string getMove(MOVE ind);
        
        void print() const;
    
        vector<MOVE> randomShuffle(unsigned int times);
    
        RubiksCube &move(MOVE ind);
    
        RubiksCube &invert(MOVE ind);
        
        // Defining the moves in different models
        virtual RubiksCube &f() = 0;
        virtual RubiksCube &fPrime() = 0;
        virtual RubiksCube &f2() = 0;
    
        virtual RubiksCube &u() = 0;
        virtual RubiksCube &uPrime() = 0;
        virtual RubiksCube &u2() = 0;
    
        virtual RubiksCube &l() = 0;
        virtual RubiksCube &lPrime() = 0;
        virtual RubiksCube &l2() = 0;
    
        virtual RubiksCube &r() = 0;
        virtual RubiksCube &d() = 0;
        virtual RubiksCube &dPrime() = 0;
    
        virtual RubiksCube &d2() = 0;
        virtual RubiksCube &rPrime() = 0;
        virtual RubiksCube &r2() = 0;
    
        virtual RubiksCube &b() = 0;
        virtual RubiksCube &bPrime() = 0;
        virtual RubiksCube &b2() = 0;
    
        string getCornerColorString(uint8_t ind) const;
    
        uint8_t getCornerIndex(uint8_t ind) const;
    
        uint8_t getCornerOrientation(uint8_t ind) const;
};


#endif //RUBIKS_CUBE_SOLVER_LIB

/******************For notes purposes*******************
     * Print function defined above should print 
     * in this format only in this Planar format.
     * The cube is laid out as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     * Color wise (Unsolved):
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *****************************************************
     * randomShuffle function should be implemented such that
     * it should only shuffe the cube in one of the
     * solvable ways only
     * ***************************************************
     * isSolved function to check that have we reached the
     * desired solution or not
     * ***************************************************
     * 
     */