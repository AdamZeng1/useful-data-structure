//
// Created by adamzeng on 2019-06-24.
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 110;

struct node {
    int weight; // 数据域
    vector<int> child; // 指针域
} Node[MAXN]; // 结点数组

bool cmp(int a, int b) {
    return Node[a].weight > Node[b].weight; // 按结点数据域从大到小排序
}

int n, m, S; // 结点数、边数、给定的和
int path[MAXN]; // 记录路径

// 当前访问结点为index, numNode为当前路径path上的结点个数
// sum为当前的结点点权和
void DFS(int index, int numNode, int sum) {
    if (sum > S) return; // 当前和sum超过S,直接返回
    if (sum == S) { // 当前和sum等于S
        if (Node[index].child.size() != 0) return; // 还没到叶子结点，直接返回
        // 到达叶子结点，此时path[]中存放了一条完整的路径，输出它
        for (int i = 0; i < numNode; ++i) {
            printf("%d", Node[path[i]].weight);
            if (i < numNode - 1) printf(" ");
            else printf("\n");
        }
        return; // 返回
    }
    for (int i = 0; i < Node[index].child.size(); ++i) { // 枚举所有子结点
        int child = Node[index].child[i]; // 结点index的第i的子结点编号
        path[numNode] = child; // 将结点child加到路径path末尾
        DFS(child, numNode + 1, sum + Node[child].weight); // 递归进入下一层
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &S);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &Node[i].weight);
    }
    int id, k, child;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &id, &k); // 结点编号,孩子个数
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child);
            Node[i].child.push_back(child); // child为结点id的孩子
        }
        // 每一个结点的child's vector中的结点序号都是从小到大排列
        sort(Node[id].child.begin(), Node[id].child.end(), cmp); // 排序
    }

    path[0] = 0; //路径的第一个结点设置为0号结点
    DFS(0, 1, Node[0].weight); // DFS求解
    return 0;
}


