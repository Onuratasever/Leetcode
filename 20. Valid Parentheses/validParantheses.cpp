#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class validParantheses 
{
public:
    validParantheses() {
        // Constructor implementation
    }
    ~validParantheses() {
        // Destructor implementation
    }   

    // O(n) solution using stack
    // Extra space usage O(n) in the worst case
    // Stack is deque based. So cache miss can be high
    bool isValid(string s) 
    {
        stack<char> charStack;
        for(int i = 0; i < s.length(); i++)
        {
            char currentChar = s.at(i);
            if(currentChar == '(' || currentChar == '{' || currentChar == '[')
            {
                charStack.push(currentChar);
            }
            else if(currentChar == ')' || currentChar == '}' || currentChar == ']')
            {
                if(charStack.empty())
                    return false;

                char charTop = charStack.top();
                
                if((currentChar == ')' && charTop != '(') ||
                   (currentChar == '}' && charTop != '{') ||
                   (currentChar == ']' && charTop != '['))
                {
                    return false;
                }

                charStack.pop();

            }
        }

        return charStack.empty();
    }

    // O(n) solution using vector as stack
    // Extra space usage O(n) in the worst case
    // Vector is array based. So better cache locality
    bool isValidOptimized(string s) 
    {
        vector<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push_back(c);
            else {
                if (st.empty()) return false;
                char top = st.back();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                    return false;
                st.pop_back();
            }
        }
        return st.empty();
    }
};

int main() 
{
    std::cout << "This is a placeholder for the containsDuplicate3 solution." << std::endl;
    return 0;
}
