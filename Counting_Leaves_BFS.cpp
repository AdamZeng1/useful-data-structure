//
// Created by adamzeng on 2019-07-03.
//
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int N = 105;

vector<int> G[N]; // 树
int h[N] = {0}; // 各结点所处的层号,从1开始
int leaf[N] = {0}; // 存放每层的叶子结点个数
int max_h = 0; // 树的最大深度


void BFS() {
    queue<int> Q;
    Q.push(1); // 将树的根结点压入栈
    while (!Q.empty()) { // 开始BFS
        int id = Q.front(); // 弹出队首元素
        if (G[id].size() == 0) { // 如果该层是叶子结点
            leaf[h[id]]++; // 该层叶子结点个数加一
        }
        for (int i = 0; i < G[id].size(); ++i) { //遍历该点所有子结点
            h[G[id][i]] = h[id] + 1; // 子结点的层号为父结点加一
            Q.push(G[id][i]); // 将子结点压入栈
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) { // 输入
        int parent, k, child;
        scanf("%d%d", &parent, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child);
            G[parent].push_back(child);
        }
    }
    h[1] = 1; // 初始化根结点
    BFS(); // BFS入口
    for (int i = 1; i <= max_h; ++i) { //输出
        if (i == 1) printf("%d", leaf[i]);
        else printf(" %d", leaf[i]);
    }
    return 0;
}
