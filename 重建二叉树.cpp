/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int, int> mp;
    // 查找pre中的节点在vin中的位置
    int find( int pre ) {
        return mp[pre];
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        
		// init map
        for( int i=0 ; i<vin.size() ; i++ ) {
            mp[ vin[i] ] = i;
        }
        
        // work
        TreeNode* root = build(pre, 0, pre.size()-1, vin, 0, vin.size()-1 );
        return root;
    }
    
    TreeNode* build(vector<int> &pre, int pbeg, int pfin, vector<int> &vin, int vbeg, int vfin) {
        if( vbeg>vfin ) return NULL;	// 已经没有子树的情况
        
        // work
        int pos = find( pre[pbeg] );
        TreeNode* root = new TreeNode( pre[pbeg] );
        
        int len = pos - vbeg;	// 左子树的节点个数
        root->left = build(pre, pbeg+1, len, 	vin, vbeg, pos-1 );
        root->right = build(pre, pbeg+len+1, pfin, vin, pos+1, vfin );
          
        return root;
    }
};
