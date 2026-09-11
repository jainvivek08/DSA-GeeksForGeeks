class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        for(int i=0;i<k;i++){
            if(type==1){
                dq.push_front(dq.back());
                dq.pop_back();
            }else{
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
};