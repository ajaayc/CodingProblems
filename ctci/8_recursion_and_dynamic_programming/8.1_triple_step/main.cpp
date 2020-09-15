#include <iostream>
#include <cassert>
#include <vector>
#include <string.h> //memset

using namespace std;

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}

class Solution{
public:
  virtual int countWays(int N) = 0;

  virtual void printMethod() = 0;

  virtual ~Solution(){}
};
/*
O(3^N) time solution, O(N) memory for recursion and memo array.
 */
class SolutionRecursive : public Solution{
public:
  virtual int countWays(int N){
    return countWaysHelper(N);
  }
  
  virtual int countWaysHelper(int N){
    if(N == 1)
      return 1;
    if(N == 2)
      return 2;
    if(N == 3)
      return 4;

    return countWaysHelper(N - 1) + countWaysHelper(N - 2) + countWaysHelper(N - 3);
  }

  virtual void printMethod(){
    std::cout << "--Recursive Solution--" << std::endl;
  }
};
  
/*
O(N) time solution, O(N) memory for recursion and memo array.
 */
class SolutionTopDownDP : public Solution{
  int* memo;
public:
  virtual int countWays(int N){
    memo = new int[N + 1];
    memset(memo, 0, (N + 1) * sizeof(int));
    int result = countWaysHelper(N);
    delete[] memo;
    memo = nullptr;

    return result;
  }

  virtual int countWaysHelper(int N){
    if(N == 1)
      return 1;
    if(N == 2)
      return 2;
    if(N == 3)
      return 4;

    if(memo[N] == 0){
      memo[N] = countWaysHelper(N - 1) + countWaysHelper(N - 2) + countWaysHelper(N - 3);
    }

    return memo[N];
  }

  virtual void printMethod(){
    std::cout << "--Top Down DP Solution--" << std::endl;
  }
};

/*
O(N) time solution, O(N) memory for memo array...don't need memory for any recursion.
 */
class SolutionBottomUpDP : public Solution{
  int* memo;
public:
  virtual int countWays(int N){
    memo = new int[N + 1];
    memset(memo, 0, (N + 1) * sizeof(int));
    int result = countWaysHelper(N);
    delete[] memo;
    memo = nullptr;

    return result;
  }

  virtual int countWaysHelper(int N){
    //We need the base cases for the case the caller
    //calls N = 1, or N = 2. In those cases, we would
    //get a seg fault if we didn't have these.
    if(N == 1)
      return 1;
    if(N == 2)
      return 2;
    if(N == 3)
      return 4;

    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    for(int i = 4; i <= N; ++i){
      memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }
    
    return memo[N];
  }

  virtual void printMethod(){
    std::cout << "--Bottom Up DP Solution--" << std::endl;
  }
};

/*
O(N) time solution, O(1) memory. Don't need a memoization array.
 */
class SolutionBottomUpDPOptimized : public Solution{
public:
  virtual int countWays(int N){
    return countWaysHelper(N);
  }

  virtual int countWaysHelper(int N){
    if(N == 1)
      return 1;
    if(N == 2)
      return 2;
    if(N == 3)
      return 4;

    int prev2 = 1, prev1 = 2, prev = 4;
    int curr = 0;
    
    for(int i = 4; i <= N; ++i){
      curr = prev2 + prev1 + prev;
      prev2 = prev1;
      prev1 = prev;
      prev = curr;
    }
    
    return curr;
  }

  virtual void printMethod(){
    std::cout << "--Bottom Up DP Optimized Solution--" << std::endl;
  }
};


void processTest(int N, std::vector<Solution*>& methods){
  std::cout << std::endl;
  std::cout << "N = " << N << std::endl;
  
  for(Solution* s : methods){
    s->printMethod();
    std::cout << s->countWays(N) << std::endl;
  }
}

int main(){
  Solution* s1 = new SolutionRecursive();
  Solution* s2 = new SolutionTopDownDP();
  Solution* s3 = new SolutionBottomUpDP();
  Solution* s4 = new SolutionBottomUpDPOptimized();
  std::vector<Solution*> methods = {s1, s2, s3, s4};
  
  /*
  processTest(1, methods);
  processTest(2, methods);
  processTest(3, methods);
  processTest(4, methods);
  processTest(5, methods);
  processTest(6, methods);
  processTest(7, methods);
  processTest(8, methods);
  */
  //processTest(38, methods);

  for(int N = 1; N <= 33; ++N){
    processTest(N, methods);
  }

  for(Solution* s : methods){
    delete s;
  }
}
