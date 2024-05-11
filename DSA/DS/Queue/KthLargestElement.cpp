#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int hold = 0;
    // push every number into a priority queue
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) 
            pq.push(nums[i]);
        hold = k;
    }
    
    // upon adding a new element into the pq, pop out the other numbers
    // so that there are only k numbers in the pq everytime
    int add(int val) {
        pq.push(val);
        while (pq.size() > hold)
            pq.pop();
        
        return pq.top();
    }
};

int main() {
    vector<int> v = {4, 5, 8, 2};
    KthLargest kthLargest(3, v);
    kthLargest.add(3);  
    kthLargest.add(5);  
    kthLargest.add(10);  
    kthLargest.add(9);   
    kthLargest.add(4);   

    return 0;
}