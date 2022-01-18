// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    // couldn't do by myself
    void dfs(int src, vector<int>& visited, string& res, vector<int> adj[]){
	    visited[src] = 1;
	    for(auto i : adj[src]){
	        if(!visited[i]){
	            dfs(i,visited,res,adj);
	        }
	    }
	    res = char(src+'a') + res;
	}
    
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for(int i=1; i<N; i++){
            string s1 = dict[i-1];
            string s2 = dict[i];
            
            for(int j=0; j<min(s1.size(),s2.size()); j++){
                if(s1[j] != s2[j]){
                   int u = s1[j] - 'a';
                   int v = s2[j] - 'a';
                   adj[u].push_back(v);
                   break;
                }
            }
        }
        
        vector<int>visited(K,0);
        string res="";
        
	    for(int i=0; i<K; i++){
	        if(!visited[i]){
	            dfs(i,visited,res,adj);
	        }
	    }
	    return res;
    }
};


// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends