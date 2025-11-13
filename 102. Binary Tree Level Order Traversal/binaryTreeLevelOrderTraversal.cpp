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

    //DFS approach
    //O(n) time complexity
    //O(h) space complexity due to call stack, h is the height of the tree
    //Worst case space complexity O(n) for skewed tree
    //Best case space complexity O(log n) for balanced tree
    vector<vector<int>> levelOrderDFS(TreeNode* root)
    {
        vector<vector<int>> result;
        levelOrderDFSHelper(root, 0, result);
        return result;
    } 

    void levelOrderDFSHelper(TreeNode* node, int level, vector<vector<int>>& result)
    {
        if(node == nullptr)
            return;

        // Level is known
        // create vector if it is not exist
        if(result.size() == level)
        {
            result.push_back(vector<int>());
        }
        result[level].push_back(node->val);

        levelOrderDFSHelper(node->left, level + 1, result);
        levelOrderDFSHelper(node->right, level + 1, result);
    }
};