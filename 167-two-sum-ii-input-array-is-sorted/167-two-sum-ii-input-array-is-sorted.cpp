class Solution {
public: 
    // using map
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> map;
        
        for(int i=0;i<numbers.size();i++) {
            if(map.find(numbers[i])!=map.end()){
                return {map[numbers[i]], i+1};
            }
            map[target-numbers[i]] = i+1;
        }
        return {};
    }
    
    // could also be solved using binary search/two pointer 
    // since its sorted in non decreasing order
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int l = 0;
//         int r = numbers.size() -1;

//         while(l < r){
//             if(numbers[l] + numbers[r] == target){
//                 return {l+1,r+1};;
//             }
//             else if(numbers[l] + numbers[r] > target){
//                 r--;
//             }
//             else{
//                 l++;
//             }
//         }
//         return {};
//     }
    
};