#include <unordered_set>
#include <iostream>
#include <vector>

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
  //This solution is O(log N) where N=num.
  //num has floor(log_2(num)) + 1 bits in it. In the
  //worst case: All of the bits are 1. For each 1 except
  //the most significant 1, this algorithm uses 2 steps. The
  //last 1 uses just one step.
  //Thus this algorithm would take  2 * (floor(log_2(num)) + 1) - 1
  //steps. It can be shown that this can be represented as
  //2 * log_2(num) - 2 * x + 1, where x is a constant in the interval
  //[0,1). Therefore, the number of steps is O(log num).
  int numberOfSteps (int num) {
    int count = 0;

    while(num != 0){
      if(num & 1)
	--num;
      else
	num = (num >> 1);

      ++count;
    }

    return count;
  }
};

int main(){
    Solution s;
    int input;

    input = 14;
    std::cout << "Input:\n";
    std::cout << input << "\n";
    std::cout << "Output:\n";
    std::cout << s.numberOfSteps(input) << "\n";

    input = 8;
    std::cout << "Input:\n";
    std::cout << input << "\n";
    std::cout << "Output:\n";
    std::cout << s.numberOfSteps(input) << "\n";

    input = 123;
    std::cout << "Input:\n";
    std::cout << input << "\n";
    std::cout << "Output:\n";
    std::cout << s.numberOfSteps(input) << "\n";
}
