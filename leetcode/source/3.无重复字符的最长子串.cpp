// 用一个map保存前面的字符和位置。
// 一个指针标记当前不重复子字符串的位置。
#include <map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        map<char, int> index;
        int pre = 0;
        //int len = 0;
        for(size_t i = 0; i < s.size(); ++i){
            // 判断之前是否出现过该字符。
            // 如果没有出现。则添加
            if(index.find(s[i]) == index.end()){
                index[s[i]] = i;
                int cur_len = i - pre + 1;
                if(cur_len > len){
                    len = cur_len;
                }
                else{
                    continue;
                }
            }
            // 如果之前出现过
            else{
                if(index[s[i]] >= pre){
                    pre = index[s[i]]+1;
                    int cur_len = i - pre +1;
                    // 更新位置
                    index[s[i]] = i;
                    if(cur_len > len){
                        len = cur_len;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    index[s[i]] = i;
                    int cur_len = i - pre +1;
                    if(cur_len > len){
                        len = cur_len;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        return len;
    }
};
