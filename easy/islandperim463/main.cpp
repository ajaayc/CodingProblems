#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

void printVec(std::vector<int>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
}

void printMat(std::vector<std::vector<int>>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        for(auto it2 = it->begin(); it2 != it->end(); ++it2){
            cout << *it2 << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    //Given grid[row][col] = 1, this function returns the number of adjacent 0's
    //to this cell
    int getNumAdjacentZeros(vector<vector<int>>& grid, int row, int col){
        //Check all four edges
        int counter = 0;

        //1-x will map x to 0 if x == 1, and 1 if x == 0
        counter += (row == 0 ? 1 : 1 - grid[row - 1][col]);
        counter += (row == static_cast<int>(grid.size()) - 1 ? 1 : 1 - grid[row + 1][col]);
        counter += (col == 0 ? 1 : 1 - grid[row][col - 1]);
        counter += (col == static_cast<int>(grid[0].size()) - 1 ? 1 : 1 - grid[row][col + 1]);

        return counter;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(unsigned currRow = 0; currRow < grid.size(); ++currRow){
            for(unsigned currCol = 0; currCol < grid[0].size(); ++currCol){
                if(grid[currRow][currCol] == 1){
                    //Count number of adjacent zeroes
                    perimeter += getNumAdjacentZeros(grid,currRow,currCol);
                }
            }
        }
        return perimeter;
    }
};

int main(){
    Solution s;
    std::vector<vector<int>> island = {{0,1,0,0},
                                       {1,1,1,0},
                                       {0,1,0,0},
                                       {1,1,0,0}};
    cout << "Here's the island:" << endl;
    printMat(island);
    cout << "The perimeter is:" << endl;
    cout << s.islandPerimeter(island);

    cout << endl;
}
