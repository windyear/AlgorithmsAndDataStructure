// 固定一个数，剩下数找对应的和为差值的数。
// 剩下的数可以根据指针从两边向中间寻找的过程。
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        if(nums.size() < 3){
            return result;
        }
        // 先排序
        sort(nums.begin(), nums.end());
        // 设定三个指针和一个存结果的变量
        vector<int> group(3,0);
        int fixed = 0;
        int start = fixed+1;
        int end = nums.size()-1;
        int dif = 0 - nums[fixed];
        // fixed需要跳过重复的三元组。
        for(;fixed < nums.size() - 2; ){
            start = fixed + 1;
            end = nums.size() -1;
            dif = 0 - nums[fixed];
            // bool用于加快速度提前退出。
            //bool is_found = false;
            // 两指针还没相遇时
            while(start < end){
                // 如果存在
                if((nums[start]+nums[end]) == dif){
                    group[0] = nums[fixed];
                    group[1] = nums[start];
                    group[2] = nums[end];
                    result.push_back(group);
                    --end;
                    while(nums[end] == nums[end+1]){
                        --end;
                    }
                    ++start;
                    while(nums[start] == nums[start-1]){
                        ++start;
                    }
                   // is_found = true;
                }
                else{
                    //if(is_found){
                        //break;
                    //}
                    if((nums[start]+nums[end]) > dif){
                        --end;
                        while(nums[end] == nums[end+1]){
                            --end;
                        }
                    }
                    else{
                        ++start;
                        while(nums[start] == nums[start-1]){
                            ++start;
                        }
                    }
                }
            }
            ++fixed;
            while(nums[fixed] == nums[fixed-1]){
                ++fixed;
            }
        }
        return result;
    }
};
