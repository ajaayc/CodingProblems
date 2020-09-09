#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}

//TODO Implement Alternate Solution
/*
What if we do a topological sort by storing in each node the number
of nodes that it depends on? Maintain a queue of nodes to be processed.
Start off by adding the nodes with 0 dependencies to the queue.
While queue is not empty, get the front element, consider it built,
decrement number of dependencies for all of its children, and if one of
the children would then have 0 dependencies, add it to the queue.
If the queue is empty but there are still nodes that haven't been built
yet i.e. they have more than 0 dependencies, then we have a build error i.e.
a cycle. This is because we know that we have processed as many nodes possible
and satisfied as many dependencies as we possibly could...if there are still nodes
that have dependencies even after the algorithm, that implies they are contained
within their own cycles and there was no way to reach them in the build order.

See CTCI Pg 250 Solution 1 for reference. The algorithm I implemented here
is CTCI's suggested Solution 2 for this problem.
*/

template <typename T>
class Graph{
public:
  struct Node{
    T val;
    std::vector<Node*> neighbors;

    Node():val(T()){}
    Node(T valIn):val(valIn){}
  };

  //Array of nodes
  std::vector<Node> nodes;
  const unsigned numNodes;

  //Map of T to its index in the nodes array
  std::unordered_map<T,unsigned> nodeIndexMap;

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

/*
O(V) space. This is a recursive algorithm, so in the worst case, the 
dependency graph is a stick, causing the recursion to go down V levels
O(Max(V,E)) time. This algorithm is a graph traversal algorithm. If there
are more edges than vertices, the complexity is O(E). If there are more
vertices than edges, the complexity is O(V).
 */
template <typename T>
class Solution {
public:
  bool getBuildOrder(const Graph<T>& g, std::vector<T>& orderOutput){
    std::unordered_map<T, bool> isBuilt;
    //Populate isBuilt with all false
    for(const typename Graph<T>::Node& currNode : g.nodes){
      isBuilt[currNode.val] = false;
    }

    std::unordered_set<T> currPath;

    bool buildError = false;
    
    for(unsigned i = 0; i < g.numNodes; ++i){
      const typename Graph<T>::Node& currNode = g.nodes[i];
      if(!isBuilt[currNode.val]){
	  currPath.insert(currNode.val);
	  buildNode(currNode, g, orderOutput, isBuilt, currPath, buildError);
	  currPath.erase(currNode.val);

	  if(buildError)
	    return buildError;

	  isBuilt[currNode.val] = true;
	  orderOutput.push_back(currNode.val);
	}
    }

    return buildError;
  }
private:
  void buildNode(const typename Graph<T>::Node& currNode, const Graph<T>& g, std::vector<T>& orderOutput, std::unordered_map<T, bool>& isBuilt, std::unordered_set<T>& currPath, bool& buildError){

    //Build the neighbors of N
    for(const typename Graph<T>::Node* neighbor : currNode.neighbors){
      if(!isBuilt[neighbor->val]){

	//Check for cycle
	if(currPath.find(neighbor->val) != currPath.end()){
	  buildError = true;
	  return;
	}

	currPath.insert(neighbor->val);
	buildNode(*neighbor, g, orderOutput, isBuilt, currPath, buildError);
	currPath.erase(neighbor->val);
	if(buildError){
	  return;
	}

	isBuilt[neighbor->val] = true;

	orderOutput.push_back(neighbor->val);
      }
    }
  }
};

template <typename T>
void processTest(const std::vector<T>& projects, const std::vector<vector<T>> dependencies){
  Graph<T> g(projects, dependencies);
  std::cout << g << std::endl;
  Solution<T> s;
  std::cout << "--Build Order--" << std::endl;

  std::vector<T> orderOutput;
  bool buildErrorExists = s.getBuildOrder(g, orderOutput);

  if(!buildErrorExists)
    printVec(orderOutput);
  else
    std::cout << "No valid build order." << std::endl;
}


int main(){
  std::vector<char> projects;
  std::vector<vector<char>> dependencies;

  projects = {'a','b','c','d','e','f','g'};
  dependencies = {{'d','a'},{'b','f'},{'d','b'},{'a','f'},{'c','d'}};
  processTest(projects, dependencies);
  
  projects = {'a','b','c','d'};
  dependencies = {{'a','b'},{'b','c'},{'c','d'},{'d','b'}};
  processTest(projects, dependencies);
}
