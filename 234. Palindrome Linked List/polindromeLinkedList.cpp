/*
 * Palindrome Linked List Solutions
 * --------------------------------
 * This file demonstrates multiple approaches to detect if a singly-linked list
 * is a palindrome. Each method has different time-space tradeoffs.
 * 
 * Methods:
 * 1. ReverseList Comparison (O(n) time, O(n) space)
 * 2. Stack-based Comparison (O(n) time, O(n) space)
 * 3. Fast-Slow Pointer (O(n) time, O(1) space)
 */

#include <stack>

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

    ListNode* cloneList(ListNode* head)
    {
        if(head == nullptr)
            return nullptr;
        ListNode* newHead = new ListNode(head->val);
        ListNode* tempNew = newHead;
        ListNode* tempOld = head->next;

        while(tempOld != nullptr)
        {
            tempNew->next = new ListNode(tempOld->val);
            tempNew = tempNew->next;
            tempOld = tempOld->next;
        }
        return newHead;
    }

    // Reverse the linked list and compare with the original
    // O(n) time complexity
    // O(n) space complexity due to reversed list
    // Reversed list can be other data structure to increase cache hits
    bool isPalindromeReverseList(ListNode* head) 
    {
        
        ListNode* clonedList = cloneList(head);
        ListNode* reverseHead = reverseList(clonedList);

        while(head != nullptr && reverseHead != nullptr)
        {
            if(head->val != reverseHead->val)
                return false;
            head = head->next;
            reverseHead = reverseHead->next;
        }
        return true;
    }

    // Using stack to store values of linked list
    // O(n) time complexity
    // O(n) space complexity due to stack
    // Stack approach increases cache misses due to LIFO memory pattern
    bool isPalindromeStack(ListNode* head)
    {
        std::stack<int> stk;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            stk.push(temp->val);
            temp = temp->next;
        }

        while(head != nullptr)
        {
            int topValue = stk.top();
            stk.pop();
            if(head->val != topValue)
                return false;
            head = head->next;
        }
        return true;
    }

    // Reverse given linked list
    // O(n) time complexity
    // O(1) space complexity
    ListNode* reverseList(ListNode* head) 
    {
        
        ListNode* previous = nullptr;

        while(head != nullptr)
        {
            ListNode* next = head->next;
            head->next = previous;
            previous = head;
            head = next;
        }
        return previous;
    }

    // Using fast and slow pointers to find middle of linked list
    // Reverse second half of linked list and compare with first half
    // O(n) time complexity
    // O(1) space complexity
    bool isPalindromeFastSlow(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
    
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reverseHead = reverseList(slow->next);

        while(reverseHead != nullptr)
        {
            if(head->val != reverseHead->val)
                return false;
            head = head->next;
            reverseHead = reverseHead->next;
        }
        return true;
    }
};