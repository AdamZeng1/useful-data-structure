//
// Created by adamzeng on 2019-06-17.
//

#include <cstdio>

const int maxn = 30;

int n, V, maxValue = 0; // 物品件数n, 背包容量V, 最大价值maxValue

int w[maxn], c[maxn]; // w[i]为每件物品的重量, c[i]为每件物品的价值
// DFS, index为当前处理的物品编号
// sumW和sumC分别为当前总重量和当前总价值
void DFS(int index, int sumW, int sumC) {
    if (index == n) { // 已经完成对n件物品的选择(死胡同)
        if (sumW <= V && sumC > maxValue) {
            maxValue = sumC; // 不超过背包容量时更新最大价值maxValue
        }
        return;
    }
    // 岔道口
    DFS(index + 1, sumW, sumC);
    DFS(index + 1, sumW + w[index], sumC + c[index]);
}

int ans;

void DFS1(int index, int sumW, int sumC) {
    if (index == n) {
        return;
    }
    DFS1(index + 1, sumW, sumC);
    // 只有加入第index件物品后未超过容量V,才能继续
    if (sumW + w[index] <= V) {
        if (sumC + w[index] > ans) {
            ans = sumC + c[index]; // 更新最大价值maxValue
        }
        DFS1(index + 1, sumW + w[index], sumC + c[index]);
    }
}

int main() {
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    DFS(0, 0, 0);
    printf("%d\n", maxValue);
    return 0;
}