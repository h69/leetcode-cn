#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> results;

    unordered_map<int, int> hashTable;
    for (int i = 0; i < nums.size(); i++) {
      hashTable[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (hashTable.find(target - nums[i]) != hashTable.end() && hashTable[target - nums[i]] != i) {
        results.push_back(i);
        results.push_back(hashTable[target - nums[i]]);
        return results;
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