class Solution {
public:
//     int fib(int n) {
//         if(n<=1) return n;
        
//         unsigned int fib[n+1];
//         fib[0]=0;
//         fib[1]=1;
        
//         for(int i=2;i<=n;i++){
//             fib[i] = fib[i-1]+fib[i-2];
//         }
//         return fib[n];
//     }
    
    int fib(int n) {
        if(n<=1) return n;
        return fib(n-2) + fib(n-1);
    }
};