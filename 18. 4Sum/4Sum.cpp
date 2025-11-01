#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class FourSum
{
public:
    FourSum();
    ~FourSum();

    // O(n^3) solution using hash map
    // Bad memory usage because o(n^2) times of hash map
    // Bad run time because of cache misses of hash map
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        if (n < 4)
            return {};

        std::set<std::vector<int>> uniqueResults;

        for (int first = 0; first < n - 3; first++)
        {
            long long secondTarget = (long long)target - (long long)nums[first];

            for (int second = first + 1; second < n - 2; second++)
            {
                long long twoSumTarget = secondTarget - (long long)nums[second];
                unordered_map<long long, int> num_map;

                for (int third = second + 1; third < n; third++)
                {
                    long long complement = twoSumTarget - (long long)nums[third];

                    if (num_map.count(complement) && num_map[complement] != third)
                    {
                        std::vector<int> quad = {nums[first], nums[second], nums[third], (int)complement};
                        std::sort(quad.begin(), quad.end());
                        uniqueResults.insert(quad);
                    }

                    num_map[(long long)nums[third]] = third;
                }
            }
        }

        return std::vector<std::vector<int>>(uniqueResults.begin(), uniqueResults.end());
    }

    // O(n^3) solution using two-pointer technique  
    // Better memory usage because no hash map
    // Better run time because of better cache usage
    // No need to use set to avoid duplicates
    vector<vector<int>> fourSum2(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> result;
        if (n < 4)
            return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];

                    if (sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};


int main() 
{
    return 0;
}