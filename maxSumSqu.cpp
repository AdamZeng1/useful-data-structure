//
// Created by adamzeng on 2019-06-22.
//

#include <stdio.h>
#include<vector>

const int maxn = 100;
// 序列A中n个数选k个数使得和为x,最大平方和为maxSumSqu
int n, k, x, maxSumSqu = -1;
// temp存放临时方案,ans存放平方和最大的方案
std::vector<int> temp, ans;
// 当前处理index号整数,当前已选整数个数为nowK
// 当前已选整数之和为sum,当前已选整数平方和为sumSqu
int A[maxn];

void DFS(int index, int nowK, int sum, int sumSqu) {
    if (nowK == k && sum == x) {
        if (sumSqu > maxSumSqu) {
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }

    // 已经处理完n个数, 或者超过k个数,或者和超过x, 返回
    if (index == n || nowK > k || sum > x) return;

    // 选index号数
    temp.push_back(A[index]);
    DFS(index + 1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
    temp.pop_back();

    // 不选index号数
    DFS(index + 1, nowK, sum, sumSqu);
}
