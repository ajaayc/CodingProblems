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
    //Returns true if row,col is in bounds of grid
    inline bool isInBounds(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || row >= static_cast<int>(grid.size())){
            return 0;
        }
        if(col < 0 || col >= static_cast<int>(grid[0].size())){
            return 0;
        }
        return 1;
    }
    
    int getNumAdjacentZeros(vector<vector<int>>& grid, int row, int col){
        int numAdjacentZeros = 0;
        std::vector<std::pair<int,int>> directions;
        directions.push_back(std::pair<int,int>(row-1,col));
        directions.push_back(std::pair<int,int>(row,col+1));
        directions.push_back(std::pair<int,int>(row+1,col));
        directions.push_back(std::pair<int,int>(row,col-1));
        //Check if N, E, S, W are in bounds

        for(unsigned currDirection = 0; currDirection < directions.size(); ++currDirection){
            int currRow = directions[currDirection].first;
            int currCol = directions[currDirection].second;

            if(isInBounds(grid,currRow,currCol)){
                numAdjacentZeros += !grid[currRow][currCol];
            }
            else{
                numAdjacentZeros += 1;
            }
        }
        
        return numAdjacentZeros;
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
