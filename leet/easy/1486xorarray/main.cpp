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

class Solution {
public:
    int xorOperation(int n, int start) {
      int result = 0;
      for(int i = 0; i < n; ++i){
	result ^= (start + 2 * i);
      }
      
      return result;
    }
};

void processTest(int n, int start){
  Solution s;
  int output;
  std::cout << "Input:\n";
  std::cout << "n: " << n << " start: " << start << std::endl;
  output = s.xorOperation(n, start);
  std::cout << "Output:\n";
  std::cout << output << std::endl;
}

int main(){
  int start, n;

  n = 5, start = 0;
  processTest(n, start);

  n = 4, start = 3;
  processTest(n, start);

  n = 1, start = 7;
  processTest(n, start);

  n = 10, start = 5;
  processTest(n, start);
}
