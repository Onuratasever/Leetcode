#include <iostream>
#include <vector>
#include <unordered_map>    
#include <unordered_set>

using namespace std;

class containsDuplicate2 
{
public:
    containsDuplicate2() {
        // Constructor implementation
    }
    ~containsDuplicate2() {
        // Destructor implementation
    }
    
    // O(n) solution using hash map
    // Extra space usage O(n)
    // Average O(1) time complexity for insert and find operations
    // Cache locality is worse than sorting because of hash map
    // Run time is worse than sorting because of hash map overhead
    // Branch prediction is worse than sorting because of hash map
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> lastSeenIndex;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (lastSeenIndex.find(nums[i]) != lastSeenIndex.end())
            {
                if (i - lastSeenIndex[nums[i]] <= k)
                {
                    return true;
                }
            }
            lastSeenIndex[nums[i]] = i;
        }
        return false;    
    }

    // Contigous memory usage is better than hash map
    // Cache locality is better than hash map
    // O(n log n) solution using sorting
    // Extra space usage O(n)
    // Less instruction overhead than hash map
    // Branch prediction is better than hash map
    bool containsNearbyDuplicateSort(vector<int>& nums, int k) 
    {
        vector<pair<int, int>> numIndexPairs;
        numIndexPairs.reserve(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) 
        {
            numIndexPairs.emplace_back(nums[i], i);
        }
        
        sort(numIndexPairs.begin(), numIndexPairs.end()); // Sort by first element of pair (the number)
        
        for (size_t i = 1; i < numIndexPairs.size(); ++i) 
        {
            if (numIndexPairs[i].first == numIndexPairs[i - 1].first) 
            {
                if (numIndexPairs[i].second - numIndexPairs[i - 1].second <= k) 
                {
                    return true;
                }
            }
        }
        
        return false;    
    }

    // O(n) solution using sliding window and hash set
    // Extra space usage O(min(n, k))
    // Average O(1) time complexity for insert and find operations
    // Cache locality is worse than sorting because of hash set
    // if k is small, better than hash map because of cache locality and less instruction overhead
    // Each step has one insert + one erase
    bool containsNearbyDuplicateSlidingWindow(vector<int>& nums, int k) 
    {
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (window.find(nums[i]) != window.end()) 
            {
                return true;
            }
            window.insert(nums[i]);
            if (window.size() > k) 
            {
                window.erase(nums[i - k]);
            }
        }
        return false;    
    }
};

int main() 
{
    return 0;
}