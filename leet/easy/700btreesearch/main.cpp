#include <queue>
#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        //If root is null, return NULL
        if(root == NULL || root->val == val){
            return root;
        }

        return (val > root->val ? searchBST(root->right, val) : searchBST(root->left, val));
    }
};

int main(){
    BTree t;
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

    TreeNode* root = t.getRootNode();
    cout << "Original Tree" << endl;
    print2D(root);


    Solution s;
    TreeNode* found = s.searchBST(root,22);
    cout << "Found the node" << endl;
    print2D(found);
}
