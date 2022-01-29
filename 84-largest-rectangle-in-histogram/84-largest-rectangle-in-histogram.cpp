class Solution {
public:
//     //brute force
//     // tc - o(n2)
//     // sc - o(n)
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size(), mx = 0;
//         // we have to find next consecutive greater heights
//         vector<int> nextgreater(n);
        
//         for(int i=0; i<n; i++) {
//             int l = i-1, r = i+1;
            
//             // elements until greater equal to height[i] rightward
//             while(r < n && heights[i] <= heights[r])    r++;
//             while(l >= 0 && heights[i] <= heights[l])   l--;
            
//             int mxarea = heights[i] * (r-l-1);
//             mx = max(mx, mxarea);
//         }
        
//         return mx;
//     }
    
//     // using stack, next greater element concept
//     // tc - o(n2)
//     // sc - o(n)
    
//     // my algo is, finding left smaller element for each element
//     // also right smaller element index 
//     // that will give us max width
//     int largestRectangleArea(vector<int>& h) {
//         int n = h.size(), mx = 0;
        
//         stack<int> st;
//         vector<int> nextsmallerleft(n), nextsmallerright(n);
        
//         for(int i=0; i<n; i++) {
            
//             while(st.size() && h[i]<=h[st.top()]) {
//                 st.pop();
//             }
            
//             if(st.size()) {
//                 nextsmallerleft[i] = st.top()+1;
//             } else {
//                 nextsmallerleft[i] = 0;
//             }
            
//             st.push(i);
//         }
        
//         while(st.size()) st.pop();
        
//         for(int i=n-1; i>=0; i--) {
            
//             while(st.size() && h[i]<=h[st.top()]) {
//                 st.pop();
//             }
            
//             if(st.size()) {
//                 nextsmallerright[i] = st.top()-1;
//             } else {
//                 nextsmallerright[i] = n-1;
//             }
            
//             st.push(i);
//         }
        
//         for(int i=0; i<n; i++) {
//             // cout << nextsmallerright[i] << " " << nextsmallerleft[i] << endl;
//             mx = max(mx, h[i] * (nextsmallerright[i] - nextsmallerleft[i] + 1));
//         }
        
//         return mx;
//     }
    
    // most optimised stack code
	int largestRectangleArea(vector<int>& height) {
		int n = height.size(), area = 0, h, l;
		stack<int> indexes;
		for (int i = 0; i <= n; i++) {
			while (i == n || (!indexes.empty() && height[indexes.top()] > height[i])) {
				if (i == n && indexes.empty()) h = 0, i++;
				else h = height[indexes.top()], indexes.pop();			
				l = indexes.empty() ? -1 : indexes.top();
				area = max(area, h * (i - l - 1));
			}
			indexes.push(i);
		}
		return area;
	}
};