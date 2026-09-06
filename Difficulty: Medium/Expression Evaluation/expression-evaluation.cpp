class Solution {
  public:
    int prio(char ch){
        if(ch=='+' || ch=='-') return 1;
        else if(ch=='*' || ch=='/') return 2;
        else return 3;
    }
    int solve(int val1, int val2, char ch){
        if(ch=='+') return val1+val2;
        else if(ch=='-') return val1-val2;
        else if(ch=='*') return val1*val2;
        else if(ch=='/') return val1/val2;
        else return pow(val1, val2);
    }
    int evaluateInfix(vector<string>& arr) {
        // code here
        stack<int>val;
        stack<char>op;
        for(int i=0;i<arr.size();i++){
            if(isdigit(arr[i][0])) {
                val.push(stoi(arr[i]));
            }else{
                if(op.empty() || prio(arr[i][0])> prio(op.top())) op.push(arr[i][0]);
                else{
                    while(!op.empty() &&
                                (prio(arr[i][0]) < prio(op.top()) ||
                                (prio(arr[i][0]) == prio(op.top()) && arr[i][0] != '^'))){
                        char ch=op.top();
                        op.pop();
                        int val2=val.top();
                        val.pop();
                        int val1=val.top();
                        val.pop();
                        int ans=solve(val1, val2, ch);
                        val.push(ans);
                    }
                    op.push(arr[i][0]);
                }
            }
        }
        while(!op.empty()){
            char ch=op.top();
            op.pop();
            int val2=val.top();
            val.pop();
            int val1=val.top();
            val.pop();
            int ans=solve(val1, val2, ch);
            val.push(ans);
        }
        return val.top();
    }
};