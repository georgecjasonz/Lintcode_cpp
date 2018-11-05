class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        struct Tuple{
            int x, y, val;
            Tuple(int _x, int _y, int _val): x(_x), y(_y), val(_val){}
        };

        auto compare = [](const Tuple &left, const Tuple& right) {
            return left.val > right.val;
        };

        priority_queue<Tuple, vector<Tuple>, decltype(compare)> pq(compare);
        
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; i++)
            pq.push(Tuple(i, 0, matrix[i][0]));

        for (int i = 0; i < k - 1; i++){
            Tuple t = pq.top();
            pq.pop();

            if (t.y + 1 < n)
                pq.push(Tuple(t.x, t.y + 1, matrix[t.x][t.y + 1]));
        }

        return pq.top().val;
    }
};

/*
    401. Kth Smallest Number in Sorted Matrix
    Find the kth smallest number in at row and column sorted matrix.

    Example
    Given k = 4 and a matrix:

    [
      [1 ,5 ,7],
      [3 ,7 ,8],
      [4 ,8 ,9],
    ]
    return 5

    Challenge
    Solve it in O(k log n) time where n is the bigger one between row size and column size.
*/