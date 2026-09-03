class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        queue<int>s;
        for(int i=0;i<n/2;i++){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.front());
            s.pop();
            q.push(q.front());
            q.pop();
        }
    }
};