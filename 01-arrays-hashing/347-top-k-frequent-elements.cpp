#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }
        vector<pair<int, int>> pairs;
        for(auto& p : freq){
            pairs.push_back(p);
        }
        sort(pairs.begin(), pairs.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        });
        vector<int> result;
        for(int i = 0 ; i < k ; i++){
            result.push_back(pairs[i].first);
        }
        return result;
    }
};
