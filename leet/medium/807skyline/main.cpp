#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <limits>

using namespace std;

void printVec(std::vector<int>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
}

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        //Maintain vector of max elements for each column and one for max element
        //in each row
        vector<int> rowMaxes(grid[0].size(),std::numeric_limits<int>::min());
        vector<int> colMaxes = grid[0];

        //Loop through whole grid and get the rowMaxes and colMaxes
        for(unsigned currRow = 0; currRow < grid.size(); ++currRow){
            for(unsigned currCol = 0; currCol < grid[0].size(); ++currCol){
                //Check if beats currColmax
                rowMaxes[currRow] = std::max(rowMaxes[currRow],grid[currRow][currCol]);
                colMaxes[currCol] = std::max(colMaxes[currCol],grid[currRow][currCol]);
            }
        }

        //Reloop through array and elevate buildings
        int maxIncrease = 0;
        for(unsigned currRow = 0; currRow < grid.size(); ++currRow){
            for(unsigned currCol = 0; currCol < grid[0].size(); ++currCol){
                //Get min of the maxes
                int newVal = std::min(rowMaxes[currRow],colMaxes[currCol]);

                //Get difference between this and the curr value in matrix
                maxIncrease += (newVal - grid[currRow][currCol]);
            }
        }

        
        return maxIncrease;
    }
};

int main(){
    Solution s;
    vector<vector<int>> city = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    int maxIncrease = s.maxIncreaseKeepingSkyline(city);
    cout << "Max Increase Keeping Skyline: " << maxIncrease << endl;
}
