#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
旋转数组
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的原地算法。
*/
//解法1：
void rotate1(vector<int> &nums, int k)
{
    if (k > nums.size())
    {
        k = k % nums.size();
    }
    size_t len = nums.size();
    for (size_t i = 0; i < len - k; i++)
    {
        nums.push_back(nums[0]);
        nums.erase(nums.begin());
    }
}

//解法2
void rotate(vector<int> &nums, int k)
{
    if (k > nums.size())
    {
        k = k % nums.size();
    }
    size_t len = nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.begin() + k);
}
int main(int argc, char const *argv[])
{
    int v[] = {8, 2, 0, 4};
    vector<int> v1(v, v + sizeof(v) / sizeof(int));
    rotate(v1, 11939);
    for (auto vv : v1)
    {
        cout << vv << endl;
    }
    return 0;
}
