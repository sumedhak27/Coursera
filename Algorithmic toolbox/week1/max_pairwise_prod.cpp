#include <iostream>
using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int arr[n], max1=0, max2=0, maxi1=0;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        if(arr[i]>max1) {
            max1 = arr[i];
            maxi1 = i;
        }     
    }
    for(int i = 0; i<n; i++)
        if(i!=maxi1 && arr[i]>max2)
            max2=arr[i];
    cout<<(ll)(max1)*max2<<endl;
}