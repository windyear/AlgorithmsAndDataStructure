/*
dijkstra算法
author: windyear
date: 2018.1.18
参考资料：《啊哈， 算法》 《算法导论》
*/

#include <iostream>
//包含内置类型的最大和最小值
#include <climits>

using namespace std;

//一个读入图信息的函数，需要输入一行一行的边，分别是两个点和边的权值
void InitMap(int* map[], int& source, int num){
    for(int i = 0; i < num; i++){
        for(int j =0; j < num; j++){
            if(i == j){
                    map[i][j] = 0;
            }else{
                map[i][j] = 999;
            }
        }
    }
    cout << "Please input the index of start point: ";
    cin >> source;
    cout << "Please input the number of side: ";
    int num_of_side;
    cin >> num_of_side;
    cout << "Please input the two point and their distance!" << endl;
    for(int i = 0; i < num_of_side; i++){
        int a, b, value_of_side;
        cin >> a >> b >> value_of_side;
        map[a][b] = value_of_side;
    }
}

void Dijkstra(int* map[], int shortest_distance[], int num, int source){
    //传入参数分别是邻接矩阵，松弛记录数组，用于防止数组越界的结点数目。
    //根据输入的起点进行距离数组的初始化。为了方便操作，这里的结点都是从0开始计数的。
    //判断起点是否大于结点数
    if( source >= num){
        cout << "The start point is out of range!" << endl;
        return;
    }
    //检查每个结点是否与起始结点相连接，如果没有连接，初始化距离为可表示的最大整数值。
    for( int i = 0; i < num; i++){
        //读入图的时候做了处理，如果没有连接的两个点的距离是整数的最大值。
        shortest_distance[i] = map[source][i];
    }

    //一个数组用来记录已经松弛了的点，0表示还没松弛，1表示已经松弛
    int record[num];
    record[source] = 1;
    //逐个点对应的邻边进行松弛
    //先在还没松弛的点中距离顶点最近的点。
    while(true){
        int shortest = 999;
        int shortest_index = 999;
        for(int i = 0; i < num; i++){
            if(record[i] == 1){
                continue;
            }
            if(shortest > shortest_distance[i]){
                shortest = shortest_distance[i];
                shortest_index = i;
            }
        }

    //这里应该有一个判断是否所有点已经进行了松弛
        if( shortest_index == 999){
            break;
        }

    //逐个进行松弛
        for(int i = 0; i < num; i++){
        //判断是否可以进行松弛
            if(shortest_distance[i] > shortest_distance[shortest_index] + map[shortest_index][i]){
                shortest_distance[i] = shortest_distance[shortest_index] + map[shortest_index][i];
            }
        }
        record[shortest_index] = 1;
        }

}

void ShowShortest(int* shortest_distance, int num){
    for(int i = 0; i < num; i++){
        cout << shortest_distance[i] << " " << endl;
    }
}
int main()
{
    /*
    算法思路：dijkstra算法主要是为了解决单源最短路径的计算问题，可以计算出起点到所有结点的
    最短路径长度。算法的关键点在于记录一个起点到每个结点的最短路径数组，然后每次从数组中选
    出当前距离起点最短的点，对该点的邻边对其他点到起点的距离进行松弛。
    1、初始化最短路径数组shortest。
    2、用另外一个数组保存两个集合，分别是已经进行松弛的点和待松弛的点。
    3、选出距离起点最近的那个结点，用它的所有邻边对所有的其他结点进行松弛，更新距离，和松弛
    点数组。
    4、一直循环第三个步骤直至所有点都已经进行了松弛。
    */
    cout << "Please input the number of point: " ;
    int num;
    int source;
    cin >> num;
    //动态开辟二维数组，新开辟行，再开辟列
    int* shortest_distance = new int[num];
    int** map = new int*[num];
    for(int i = 0; i < num; i++){
        map[i] = new int[num];
    }
    InitMap(map,source, num);
    Dijkstra(map, shortest_distance, num, source);
    ShowShortest(shortest_distance, num);
    //释放列再释放行
    for(int i = 0; i < num; i++){
        delete[] map[i];
    }
    delete[] map;
    delete[] shortest_distance;
    return 0;
}


