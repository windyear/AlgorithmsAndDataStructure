---
title: leetcode_两整数之和
tags: leetcode,算法,C++
grammar_cjkRuby: true
---
## 题目
- 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
- 示例：给定 nums = [2, 7, 11, 15], target = 9，因为 nums[0] + nums[1] = 2 + 7 = 9，所以返回 [0, 1]

## 思路分析
- 一个马上想到的思路是遍历所有整数的两两组合，直到和为目标值。可用二重循环实现。由于1+2和2+1的等效性，内层循环可以从i+1开始。
- 代码：
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2){
           vector<int> result;
           return result;
        }
        vector<int> result = {0, 0};
        for(vector<int>::size_type i = 0; i < nums.size()-1; i++){
            for(vector<int>::size_type j = i+1; j < nums.size(); j++){
               if(nums[i] + nums[j] == target){
                   result[0] = i;
                   result[1] = j;
                   break;
               } 
            }
        }
        return result;
    }
};
```
## 算法优化
- 这道题可以只用一个遍历循环，只需要用一个hashmap保存前面遍历过的元素。值为key，索引为value。遍历到下一个整数时查看前面是否有该差值的索引即可。
- 代码：
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i)
        {
            int k = target - nums[i];
            if(hash.find(k) != hash.end())
            {
                result.push_back(hash[k]);
                result.push_back(i);
                break;
            }
            else
                hash[nums[i]] = i;
        }
        return result;
    }
};
```
## 总结
题目较为简单，建立索引是一个保存元素位置的重要方法。牺牲存储空间换取运行时间。