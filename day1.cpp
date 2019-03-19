#include <stdio.h>
#include <iostream>
#include <vector>
#include <hash_map>
#include <map>
using namespace std;

//求只出现一次的数字
int singleNumber(vector<int>& nums) {
    int re = 0;
    for(size_t i = 0; i < nums.size(); i++)
    {
        re ^= nums[i];
        cout<<"singleNum re=="<<re<<endl;
    }
    return re;
    
}

//求众数，解法1，快排之后去中间数
int partition(vector<int> &vi,int low,int up)
{
    int pivot = vi[up];
    int i = low;
    for(size_t j = low; j < up; j++)
    {
        if(vi[j]<=pivot){
            swap(vi[j],vi[i]);
            i++;
        }
    }
    swap(vi[i],vi[up]);
    return i;
}

void quickSort(vector<int> &vi,int low,int up)
{
    if(low<up){
        int mid = partition(vi,low,up);
        quickSort(vi,low,mid-1);
        quickSort(vi,mid+1,up);
    }
}

int majorityElement(vector<int>& nums) {
    quickSort(nums,0,nums.size()-1);
    return nums[nums.size()/2];
}
//众数2 map
int majorityEle(vector<int>& nums) {
    map<int,int> m;
    for(size_t i = 0; i < nums.size(); i++)
    {
        m[nums[i]]  = m.find(nums[i])==m.end()? 1:m[nums[i]] + 1;
    }

    for(map<int,int>::iterator i=m.begin(); i!=m.end();++i){
        if (i->second > nums.size()/2){
            return i->first;
        }
    }
    
}

//众数3 摩尔投票

int majorityEle2(vector<int>& nums){
    int major,count=0;
    int n = nums.size();
    for(size_t i = 0; i < n; i++)
    {
        if (count == 0){
            major = nums[i];
            count ++;
        }else{
            count += nums[i] == major ? 1: -1;
        }
    }
    return major;
}

//合并两个有序数组
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos = m+n-1;
    m -= 1;
    n -= 1;
    while(m>=0 && n>=0){
        if (nums1[m]>nums2[n]){
            nums1[pos] = nums1[m];
            pos -=1;
            m -=1;
        }else{
            nums1[pos] = nums2[n];
            pos -=1;
            n -=1;
        }
    }

    while(n>=0){
        nums1[pos] = nums2[n];
        pos --;
        n --;
    }        
}

//搜索二维矩阵
bool searchMatrix(vector<vector<int>>& matrix, int target) {
           if(matrix.size() == 0) {
            return false;
        }
        int i = 0;
        int j = matrix[0].size()-1;
        while(i < matrix.size() && j >= 0) {
            if(matrix[i][j] == target) {
                return true;
            }
            if(matrix[i][j] < target) {
                ++ i;
            }
            else {
                -- j;
            }
        }
        return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    int v[] = {2,3,3,4,5,5,6,6,2};
    vector<int> v1(v,v+sizeof(v)/sizeof(int));
    cout<<singleNumber(v1)<<endl;

    printf("----%d",10^11);

    //众数
    int vm[] ={3,2,1,4,4,4,4,4,5};
    vector<int> vmv(vm,vm+sizeof(vm)/sizeof(int));
    cout<<"众数结果"<<majorityEle2(vmv)<<endl;

    //int v2[][] = {{1,4},{2,5}};
    vector<vector<int>> v2v = {{-5}};
    //cout<<v2v[0][0]<<endl;
    cout<<searchMatrix(v2v,-10)<<endl;
    return 0;
}


