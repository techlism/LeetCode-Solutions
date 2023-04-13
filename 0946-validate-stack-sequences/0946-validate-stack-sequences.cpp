class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int i=0;
        for (auto x : pushed) {
            stack.push(x);
            while (!stack.empty() && stack.top() == popped[i]) {
                stack.pop();
                i++;
            }
        }
        return stack.size() == 0;
    }
};