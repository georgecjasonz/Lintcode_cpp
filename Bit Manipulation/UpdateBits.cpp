class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param i: A bit position
     * @param j: A bit position
     * @return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        //          j---i   
        //n:  10010000000001000
        //          -----     
        //m:        11011
        // 1. Generate a mask for n(11111100000111111)
        // 2. mask & n becomes n preseving all bits in n with i to j set to 0
        // 3. L-Shift m with i times(1101100000) then 'AND' the number above to get the result
        
        int mask;
        
        if (j < 31) {
            mask = ~((1 << (j + 1)) - (1 << i));
        } else {
            mask = (1 << i) - 1;
        }
        return (m << i) + (mask & n);
    }
};