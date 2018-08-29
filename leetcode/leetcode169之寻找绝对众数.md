---
title: leetcode169之寻找绝对众数
tags: leetcode,算法, C++
grammar_cjkRuby: true
---
## 题目
- 给出一串数字，求出其中的众数的值，保证输入的数字数组拥有绝对众数。
- 绝对众数是指超过总的数字个数的一半的数字。
## 分析
- 这道题被归到分治算法当中去，应当使用分解为不同过得子问题的问题。
- 想了很久无法拆出子问题来求解。无法利用超过一半数量的数字这个条件。后来直接使用了map去统计数字的个数的方法。直到找到超多一半数量的数字返回。
- 还有一个方法是直接排序，然后找到其中中间的数字。
- **后来查看资料得知可以使用摩尔投票法**，通过不断抵消两种不同的数字，最后剩下数字肯定是绝对众数。参考资料：[enter description here](https://blog.sengxian.com/algorithms/mode)。这篇文章说明了其中的动态规划思想。就是根据遍历的过程将数组分成两个部分，记录前面的数组是否有众数，入果有，就根据当前遍历的数字更新众数的情况。如果没有，就将剩下的数组当做一个子问题，继续从开头的一个数字当做数组求解。
## 代码
- 第一个版本的使用了一个map，时间复杂读是nlgn，查找的时间复杂度是lgn。一旦找到超过一半的数量的数马上返回。
```c++?linenums
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int length = nums.size() / 2;
        // 想不到分治的方法，使用暴力统计的方法，判断是否有数量超过一半的数字
        // 使用一个hashmap
        map<int, int> statistics;
        
        // 遍历数字
        for(auto number: nums){
            if(statistics.find(number) == statistics.end()){
                statistics[number] = 1;
            }
            else{
                statistics[number] += 1;
            }
            if(statistics[number] > length){
                return number;
            }
        }
    }
};
```
- 第二个版本的代码参考了网上的资料，理解了动态规划分解出子问题的原理之后写出来的。时间复杂度为n。代码量更少。
```c++?linenums
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        // 采用摩尔投票法，按照数组遍历到的位置将问题分为两个部分，求绝对众数
        int num = nums[0];
        int count = 1;
        for(vector<int>::size_type i = 1; i < nums.size(); i++){
            if(count == 0){
                num = nums[i];
                count = 1;
            }
            else if(num == nums[i]){
                count += 1;
            }
            else{
                count -= 1;
            }
        }
        return num;
    }
};
```
## 总结
- 涉及到分治方法的题目，关键是如何拆出子问题。