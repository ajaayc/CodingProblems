#include <iostream>
#include <cassert>
#include <vector>
#include <string.h> //memset

using namespace std;

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}

template <typename T>
void printVec2D(const std::vector<std::vector<T>>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    printVec(*it);
  }
  
  std::cout << std::endl;
}


class Solution{
public:
  //Returns if path exists, and if so, what the path is
  virtual bool findPath(const std::vector<std::vector<bool>>& map, std::vector<char>& path) = 0;

  virtual void printMethod() = 0;

  virtual ~Solution(){}

  static inline bool isValidCell(const std::vector<std::vector<bool>>& map, int r, int c){
    return inBounds(map, r, c) && !hasObstacle(map, r, c);
  }
  
  
  static inline bool inBounds(const std::vector<std::vector<bool>>& map, int r, int c){
    int numRows = map.size(), numCols = map[0].size();

    return 0 <= r && r < numRows && 0 <= c && c < numCols;
  }
  
  static inline bool hasObstacle(const std::vector<std::vector<bool>>& map, int r, int c){
    return map[r][c];
  }

};

/*
  Let r be the number of rows in the map and c be the number of columns in the map.
  O(r + c) memory for recursion,
  O(2 ^ (r+c)) time to explore all possible paths from the goal node to the start node

  Can we reduce the time complexity of this solution?
 */
class SolutionRecursive : public Solution{
public:
  virtual bool findPath(const std::vector<std::vector<bool>>& map, std::vector<char>& path){
    int numRows = map.size(), numCols = map[0].size();

    return findPathHelper(map, numRows, numCols, numRows - 1, numCols - 1, path);
  }

  //Returns if a path exists
  virtual bool findPathHelper(const std::vector<std::vector<bool>>& map, const int numRows, const int numCols, int currRow, int currCol, std::vector<char>& path){
    if(currRow == 0 && currCol == 0){
      return true;
    }

    if(Solution::isValidCell(map, currRow, currCol - 1)){
      bool leftPathFound = findPathHelper(map, numRows, numCols, currRow, currCol - 1, path);
      if(leftPathFound){
	path.push_back('r');
	return true;
      }
    }

    if(Solution::isValidCell(map, currRow - 1, currCol)){
      bool upPathFound = findPathHelper(map, numRows, numCols, currRow - 1, currCol, path);
      if(upPathFound){
	path.push_back('d');
	return true;
      }
    }

    return false;
  }

  virtual void printMethod(){
    std::cout << "--Recursive Solution--" << std::endl;
  }
};
  
/*
  Let r and c be the number of rows and columns respectively in the map.
  Space complexity: O(r * c) bool matrix + O(r + c) map = O(r * c) for large r and c
  Time complexity: O(r * c). Each map element is only explored once at most.
 */
class SolutionRecursiveDP : public Solution{
  virtual bool findPath(const std::vector<std::vector<bool>>& map, std::vector<char>& path){
    int numRows = map.size(), numCols = map[0].size();

    //Represents if the recursion has been performed on a cell already and yielded no result
    //This improves the complexity by saving time if we have already tried to explore a path
    //from the cell to the upper left cell
    std::vector<std::vector<bool>> exploredMem(numRows, std::vector<bool>(numCols, false));
    
    bool result = findPathHelper(map, numRows, numCols, exploredMem, numRows - 1, numCols - 1, path);

    //cout << "Mem Map" << endl;
    //printVec2D(exploredMem);
    
    return result;
  }

  //Returns if a path exists
  virtual bool findPathHelper(const std::vector<std::vector<bool>>& map, const int numRows, const int numCols, std::vector<std::vector<bool>>& exploredMem, int currRow, int currCol, std::vector<char>& path){
    if(currRow == 0 && currCol == 0){
      return true;
    }

    int rowToExplore = currRow;
    int colToExplore = currCol - 1;
    
    if(Solution::isValidCell(map, rowToExplore, colToExplore)){
      if(!exploredMem[rowToExplore][colToExplore]){
	bool leftPathFound = findPathHelper(map, numRows, numCols, exploredMem, rowToExplore, colToExplore, path);
	if(leftPathFound){
	  path.push_back('r');
	  return true;
	}
	else{
	  exploredMem[rowToExplore][colToExplore] = true;
	}
      }
    }

    rowToExplore = currRow - 1;
    colToExplore = currCol;

    if(Solution::isValidCell(map, rowToExplore, colToExplore)){
      if(!exploredMem[rowToExplore][colToExplore]){
	bool upPathFound = findPathHelper(map, numRows, numCols, exploredMem, rowToExplore, colToExplore, path);
	if(upPathFound){
	  path.push_back('d');
	  return true;
	}
	else{
	  exploredMem[rowToExplore][colToExplore] = true;
	}
      }
    }

    return false;
  }

  virtual void printMethod(){
    std::cout << "--Recursive DP Solution--" << std::endl;
  }  
};

void processTest(const std::vector<std::vector<bool>>& map, std::vector<Solution*>& methods){
  std::cout << std::endl;
  std::cout << "--Map--" << std::endl;
  printVec2D(map);
  
  for(Solution* s : methods){
    s->printMethod();
    std::vector<char> path;
    bool foundPath = s->findPath(map, path);
    if(foundPath)
      printVec(path);
    else
      cout << "No path found!" << endl;
  }
}

int main(){
  Solution* s1 = new SolutionRecursive();
  Solution* s2 = new SolutionRecursiveDP();

  std::vector<Solution*> methods = {s2,s1};
  
  std::vector<std::vector<bool>> map;

  std::vector<std::vector<std::vector<bool>>> maps;

  maps.push_back({{0,0,0,0,0},
                {0,0,0,1,0},
                {0,0,0,1,0},
                {0,0,0,1,0}});

  maps.push_back({{0,1,0,0,0},
                {1,0,0,1,0},
                {0,0,0,1,0},
                {0,0,0,1,0}});

  maps.push_back({{0,1,0,1,0},
                {1,0,0,1,0},
                {0,0,0,1,0},
                {0,0,0,0,0}});

  maps.push_back({{0,1,0,0,0},
                {0,1,0,1,0},
                {0,1,0,1,0},
                {0,0,0,0,0}});

  maps.push_back({{0,1,0,0,0},
                {0,1,0,1,0},
                {0,1,0,1,0},
                {0,0,0,0,0}});

  maps.push_back({{0,0,1,0,0},
                {0,1,0,1,0},
                {0,1,0,1,0},
                {0,0,0,0,0}});

  maps.push_back({{0,0,1,1,0},
                {1,0,0,1,1},
                {1,1,0,0,1},
                {0,1,1,0,0}});

  maps.push_back({{0,1,1,1,0},
                {0,0,0,0,1},
                {1,0,1,0,1},
		{0,0,0,0,0}});

  maps.push_back({{0,1,1,1,1},
                  {0,0,1,1,1},
                  {1,1,0,1,1},
		  {1,1,0,0,0}});

  int mapSize = 5000;
  std::vector<std::vector<bool>> bigMap(mapSize, std::vector<bool>(mapSize, false));
  bigMap[1][0] = true;
  bigMap[0][1] = true;
  
  maps.push_back(bigMap);
  
  for(auto it = maps.begin(); it != maps.end(); ++it){
    processTest(*it, methods);
  }

  for(Solution* s : methods){
    delete s;
  }
}
