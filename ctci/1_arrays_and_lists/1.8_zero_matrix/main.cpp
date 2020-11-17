#include <unordered_set>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}

template <typename T>
void printMat(const std::vector<std::vector<T>>& mat){
  for(unsigned row = 0; row < mat.size(); ++row){
    printVec(mat[row]);
  }
}

template <typename T>
class Solution {
public:
  std::vector<std::vector<T>> zeroMat(const std::vector<std::vector<T>>& input, unsigned numRows, unsigned numCols) {
    std::vector<std::vector<T>> out;

    return out;
  }
};

enum Choice{
  INPLACE,NOTINPLACE
};

template <typename T>
void processTest(std::vector<std::vector<T>> input, unsigned numRows, unsigned numCols, Choice c){
  Solution<int> s;
  std::vector<std::vector<T>> output;
  if(c == INPLACE)
    std::cout << "--In Place Test Case--" << std::endl;
  else if(c == NOTINPLACE)
    std::cout << "--Not In Place Test Case--" << std::endl;    

  std::cout << "Input:\n";
  printMat(input);
  /*
  std::cout << "Output:\n";
  if(c == NOTINPLACE){
    output = s.zeroMat(input, size);
    printMat(output);
  }
  */
  /*
  else if(c == INPLACE){
    s.rotateMatInPlace(input, size);
    printMat(input);
  }
  */
  std::cout << std::endl;
}

int main(){
  std::vector<std::vector<int>> input;

  return 0;
}
