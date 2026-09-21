class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_set<int>s;
        for(int x:arr){
            int need=target-x;
            if(s.count(need)){
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};