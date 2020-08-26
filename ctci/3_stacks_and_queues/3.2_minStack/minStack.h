#ifndef MINSTACK_H
#define MINSTACK_H

#include <cassert>
#include <vector>
#include <stack>

using namespace std;

namespace CTCI{
  template <typename T>
  class minStack{
  public:
    //O(1) time
    virtual void push(const T& elt) = 0;

    //O(1) time
    virtual void pop() = 0;

    //O(1) time
    virtual const T& top() const = 0;

    //O(1) time
    virtual const T& min() const = 0;
    
    //O(1) time
    virtual bool empty() const = 0;

    //O(1) time
    virtual unsigned size() const = 0;
  };

  template <typename T>
  class minStackBasic : public minStack<T>{
  private:
    struct stackNode{
      T val;
      bool isMin;
      unsigned prevMin;

    stackNode(const T& val):val(val),isMin(false),prevMin(0){}
    };
      
    std::vector<stackNode> s;

    unsigned minIndex;

  public:
    virtual void push(const T& elt);

    //O(1) time
    virtual void pop();

    //O(1) time
    virtual const T& top() const;

    //O(1) time
    virtual const T& min() const;
    
    //O(1) time
    virtual bool empty() const;

    //O(1) time
    virtual unsigned size() const;
  };


  /*
    This minStack uses less memory. Instead of making each
    element store a boolean isMin and the index of the previous min
    if isMin is true, we use a separate stack to keep track of the
    sequence of mins for the main stack while the main stack
    just needs to store the actual stack elements without any
    extra information. Whenever we push a new min onto the main
    stack, we add a copy of it to the separate min stack, whose
    top always represents the min element. When we want to pop from
    the main stack, we check if the top is = to the current top of the min stack,
    signifying it's part of the sequence of minimums...and if this is true,
    we pop from both stacks.
   */
  template <typename T>
    class minStackOptimal : public minStack<T>{
  private:
    std::stack<T> mins;
    std::stack<T> s;      
    
  public:
    virtual void push(const T& elt);

    //O(1) time
    virtual void pop();

    //O(1) time
    virtual const T& top() const;

    //O(1) time
    virtual const T& min() const;
    
    //O(1) time
    virtual bool empty() const;

    //O(1) time
    virtual unsigned size() const;
  };
  
}

#endif /* MINSTACK_H */
