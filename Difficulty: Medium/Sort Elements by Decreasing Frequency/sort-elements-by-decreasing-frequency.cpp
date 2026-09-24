class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        vector<int>ans;
        unordered_map<int, int> mp;
        for(int x:arr){
            mp[x]++;
        }
        vector<pair<int,int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        for(auto &it:v){
            int element = it.first;
            int freq = it.second;

            while(freq--) {
                ans.push_back(element);
            }
        }
        return ans;
    }
};