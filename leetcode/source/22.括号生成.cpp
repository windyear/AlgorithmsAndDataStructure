// 深度优先搜索加剪枝，从左到右左括号数量要大于等于右括号。
// 记录左右括号的数量。

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n <= 0){
            return result; 
        }
        string s;
        getParenthesis(n, 0, s, 0, 0, result);
        return result;
    }
    
    void getParenthesis(int total, int cur, string& s, int open, int close, vector<string>& result){
        if(cur == 2 * total){
            result.push_back(s);
            // 不用pop_back()出来。上层函数负责pop_back();
            //s.pop_back();
            return;
        }
        else{
            if(open < total){
                s.push_back('(');
                getParenthesis(total, cur+1, s, open+1, close, result);
                s.pop_back();
            }
            if(close < open){
                s.push_back(')');
                getParenthesis(total, cur+1, s, open, close+1, result);
                s.pop_back();
            }
        }
        
    }
};
