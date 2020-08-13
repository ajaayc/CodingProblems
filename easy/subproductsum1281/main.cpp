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
  //This algorithm takes O(log n) time and O(1)
  //memory, where n is the input.
  //The reasoning is that n has floor(log_10(n)) + 1
  //digits in it, which is the number of times that
  //the while loop in this algorithm will execute.
  //It can be shown therefore that this algorithm takes
  //O(log n) time.
  int subtractProductAndSum(int n) {
    int nextDigit;

    int product = 1, sum = 0;

    if(n == 0)
      return 0;
      
    while(n != 0){
      nextDigit = n % 10;
      product *= nextDigit;
      sum += nextDigit;
      n /= 10;
    }

    return product - sum;
  }
};

void processTest(int input){
  Solution s;
  int output;
  std::cout << "Input:\n";
  std::cout << input << std::endl;
  output = s.subtractProductAndSum(input);
  std::cout << "Output:\n";
  std::cout << output << std::endl;
}

int main(){
  int input;

  input = 234;
  processTest(input);

  input = 4421;
  processTest(input);

  input = 0;
  processTest(input);
}
