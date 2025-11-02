#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class validAnagram 
{
public:
    validAnagram() {
        // Constructor implementation
    }
    ~validAnagram() {
        // Destructor implementation
    }

    // O(n) solution using hash map
    // Extra space usage O(k) where k is the number of unique characters
    // Average O(1) time complexity for insert and find operations
    // Cache locality is worse than array because of hash map
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
            return false;

        unordered_map<char, int> charCountMap;

        for(char c : s)
        {
            charCountMap[c]++;
        }

        for(char c : t)
        {
            if(charCountMap.find(c) == charCountMap.end() || charCountMap[c] == 0)
                return false;
            charCountMap[c]--;
        }

        return true;    
    }

    // O(n) solution using fixed size array
    // Extra space usage O(1) because array size is fixed (26 for lowercase letters)
    // Better cache locality than hash map
    bool isAnagramOptimized(string s, string t) 
    {
        if(s.length() != t.length())
            return false;

        int charCount[26] = {0};

        for(char c : s)
        {
            charCount[c - 'a']++;
        }

        for(char c : t)
        {
            if(charCount[c - 'a'] == 0)
                return false;
            charCount[c - 'a']--;
        }

        return true;    
    }

    // O(n log n) solution using sorting
    // Extra space usage O(1) if in-place sort is used
    bool isAnagramSorting(string s, string t) 
    {
        if(s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;    
    }
};

int main() 
{
   return 0;
}