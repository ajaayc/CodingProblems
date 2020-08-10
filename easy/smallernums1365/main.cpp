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

/*
  O(N^2) solution and O(N) memory, where N is nums.size().
  Can we do this in place so that we use O(1) memory?
  Ignoring the memory usage for the output, can we decrease the
  time complexity via an extra data structure?
  Can we reduce time complexity without an extra data structure?
 */
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      vector<int> output(nums.size(), 0);

      for(unsigned i = 0; i < nums.size(); ++i){
	//Loop through all elements and count which ones are smaller
	for(unsigned j = 0; j < nums.size(); ++j){
	  if(nums[j] < nums[i]){
	    ++output[i];
	  }
	}
      }

      return output;
    }
};

void processTest(std::vector<int>& input){
  Solution s;
  std::vector<int> output;
  std::cout << "Input:\n";
  printVec(input);
  output = s.smallerNumbersThanCurrent(input);
  std::cout << "Output:\n";
  printVec(output);
}

int main(){
    std::vector<int> input;

    input = {6,5,4,8};
    processTest(input);

    input = {7,7,7,7};
    processTest(input);

    input = {3,2,19,11,20,24,7};
    processTest(input);    
}
