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
  //O(n) memory, O(n) time, where n is the size of nums
  //Worst case, nums is all unique, in which case countMap
  //will be size N or so. Best case, all the nums are the same
  //in which case, countMap may be size 1. Depends on how
  //the map is implemented in the STL.

  //The original question states that 1 <= nums[i] <= 100,
  //so we could argue that this will use O(1) memory.
  int numIdenticalPairs(vector<int>& nums) {
    //Map a number to the count of times it occurs in nums
    std::unordered_map<int,int> countMap;

    int numPairs = 0;
    
    for(unsigned i = 0; i < nums.size(); ++i){
      numPairs += countMap[nums[i]];
      ++countMap[nums[i]];
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
