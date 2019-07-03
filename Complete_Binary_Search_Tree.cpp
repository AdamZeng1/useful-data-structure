//
// Created by adamzeng on 2019-06-30.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1010;

// n为结点数,number用以存放结点权值,CBT用以存放完全二叉树
// index从小到大枚举number数组
int n, number[manx], CBT[maxn], index = 0;

void inOrder(int root) {// 中序遍历
    if (root > n) return; // 空结点,直接返回
    inOrder(root * 2); // 往左子树递归
    CBT[root] = number[index++]; // 根结点处赋值number[index]
    inOrder(root * 2 + 1); // 往右子树递归
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &number[i]);
    }
    sort(number, number + n); // 从小到大排序
    inOrder(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d", CBT[i]); // CBT数组本身就是层序
        if (i < n) printf(" ");
    }
    return 0;
}