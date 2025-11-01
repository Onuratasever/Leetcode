#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class containsDuplicate 
{
public:
    containsDuplicate() {
        // Constructor implementation
    }
    ~containsDuplicate() {
        // Destructor implementation
    }       

    bool containsDuplicateFunc(vector<int>& nums) 
    {
        unordered_set<int> num_set;

        for (const int& num : nums) 
        {
            if (num_set.find(num) != num_set.end()) 
            {
                return true;
            }
            num_set.insert(num);
        }

        return false;
    }
};

int main() 
{
    return 0;
}