class Solution {
public:
    /**
     * @param words: an array of string
     * @param k: An integer
     * @return: an array of string
     */
    vector<string> topKFrequentWords(vector<string> &words, int k) {
        vector<string> res;
        unordered_map<string, int> dictionary;
        
        if (words.size() == 0) 
            return res;
        
        auto compare = [&](const string& word1, const string& word2) {
            if (dictionary[word2] == dictionary[word1]) 
                return word2 < word1;
            return dictionary[word2] > dictionary[word1];  
        };  //words of higher frequency appears first; if same freqency, lower alphabet first
        
        priority_queue<string, vector<string>, decltype(compare)> pq(compare);
        
        for (auto word : words) {  //save frequency of each word
            if (dictionary.find(word) == dictionary.end()) 
                dictionary[word] = 1;
            else 
                dictionary[word] += 1;
        }
        
        for (auto elem : dictionary) 
            pq.push(elem.first);
        
        for (int i = 0; i < k; i++) {
            res.emplace_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};

/*
	471. Top K Frequent Words
	Given a list of words and an integer k, return the top k frequent words in the list.

	Example
	Given

	[
	    "yes", "lint", "code",
	    "yes", "code", "baby",
	    "you", "baby", "chrome",
	    "safari", "lint", "code",
	    "body", "lint", "code"
	]
	for k = 3, return ["code", "lint", "baby"].

	for k = 4, return ["code", "lint", "baby", "yes"],

	Challenge
	Do it in O(nlogk) time and O(n) extra space.

	Notice
	You should order the words by the frequency of them in the return list, the most frequent one comes first. If two words has the same frequency, the one with lower alphabetical order come first.
*/