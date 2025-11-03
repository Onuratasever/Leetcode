#include <iostream>
#include <vector>

using namespace std;

class groupAnagrams 
{
public:
    groupAnagrams() {
        // Constructor implementation
    }
    ~groupAnagrams() {
        // Destructor implementation
    }   
    vector<vector<string>> groupAnagramsFunc(vector<string>& strs) 
    {
        vector<vector<string>> result;
        vector<vector<int>> charCountVectors(strs.size(), vector<int>(26, 0));

        for (size_t i = 0; i < strs.size(); ++i) 
        {
            for (char c : strs[i]) 
            {
                charCountVectors[i][c - 'a']++;
            }
        }

        vector<bool> visited(strs.size(), false);
        for (size_t i = 0; i < strs.size(); ++i) 
        {
            if (visited[i]) 
                continue;

            vector<string> anagramGroup;
            anagramGroup.push_back(strs[i]);
            visited[i] = true;

            for (size_t j = i + 1; j < strs.size(); ++j) 
            {
                if (visited[j]) 
                    continue;

                if (charCountVectors[i] == charCountVectors[j]) 
                {
                    anagramGroup.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            result.push_back(anagramGroup);
        }

        return result;
    }

    // Optimized version using unordered_map
    vector<vector<string>> groupAnagramsOptimized(vector<string>& strs)
    {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs)
        {
            vector<int> freq(26, 0);
            for (char c : word)
                freq[c - 'a']++;

            // convert frequency vector to a string key
            string key;
            for (int count : freq)
            {
                key += "#" + to_string(count);
            }

            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& [key, group] : groups)
            result.push_back(std::move(group));

        return result;
    }

    vector<vector<string>> groupAnagramsOptimized(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ret;
        for (const auto& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        ret.reserve(map.size());
        for (auto& p : map) {
            ret.push_back(std::move(p.second));
        }
        return ret;
    }
};

int main() 
{
   return 0;
}