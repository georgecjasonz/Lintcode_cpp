/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
 
struct compare {
    bool operator()(const Record& A, const Record& B) {
        return (A.id == B.id)? (A.score < B.score): (A.id > B.id);
    }
};       
 

class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        priority_queue<Record, vector<Record>, compare> pq;
        map<int, double> result;
        
        for (auto result : results){
            pq.push(result);
        }
        
        
        while (!pq.empty()){
            int curr_id = pq.top().id;
            double avg = 0;
            for (int i = 0; i < 5; i++){
                avg += pq.top().score;
                pq.pop();
            }
            avg /= 5;
            result.emplace(curr_id, avg);
            
            while (!pq.empty() && pq.top().id == curr_id)
                pq.pop();
        }
        
        return result;
    }
};

/*
	613. High Five
	There are two properties in the node student id and scores, to ensure that each student will have at least 5 points, find the average of 5 highest scores for each person.

	Input
	[[1,91],[1,92],[2,93],[2,99],[2,98],[2,97],[1,60],[1,58],[2,100],[1,61]]
	Output
	1: 72.40
	2: 97.40
*/