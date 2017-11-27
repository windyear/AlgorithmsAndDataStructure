/*
author: windyear
time: 2017-11-26
*/
#include <iostream>
#include "union_find.h"
#include "quick_union.h"
#include "weighted_quick_union.h"
using namespace std;

int main()
{
    /*cout << "Hello world!" << endl;
    cout << "Test UnionFind:" << endl;
    UnionFind test_unionfind(10);
    test_unionfind.Union(4, 3);
    test_unionfind.Union(3, 8);
    test_unionfind.Union(6, 5);
    test_unionfind.Union(9, 4);
    test_unionfind.Union(2, 1);
    cout << "Is 8 and 9 connected?" <<endl << test_unionfind.IsConnected(8, 9) << endl;
    cout << "Is 6 and 8 connected?" <<endl << test_unionfind.IsConnected(6, 8) << endl;

    cout << "Test quick union:" << endl;
    QuickUnion quickunion(100);
    quickunion.Union(67, 8);
    quickunion.Union(8, 99);
    quickunion.Union(98, 7);
    cout << "Is 8 and 99 connected? " << endl << quickunion.IsConnected(8, 99) <<endl;
    cout << "Is 8 and 98 connected? " << endl << quickunion.IsConnected(8, 98) <<endl;

    cout << "Test weighted quick union:" << endl;
    WeightedQuickUnion weightedquickunion(100);
    weightedquickunion.Union(66, 8);
    weightedquickunion.Union(8, 99);
    weightedquickunion.Union(98, 7);
    cout << "Is 8 and 99 connected? " << endl << weightedquickunion.IsConnected(66, 99) <<endl;
    cout << "Is 8 and 98 connected? " << endl << weightedquickunion.IsConnected(8, 98) <<endl;*/

    //改良一下从标准输入中获取内容
    //100万个数据时间非常长，跑不出来
    /*int N;
    cin >> N;
    QuickUnion testquickunion(N);
    int p, q;
    while(cin >> p >> q){
        if(testquickunion.IsConnected(p, q)){
            continue;
        }
        testquickunion.Union(p, q);
        cout << p << " " << q << endl;
    }
    cout << "components: " << testquickunion.Count() << endl;*/
　　　　//优化之后十几秒就可以跑出来
    int N;
    cin >> N;
    WeightedQuickUnion testweightedquickunion(N);
    int p, q;
    while(cin >> p >> q){
        if(testweightedquickunion.IsConnected(p, q)){
            continue;
        }
        testweightedquickunion.Union(p, q);
        cout << p << " " << q << endl;
    }
    cout << "components: " << testweightedquickunion.Count() << endl;
    return 0;
}
