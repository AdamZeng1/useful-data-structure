//
// Created by adamzeng on 2019-07-03.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


const int N = 110;

vector<int> G[N]; // 存放树
int leaf[N] = {0}; // 存放每层的叶子结点个数
int max_h = 1; // 树的深度

void DFS(int index, int h) { // index为当前遍历到的结点编号,h为当前深度
    max_h = max(h, max_h);
    if (G[index].size() == 0) { // 如果该结点是叶子结点
        leaf[h]++;
        return;
    }
    for (int i = 0; i < G[index].size(); ++i) { // 枚举所有子结点
        DFS(G[index][i], h + 1);
    }
}

int main() {
    int n, m, parent, child, k;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &parent, &k); // 父结点编号及子结点个数
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child);
            G[parent].push_back(child); // 加边
        }
    }
    DFS(1, 1); // 初始入口为根结点与第一层
    printf("%d", leaf[1]);
    for (int i = 2; i <= max_h; ++i) {
        printf(" %d", leaf[i]);
    }
    return 0;
}

