//
// Created by adamzeng on 2019-07-06.
//

#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
const int maxn = 100010;

vector<int> child[maxn]; // 存放树
double p, r;
// maxDepth为最大深度,num为最大深度的叶结点个数
int n, maxDepth = 0, num = 0;

void DFS(int index, int depth) {
    if (child[index].size() == 0) { // 如果该结点为叶结点
        if (depth > maxDepth) { // 如果该节点的深度大于maxDepth
            maxDepth = depth; // 更新最大深度
            num = 1; // 重新从1开始计数
        } else if (depth == maxDepth) { // 深度等于最大深度
            num++;
        }
        return; // 叶结点但深度小于最深
    }
    for (int i = 0; i < child[index].size(); ++i) {
        DFS(child[index][i], depth + 1); // 深度加一
    }
}

int main() {
    int father, root;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &father);
        if (father != -1) {
            child[father].push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root, 0);
    printf("%.2f %d\n", p * pow(1 + r, maxDepth), num); // 输出结果
}

