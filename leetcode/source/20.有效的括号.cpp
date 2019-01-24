// 使用一个栈辅助匹配，把匹配的括号对弹出，遇到不能匹配的即为不合法的括号串。
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        if(s.size() < 1){
            return true;
        }
        else if(s.size() == 1){
            return false;
        }
        else{
            stack<char> brackers;
            bool is_valid = true;
            for(size_t i = 0; i < s.size(); ++i){
                if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                    brackers.push(s[i]);
                }
                else{
                    switch(s[i]){
                        case ')':
                            if(!brackers.empty() && brackers.top() == '('){
                                brackers.pop();
                            }
                            else{
                                is_valid = false;
                            }
                            break;
                        case ']':
                            {
                            if(!brackers.empty() && brackers.top() == '['){
                                brackers.pop();
                            }
                            else{
                                is_valid = false;
                            }
                            break;
                        }
                        case '}':
                            {
                            if(!brackers.empty() && brackers.top() == '{'){
                                brackers.pop();
                            }
                            else{
                                is_valid = false;
                            }
                            break;
                        }
                    }
                }
                if(!is_valid){
                    break;
                }
            }
            if(is_valid && brackers.empty()){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
