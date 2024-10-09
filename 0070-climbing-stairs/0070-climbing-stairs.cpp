class Solution {
public:
    int climbStairs(int n) {
        int perv1 = 1;
        int perv2 =1;
        int current ;
        if(n==0 | n==1)
            return 1;
        else{
            for(int i =2; i<=n; ++i){
                current = perv1 + perv2;
                perv2 = perv1;
                perv1 = current;
            }
            return current;
        }
    }
};