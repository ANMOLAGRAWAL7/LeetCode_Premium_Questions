/*
You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.
*/
class FirstUnique {
    unordered_map<int, int> freq;
    queue<int> q;

public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
        if (!q.empty()) return q.front();
        return -1;
    }
    
    void add(int value) {
        freq[value]++;
        if (freq[value] == 1) {
            q.push(value);
        }
    }
};
