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
    void pruneTreeHelper(TreeNode*& currRoot, TreeNode* parent) {
        if(currRoot == NULL){
            return;
        }

        //Call pruneTreeHelper on children
        if(currRoot->left != NULL){
            pruneTreeHelper(currRoot->left,currRoot);
        }
        
        if(currRoot->right != NULL){
            pruneTreeHelper(currRoot->right,currRoot);
        }

        //Prune if this is a child node of value 0 and also check parent isn't NULL
        if(currRoot->left == NULL && currRoot->right == NULL && currRoot->val == 0){
            if(parent == NULL){
                delete currRoot; currRoot = NULL;
                return;
            }

            const TreeNode* currRootCp = currRoot;
            delete currRoot;
            //Prune from the parent
            if(parent->left == currRootCp){
                parent->left = NULL;
            }
            else if(parent->right == currRootCp){
                parent->right = NULL;
            }
        }
    }

    TreeNode* pruneTree(TreeNode* root) {
        pruneTreeHelper(root,NULL);
        return root;
    }
};

int main(){
   TreeNode* root = new TreeNode(1);
   root->left = new TreeNode(1);
   root->left->right = new TreeNode(0);
   root->left->left = new TreeNode(0);
   root->left->left->left = new TreeNode(0);
   root->left->left->left->left = new TreeNode(1);
   root->left->left->right = new TreeNode(0);
   root->left->left->right->left = new TreeNode(0);
   root->left->left->right->right = new TreeNode(0);
   root->left->left->right->right->right = new TreeNode(0);

   root->right = new TreeNode(1);
   root->right->left = new TreeNode(1);
   root->right->right = new TreeNode(0);
   root->right->right->left = new TreeNode(0);
   root->right->right->right = new TreeNode(0);
   root->right->right->left->left = new TreeNode(0);
   root->right->right->right->right = new TreeNode(1);

    cout << "Original Tree" << endl;
    print2D(root);

    Solution s;
    root = s.pruneTree(root);
    
    cout << "Tree after pruning" << endl;
    print2D(root);

    //Clean memory
    BTree b(root);

    TreeNode* root2 = new TreeNode(0);
    cout << "Original Tree2" << endl;
    print2D(root2);
    root2 = s.pruneTree(root2);
    cout << "Tree2 after pruning" << endl;
    print2D(root2);

    //Clean memory
    BTree b2(root2);

    TreeNode* root3 = new TreeNode(0);
    root3->right = new TreeNode(0);
    cout << "Original Tree3" << endl;
    print2D(root3);
    root3 = s.pruneTree(root3);
    cout << "Tree3 after pruning" << endl;
    print2D(root3);

    //Clean memory
    BTree b3(root3);

    TreeNode* root4 = new TreeNode(0);
    root4->right = new TreeNode(0);
    root4->left = new TreeNode(1);
    cout << "Original Tree4" << endl;
    print2D(root4);
    root4 = s.pruneTree(root4);
    cout << "Tree4 after pruning" << endl;
    print2D(root4);

    //Clean memory
    BTree b4(root4);
}
