#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() {
        
    }
    
    // O(n) push operation
    void push(int x) 
    {
        if(queue1.empty()) 
        {
            queue1.push(x);
            while(!queue2.empty()) 
            {
                queue1.push(queue2.front());
                queue2.pop();
            }
        } 
        else 
        {
            queue2.push(x);
            while(!queue1.empty()) 
            {
                queue2.push(queue1.front());
                queue1.pop();
            }
        }
    }
    
    // O(1) pop operation
    int pop() 
    {
        if(!queue1.empty()) 
        {
            int topElement = queue1.front();
            queue1.pop();
            return topElement;
        } 
        else 
        {
            int topElement = queue2.front();
            queue2.pop();
            return topElement;
        }
        
    }
    
    // O(1) top operation
    int top() 
    {
        if(!queue1.empty()) 
        {
            return queue1.front();
        } 
        else 
        {
            return queue2.front();
        }
        
    }
    
    // O(1) empty operation
    bool empty() 
    {
        return queue1.empty() && queue2.empty();
        
    }

    queue<int> queue1;
    queue<int> queue2;
};

int main() 
{
   return 0;
}