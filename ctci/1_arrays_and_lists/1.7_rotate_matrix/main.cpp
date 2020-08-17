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

template <typename T>
void printMat(const std::vector<std::vector<T>>& mat){
  for(unsigned row = 0; row < mat.size(); ++row){
    printVec(mat[row]);
  }
}

template <typename T>
class Solution {
public:
  //This solution takes O(N^2) time, and O(N^2) memory, where N is the width or length
  //of the input matrix, which is assumed to be a square matrix.
  std::vector<std::vector<T>> rotateMat(const std::vector<std::vector<T>>& input, unsigned size) {
    T temp1;
    std::vector<T> temp2(size, temp1);
    std::vector<std::vector<T>> out(size, temp2);

    unsigned rowOutput, colOutput;
    
    //Loop through input
    for(unsigned currRow = 0; currRow < size; ++currRow){
      for(unsigned currCol = 0; currCol < size; ++currCol){
	//Populate value in output matrix
	colOutput = size - currRow - 1;
	rowOutput = currCol;

	out[rowOutput][colOutput] = input[currRow][currCol];
      }
    }
    
    return out;
  }

  //Recursive solution
  //Uses O(N^2) time and O(1) memory.
  void rotateMatInPlace(std::vector<std::vector<T>>& input, unsigned size){
    return;
  }


  //Helper recursive function for rotateMatInPlace
  void rotateMatInPlaceHelper(std::vector<std::vector<T>>& input, unsigned begin, unsigned end){
    //Base case. Need to review this
    if((begin == end) || (begin + 1 == end)){
      return;
    }
    //Do rotation algorithm

    //Call this function again with begin + 1 and end - 1 as the new begin and end.
  }
  
};

enum Choice{
  INPLACE,NOTINPLACE
};

//size is the number of rows = number of columns of the input,
//which is assumed to be a square matrix
template <typename T>
void processTest(std::vector<std::vector<T>> input, int size, Choice c){
  Solution<int> s;
  std::vector<std::vector<T>> output;
  if(c == INPLACE)
    std::cout << "--In Place Test Case--" << std::endl;
  else if(c == NOTINPLACE)
    std::cout << "--Not In Place Test Case--" << std::endl;    

  std::cout << "Input:\n";
  printMat(input);
  std::cout << "Output:\n";
  if(c == NOTINPLACE){
    output = s.rotateMat(input, size);
    printMat(output);
  }
  else if(c == INPLACE){
    s.rotateMatInPlace(input, size);
    printMat(input);
  }
  std::cout << std::endl;
}

int main(){
  std::vector<std::vector<int>> input;

  input = {{11}};
  processTest(input, input.size(), NOTINPLACE);
  processTest(input, input.size(), INPLACE);

  input = {{11,20},
	   {92,230}};
  processTest(input, input.size(), NOTINPLACE);
  processTest(input, input.size(), INPLACE);

  input = {{11,20,24},
	   {92,230,78},
	   {231,198,99}};  
  processTest(input, input.size(), NOTINPLACE);
  processTest(input, input.size(), INPLACE);

  input = {{11,20,24,781},
	   {92,230,78,293},
	   {231,198,99,167},
	   {1,7,14,189}};  
  processTest(input, input.size(), NOTINPLACE);
  processTest(input, input.size(), INPLACE);
}
