
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:

    ListNode* previous = nullptr;

    // Iterative solution
    // O(n) time complexity
    // O(1) space complexity
    ListNode* reverseList(ListNode* head) {
        
        while(head != nullptr)
        {
            ListNode* next = head->next;
            head->next = previous;
            previous = head;
            head = next;
        }
        return previous;
    }

    // Recursive solution
    // O(n) time complexity
    // O(n) space complexity due to call stack
    // Instead of passing previous as parameter, using class member to reduce function parameters but as a recursive method passing previous as parameter is more appropriate
    ListNode* reverseListRecursive(ListNode* head)
    {
        if(head == nullptr)
            return previous;
        ListNode* next = head->next;
        head->next = previous;
        previous = head;
        return reverseListRecursive(next);
    }
};