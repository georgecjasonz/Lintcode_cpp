class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b 
     */
    int aplusb(int a, int b) {
         return (b == 0) ? a : aplusb(a ^ b, (a & b) << 1);
    }
};