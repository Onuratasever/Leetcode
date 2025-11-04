#include <iostream>
#include <stack>


using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack_in.push(x);
    }
    
    int pop() 
    {
        if(stack_out.empty()) 
        {
            while(!stack_in.empty()) 
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        int topElement = stack_out.top();
        stack_out.pop();
        return topElement;
    }
    
    int peek() 
    {
        if(stack_out.empty()) 
        {
            while(!stack_in.empty()) 
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        return stack_out.top();
    }
    
    bool empty() 
    {
        return stack_in.empty() && stack_out.empty();    
    }

    stack<int> stack_in;
    stack<int> stack_out;
};

int main() 
{
   return 0;
}