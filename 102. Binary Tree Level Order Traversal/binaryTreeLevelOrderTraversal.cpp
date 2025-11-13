#include <vector>
#include <queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution 
{
public:

    //O(n) time complexity
    //O(w) space complexity, w is the maximum width of the tree which is n/2 for a balanced tree
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> nodeQueue;
        vector<vector<int>> result;

        if(root != nullptr)
            nodeQueue.push(root);

        while(!nodeQueue.empty())
        {
            vector<int> currentLevel;
            int levelSize = nodeQueue.size();
            
            currentLevel.reserve(levelSize);

            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                currentLevel.push_back(currentNode->val);

                if(currentNode->left != nullptr)
                    nodeQueue.push(currentNode->left);
                if(currentNode->right != nullptr)
                    nodeQueue.push(currentNode->right);
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};