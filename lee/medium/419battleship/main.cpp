#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

template <typename T>
void printVec(std::vector<T>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
}

template <typename T>
void printMat(std::vector<std::vector<T>>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        for(auto it2 = it->begin(); it2 != it->end(); ++it2){
            cout << *it2 << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int battleShipCount = 0;

        int numRows = static_cast<int>(board.size());
        int numCols = static_cast<int>(board[0].size());
        
        for(int currRow = 0; currRow < numRows; ++currRow){
            for(int currCol = 0; currCol < numCols; ++currCol){
                if(board[currRow][currCol] == 'X'){
                    if(currCol < (numCols - 1) && board[currRow][currCol + 1] == 'X'){
                        //Detected a horizontal battleship, keep incrementing currCol until we reach
                        //'.' or off the board
                        while(currCol < numCols && board[currRow][currCol] == 'X'){
                            ++currCol;
                        }
                        ++battleShipCount;
                    }
                    //Vertical battleship or lone battleship detected.
                    //Note that if previous row is a '.' and current row is an 'X',
                    //and no horizontal battleship was detected in previous statement,
                    //then this has to be either a lone battleship or a new uncounted
                    //vertical battleship
                    else if(currRow == 0 || board[currRow-1][currCol] != 'X'){
                        ++battleShipCount;
                    }
                }
                //else ignore if it's a '.'
            }
        }

        return battleShipCount;
    }
};

int main(){
    Solution s;
    std::vector<vector<char>> board = {
        {'.','.','.','.','X','.','.','.'},
        {'.','X','X','.','X','.','X','X'},
        {'X','.','.','.','.','.','.','.'},
        {'X','.','X','.','X','X','.','X'},
        {'X','.','X','.','.','.','.','.'},
        {'.','.','X','.','X','X','X','X'},
        {'X','X','.','X','.','.','.','.'},
        {'.','.','.','X','.','X','X','X'}
    };

    cout << "Here's the board:" << endl;
    printMat(board);
    cout << "Number of battleships:" << endl;
    cout << s.countBattleships(board);

    cout << endl;
}
