//https://leetcode.com/problems/validate-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxValue(TreeNode* root){
        if(root->right==nullptr){
            return root->val;
        }
        return max(maxValue(root->right),root->val);
        return root->val;
    }
    int minValue(TreeNode* root){
        if(root->left==nullptr){
            return root->val;
        }
        return min(minValue(root->left),root->val);
        return root->val;    
        }
    bool isValidBST(TreeNode* root) {
        // base case
        if (root == nullptr)
            return true;
        // constraints
        if (root->left != nullptr && root->val <= maxValue(root->left))
            return false;
        if (root->right != nullptr && root->val >= minValue(root->right))
            return false;
        if (!isValidBST(root->left) || !isValidBST(root->right))
            return false;
        return true;
    }
};