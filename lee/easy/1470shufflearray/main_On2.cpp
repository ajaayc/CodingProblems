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
  //Requires O(N^2) time and will require O(1) memory
  //n should be nums.size()/2
  //This method utilizes insertions similar to those done
  //in the insertion sort algorithm to shuffle the array in
  //place
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> out;

    unsigned p1 = 1, p2 = n;

    int temp;
    while(p1 < p2){
      temp = nums[p2];

      for(unsigned i = p2 - 1; i >= p1; --i){
	nums[i+1] = nums[i];
      }
      nums[p1] = temp;

      p1 += 2;
      p2++;
    }

    //Defeats the purpose of in-place shuffle since we
    //still have to do an O(n) copy
    out = nums;
    
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
