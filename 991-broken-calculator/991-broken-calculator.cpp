class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // if startValue is more than target,
        // only way we can reach target is by decreamenting
        if(startValue >= target)
            return startValue-target;
        
        int res=0;
        
        // else we will try to reach startValue from target
        // 1. if target is odd, we'll increment by 1
        // 2. if target is even, we'll divide by 1
        // break out of loop if target becomes equals or less than startValue
        while(startValue < target){
            if(target&1) target++;
            else  target/=2;
            
            res++;
        }
        
        // if target has become less, we need to increment until it equals startValue
        if(target < startValue){
            res += (startValue-target);
        }
        
        return res;
    }
};