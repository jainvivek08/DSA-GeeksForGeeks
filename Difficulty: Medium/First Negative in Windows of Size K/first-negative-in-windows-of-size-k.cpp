class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // code here
        vector<int>ans;
        queue<int>q;
        for(int i = 0; i < k; i++) {
            if(arr[i] < 0) {
                q.push(i);
            }
        }
        for(int i = k; i < arr.size(); i++) {

            // Current window ka first negative
            if(q.empty())
                ans.push_back(0);
            else
                ans.push_back(arr[q.front()]);

            // Jo element window se bahar chala gaya
            if(!q.empty() && q.front() <= i - k) {
                q.pop();
            }

            // New element negative hai toh queue mein daalo
            if(arr[i] < 0) {
                q.push(i);
            }
        }
        if(q.empty())
            ans.push_back(0);
        else
            ans.push_back(arr[q.front()]);
        return ans;
    }
};