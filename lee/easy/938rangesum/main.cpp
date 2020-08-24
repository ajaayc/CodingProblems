#include <queue>
#include <iostream>

using namespace std;

template <typename T>
class BTree{
    struct TreeNode{
        T val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(T val):val(val),left(nullptr),right(nullptr){}
    };

    void cleanTree(TreeNode* curr){
        if(curr == nullptr) return;

        cleanTree(curr->left);
        cleanTree(curr->right);
        delete curr;
        curr = nullptr;
    }
    
public:
    TreeNode* root;
    
    BTree():root(nullptr){}

    ~BTree(){
        cleanTree(root);
    }

    bool isEmpty(){
        return root == nullptr;
    }
   
     int maxDepth(){
        if(root == nullptr) return 0;
        int maxHeight = 0, currHeight = 0;

        depthFirstTraverse(root,maxHeight,currHeight);

        return maxHeight;
    }
private:
    void depthFirstTraverse(TreeNode* curr, int& maxHeight, int& currHeight){
        ++currHeight;
        //If currHeight > maxHeight, update maxHeight
        if(currHeight > maxHeight){
            maxHeight = currHeight;
        }

        //Call traverse left, Call traverse on right
        if(curr->left != nullptr){
            depthFirstTraverse(curr->left,maxHeight,currHeight);
            --currHeight;
        }
        if(curr->right != nullptr){
            depthFirstTraverse(curr->right,maxHeight,currHeight);
            --currHeight;
        }
    }
private:
    //currTreeNode is current TreeNode we're looking at in tree
    //currLevel is current level we're on. Root is level 1
    void leftMost(int& levelOfLeftMost, T& nodeValOfLeftMost, TreeNode* currNode, int& currLevel){
        ++currLevel;

        //Base Case:
        //If left and right node are nullptr, then the leftmost node is this node itself
        if(currNode->left == nullptr && currNode->right == nullptr){
            levelOfLeftMost = currLevel;
            nodeValOfLeftMost = currNode->val;
            --currLevel;
            return;
        }

        //At least one of left and right nodes has a value. Possibly both
        int leftTreeLowestLevel, rightTreeLowestLevel;
        T leftTreeLeftMostNode;
        T rightTreeLeftMostNode;

        if(currNode->left != nullptr){
            leftMost(leftTreeLowestLevel, leftTreeLeftMostNode, currNode->left, currLevel);
        }
        else /* leftNode is nullptr and rightNode has something*/{
            leftTreeLowestLevel = -5;
            leftTreeLeftMostNode = T();
        }
        
        if(currNode->right != nullptr){
            leftMost(rightTreeLowestLevel, rightTreeLeftMostNode, currNode->right, currLevel);
        }
        else /* leftNode has something and rightNode is nullptr*/{
            rightTreeLowestLevel = -5;
            rightTreeLeftMostNode = T();
        }

        //Could simply following comparison if only a left or a right node exists.
        //In that case levelOfLeftMost would just be the answer to the leftTree
        //or the rightTree respectively. Just didn't feel like writing this.

        //Compare the results of left and right tree
        //If left tree lower than right tree, we're good
        if(leftTreeLowestLevel >= rightTreeLowestLevel){
            levelOfLeftMost = leftTreeLowestLevel;
            nodeValOfLeftMost = leftTreeLeftMostNode;
        }
        else{
            levelOfLeftMost = rightTreeLowestLevel;
            nodeValOfLeftMost = rightTreeLeftMostNode;
        }

        --currLevel;
        return;
    }
    
public:
    //Finds the bottom leftmost value
    T findBottomLeftValue(){
        if(root == nullptr) return T();

        int levelOfLeftMost;
        T nodeValOfLeftMost;
        int currLevel = 0;
        
        leftMost(levelOfLeftMost, nodeValOfLeftMost, root, currLevel);

        return nodeValOfLeftMost;
    }
    
    void insert(T val){
        TreeNode* n = new TreeNode(val);
        if(root == nullptr){
            root = n;
            return;
        }

        //Get destination
        TreeNode* curr = root;
        TreeNode* prev = nullptr;

        bool isRight = false;
        while(curr != nullptr){
            prev = curr;

            if(val > curr->val){
                curr = curr->right;
                isRight = true;
            }
            else{
                curr = curr->left;
                isRight = false;
            }
        }
        //Target
        TreeNode*& target = (isRight ? prev->right : prev->left);
        
        target = n;
    }

    void printTreeInOrder(){
        if (this->isEmpty()) return;

        std::queue<TreeNode*> toPrint;

        toPrint.push(root);
        while(!toPrint.empty()){
            TreeNode* curr = toPrint.front();
            toPrint.pop();

            if(curr != nullptr){
                std::cout << curr->val << std::endl;
                //Add left and right nodes if they're not null
                toPrint.push(curr->left);
                toPrint.push(curr->right);
            }
        }
    }

    //DFS search
    //BFS search


    //TODO: This function isn't done
    //Binary search. Returns node containing desired value. Or returns
    //reference to where the value should go, which can be used with insert
    TreeNode* bSearch(T val){
        if(this->isEmpty()) return root;

        TreeNode* curr = root;

        while(curr !=nullptr){
            if(curr->val == val){
                return curr;
            }

            if(val > root.val){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        
        return curr;
    }

    //TODO: Implement tree balance

    //Finds the sum of values of nodes whose values are between L and R.
    int rangeSumBST(TreeNode* root, T L, T R) {
        //Do a breadth first tree traversal
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        int sum = 0;
        
        while(!nodeQueue.empty()){
            //Get next element
            TreeNode* next = nodeQueue.front();
            nodeQueue.pop();

            //Check if value of node is in the range
            if(L <= next->val && next->val <= R){
                sum += next->val;
            }
            
            //Push left and right child
            if(next->left != nullptr)
                nodeQueue.push(next->left);
            if(next->right != nullptr)
                nodeQueue.push(next->right);
        }

        return sum;
    }
    
};



int main(){
    BTree<int> t;
    t.insert(39);
    t.insert(23);
    t.insert(1);
    t.insert(9332);
    t.insert(82);
    t.insert(21);
    t.insert(89);
    t.insert(94);
    t.insert(71);
    t.insert(95);
    t.insert(20);
    t.insert(19);
    t.insert(18);

    t.printTreeInOrder();
    cout << "Max depth: " << t.maxDepth() << endl;

    int val = t.findBottomLeftValue();
    cout << "Left most node: " << val << endl;

    int rangeSum = t.rangeSumBST(t.root,1,50);
    cout << "Range sum: " << rangeSum << endl;
}
