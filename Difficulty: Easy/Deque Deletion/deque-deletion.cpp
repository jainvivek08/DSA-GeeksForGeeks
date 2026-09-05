class Solution {
public:
    void eraseAt(deque<int> &deq, int x) {
        if (x < 0 || x >= (int)deq.size()) return;
        deq.erase(deq.begin() + x);
    }

    void eraseInRange(deque<int> &deq, int start, int end) {
        if (start < 0) start = 0;
        if (end > (int)deq.size()) end = deq.size();
        if (start >= end) return;
        deq.erase(deq.begin() + start, deq.begin() + end);
    }

    void eraseAll(deque<int> &deq) {
        deq.clear();
    }
};