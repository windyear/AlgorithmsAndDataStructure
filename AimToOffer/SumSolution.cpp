class Solution {
public:
    int Sum_Solution(int n) {
        //短路求值，其实就是递归，不过不用if语句来结束递归
        int sum = n;
        sum > 0 && (sum += Sum_Solution(n-1));
        return sum;
    }
};