#include "minStack.h"

template <typename T>
void CTCI::minStack<T>::push(const T& elt){
  minStack<T>::stackNode n(elt);
  if(empty()){
    n.isMin = true;
    n.prevMin = 0;
    minIndex = 0;
    s.push_back(n);
    return;
  }

  s.push_back(n);
  
  //Check if new elt is smaller than current min
  if(s[minIndex].val > elt){
    unsigned prevMinIndex = minIndex;
    minIndex = s.size() - 1;
    s[minIndex].isMin = true;
    s[minIndex].prevMin = prevMinIndex;
  }
}

template <typename T>
void CTCI::minStack<T>::pop(){
  assert(!s.empty());
  //Check if the top is a min element.
  //If so, update the minimum
  const stackNode& topN = *(s.end() - 1);

  if(topN.isMin){
    minIndex = topN.prevMin;
  }

  s.pop_back();
}

template <typename T>
const T& CTCI::minStack<T>::top() const{
  return (s.end()-1)->val;
}

template <typename T>
const T& CTCI::minStack<T>::min() const{
  return s[minIndex].val;
}
    
template <typename T>
bool CTCI::minStack<T>::empty() const{
  return s.empty();
}

template <typename T>
unsigned CTCI::minStack<T>::size() const{
  return s.size();
}
