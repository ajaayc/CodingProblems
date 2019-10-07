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

        for(int currRow = 0; currRow < static_cast<int>(board.size()); ++currRow){
            for(int currCol = 0; currCol < static_cast<int>(board[0].size()); ++currCol){
                if(board[currRow][currCol] == 'X'){
                    //If previous row has an X, pass
                    if(currRow > 0 && board[currRow-1][currCol] == 'X'){
                        continue;
                    }
                    else if(currCol < (static_cast<int>(board[0].size()) - 1) && board[currRow][currCol + 1] == 'X'){
                        //Detected a horizontal battleship, keep incrementing currCol until we reach
                        //'.' or off the board
                        while(currCol < static_cast<int>(board[0].size()) && board[currRow][currCol] == 'X'){
                            ++currCol;
                        }
                        ++battleShipCount;
                    }
                    else if(currRow < (static_cast<int>(board.size()) - 1) && board[currRow + 1][currCol] == 'X'){
                        //Detected a vertical battleship
                        ++battleShipCount;
                    }
                    //Lone battleship
                    else{
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
