#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

const int N = 150009;
const int MAX = 0x3f3f3f3f;

bool vis[N];
int d[N];//保存最短距离
int head[N];//标志头节点

struct Edge
{
    int start, end, w, next;
}Edge[N];

struct Node
{
    int x, v;
    Node(int a, int b): x(a), v(b) {}
    bool operator < (const Node &t) const//确定优先级
    {
        return this->v > t.v;
    }
};

int dijkstra(int n)
{
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f3f3f3f, sizeof(d));
    //优先队列优化
    priority_queue<Node, vector<Node> > q;
    
    for(int i=head[1]; i!=-1; i=Edge[i].next)
        d[Edge[i].end] = Edge[i].w;
    
    for(int i=2; i<=n; i++)
        
        q.push(Node(i,d[i]));
    d[1] = 0;
    
    vis[1] = 1; //表示已被访问
    
    for(int k=1; k<n && !q.empty(); k++)
    {
        Node t = Node(0, 0);
        do{
            t = q.top();
            q.pop();
        }while(vis[t.x] && !q.empty()); //优先队列不为空时
        int x = t.x;
        if(x == -1)
            break;
        vis[x] = 1;
        
        for(int i=head[x]; i!=-1; i=Edge[i].next)
        {
            if(!vis[Edge[i].end] && d[Edge[i].end] > d[x] + Edge[i].w)//如更小，则替换
            {
                d[Edge[i].end] = d[x] + Edge[i].w;
                q.push(Node(Edge[i].end, d[Edge[i].end]));
            }
        }
    }
    return d[n];
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))//也就是输入点数量和边数量
    {
//        memset(ans, 0, sizeof(ans));
        memset(head, -1, sizeof(head));
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d", &Edge[i].start, &Edge[i].end, &Edge[i].w);//每段的起始点，结束点，权重
            Edge[i].next = head[Edge[i].start];
            head[Edge[i].start] = i;
        }
        printf("%d\n", dijkstra(n));
    }
    return 0;
}
