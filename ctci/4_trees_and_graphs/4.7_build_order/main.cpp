#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}

template <typename T>
class Graph{
private:
  struct Node{
    T val;
    std::vector<Node*> neighbors;
    bool isVisited;

    Node():val(T()), isVisited(false){}
    Node(T valIn):val(valIn), isVisited(false){}
  };


  //Array of nodes
  std::vector<Node> nodes;
  const unsigned numNodes;

  //Map of T to its index in the nodes array
  std::unordered_map<T,unsigned> nodeIndexMap;
      
public:
  Graph(const std::vector<T>& nodesInput, const std::vector<std::vector<T>>& edges):numNodes(nodesInput.size()){
    this->nodes.resize(nodesInput.size());
    
    //Populate nodes
    for(unsigned i = 0; i < numNodes; ++i){
      this->nodes[i] = Node(nodesInput[i]);
      nodeIndexMap[nodesInput[i]] = i;
    }

    //Populate edges
    for(unsigned i = 0; i < edges.size(); ++i){
      const std::vector<T>& currEdge = edges[i];
      T node1 = currEdge[0];
      T node2 = currEdge[1];

      Node& node1N = this->nodes[nodeIndexMap[node1]];
      Node* node2N = &(this->nodes[nodeIndexMap[node2]]);
      node1N.neighbors.push_back(node2N);
    }
  }

  ~Graph(){}
  
  void resetGraph(){
    for(unsigned i = 0; i < numNodes; ++i){
      nodes[i].isVisited = false;
    }
  }

  friend ostream& operator<<(ostream& os, const Graph<T>& g){
    for(auto n : g.nodes){
      os << n.val << ": ";
      for(auto neighbor: n.neighbors){
	os << neighbor->val << " ";
      }
      os << endl;
    }
    
    return os;
  }
  
};


template <typename T>
void processTest(const std::vector<T>& projects, const std::vector<vector<T>> dependencies){
  Graph<T> g(projects, dependencies);
  std::cout << g << std::endl;
}


int main(){
  std::vector<char> projects;
  std::vector<vector<char>> dependencies;

  projects = {'a','b','c','d','e','f','g'};
  dependencies = {{'d','a'},{'b','f'},{'d','b'},{'a','f'},{'c','d'}};

  processTest(projects, dependencies);
  
}
