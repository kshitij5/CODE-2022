// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    private:
    void f(vector<int>& arr, int n, vector<int>& res, int i, int sum) {
        if(i==n) {
            res.push_back(sum);
            return;
        }
        
        f(arr, n, res, i+1, sum+arr[i]);
        f(arr, n, res, i+1, sum);
        return;
    }
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> res;
        f(arr, n, res, 0, 0);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends