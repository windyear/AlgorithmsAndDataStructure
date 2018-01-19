/*
author: windyear
date: 2018-01-19
program: dynamic programming for a question about steel bars.
*/
#include <iostream>

using namespace std;

/*
问题：给出一个钢条长度以及能够获得利润的列表，求如何切割某个长度的钢条
才能使的获得的利润最大。
*/

/*
采用动态规划的方法，问题可以分解为子问题的组合，问题的最优解也是子问题
的最优解的组合。保存计算子问题的结果，对于要重复计算的子问题有极大的优
化作用。钢条问题可以分解为先切割一段，然后加上剩下的最优化切割子问题得
到的最大的利润。
*/

/*做一个拓展，重构解，就是记录下来应该分割的方法。
只需要记住每个最佳分割的第一下应该切多少，剩下的可以通过迭代或者递归求出。
*/
//先写自顶向下的切割方法
//最开始的思路也实现了动态规划，不过比较繁琐，其实可以在函数的开始判断
//是否已经进行了计算。
//该函数是在拆分子问题的内部进行判断的
double Cut_Steel_bars(double profit[], int length, double cut_profit[]){
    if(length == 0){
        return 0;
    }
    //找出所有子问题中的最优解，循环找出利润最大。
    double max_profit = 0;
    for(int i = 1; i <= length; i++){
        if(profit[length - i] != 0){
            if(max_profit < profit[length -i] + cut_profit[i] ){
                max_profit = profit[length -i] + cut_profit[i];
            }
        }else{
            double temp_profit = Cut_Steel_bars(profit, length - i, cut_profit);
            if(max_profit < temp_profit + cut_profit[i] ){
                max_profit =  temp_profit + cut_profit[i];
            }
        }
    }
    //一开始这里写错了，数组的索引写了 max_profit_index, 覆盖了原来的值，应该是当前的长度作为索引。
    profit[length] = max_profit;
    //cout << max_profit_index << " " << profit[max_profit_index] << endl;
    return max_profit;
}

double Cut_Steel_bars_2(double profit[], int length, double cut_profit[]){
    if(length == 0){
        return 0;
    }
    if(profit[length] != 0){
        return profit[length];
    }
    //找出所有子问题中的最优解，循环找出利润最大。
    double max_profit = 0;
    for(int i = 1; i <= length; i++){
            double temp_profit = Cut_Steel_bars(profit, length - i, cut_profit);
            if(max_profit < temp_profit + cut_profit[i] ){
                max_profit =  temp_profit + cut_profit[i];
            }
        }
    //一开始这里写错了，数组的索引写了 max_profit_index, 覆盖了原来的值，应该是当前的长度作为索引。
    profit[length] = max_profit;
    //cout << max_profit_index << " " << profit[max_profit_index] << endl;
    return max_profit;
}

//自底向上的方法是使用了迭代的方式，求解问题前其子问题已经完成
double Cut_Steel_bars_From_Bottom(double profit[], int length, double cut_profit[], int cut_index[]){
    if(length == 0){
        return 0;
    }
    profit[0] = 0;
    for(int i = 1; i <= length; i++){
        for(int j = 1; j <= i; j++){
            if(profit[i] < cut_profit[j] + profit[i -j]){
                profit[i] = cut_profit[j] + profit[i - j];
                cut_index[i] = j;
            }
        }
    }
    return profit[length];
}
int main()
{
    cout << "Please input the max length of the steel." << endl;
    int steel_length;
    cin >> steel_length;
    cout << "Please input the profit of every length of the steel." << endl;
    //两个数组分别存储不同长度可以获取的利润和最佳切割获取的利润。
    double* profit = new double[steel_length + 1];
    profit[0] = 0;
    double* cut_profit = new double[steel_length + 1];
    int* cut_index = new int[steel_length + 1];
    for(int i = 1; i <= steel_length; i++){
        cin >> cut_profit[i];
        profit[i] = 0;
        cut_index[i] = 0;
    }

    //Cut_Steel_bars_2(profit, steel_length, cut_profit);
    Cut_Steel_bars_From_Bottom(profit, steel_length, cut_profit, cut_index);
    for(int i = 1; i <= steel_length; i++){
        cout << profit[i] << endl;
    }

    while(steel_length != 0){
        cout << cut_index[steel_length] << " ";
        steel_length = steel_length - cut_index[steel_length];
    }
    delete[] cut_profit;
    delete[] profit;
    delete[] cut_index;
    return 0;
}
