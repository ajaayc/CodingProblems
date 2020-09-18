#include <iostream>
#include <iomanip>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

#define THREE 3
#define FIVE 5
#define FIFTEEN 15

std::mutex m1;
std::queue<unsigned> numbers3Check;
std::condition_variable_any cv1;

std::mutex m2;
std::queue<unsigned> numbers5Check;
std::condition_variable_any cv2;

std::mutex m3;
std::queue<unsigned> numbers35Check;
std::condition_variable_any cv3;

std::mutex coutlock;

void divCheck(int numDiv, string message, std::queue<unsigned>* sourceQueue, std::mutex* sourceQueueMutex, std::condition_variable_any* sourceQueueCV, std::queue<unsigned>* destQueue, std::mutex* destQueueMutex, std::condition_variable_any* destQueueCV){
  while(true){

    sourceQueueMutex->lock();

    while(sourceQueue->empty()){
      sourceQueueCV->wait(*sourceQueueMutex);
    }

    unsigned next = sourceQueue->front();
    sourceQueue->pop();

    sourceQueueMutex->unlock();

    //3 and 5 threads should not print numbers divisible by 15
    if(numDiv != FIFTEEN && next % numDiv == 0 && next % FIFTEEN != 0){
      coutlock.lock();
      cout << std::setw(10) << next << std::setw(10) << message << endl;
      coutlock.unlock();
    }

    //15 thread should print numbers divisible by 15
    if(numDiv == FIFTEEN && next % numDiv == 0){
      coutlock.lock();
      cout << std::setw(10) << next << std::setw(10) << message << endl;
      coutlock.unlock();
    }

    //Populate next queue, if it exists
    if(destQueue != nullptr){
      destQueueMutex->lock();
      destQueue->push(next);
      destQueueMutex->unlock();

      destQueueCV->notify_all();
    }
  }

}



//Thread to produce numbers iteratively
void numProduction(){
  unsigned i = 0;
  while(i >= 0){
    ++i;
    m1.lock();
    numbers3Check.push(i);
    m1.unlock();

    cv1.notify_all();

    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }
}


//Thread to check divisibility by 3
void div3Check(){
  divCheck(THREE, "Fizz", &numbers3Check, &m1, &cv1, &numbers5Check, &m2, &cv2);
}


//Thread to check divisibility by 5
void div5Check(){
  divCheck(FIVE, "Buzz", &numbers5Check, &m2, &cv2, &numbers35Check, &m3, &cv3);
}


//Thread to check divisibility by 3 and 5
void div35Check(){
  divCheck(FIFTEEN, "FizzBuzz", &numbers35Check, &m3, &cv3, nullptr, nullptr, nullptr);
}

int main(){
  std::thread t1(numProduction);
  std::thread t2(div3Check);
  std::thread t3(div5Check);
  std::thread t4(div35Check);
  
  t1.join();
  t2.join();
  t3.join();
  t4.join();

  return 0;
}
