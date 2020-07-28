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

 */
class Solution {
public:
  //Requires O(N) time and will require O(N) extra memory
  //n should be nums.size()/2
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> out;

    //Two pointers
    unsigned p1 = 0, p2 = n;
    while(p1 != (unsigned) n){
      out.push_back(nums[p1++]);
      out.push_back(nums[p2++]);
    }

    return out;
  }
  
};

int main(){
    Solution s;
    std::vector<int> input;
    std::vector<int> shuffled;

    input = {-1, 2};
    std::cout << "Input:\n";
    printVec(input);
    shuffled = s.shuffle(input, input.size()/2);
    std::cout << "Shuffled:\n";
    printVec(shuffled);

    input = {1, 2, 3, 4};
    std::cout << "Input:\n";
    printVec(input);
    shuffled = s.shuffle(input, input.size()/2);
    std::cout << "Shuffled:\n";
    printVec(shuffled);

    input = {-2, 5, 1, 11, 29, 34};
    std::cout << "Input:\n";
    printVec(input);
    shuffled = s.shuffle(input, input.size()/2);
    std::cout << "Shuffled:\n";
    printVec(shuffled);

    input = {-2, 5, -101, 11, 29, 23, 89, 92};
    std::cout << "Input:\n";
    printVec(input);
    shuffled = s.shuffle(input, input.size()/2);
    std::cout << "Shuffled:\n";
    printVec(shuffled);
}
