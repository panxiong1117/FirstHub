Problem Description
由某个集合上的一个偏序得到该集合上的一个全序，这个操作被称为拓扑排序。偏序和全序的定义分别如下：
若集合X上的关系R是自反的、反对称的和传递的，则称R是集合X上的偏序关系。
设R是集合X上的偏序，如果对每个x,y∈X必有xRy或yRx，则称R是集合X上的全序关系。
由偏序定义得到拓扑有序的操作便是拓扑排序。
拓扑排序的流程如下：
1.       在有向图中选一个没有前驱的顶点并且输出之；
2.       从图中删除该顶点和所有以它为尾的弧。
重复上述两步，直至全部顶点均已输出，或者当前图中不存在无前驱的顶点为止。后一种情况则说明有向图中存在环。
采用邻接表存储有向图，并通过栈来暂存所有入度为零的顶点，可以描述拓扑排序的算法如下：

在本题中，读入一个有向图的邻接矩阵（即数组表示），建立有向图并按照以上描述中的算法判断此图是否有回路，如果没有回路则输出拓扑有序的顶点序列。

Input Description
输入的第一行包含一个正整数n，表示图中共有n个顶点。其中n不超过50。
以后的n行中每行有n个用空格隔开的整数0或1，对于第i行的第j个整数，如果为1，则表示第i个顶点有指向第j个顶点的有向边，0表示没有i指向j的有向边。当i和j相等的时候，保证对应的整数为0。
Output Description
如果读入的有向图含有回路，请输出“ERROR”，不包括引号。
如果读入的有向图不含有回路，请按照题目描述中的算法依次输出图的拓扑有序序列，每个整数后输出一个空格。
请注意行尾输出换行。
Sample Input
4
0 1 0 0
0 0 1 0
0 0 0 0
0 0 1 0
Sample Output
3 0 1 2 
Hint
在本题中，需要严格的按照题目描述中的算法进行拓扑排序，并在排序的过程中将顶点依次储存下来，直到最终能够判定有向图中不包含回路之后，才能够进行输出。
另外，为了避免重复检测入度为零的顶点，可以通过一个栈结构维护当前处理过程中入度为零的顶点。


#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
const int MAX = 105;
vector<int> edge[MAX];
int in[MAX]={0};
queue<int> q;
vector<int> res;
stack<int> s;
int n;
int t;
void top_sort()
{
    for(int i=0;i<n;++i) {
        if(!in[i]) s.push(i);
    }
    while(!s.empty()) {
        int p=s.top();
        s.pop();
        res.push_back(p);
        for(int i=0;i<edge[p].size();++i) {
            t=edge[p][i];
            in[t]--;
            if(in[t]==0) {
                s.push(t);
            }
        }
    }
    if(res.size()==n) {
        for(int i=0;i<n;++i) {
            cout << res[i] << " ";
        }
    } else {
        cout << "ERROR";
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;) {
        for(int j=0;j<n;) {
            cin >> t;
            if(t) {
                edge[i].push_back(j);
                in[j]++;
            }
            j++;
        }
        i++;
    }
    top_sort();
    return 0;
}
