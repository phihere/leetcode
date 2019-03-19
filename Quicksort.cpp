#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
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

void sortmp(vector<int> &vi)
{
    for(size_t i = 0; i < vi.size(); i++)
    {
        for(size_t j = i+1; j < vi.size(); j++)
        {
            if(vi[i]>vi[j]){
                swap(vi[i],vi[j]);
            }
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    // int a[] = {3,5,7,9,2,3,1,0,7,5,4};
	// vector<int> va(a, a+11);
 
	// cout<<"Before quicksort:\n";
	// for(auto x:va)
	// 	cout<<x<<" ";
	// cout<<endl;
    const int count= 10000000;
    int *b = (int*)malloc(sizeof(int) * count);
    //memset(b,sizeof(int)*10000); 
    for(size_t i = 0; i < count; i++)
    {
        b[i] = rand() % count;
        /* code */
    }
    
    vector<int> va(b,b+count);
    time_t start = time(0);
    quickSort(va,0,va.size()-1);
    time_t end = time(0);
    cout<<(end-start)*1000<<endl;

    // vector<int> vc(b,b+count);
    // start = time(0);
    // sortmp(vc);
    // end = time(0);
    // cout<<end-start<<endl;
    // for(size_t i = 0; i < va.size(); i++)
    // {
            
    //     cout<<va[i]<<" ";
    //     cout<<endl;
    // }
    return 0;
}