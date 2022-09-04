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
   static bool comp(pair<int,int>a,pair<int,int>b)
    {   
        if(a.second!=b.second)
        return a.second<b.second;
        
        return a.first<b.first;
    }
    void verticalview(TreeNode *root, map<int, vector<pair<int,int>> >&m, int hd,int level)
{
    if (root == NULL)
        return;

    m[hd].push_back({root->val,level});

    verticalview(root->left, m, hd - 1,level+1);
    verticalview(root->right, m, hd + 1,level+1);

}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int> >res;
        map<int,vector<pair<int,int> > >m;
        verticalview(root,m,0,0);
        
        for (auto x : m)
    {
            vector<pair<int,int> >v;
            v.clear();
        for (auto y : x.second)
        {
            v.push_back(y);
        }
            sort(v.begin(),v.end(),comp);
            vector<int>z;
            for(auto x:v)
            {
                z.push_back(x.first);
            }
        res.push_back(z);
    }
        
        return res;
    }
};