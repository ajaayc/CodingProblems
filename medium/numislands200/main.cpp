#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

template <typename T>
void printVec(std::vector<int>& v){
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

//DFS solution. O(n^2) time + O(n^2) time for recursion = O(n^2) time. O(n^2) memory for recursion and for boolean grid = O(n^2) memory
class Solution {
public:
    void DFS(const vector<vector<char>>& grid, vector<vector<bool>>& visitedGrid, int r, int c){
        //Potentially using an explicit stack could reduce the amount of memory used in practice

        if(grid[r][c] != '1' || visitedGrid[r][c])
            return;
        //Mark visited
        visitedGrid[r][c] = true;
                
        //Up
        if(r != 0){
            DFS(grid,visitedGrid,r-1,c);
        }
        //Right
        if(c != static_cast<int>(grid[0].size()) - 1){
            DFS(grid,visitedGrid,r,c+1);
        }
        //Down
        if(r != static_cast<int>(grid.size()) - 1){
            DFS(grid,visitedGrid,r+1,c);
        }
        //Left
        if(c != 0){
            DFS(grid,visitedGrid,r,c-1);
        }
    }

    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        if(grid[0].empty()) return 0;

        //Initialize a boolean array of same size as grid, representing
        //which cells have been visited
        vector<bool> row(grid[0].size(),false);
        vector<vector<bool>> isVisited(grid.size(),row);

        int islandCount = 0;
        for(int currRow = 0; currRow < static_cast<int>(grid.size()); ++currRow){
            for(int currCol = 0; currCol < static_cast<int>(grid[0].size()); ++currCol){
                if(grid[currRow][currCol] == '1' && !isVisited[currRow][currCol]){
                    ++islandCount;
                    DFS(grid,isVisited,currRow,currCol);
                }
            }
        }
        
        return islandCount;
    }
};

int main(){
    Solution s;
    //std::vector<vector<char>> island = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    std::vector<vector<char>> island = {
        {'1','1','1','1','0','0'},
        {'1','1','0','1','0','0'},
        {'1','1','0','0','1','1'},
        {'0','0','0','0','0','1'},
        {'0','1','1','0','0','0'},
        {'1','1','0','0','1','0'}
    };

    cout << "Here's the island:" << endl;
    printMat(island);
    cout << "The number of islands is:" << endl;
    cout << s.numIslands(island);

    cout << endl;
}
