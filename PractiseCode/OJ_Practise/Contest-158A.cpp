// A - E001 数的划分
// Time Limit: 1000/1000MS (C++/Others) Memory Limit: 65536/65536KB (C++/Others)
// Problem Description
// 将整数n分成k份，且每份不能为空，任意两种分法不能相同（不考虑顺序）。
// 例如：n=7，k=3，下面三种分法被认为是相同的。
// 1,1,5；1,5,1；5,1,1；
// 问有多少种不同的分法。

// Input
// 每组数据由一行上的2个整数n，k构成（6 < n ≤ 200,2 ≤ k ≤ 6）。

// Output
// 对每组测试数据，输出不同的分法整数。

// Sample Input
// 7 3
// Sample Output
// 4


#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int Seg(int n, int k, int pre);

int main() {
    int n, k;
    while (cin >> n >> k) {
        cout << Seg(n, k, 1) << endl;
    }
    return 0;
}

int Seg(int n, int k, int pre) {//n是要划分的数字，k是份数，pre是上一次分得的数字，为了避免重复每次分出来的数字都要比pre大
    int ans = 0;
    if (k == 1) {//当把n分成1份时，只有一种分法
            return 1;
    }
    for (int i = pre; i <= n / 2; i++) {//n/2之后的数字是重复的，所以到这里结束循环
        ans += Seg(n - i, k - 1, i);
    }
    return ans;
}