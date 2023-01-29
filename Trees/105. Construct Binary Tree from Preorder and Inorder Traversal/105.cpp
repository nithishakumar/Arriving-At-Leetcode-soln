#include<iostream>
#include<vector>
#include<unordered_map>


struct TreeNode {
    *int val;
    *TreeNode* left;
    *TreeNode* right;
    *TreeNode() : val(0), left(nullptr), right(nullptr) {}
    *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    *TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    *
};


// O(n) time, O(n) memory
unordered_map<int, int> inelt2idx;
TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int pstart, int pend, int istart, int iend) {
    if (iend < istart || pend < pstart) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[pstart]);
    int rootIdx = inelt2idx[preorder[pstart]];
    int numLeftElts = rootIdx - istart;
    root->left = recursion(preorder, inorder, pstart + 1, pstart + numLeftElts, istart, rootIdx - 1);
    root->right = recursion(preorder, inorder, pstart + numLeftElts + 1, pend, rootIdx + 1, iend);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
        inelt2idx[inorder[i]] = i;
    }
    return recursion(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}