#include <algorithm>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:

    // Recursive DFS approach
    // O(n) time complexity
    // O(h) space complexity due to call stack, h is the height of the tree
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return 1 + std::max(leftDepth, rightDepth);
    }

    // Iterative BFS approach
    // O(n) time complexity
    // O(w) space complexity, w is the maximum width of the tree
    int maxDepthBFS(TreeNode* root)
    {
        std::queue<TreeNode*> nodeQueue;
        if(root != nullptr)
            nodeQueue.push(root);
        int depth = 0;

        while(nodeQueue.empty() == false)
        {
            int levelSize = nodeQueue.size();

            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();

                if(currentNode->left != nullptr)
                    nodeQueue.push(currentNode->left);
                if(currentNode->right != nullptr)
                    nodeQueue.push(currentNode->right);
            }

            depth++;
        }

        return depth;
    }
};