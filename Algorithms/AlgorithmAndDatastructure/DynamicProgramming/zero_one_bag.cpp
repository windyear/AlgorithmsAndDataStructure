//
// Created by windyear_office on 18-1-20.
//
#include "zero_one_bag.h"
#include <iostream>

using namespace std;

void ZeroOneBag::Dynamic_Zero_One_Bag(double *value_of_goods, int *weight_of_goods, int number_of_goods, int max_weight) {
    /*
     * 0-1背包问题，给定一个最多能装w重量的背包，每种物品都有一个重量以及价值，求可以带走最大价值的物品。
     * 分析：可以采用动态规划的方法，分解为两个子问题，即包含第i个物品的最大价值和不包含第i个物品的最大价值。
     * value[i][j]表示一个物品，重量为j的包能够带走的最大价值。从子问题中得到原问题的状态转移方程为：
     * value[i][j] = max{value[i-1][j] + value[i-1][j-wj] + vj}
     * 可以采取自底向上的方法通过迭代得到value[i][j]
     */
    //声明一个存储最大价值的数组，maxvalue[i][j]表示包的最大容量为j，一共i个物品的可以带走的最大价值。
    int max_value[number_of_goods+1][max_weight+1];
    for(int i = 0; i <= max_weight; i++){
        max_value[0][i] = 0;
    }
    for(int i = 0; i <= number_of_goods; i++){
        max_value[i][0] = 0;
    }

    for(int i = 1; i <= number_of_goods; i++){
        for(int j = 1; j <= max_weight; j++){
            //如果第i个物品的重量大于最大的重量，证明不能加入，取前i-1个物品的最大值即可
            if(weight_of_goods[i] > j){
                max_value[i][j] = max_value[i-1][j];
                continue;
            }
            //根据状态方程选出最大的价值
            if(max_value[i-1][j] > max_value[i-1][j-weight_of_goods[i]] + value_of_goods[i]){
                max_value[i][j] = max_value[i-1][j];
            }else{
                max_value[i][j] = max_value[i-1][j-weight_of_goods[i]] + value_of_goods[i];
            }
        }
    }
    cout << "The max value is: " << max_value[number_of_goods][max_weight] << endl;

}
