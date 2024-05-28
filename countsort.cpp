#include<iostream>
using namespace std;
int main() {
    int a[10],b[10];
    int i,max,j,n=10;
    cout<<"Enter any 10 numbers : ";
    for(i=0;i<n;i++)
    cin>>a[i];
    max = a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    int *cnt = new int[max+1];
    for(i=0;i<=max;i++)
    cnt[i]=0;
    
    for(i=0;i<n;i++)
    {
        cnt[a[i]]++;
    }
    for(i=1;i<=max;i++)
    {
        cnt[i] += cnt[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        b[cnt[a[i]]-1] = a[i];
        cnt[a[i]]--;
    }
    cout<<"\nSorted Array "<<endl;
    for(i=0;i<n;i++)
    cout<<b[i]<<"\t";
    
    return 0;
}
