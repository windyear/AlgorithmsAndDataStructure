//
// Created by windyear_office on 19-2-22.
//

#ifndef LEETCODE_TEST_137WORDBREAD_H
#define LEETCODE_TEST_137WORDBREAD_H
#include <string>
#include <vector>
#include <set>
using namespace std;
//动态规划，首先找出第一个能拆分出来的字符串。
// 接下来在前面能够拆分的情况下依次拆分后面的。
class Solution137 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        //int start = dp.size()-1;
//        for(size_t i = 0; i < dp.size(); ++i){
//            if(wordSet.find(s.substr(0, i+1)) != wordSet.end()){
//                dp[i] = true;
//                //start = i;
//                break;
//            }
//        }
		dp[0] = true;
        for(int i=0; i <= dp.size(); ++i){
            for(int j = i +1; j <= dp.size(); ++j){
                if(dp[i] && wordSet.find(s.substr(i, j-i)) != wordSet.end()){
                    dp[j] = true;
                }
            }
        }
        return dp.back();
    }
};
#endif //LEETCODE_TEST_137WORDBREAD_H
