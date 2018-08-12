/**
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <vector>
 using namespace std;
 
 
 typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int>& pre,vector<int>& vin) {
        return reConstructBinaryTree1(pre,0,pre.size(),vin,0,vin.size());
    }
    TreeNode* reConstructBinaryTree(vector<int>& pre, int pp, int pe, vector<int>& vin, int vp, int ve)
    {
    	
        if (pp >= pe || vp >= ve) return NULL;
        TreeNode *root = new TreeNode(pre[pp]);
        int k = find(vin, pre[pp],vp,ve);
        int leftnum = k-vp;
        root->left = reConstructBinaryTree(pre,pp+1,pp+1+leftnum,vin,vp,k);
        root->right = reConstructBinaryTree(pre,pp+1+leftnum,pe,vin,k+1,ve);
        return root;
    }
    int find (vector<int>& vec, int key, int p, int e) {
        for (int i = p; i < e; i++) {
            if (vec[i] == key) {
                return i;
            }
        }
        return -1;
    }
    
};
void print(TreeNode* r) {
	if (r == NULL) return;
	print(r->left);
	cout << " " << r->val;
	print(r->right);
}
int main() {
	vector<int> pre = {1,2,4,3,5,6};
	vector<int> vin = {4,2,1,5,3,6};
	Solution a;
	TreeNode* root=a.reConstructBinaryTree(pre,vin);
	print(root);
}
