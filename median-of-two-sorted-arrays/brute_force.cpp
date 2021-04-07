#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> results;

    int n = 0, m = 0;

    if (((nums1.size() + nums2.size()) % 2) != 0) {
      n = m = (nums1.size() + nums2.size()) / 2 + 1;
    } else {
      n = (nums1.size() + nums2.size()) / 2;
      m = n + 1;
    }

    int i = 0, j = 0;

    while (i < nums1.size() || j < nums2.size()) {
      if (j >= nums2.size() || (i < nums1.size() && nums1[i] < nums2[j])) {
        results.push_back(nums1[i]);
        i++;
      } else {
        results.push_back(nums2[j]);
        j++;
      }

      if (n == m && results.size() == n) {
        return *(results.end() - 1);
      } else if (n != m && results.size() == m) {
        return (*(results.end() - 1) + *(results.end() - 2)) / 2.0;
      }
    }

    return 0;
  }
};

int main() {
  vector<int> nums1;
  nums1.push_back(1);
  nums1.push_back(3);

  vector<int> nums2;
  nums2.push_back(2);

  Solution solution;
  double result = solution.findMedianSortedArrays(nums1, nums2);

  cout << result << endl;

  return 0;
}