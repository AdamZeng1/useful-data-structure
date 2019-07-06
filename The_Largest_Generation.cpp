//
// Created by adamzeng on 2019-07-06.
//

#include <cstdio>
#include <vector>

using namespace std;
const int MAXN = 1001;

vector<int> Node[MAXN]; // Node[i]代表一个vector<int>,里面存的都是索引为i的子结点的索引
int hashTable[MAXN] = {0}; // 存的是每个level中的结点个数

void DFS(int index, int level) { // index为该结点的索引,level为该节点所在的层级
    hashTable[level]++; // 使这个结点所在的level的结点个数加一
    for (int i = 0; i < Node[index].size(); ++i) { // 遍历每一个结点
        DFS(Node[index][i], level + 1); // level+1是因为进入目前结点的子结点,所以level++
    }
}

int main() {
    int n, m, parent, k, child; // 树的结点个数n,非叶子结点个数m
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &parent, &k); // 父结点的索引,该结点的子结点的个数
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child);
            Node[parent].push_back(child);
        }
    }

    DFS(1, 1);
    int maxLevel = -1, maxValue = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (hashTable[i] > maxValue) {
            maxLevel = i;
        }
    }

    printf("%d %d\n", maxValue, maxLevel); // 输出最大结点数与该层层号
    return 0;
}


