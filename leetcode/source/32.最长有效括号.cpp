// 动态规划，d[i]表示以i结尾的最长有效子串长度
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2){
            return 0;
        }else{
            vector<int> length(s.size(),0);
            length[0] = 0;
            int max = 0;
            for(size_t i = 1; i < s.size(); ++i){
                // 如果是左括号则不能跟前面匹配
                if(s[i] == '('){
                    length[i] = 0;
                }
                else{
                    if((i-length[i-1]-1)>=0 && s[i-length[i-1]-1] == '('){
                        length[i] = length[i-1]+2;
                        if((i-length[i-1]-2) >=0){
                            length[i] += length[i-length[i-1]-2];
                        }
                        if(length[i] > max){
                            max = length[i];
                        }
                    }
                    else{
                        length[i] = 0;
                    }
                }
            }
            return max;
        }
    }
};
