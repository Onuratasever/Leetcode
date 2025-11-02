#include <iostream>
#include <vector>

using namespace std;

class generateParantheses 
{
public:
    generateParantheses() {
        // Constructor implementation
    }
    ~generateParantheses() {
        // Destructor implementation
    }   

    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
        generateParenthesisHelper("", 0, 0, result, n);
        return result;
    }

    void generateParenthesisHelper(const string& current, int openCount, int closeCount, vector<string>& result, int maxPairs)
    {
        if(openCount == maxPairs && closeCount == maxPairs)
        {
            result.push_back(current);
            return;
        }

        if(openCount < maxPairs)
        {
            generateParenthesisHelper(current + "(", openCount + 1, closeCount, result, maxPairs);
        }
        if(closeCount < openCount)
        {
            generateParenthesisHelper(current + ")", openCount, closeCount + 1, result, maxPairs);
        }
    }

    // Optimized version to reduce string copying
    // Uses a reference to a mutable string
    void generateParenthesisHelper(string& current, int openCount, int closeCount, vector<string>& result, int maxPairs)
    {
        if(openCount == maxPairs && closeCount == maxPairs)
        {
            result.push_back(current);
            return;
        }

        if(openCount < maxPairs)
        {
            current.push_back('(');
            generateParenthesisHelper(current, openCount + 1, closeCount, result, maxPairs);
            current.pop_back();
        }
        if(closeCount < openCount)
        {
            current.push_back(')');
            generateParenthesisHelper(current, openCount, closeCount + 1, result, maxPairs);
            current.pop_back();
        }
    }
};

int main() 
{
    return 0;
}