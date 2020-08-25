#include <iostream>
#include <cassert>
#include "minStack.cpp"

using namespace std;

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}





template <typename T>
void processTest(std::vector<T>& input){
  std::cout << "Input:\n";

  std::cout << "Output:\n";

}

int main(){
  CTCI::minStack<int> s;
  s.push(5);
  s.push(6);
  assert(s.min() == 5);

  s.push(4);
  assert(s.min() == 4);
  assert(s.top() == 4);
  s.pop();
  assert(s.min() == 5);
  s.pop();
  assert(s.min() == 5);
  assert(s.size() == 1);
  s.pop();
  assert(s.empty());

  //Start over
  s.push(10);
  assert(s.min() == 10);
  assert(s.top() == 10);
  s.push(11);
  s.push(7);
  s.push(20);
  s.push(2);
  s.push(-1);
  assert(s.min() == -1);
  s.push(-1);
  assert(s.min() == -1);
  s.pop();
  assert(s.top() == -1);
  s.pop();
  assert(s.min() == 2);
  s.pop();
  assert(s.min() == 7);
  s.pop();
  s.pop();
  assert(s.top() == 11);
  assert(s.min() == 10);
  s.pop();
  assert(s.size() == 1);
  assert(s.top() == 10);
  s.pop();
  assert(s.empty());
}
