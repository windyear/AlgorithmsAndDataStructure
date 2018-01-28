/*
author: windyear
date: 2018-01-23
problem: TSP
描述：旅行商要经过n个城市，每个城市只经过一次，寻找最短的路径。是一个全排列的问题。
NP完全的问题。
*/

//采用模拟退火算法寻求近似最优解，迭代策略是随机选取两个节点交换。

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

//定义一些模拟退火过程中需要用到的常量，比如初始温度等。
const double T = 100000;
const double MIN_T = 1e-8;
const int NUM_OF_CITY = 40;
const int INNER_LOOP = 10000;
const double RATE = 0.995;

//定义一个结构体，存储城市位置坐标。
struct Location{
    double x;
    double y;
};

//定义一个结构体，存储要交换的两个坐标
struct ChangeLocation{
    int location1,location2;
};

//输入城市坐标数据,设计另外一个从文件中读取数据的程序。
void Input(Location location[], int num){
    cout << "Please input the location of cities:" << endl;
    for(int i = 0; i < num; i++){
        cin >> location[i].x >> location[i].y;
    }
    return ;
}

//从文件中读取数据
void InputFromFile(Location location[], int num, char* filename){
    //文件输入流，关联到一个文件
    ifstream input_path(filename);
    if(input_path){
        int index;
        while(input_path >> index){
            //cout << "the index:" << index << endl;
            input_path >> location[index-1].x >> location[index-1].y;
            //cout << "the location: " << location[index-1].x << location[index-1].y << endl;
        }
    }
    return ;
}
//初始化
void Init(int path[], int num){
    cout << "Init the start path......" << endl;
    //由于生成一个随机的全排列比较麻烦，所以这里直接按顺序选择了一个初始化的路径
    //分别是从0到39个城市组成的路径。
    for(int i = 0; i < num; i++){
        path[i] = i;
    }
    return;
}

//计算两个点之间的距离
double GetDistance(Location location[], int start, int end, int num){
    //这里一开始写错了，这样计算的话每次都是计算出同一个值，应该用path来计算
    double distance = pow((location[start].x - location[end].x), 2) + pow((location[start].y - location[end].y), 2);
    return sqrt(distance/10.0);
}
//计算总的距离,刚开始的时候忘记了最后一段要加上
double WholeDistance(int path[], int num, Location location[]){
    double whole_distance = 0;
    for(int i = 0; i < num - 1; i++){
        whole_distance = whole_distance + GetDistance(location, path[i], path[i + 1], num);
        //cout << GetDistance(location, i , i+1, num);
    }
    whole_distance = whole_distance + GetDistance(location, 0, path[num-1], path[num]);
    return whole_distance;
}

//随机交换两个点，这个是迭代的关键。
ChangeLocation ChangePath(int num){
    //产生两个最大为40的随机数。
    //给一个种子
    srand((unsigned)time(NULL));
    ChangeLocation location;
    location.location1 = rand() % num;
    srand((unsigned)time(NULL));
    location.location2 = rand() % num;
    while( location.location1 == location.location2){
        location.location1 = rand() % num;
        srand((unsigned)time(NULL));
        location.location2 = rand() % num;
    }
    return location;
    //交换两个点
    /* int temp = path[new_x];
    path[new_x] = path[new_y];
    path[new_y] = path[new_x]; */
}

void SimulatedAnnealing(Location location[], int path[], int num){
    //设置初始温度
    double t = T;
    //只要温度大于设定的最少值，就继续寻找解
    while( t > MIN_T){
        //可以设置一个内循环，在一个温度时寻找多个解
        for(int i = 0; i < INNER_LOOP; i++){
            //产生新解
            ChangeLocation change_location = ChangePath(num);
            //计算原来的总距离
            double original_distance = WholeDistance(path, num, location);
            //交换两个点
            int temp = path[change_location.location1];
            path[change_location.location1] = path[change_location.location2];
            path[change_location.location2] = temp;
            double new_distance = WholeDistance(path, num, location);
            double delta_distance = new_distance - original_distance;
            //如果新解的距离比旧解要小，则接受新的解，继续循环
            if(delta_distance <= 0){
                continue;
            }
            srand(time(NULL));
            double rd = rand()%999 / 1000;
            //关键操作，如果新的解比旧的解的距离要大， 需要在一定的概率范围内接受该解。
            if(exp(-delta_distance/t) > rd){
                continue;
            }
            //不接受新解，交换路径为原来的解。
            //重新交换两个点
            temp = path[change_location.location1];
            path[change_location.location1] = path[change_location.location2];
            path[change_location.location2] = temp;
        }
        //做完一次内循环之后再改变温度值
        t *= RATE;
    }
}

//显示路径和坐标
void ShowLocation(Location location[], int path[], int num){
    //for(int i = 0; i < num; i++){
        //cout << location[i].x << " " << location[i].y << endl;
    //}
    cout << "the path is :" << endl;
    for(int i = 0; i <num; i++){
        cout << path[i] << " ";
    }
    return;
}
int main(int argc, char** argv){
    cout << "The simulated annealing: " << endl;
    //城市数目，路径，坐标等变量
    int num;
    cout << "Please input the number of city: ";
    cin >> num;
    Location* location = new Location[num];
    int* path = new int[num];
    if(argc == 1){
        Input(location, num);
    }else if(argc == 2){
        InputFromFile(location, num, argv[1]);
    }else{
        cout << "Error! Please input the correct arguments." << endl;
        return -1;
    }
    Init(path, num);
    SimulatedAnnealing(location, path, num);
    cout << "The whole distance is :" << WholeDistance(path , num, location) << endl;
    ShowLocation(location, path, num);
    //cin >> num;

}
