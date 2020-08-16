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

//O(2^(N-2) * N) time
/*
  There are 2^(N-2) possible paths; this is the powerset of the set of all digits [1,N-2] given
  nodes [0,N-1]. Each path is of length N maximum (loose bound). For each path, we might
  add it to the result vector, requiring O(N) copy. Thus the time complexity is
  O(2^N * N)
 */

//O(2^(N-2)) * N) memory including output, O(N) memory excluding output for recursion
/*
  There are O(2^(N-2)) possible paths to store and each path is of length N, thus requiring
  O(2^N * N) memory for the output. Excluding the output, it would just be O(N) for the
  recursion.
 */
class Solution {
public:
    //I included a visited array for the case that the graph has cycles in it. This would
    //prevent infinite recursion by avoiding paths where the same node is re-visited
    void DFS(int index,const vector<vector<int>>& graph,vector<int>& currPath,vector<bool>& visited,vector<vector<int>>& result){
        if(visited[index]){
            return;
        }
        
        //Visit this node
        currPath.push_back(index);
        visited[index] = true;

        if(index == static_cast<int>(graph.size()) - 1){
            //Found path
            result.push_back(currPath);
            //Unvisit
            currPath.pop_back();
            visited[index]=false;
            return;
        }

        
        //Visit adjacent nodes
        const vector<int>& neighbors = graph[index];

        for(auto it = neighbors.begin(); it != neighbors.end(); ++it){
            DFS(*it,graph,currPath,visited,result);
        }
        
        //Unvisit
        currPath.pop_back();
        visited[index]=false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.empty()){
            vector<vector<int>> retVal;
            return retVal;
        }

        vector<vector<int>> result;
        
        //currentPath we're on
        vector<int> currPath;
        //Keeps track of which nodes have been visited in currentPath
        vector<bool> visited(graph.size(),false);

        DFS(0,graph,currPath,visited,result);

        return result;
    }
};

int main(){
    Solution s;
    std::vector<vector<int>> graph = {{1,2}, {3}, {3}, {}};

    cout << "Here's the graph:" << endl;
    printMat(graph);

    //Here's the paths
    vector<vector<int>> paths = s.allPathsSourceTarget(graph);
    printMat(paths);

    cout << endl;
}
