#include <queue>
#include <iostream>
#include <stack>
#define COUNT 10 

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val):val(val),left(NULL),right(NULL){}
};

class BTree{
    TreeNode* root;

    void cleanTree(TreeNode* curr){
        if(curr == NULL) return;

        cleanTree(curr->left);
        cleanTree(curr->right);
        delete curr;
        curr = NULL;
    }
    
public:
    BTree():root(NULL){}

    BTree(TreeNode* root):root(root){}

    ~BTree(){
        cleanTree(root);
    }

    bool isEmpty(){
        return root == NULL;
    }

    TreeNode* getRootNode(){
        return root;
    }
    
    void insert(int val){
        TreeNode* n = new TreeNode(val);
        if(root == NULL){
            root = n;
            return;
        }

        //Get destination
        TreeNode* curr = root;
        TreeNode* prev = NULL;

        bool isRight = false;
        while(curr != NULL){
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

            if(curr != NULL){
                std::cout << curr->val << std::endl;
                //Add left and right nodes if they're not null
                toPrint.push(curr->left);
                toPrint.push(curr->right);
            }
        }
    }

};

// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void print2DUtil(TreeNode *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->val<<"\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
  
// Wrapper over print2DUtil()  
void print2D(TreeNode *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}  

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* currNode = root;

        //Maintain a stack of nodes traversed so far. Push into
        //stack each time we go down in tree
        std::stack<TreeNode*> nodeStack;

        //Keep track of whether we're left or right of the root
        bool onLeft = true;
        
        //O(2n) = O(n) time
        //O(logn) avg, O(n) worst memory
        //Loop through all values
        for(unsigned currIndex = 1; currIndex < preorder.size(); ++currIndex){
            TreeNode* toInsert = new TreeNode(preorder[currIndex]);

            //Check if curr value is < or > than currNode
            if(preorder[currIndex] < currNode->val){
                //Push node onto stack before going down
                nodeStack.push(currNode);
                
                //Make this the left node
                currNode->left = toInsert;
                currNode = currNode->left;
            }
            else{
                //Go up in tree and find the ancestor that is as large as possible without
                //exceeding current node. Make this the right child of that node.
                //If root node is reached, then stop going up and make this
                //the right child of the root node. This step has to be linear
                //Can't use binary search to go up the tree nodes

                if(onLeft){
                    while(!nodeStack.empty() && nodeStack.top()->val < toInsert->val){
                        TreeNode* parent = nodeStack.top();
                        nodeStack.pop();

                        currNode = parent;
                    }
                    if(nodeStack.empty()){
                        onLeft = false;
                    }
                    
                }
                //If on right side of tree
                //Keep going up as long as node parents are increasing 
                else{
                    while(!nodeStack.empty() && nodeStack.top()->val > currNode->val){
                        TreeNode* parent = nodeStack.top();
                        nodeStack.pop();
                        currNode = parent;
                    }

                }
                nodeStack.push(currNode);
                currNode->right = toInsert;
                currNode = currNode->right;
            }
        }

        return root;
    }
};

int main(){
    //std::vector<int> preOrder = {8,5,1,7,10,12};
    //std::vector<int> preOrder = {8,5,1,7,10,9,12,11};

    //This test case causes my approach to fail completely. It seems that
    //keeping track of whether we're on the left or right side of the root
    //node is a bad idea in general.
    std::vector<int> preOrder = {12,10,3,0,1,6,16,13,15,14,21,20};
    
    Solution s;
    TreeNode* root = s.bstFromPreorder(preOrder);

    cout << "Constructed Tree" << endl;
    print2D(root);

    //Encapsulate in BTree so that memory is freed by BTree destructor
    BTree b(root);
}
