#include "minStack.h"

//minStackBasic Implementations

template <typename T>
void CTCI::minStackBasic<T>::push(const T& elt){
  minStackBasic<T>::stackNode n(elt);
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
void CTCI::minStackBasic<T>::pop(){
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
const T& CTCI::minStackBasic<T>::top() const{
  return (s.end()-1)->val;
}

template <typename T>
const T& CTCI::minStackBasic<T>::min() const{
  return s[minIndex].val;
}
    
template <typename T>
bool CTCI::minStackBasic<T>::empty() const{
  return s.empty();
}

template <typename T>
unsigned CTCI::minStackBasic<T>::size() const{
  return s.size();
}

//minStackOptimal Implementations

template <typename T>
void CTCI::minStackOptimal<T>::push(const T& elt){
  if(empty()){
    s.push(elt);
    mins.push(elt);
    return;
  }

  s.push(elt);

  assert(!mins.empty());

  //Note that we use <= here instead of <. If we
  //used <, we could see serious bugs if two copies
  //of the same min element are pushed onto the main stack.
  if(elt <= mins.top()){
    mins.push(elt);
  }
  
  return;
}

template <typename T>
void CTCI::minStackOptimal<T>::pop(){
  assert(!s.empty());
  assert(!mins.empty());
  if(s.top() == mins.top()){
    mins.pop();
  }

  s.pop();
}

template <typename T>
const T& CTCI::minStackOptimal<T>::top() const{
  assert(!s.empty());
  return s.top();
}

template <typename T>
const T& CTCI::minStackOptimal<T>::min() const{
  assert(!s.empty());
  assert(!mins.empty());
  return mins.top();
}
    
template <typename T>
bool CTCI::minStackOptimal<T>::empty() const{
  return s.empty();
}

template <typename T>
unsigned CTCI::minStackOptimal<T>::size() const{
  return s.size();
}
