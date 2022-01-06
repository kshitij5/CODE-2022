// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    // using optimized map
    int *findTwoElement(int *arr, int n) {
        vector<int> map(n+1, 0);
        
        // marking frequency of a number
        for(int i=0; i<n; i++) map[arr[i]] += 1;
        
        int *res=new int[2];
        for(int i=1; i<=n; i++) {
            int it = map[i];
            
            // if frequency is 0, its missing
            if(it == 0) res[1] = i;
            // if frequency is 2, its repeating
            if(it == 2) res[0] = i;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends