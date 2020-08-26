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
void processTest(CTCI::minStack<T>* s){
  cout << "Test 1" << endl;
  try{
    s->push(5);
    s->push(6);
    assert(s->min() == 5);

    s->push(4);
    assert(s->min() == 4);
    assert(s->top() == 4);
    s->pop();
    assert(s->min() == 5);
    s->pop();
    assert(s->min() == 5);
    assert(s->size() == 1);
    s->pop();
    assert(s->empty());
    cout << "Passed" << endl;
  }
  catch(const std::exception& e){
    cout << "Failed" << endl;
  }

  //Start over
  cout << "Test 2" << endl;
  try{
    s->push(10);
    assert(s->min() == 10);
    assert(s->top() == 10);
    s->push(11);
    s->push(7);
    s->push(20);
    s->push(2);
    s->push(-1);
    assert(s->min() == -1);
    s->push(-1);
    assert(s->min() == -1);
    s->pop();
    assert(s->top() == -1);
    s->pop();
    assert(s->min() == 2);
    s->pop();
    assert(s->min() == 7);
    s->pop();
    s->pop();
    assert(s->top() == 11);
    assert(s->min() == 10);
    s->pop();
    assert(s->size() == 1);
    assert(s->top() == 10);
    s->pop();
    assert(s->empty());
    cout << "Passed" << endl;
  }
  catch(const std::exception& e){
    cout << "Failed" << endl;
  }
  
  //Start over
  cout << "Test 3" << endl;
  try{
    s->push(1);
    assert(s->min() == 1);
    s->push(2);
    assert(s->min() == 1);
    s->push(1);
    assert(s->min() == 1);
    assert(s->top() == 1);
    s->pop();
    assert(s->min() == 1);
    assert(s->top() == 2);
    s->pop();
    assert(s->min() == 1);
    s->pop();
    assert(s->empty());
    cout << "Passed" << endl;
  }
  catch(const std::exception& e){
    cout << "Failed" << endl;
  }

  cout << "Test 4" << endl;
  try{
    s->push(5);
    s->push(6);
    s->push(7);
    s->push(8);
    s->push(3);
    s->push(4);
    s->push(1);
    s->push(111);
    s->push(1);
    s->pop();
    assert(s->min() == 1);
    assert(s->top() == 111);
    s->pop();
    assert(s->top() == 1);
    assert(s->min() == 1);
    s->pop();
    assert(s->top() == 4);
    assert(s->min() == 3);
    s->pop();
    s->pop();
    assert(s->min() == 5);
    assert(s->top() == 8);
    s->pop();
    s->pop();
    s->pop();
    assert(s->min() == 5);
    s->pop();
    assert(s->empty());
    cout << "Passed" << endl;
  }
  catch(const std::exception& e){
    cout << "Failed" << endl;
  }
}

int main(){
  CTCI::minStackBasic<int> s1;
  CTCI::minStackOptimal<int> s2;
  
  cout << "Basic Min Stack" << endl;
  processTest(&s1);
  cout << "Optimized Memory Min Stack" << endl;
  processTest(&s2);
}
