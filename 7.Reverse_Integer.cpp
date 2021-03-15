class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        
        while(x != 0)
        {
            int digit = x % 10;
            int temp = 10 * temp + digit;
            
            if((temp - digit)/10 != reversed)
                return 0;
            
            reversed = temp;
            
            x /= 10;
        }
        
        return reversed;
    }
};