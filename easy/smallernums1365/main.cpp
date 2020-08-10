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

/*
  O(N Log N) time and O(N) memory, where N is nums.size().
  This solution creates a mapping of values in nums
  to the count of all values in nums that are lower.

  The bulk of the time complexity is in creating the mapping.
  Is the time complexity the best it can be? Do we need to 
  sort the values in nums (requires N log N time) or can
  sorting be avoided?
 */
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      vector<int> output(nums.size(), 0);
      std::map<int,int> countMap;

      //O(N Log N) to make map
      for(unsigned i = 0; i < nums.size(); ++i){
	++countMap[nums[i]];
      }

      int prevCount = 0;
      int count = 0;

      //O(N) to create cumulative map
      //Loop through countMap and make it a cumulative sum map
      //i.e. for each i in countMap.keys, countMap[i] = count
      //of all values in nums that are less than i.
      for(auto it = countMap.begin(); it != countMap.end(); ++it){
	prevCount = it->second;
	it->second = count;

	count += prevCount;
      }

      //Loop through intput and assign values to output based on the map
      for(unsigned i = 0; i < nums.size(); ++i){
	output[i] = countMap[nums[i]];
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
