class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> freq;

            // Count frequency in current subarray
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // Collect into vector for sorting
            vector<pair<int,int>> v; // {freq, value}
            for (auto &p : freq)
                v.push_back({p.second, p.first});

            // Sort by freq desc, then value desc
            sort(v.begin(), v.end(), [](auto &a, auto &b){
                if (a.first == b.first)
                    return a.second > b.second;
                return a.first > b.first;
            });

            // Take top x and compute sum
            unordered_set<int> keep;
            for (int t = 0; t < x && t < (int)v.size(); t++) {
                keep.insert(v[t].second);
            }

            int sum = 0;
            for (int j = i; j < i + k; j++) {
                if (keep.count(nums[j])) sum += nums[j];
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
