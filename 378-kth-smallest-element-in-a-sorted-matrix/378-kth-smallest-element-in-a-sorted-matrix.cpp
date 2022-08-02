#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // Brute force approach
    // // works just fine but isn't the best solution
    // // TC - O(n^2)
    // // SC - O(n^2)
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     vector<int> linearMatrix;

    //     for(auto row: matrix) {
    //         for(int element: row) {
    //             linearMatrix.push_back(element);
    //         }
    //     }

    //     sort(linearMatrix.begin(), linearMatrix.end());
    //     return linearMatrix[k-1];
    // }

    // Using the given information that the matrix is already sorted 
    // row wise and column wise it is clear that the first efficient solution
    // that one should think is using binary search technique
    // TC - O(nlogn)
    // SC - O(1)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); //size of row/column

        int left = matrix[0][0];
        int right = matrix[n-1][n-1];

        while(left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            for(auto row: matrix) {
                count += upper_bound(row.begin(), row.end(), mid) - row.begin();
                cout << upper_bound(row.begin(), row.end(), mid) - row.begin() << endl;
            }

            if(count < k) {
                left = mid + 1;
            }else {
                right = mid;
            }
        }
        return left;
    }
};