//
// Created by windyear_office on 19-2-22.
//

#ifndef LEETCODE_TEST_138WORDBREAK2_H
#define LEETCODE_TEST_138WORDBREAK2_H
#include <string>
#include <vector>
#include <set>
using namespace std;
class Solution138 {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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
        //用来记录下一个可以匹配的路径。
        vector<vector<int> > path(s.size()+1, vector<int>());
        for(int i=0; i < dp.size(); ++i){
            for(int j = i +1; j < dp.size(); ++j){
                if(dp[i] && wordSet.find(s.substr(i, j-i)) != wordSet.end()){
                    dp[j] = true;
                    path[i].push_back(j);
                }
            }
        }
        // 深度优先搜索获得答案
        vector<string> result;
        string sentence;
        getSentence(result, sentence, dp, 0, s, path, 0);
        return result;
    }

    void getSentence(vector<string>& result, string sentence, vector<bool>& dp, int index, string& s, vector<vector<int> >& path, int start){
//        if(index == (dp.size()-2)){
//            // 添加到result
//            result.push_back(sentence.substr(0, sentence.size()-1));
//            return;
//        }
        if(dp[index] == true){
          if(index >= s.size()){
            string tmp = sentence + " "+ s.substr(start, index-start);
                result.push_back(tmp.substr(2));
                return;
              }
            for(int i = 0; i < path[index].size(); ++i){
                string tmp = sentence + " "+ s.substr(start, index-start);
                getSentence(result, tmp, dp,path[index][i], s, path, index);
            }
        }
        else{
            return;
        }
    }
};
#endif //LEETCODE_TEST_138WORDBREAK2_H
