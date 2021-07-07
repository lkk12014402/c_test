// Author: kaokao
// Date: 2021-07-07

/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> TwoSum(vector<int> &nums, int target) {
	int len = nums.size();
	map<int, int> m;
	for (int i = 0; i< len; i++) {
	    auto it = m.find(target - nums[i]);
	    if (it != m.end()) return {i, it->second};
	    m[nums[i]] = i;
	}
	return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution;
    vector<int> results = solution.TwoSum(nums, target);
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    return 0;
}

