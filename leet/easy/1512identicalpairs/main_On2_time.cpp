#include <iostream>
#include <unordered_map>
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
  //O(n^2) time, O(1) memory, where n is the size of nums.
  //Loops through nums in a double for loop, and counts
  //number of matching pairs
  int numIdenticalPairs(vector<int>& nums) {
    int numPairs = 0;
    
    for(unsigned i = 0; i < nums.size(); ++i){
      for(unsigned j = i+1; j < nums.size(); ++j){
	if(nums[i] == nums[j]){
	  ++numPairs;
	}
      }
    }

    return numPairs;
  }
};

int main(){
  Solution s;
  vector<int> currVec;
    
  currVec = {1,2,3,1,1,3};
  printVec(currVec);
  std::cout << "NumPairs: " << s.numIdenticalPairs(currVec) << std::endl;
  
  currVec = {1,1,1,1};
  printVec(currVec);
  std::cout << "NumPairs: " << s.numIdenticalPairs(currVec) << std::endl;
  
  currVec = {1,2,3};
  printVec(currVec);
  std::cout << "NumPairs: " << s.numIdenticalPairs(currVec) << std::endl;
}
