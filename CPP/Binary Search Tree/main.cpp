#include <iostream>

using namespace std;

int main()
{
    int binary[20],n,i,k,low,mid,high;
    cout << "enter range of elements:" << endl;
    cin>>n;
    cout<<"enter elements into array"<<endl;
    for(i=0;i<n;i++)
       {

       cin>>binary[i];}
    cout<<"enter search key:"<<endl;
    cin>>k;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(binary[mid]<k)
            low=mid+1;
        else if(binary[mid]>k)
            high=mid-1;
        else break;
    }
    if(binary[mid]==k)
        cout<<"element is found at location"<<mid+1<<endl;
    else
        cout<<"element not found"<<endl;
    return 0;
}

