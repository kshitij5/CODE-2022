// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int zeroes = 0, ones=0, twoes = 0;
        for(int i=0; i<n; i++) {
            if(a[i] == 0) { 
                zeroes++;
            }else if(a[i] == 2) {
                twoes++;
            }else {
                ones++;
            }
        }
        
        int i=0;
        while(zeroes--) a[i++] = 0;
        while(ones--) a[i++] = 1;
        while(twoes--) a[i++] = 2;
        
        return;
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends