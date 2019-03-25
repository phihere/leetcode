#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <limits.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
*/

size_t factorial(int n,int ns = 0)
{
    if (ns == 0) ns = n;
    size_t v = (size_t)n;
    while (n > 1 && ns>1)
    {
        --n;
        --ns;
        v *= n;
    }
    // cout<<"factorial"<<v<<endl;
    return v;
}

int combination(int n, int r)
{
    if (n == r)
        return 1;
    return factorial(n,r) / factorial(r);
}
//排列组合方式容易溢出，其实最简单的就是斐波那契数列的应用
int climbStairs1(int n)
{
    int d = n;
    int s = 0;
    int sum = 0;
    while(d>=s){
        sum += combination(d,s==0?d:s);
        d--;
        s++;
    }
    return sum;
}

int climbStairs(int n){
    if (n<3) return n;
    int last1 = 1;
    int last2 = 2;
    int sum = 0;
    int index = 3;
    while (index<=n){
        sum = last1 + last2;
        last1 = last2;
        last2 = sum;
        index++;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    cout<<climbStairs(10)<<endl;
    // cout<<comb(0,10,2)<<endl;
    return 0;
}
