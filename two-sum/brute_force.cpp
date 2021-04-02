#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> results;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          results.push_back(i);
          results.push_back(j);
          return results;
        }
      }
    }

    return results;
  }
};

int main() {
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(4);

  int target = 6;

  Solution solution;
  vector<int> results = solution.twoSum(nums, target);

  for (int i = 0; i < results.size(); i++) {
    cout << results[i] << endl;
  }

  return 0;
}