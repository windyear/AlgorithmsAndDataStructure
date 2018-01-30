#include "Sort/select_sort.h"
#include "Sort/sort_compare.h"
#include "DynamicProgramming/zero_one_bag.h"
#include "Graph/Graph.h"
#include "Graph/DepthFirstPaths.h"
#include "Graph/BreadthFirstPaths.h"
#include "Graph/DegreesOfSeparation.h"

using namespace std;
//主函数封装每个不同的测试函数，需要测试的时候就调用该函数
void Test_Time_Of_Sort(){
    cout << "Please input the length of array, the times of sort, "
            "and the time of sort:\n1 select sort\n2 insert sort" << endl;
    int length, name_of_sort, times;
    if(!(cin >> length >> name_of_sort >> times)){
        cout << "error input!" << endl;
        return ;
    }
    cout << "time:" << SortCompare::Time_Of_Sort(length,times,name_of_sort) << endl;

}

//测试排序
void Test_Sort(){
    cout << "Please input the length of array and the type of sort:"
            "(1 for shell sort, \n2 for insert sort,\n3 for select sort,\n"
            "4 for merge sort,\n5 for merge sort2,\n6 for quick sort1)" << endl;
    int length, type_of_sort;
    cin >> length >> type_of_sort;
    SortCompare::TestSort(length, type_of_sort);
}

//测试01背包问题的程序
void Test_Zero_One_Bag(){
    cout << "Please input the number of goods:";
    int number_of_goods;
    cin >> number_of_goods;
    double* values_of_goods = new double[number_of_goods+1];
    int* weight_of_goods = new int[number_of_goods];
    cout << "Please input the value of goods and the weight of goods:";
    values_of_goods[0] = 0;
    weight_of_goods[0] = 0;
    for(int i = 1; i < number_of_goods + 1; i++){
        cin >> values_of_goods[i];
        cin >> weight_of_goods[i];
    }
    int max_weight;
    cout << "Please input the max weight of the bag:";
    cin >> max_weight;
    ZeroOneBag::Dynamic_Zero_One_Bag(values_of_goods,weight_of_goods,number_of_goods,max_weight);
}

//测试图的表示和算法
void Test_Graph(){
    Graph graph(6);
    graph.AddEdge(0,2);
    graph.AddEdge(0,1);
    graph.AddEdge(0,5);
    graph.AddEdge(2,3);
    graph.AddEdge(2,4);
    graph.AddEdge(2,1);
    graph.AddEdge(3,4);
    graph.AddEdge(3,5);
    //DepthFirstPaths search_path(graph, 0);
    BreadthFirstPaths search_path(graph, 0);
    for(int v = 0; v < graph.V(); v++){
        cout << 0 << " to " << v << ": ";
        if(search_path.HasPathTo(v)){
            for(int point: search_path.PathTo(v)){
                if(point == 0){
                    cout << 0;
                }else{
                    cout << "-" << point;
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

void Test_Graph2(string filename){
    Graph graph(filename, 6);
    BreadthFirstPaths search_path(graph, 0);
    for(int v = 0; v < graph.V(); v++){
        cout << 0 << " to " << v << ": ";
        if(search_path.HasPathTo(v)){
            for(int point: search_path.PathTo(v)){
                if(point == 0){
                    cout << 0;
                }else{
                    cout << "-" << point;
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}
int main(int argc, char* argv[]) {
    //Test_Sort();
    //Test_Zero_One_Bag();
    //Test_Graph2(argv[1]);
    DegreesOfSeparation degrees_of_sepatation;
    degrees_of_sepatation.TestDegrees(argv[2], argv[1], argv[3]);
    return 0;
}