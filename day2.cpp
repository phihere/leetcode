#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int superEggDrop(int K, int N)
{
    if (K == 1)
        return N;
    double e;
    unsigned int n = 65535; //用65535表示数学意义上的‘无穷大’
    e = 1 + 1.0 / n;        //注意一定写1.0
    e = pow(e, n);
    int ln = ceil(log(N));
    if (K >= ln)
    {
        return ln + 1;
    }
    else
    {
        auto v = N / pow(e, K);
        auto v2 = ceil(v);
        return (v == v2 ? v2 + 1 : v2) + K;
    }
}

//验证回文串
/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

解题思路，首尾开始向中间遍历
*/

bool isPalindrome(string s)
{
    if (s.length() == 0)
        return true;
    auto schar = s.c_str();
    size_t l = 0;
    size_t r = s.length() - 1;
    while (l < r)
    {
        if (!isalnum(schar[l]))
        {
            l++;
            continue;
        }
        if (!isalnum(schar[r]))
        {
            r--;
            continue;
        }
        if (isdigit(schar[l]) && isdigit(schar[r])) //两个都是数字
        {
            if (schar[l] == schar[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }
        else if (!isdigit(schar[l]) && !isdigit(schar[r])) //两个非数字
        {
            if (tolower(schar[l]) == tolower(schar[r]))
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

/*
 乘积最大子序列
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/

int maxProduct(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    int last = nums[0];
    int now = nums[0];
    // bool iscontinuous = true;
    vector<int> num2;
    // vector<int>::iterator it;
    // it = num2.begin();
    // num2.insert(it,now);
    for (size_t i = 1; i < nums.size(); i++)
    {
        int in = nums[i];
        num2.push_back(nums[nums.size() - i]);
        // cout << "the in==" << in << endl;
        if (in == 0)
        {
            now = 0;
        }
        else
        {
            if (now == 0)
            {
                now = in;
            }
            else
            {
                now = in * now;
            }
        }
        // cout << "the now==" << now << endl;
        if (now > last)
        {
            last = now;
        }
    }
    num2.push_back(nums[0]);

    now = num2[0];
    int last2 = num2[0];
    for (size_t i = 1; i < num2.size(); i++)
    {
        int in = num2[i];
        // cout << "the in==" << in << endl;
        if (in == 0)
        {
            now = 0;
        }
        else
        {
            if (now == 0)
            {
                now = in;
            }
            else
            {
                now = in * now;
            }
        }
        // cout << "the now==" << now << endl;
        if (now > last2)
        {
            last2 = now;
        }
    }
    return last > last2 ? last : last2;
}

int main(int argc, char const *argv[])
{
    // cout<<log()<<endl;
    // cout << superEggDrop(2, 6) << endl;
    // cout << superEggDrop(1, 2) << endl;
    // cout << superEggDrop(1, 4) << endl;

    // cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
    int i[] = {-2, 3, -4};
    vector<int> vi(i, i + sizeof(i) / sizeof(int));
    cout << "max product==" << maxProduct(vi) << endl;
    return 0;
}