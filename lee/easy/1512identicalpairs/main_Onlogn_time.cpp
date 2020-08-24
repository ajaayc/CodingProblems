#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

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
  //O(n log n) time, O(1) memory, where n is the size of nums.
  //Sorts the array of nums and then 
  int numIdenticalPairs(vector<int>& nums) {
    int numPairs = 0;
    std::sort(nums.begin(), nums.end());

    unsigned j = 0;
    
    for(unsigned i = 1; i < nums.size(); ++i){
      if(nums[j] == nums[i]){
	numPairs += (i - j);
      }
      else{
	j = i;
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
