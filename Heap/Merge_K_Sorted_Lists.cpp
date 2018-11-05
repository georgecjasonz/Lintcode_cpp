/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
 
struct compare {
    bool operator()(const ListNode *l, const ListNode *r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {

        if(lists.size() == 0) 
            return nullptr;
        
        priority_queue<ListNode* , vector<ListNode *>, compare> pq;
        
        for(auto i : lists){
            if(i){
                pq.push(i);
            }
        }
        
        ListNode *ret = new ListNode(-1);
        ListNode *tail =  ret;
        
        while(!pq.empty()){
            ListNode *head = pq.top();
            pq.pop();
            tail->next = head; 
            tail = head;
            if(head->next){
                pq.push(head->next);
            }
        }
        
        return ret->next;
    }
};

/*
	104. Merge k sorted linked lists and return it as one sorted list.

	Analyze and describe its complexity.

	Example
	Given lists:

	[
	  2->4->null,
	  null,
	  -1->null
	],
	return -1->2->4->null.
*/