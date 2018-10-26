class Solution {
public:
    /**
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        if(n<0)
            return false;
        
        int numBits = floor(log2(n)) + 1;
        // The binary form of right most Nth of 2 is like '0000100000' same as shifting 1 N times
        return n == (1 << (numBits - 1));  
    }
};