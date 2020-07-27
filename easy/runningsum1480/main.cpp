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
My solution takes O(N) time, where N is the number of elements
in the input array, nums.

It could be done in O(N^2) time by running a double for loop
that loops through all elements i of the output and sums all
of the elements from 0 to i in the input. This solution would
take O(N^2) time and would be doing lots of duplicated work since
it sums up the same numbers repeatedly.

We take advantage of the fact that output[i] = sum(nums[0]...nums[i]),
= sum(nums[0]...nums[i-1]) + nums[i]
= output[i-1] + nums[i]

output[0] is initialized to nums[0]
 */


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
      vector<int> r;
      if(nums.size() == 0)
	return r;
      
      r.resize(nums.size());
      r[0] = nums[0];

      for(unsigned i = 1; i < r.size(); ++i){
	r[i] = r[i-1] + nums[i];
      }

      return r;
    }
};

int main(){
    Solution s;
    std::vector<int> runsum;
    std::vector<int> input;

    input = {1, 2, 3, 4};
    runsum = s.runningSum(input);
    printVec(runsum);

    input = {-2, 5, 1, 11, 29};
    runsum = s.runningSum(input);
    printVec(runsum);

    input = {-2, 5, -101, 11, 29};
    runsum = s.runningSum(input);
    printVec(runsum);
}
