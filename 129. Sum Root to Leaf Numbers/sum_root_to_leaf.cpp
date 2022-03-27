/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root)
    {
        //here, the preorder traversal makes sense most, because we want to process the parent nodes before we process the children nodes so that we can get the number for each leaf node         
        int sum = 0;////sum of all the numbers formed from root-to-leaf path (a leaf node is a node with no children)
        
        int num{0}; // initial value of the number as 0 as there is nothing above root
        sumNumbersUtil(root,sum, num); //sum is pass by reference 
        return sum; 
    }
    
/*
//1st method for dfs recusrsion call:recursion will be called just after updating the number/sum. also remember root should be checked in sumNumbersUtil for if it is not null else return :
    
    void sumNumbersUtil(TreeNode* root, int& sum, int num)
    {
        if(!root) return; //if root node is nullptr, return 0
        num = num* 10 + root->val;//update the leaf number. at first it will have root value
        if(!root->left && !root->right) //if reached at the leaf node, update the sum
        {
            sum += num;//accumulate the total 
            return;
        }
        
        //pre-order DEPTH FIRST SEARCH (DFS)
        //for preorder first call left and then root and then right
        if(root->left) sumNumbersUtil(root->left, sum, num); 
        if(root->right) sumNumbersUtil(root->right, sum, num);
    }
*/   
    
//2nd method for dfs recusrsion call:recursion can be called at the retrun also as sum of left and right as shown below by making fucntion return type as int:
    int sumNumbersUtil(TreeNode* root, int& sum, int num)
    {
        if(!root) return 0; //if root node is nullptr, return 0
        num = num* 10 + root->val; //update the leaf number. at first it will have root value
        if(!root->left && !root->right) //if reached at the leaf node, update the sum
        {
            sum += num;//accumulate the total sum
            //return;
        }
        
        //pre-order DEPTH FIRST SEARCH (DFS)
        //for preorder first call left and then root and then right
        //if(root->left) sumNumbersUtil(root->left, sum, num); 
        //if(root->right) sumNumbersUtil(root->right, sum, num);
        
        return sumNumbersUtil(root->left, sum, num) + sumNumbersUtil(root->right, sum, num);//recursive call (preorder): go all the way down to leaf    
    }
};
