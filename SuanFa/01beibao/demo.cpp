#include<stdio.h>
#include<queue>

using namespace std;
#define MAXN 20
#define INF 0x3f3f3f3f3

//问题表示
int n = 3,W = 30;
int w[] = {0, 16, 15, 15};
int v[] = {0, 45, 25, 25};

//结果表示
int maxv = -9999; //存放最大价值
int bestx[MAXN]; //存放最优解
int total = 1; //解空间中的结点数累计

struct NodeType{
    int no; //结点编号
    int i; //当前结点在搜索空间中的层次
    int w; //当前结点的总重量
    int v; //当前结点的总价值
    int x[MAXN]; //当前结点包含的解向量
    double ub; // 上界

    bool operator < (const NodeType & s)  const{
        return ub < s.ub; // 上界越大越先出队
    }
};

void bound(NodeType &e){
    //计算结点e的上界

    int i = e.i + 1;
    int sumw = e.w;
    double sumv = e.v;

    while((sumw + w[i] <= W) && i <= n){
         sumw += w[i];
         sumv += v[i];
         i++;
    } 
    if(i <= n){
        e.ub = sumv + (W - sumw)* v[i]/w[i];
    }else {
        e.ub = sumv;
    }

}

void Enqueue(NodeType e, priority_queue<NodeType> &qu){
    //结点入队
    if(e.i == n){
        //得到最大值
        if(e.v > maxv){
            maxv = e.v;
            for(int j = 1; j<= n; j++)
            {
                bestx[j] = e.x[j];
            }
        }
    }else {
        qu.push(e);
    }
}


void bfs(){
    // 求最优解
    int j;
    NodeType e, el, er;
    priority_queue<NodeType> qu;

    e.i = 0;
    e.w = 0;
    e.v = 0;
    e.no = total++;
    for(j = 1; j<=n ; j++)
    {
        e.x[j] = 0;
    }
    
    bound(e);
    qu.push(e);

    while(!qu.empty())
    {
        e = qu.top();
        qu.pop();

        //进行左剪枝，判断是否超重
        if(e.w  + w[e.i +1] <= W)
        {
            //建立左孩子结点

            el.i = e.i +1;
            el.w = e.w +w[el.i];
            el.v = e.v +v[el.i];
            el.no = total++;

            for(j = 1; j<= n; j++) 
            {
                el.x[j] = e.x[j];
            }

            el.x[el.i] = 1;

            bound(el);
            Enqueue(el,qu);
        }

        //创建右节点
        er.no = total++;
        er.i = e.i + 1;
        er.w = e.w;
        er.v = e.v;

        for(j = 1; j<= n; j++)
        {
            er.x[j] = e.x[j];
        }

        er.x[er.i] = 0;
        bound(er);

        if(er.ub> maxv){
            Enqueue(er,qu);
        }
    }
}





int main(){

    bfs();
    printf("分支限界法求解0/1 背包问题： \n X=【");

    for(int i = 1; i<= n; i++)
    {
        printf("%3d",bestx[i]);
    }

    printf("】，装入的总价值为：%d\n",maxv);
    return 0;
}
