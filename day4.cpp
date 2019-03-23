#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <limits.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

class MinStack
{

  public:
  private:
    int min = INT_MAX;

  public:
    //原始栈
    stack<int> st;
    //存放最小值的栈
    stack<int> minstack;
    /** initialize your data structure here. */
    MinStack()
    {
    }
    void push(int x)
    {
        //如果原始栈为空或者插入的值小于栈内最小值
        if (st.empty() || x <= min)
        {
            //先把数插入到原始栈
            st.push(x);
            //再把数插入到存放最小值的栈
            minstack.push(x);
            //标记最小值(这个最小值即为存放最小值栈的栈顶元素，也可以写min = minstack.top())
            min = x;
        }
        else
        {
            //如果插入的值大于最小值，直接入原始栈，最小值栈不必再入
            st.push(x);
        }
    }

    void pop()
    {
        //判断原始栈栈顶元素是否和最小值栈栈顶元素相同
        if (st.top() == minstack.top())
        {
            //如果相同，把原始栈和最小值栈栈顶元素一起删去
            st.pop();
            minstack.pop();
            //判断删除之后，栈内是否为空
            if (st.empty())
            {
                //如果为空则重新标记最小值
                min = INT_MAX;
            }
            else
                //如果不为空则最小值即为小最小值栈的栈顶元素
                min = minstack.top();
        }
        else
        {
            //如果不相同，直接删除原始栈的栈顶元素，最小值仍然不变
            st.pop();
        }
    }

    int top()
    {
        //由于原始栈么有改变，所以直接返回栈顶元素
        return st.top();
    }

    int getMin()
    {
        //最小值栈的栈顶元素即为最小值
        return minstack.top();
    }
};

/*
数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
*/
int findKthLargest(vector<int> &nums, int k)
{
    if (k < 1 || k > nums.size() || nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

/*
 数据流的中位数
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
进阶:

如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
*/
class MedianFinder
{
  public:
    /** initialize your data structure here. */
    vector<int> m_v;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (m_v.size() == 0)
        {
            m_v.push_back(num);
            return;
        }
        if (num <= m_v[0])
        {
            m_v.insert(m_v.begin(), num);
            return;
        }
        else if (num >= m_v[m_v.size() - 1])
        {
            m_v.push_back(num);
            return;
        }

        size_t l = 0;
        size_t r = m_v.size() - 1;

        while (l <= r)
        {
            size_t mid = l + (r - l) / 2;
            auto mv = m_v[mid];
            if (mv <= num && num <= m_v[mid + 1])
            {
                m_v.insert(m_v.begin() + mid + 1, num);
                break;
            }
            else if (num > mv)
            {
                l = mid + 1;
                continue;
            }
            else if (num <= mv && num >= m_v[mid - 1])
            {
                m_v.insert(m_v.begin() + mid, num);
                break;
            }
            else if (num < mv)
            {
                r = mid - 1;
            }
        }
    }

    double findMedian()
    {
        auto len = m_v.size();
        if (len % 2 == 0)
        {
            auto v1 = m_v[len / 2];
            auto v2 = m_v[len / 2 - 1];
            auto result = (double)(v1 + v2) / 2.f;
            return result;
            // return (double)(m_v[len/2]+m_v[len/2-1]/2)/2.f;
        }
        else
        {
            return (double)m_v[(len - 1) / 2];
        }
    }
};

/*
题目描述
评论 (1.4k)
题解
提交记录
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
vector<int> twoSum(vector<int> &nums, int target)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                vector<int> iv;
                iv.push_back(i);
                iv.push_back(j);
                return iv;
            }
        }
    }
}

/*
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
    */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *newNode(ListNode *n, const char *s, int index)
{
    if (n->next == NULL && index >= 0)
    {
        n->next = new ListNode(s[index] - '0');
        return newNode(n->next, s, --index);
    }
    return n;
}
//此方法未考虑溢出问题，需采用大数相加
ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2)
{
    auto l = l1->next;
    auto s1 = to_string(l1->val);
    while (l != NULL)
    {
        s1 = to_string(l->val) + s1;
        l = l->next;
    }
    l = l2->next;
    auto s2 = to_string(l2->val);
    while (l != NULL)
    {
        s2 = to_string(l->val) + s2;
        l = l->next;
    }
    // ListNode *newl = new ListNode(atoi(s1.c_str()) + atoi(s2.c_str()));
    auto s = to_string(atol(s1.c_str()) + atol(s2.c_str()));
    auto chars = s.c_str();
    ListNode *n = new ListNode(chars[s.size() - 1] - '0');
    if (s.size() >= 2)
    {
        newNode(n, chars, s.size() - 2);
    }

    return n;
}

//常规解法
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *re = new ListNode(0);
    auto tmp = re;
    int carry = 0;
    int sum = 0;
    while (l1 || l2 || carry > 0)
    {
        sum += carry;
        if (l1)
        {
            sum += l1->val;
        }
        if (l2)
        {
            sum += l2->val;
        }

        if (sum >= 10)
        {
            sum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        tmp->next = new ListNode(sum);
        tmp = tmp->next;
        sum = 0;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return re->next;
}

int main()
{
    int vi[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    vector<int> vv(vi, vi + sizeof(vi) / sizeof(int));
    // cout << findKthLargest(vv, 4) << endl;

    MedianFinder m;
    m.addNum(6);
    m.addNum(10);
    m.addNum(2);
    m.addNum(6);
    m.addNum(5);
    m.addNum(0);
    m.addNum(6);
    m.addNum(3);
    m.addNum(1);
    m.addNum(0);
    m.addNum(0);
    // m.addNum(6);
    // cout << m.findMedian() << endl;

    ListNode *n1 = new ListNode(9);
    newNode(n1, "9999999999", 8);
    ListNode *n2 = new ListNode(9);
    newNode(n2, "9999999999", 8);

    auto n = addTwoNumbers(n1, n2);
    cout << n << endl;
    return 0;
}