#include <queue>
#include <iostream>
#include <stack>
#include <limits>
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

//This solution uses O(log n) avg, O(n) worst case memory for stack frames due to the recursion
//It takes O(n) time since it traverses each node at most twice
class Solution {
public:
    void bstFromPreorder(const vector<int>& preorder, int& currIndex, const int lb, const int rb,TreeNode* const currNode) {
        if(currIndex >= static_cast<int>(preorder.size())) return;
        
        //Go to the left
        if(preorder[currIndex] < currNode->val && lb < preorder[currIndex] && preorder[currIndex] < rb){
            TreeNode* node2Add = new TreeNode(preorder[currIndex]);
            int newRb = currNode->val;
            currNode->left = node2Add;
            TreeNode* childNode = currNode->left;
            bstFromPreorder(preorder, ++currIndex, lb, newRb, childNode);
        }

        if(currIndex >= static_cast<int>(preorder.size())) return;

        //Go to the right
        if(preorder[currIndex] >= currNode->val && lb < preorder[currIndex] && preorder[currIndex] < rb){
            TreeNode* node2Add = new TreeNode(preorder[currIndex]);
            int newLb = currNode->val;
            currNode->right = node2Add;
            TreeNode* childNode = currNode->right;
            bstFromPreorder(preorder, ++currIndex, newLb, rb, childNode);
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1)
            return root;
        
        int currIndex = 1;
        bstFromPreorder(preorder,currIndex,std::numeric_limits<int>::min(),std::numeric_limits<int>::max(),root);

        return root;
    }
};

int main(){
    std::vector<int> preOrder = {8,5,1,7,10,12};
    //std::vector<int> preOrder = {8,5,1,7,10,9,12,11};
    //std::vector<int> preOrder = {12,10,3,0,1,6,16,13,15,14,21,20};
    
    Solution s;
    TreeNode* root = s.bstFromPreorder(preOrder);

    cout << "Constructed Tree" << endl;
    print2D(root);

    //Encapsulate in BTree so that memory is freed by BTree destructor
    BTree b(root);
}
