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

  //Helper recursive function for rotateMatInPlace
  void rotateMatInPlaceHelper(std::vector<std::vector<T>>& input, unsigned begin, unsigned end, unsigned size){
    //Base case. If size is odd, then begin == end will become true (i.e. the matrix core). If size is even, begin > end can become true.
    if(begin >= end){
      return;
    }
    //Do rotation algorithm. Rotate outer shell of matrix
    //Loop from begin up to but not including end. The reason for this is
    //that the end element is actually the beginning of the range of the
    //side that is being "rotated into." If we include end, we get a double
    //rotation on the corners of the matrix
    for(unsigned i = begin; i < end; ++i){
      //Get row, column of four locations
      unsigned topr, topc;
      unsigned rightr, rightc;
      unsigned bottomr, bottomc;
      unsigned leftr, leftc;
      
      //Top
      topr = begin; topc = i;
      //Right
      rightr = i; rightc = end;
      //Bottom
      bottomr = end; bottomc = end - i + begin;
      //Left
      leftr = end - i + begin; leftc = begin;

      //Cycle
      T tempLeftRotatedValue = input[leftr][leftc];
      
      //Bottom goes to left
      input[leftr][leftc] = input[bottomr][bottomc];

      //Right goes to bottom
      input[bottomr][bottomc] = input[rightr][rightc];
	
      //Top goes to right
      input[rightr][rightc] = input[topr][topc];

      //Temp (left) goes to top
      input[topr][topc] = tempLeftRotatedValue;
    }
    
    //Rotate on next shell inside matrix
    rotateMatInPlaceHelper(input, begin + 1, end - 1, size);
  }

  //Recursive solution
  //Uses O(N^2) time and O(1) memory.
  void rotateMatInPlace(std::vector<std::vector<T>>& input, unsigned size){
    rotateMatInPlaceHelper(input, 0, size - 1, size);
    return;
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
