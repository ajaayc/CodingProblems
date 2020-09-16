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
  virtual std::vector<char> findPath(const std::vector<std::vector<bool>>& map) = 0;

  virtual void printMethod() = 0;

  virtual ~Solution(){}
};

class SolutionRecursive : public Solution{
public:
  virtual std::vector<char> findPath(const std::vector<std::vector<bool>>& map){
    return {'r','d'};
  }

  virtual void printMethod(){
    std::cout << "--Recursive Solution--" << std::endl;
  }
};
  


void processTest(const std::vector<std::vector<bool>>& map, std::vector<Solution*>& methods){
  std::cout << std::endl;
  std::cout << "--Map--" << std::endl;
  printVec2D(map);
  
  for(Solution* s : methods){
    s->printMethod();
    printVec(s->findPath(map));
  }
}

int main(){
  Solution* s1 = new SolutionRecursive();
  std::vector<Solution*> methods = {s1};
  
  std::vector<std::vector<bool>> map;
  map = {{0,0,0,0,0},
	 {0,0,0,1,0},
	 {0,0,0,1,0},
	 {0,0,0,1,0}};

  processTest(map, methods);

  for(Solution* s : methods){
    delete s;
  }
}
