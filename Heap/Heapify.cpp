class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
     
    void heapify(vector<int> &A) {
        int vlen = A.size();
        
        for(int i = (vlen / 2);i >= 0;i--)
            min_heapify(A, i, vlen);
    }
    
private:
    void min_heapify(vector<int> &A, int i, int len) {
        int l = 2 * i + 1, r = 2 * i + 2;  
        int small = i;  
        if(l < len && A[l] < A[i])
                small = l;  

        if(r < len && A[r] < A[small])   
                small = r;  

        if(small != i) {
            swap(A[i], A[small]);  
            min_heapify(A, small, len);  
        }  
    }    
};

/*
    130. Given an integer array, heapify it into a min-heap array.

    For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].
    Example
    Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.

    Challenge
    O(n) time complexity

    Clarification
    What is heap?

    Heap is a data structure, which usually have three methods: push, pop and top. where "push" add a new element the heap, "pop" delete the minimum/maximum element in the heap, "top" return the minimum/maximum element.

    What is heapify?
    Convert an unordered integer array into a heap array. If it is min-heap, for each element A[i], we will get A[i * 2 + 1] >= A[i] and A[i * 2 + 2] >= A[i].

    What if there is a lot of solutions?
    Return any of them.
*/