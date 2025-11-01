#include <iostream>
#include <vector>

class TwoSum 
{
public:
    TwoSum() {
        // Constructor implementation
    }
    ~TwoSum() {
        // Destructor implementation
    }

    std::vector<int> twoSum1(std::vector<int>& nums, int target) 
    {
        // Brute-force method implementation
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
    }

    // O(n) solution using hash map
    std::vector<int> twoSum2(std::vector<int>& nums, int target) 
    {
        // Method implementation
        std::unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); ++i) 
        {
            num_map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if(num_map.count(complement)>0 && num_map[complement] != i)
            {
                return {i, num_map[complement]};
            }
        }
        return {};
    }

    // O(n) solution using single pass hash map
    std::vector<int> twoSum3(std::vector<int>& nums, int target) {
        // Alternative method implementation
        std::unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); ++i) 
        {
            int complement = target - nums[i];
            if(num_map.count(complement)>0 && num_map[complement] != i)
            {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }

        return {};
    }

    // O(n) solution using a fixed-size lookup table
    // Memory is more efficient than hash map when the range of input numbers is known and limited
    // Unnecessary for large ranges or unknown ranges
    // Unnecessary when input size is small
    std::vector<int> twoSum4(std::vector<int>& nums, int target) 
    {
        std::vector<int> lookupTable(20001, -1); // Assuming numbers are in the range [-10000, 10000]

        for (int i = 0; i < nums.size(); ++i) 
        {
            int complement = target - nums[i];
            if(complement >= -10000 && complement <= 10000 && lookupTable[complement + 10000] != -1)
            {
                return {lookupTable[complement + 10000], i};
            }
            lookupTable[nums[i] + 10000] = i;
        }

        return {};
    }
};

int main() {
    TwoSum ts;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = ts.twoSum3(nums, target);
    std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;

    return 0;
}