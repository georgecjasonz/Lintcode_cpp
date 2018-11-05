class Solution {
public:
    /*
    * @param k: An integer
    */
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    
    Solution(int k) {
        this -> k = k;
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        if (pq.size() < k) 
            pq.push(num);
        else if (pq.top() < num) {
            pq.pop();
            pq.push(num);
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        vector<int> res;
        int n = pq.size(), i = 0;
        
        while (i < n && i < k) {
            res.push_back(pq.top());
            pq.pop();
            ++i;
        }

        for (int i = 0; i < n; i++)
            pq.push(res[i]);
        
        sort(res.begin(), res.end(), greater<>());
        
        return res;
    }
};

/*
    545. Top k Largest Numbers II
    Implement a data structure, provide two interfaces:

    add(number). Add a new number in the data structure.
    topk(). Return the top k largest numbers in this data structure. k is given when we create the data structure.
    Example
    s = new Solution(3);
    >> create a new data structure.
    s.add(3)
    s.add(10)
    s.topk()
    >> return [10, 3]
    s.add(1000)
    s.add(-99)
    s.topk()
    >> return [1000, 10, 3]
    s.add(4)
    s.topk()
    >> return [1000, 10, 4]
    s.add(100)
    s.topk()
    >> return [1000, 100, 10]
*/