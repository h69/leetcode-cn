#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;

    unordered_set<char> window;

    for (int left = 0, right = 0; right < s.length(); right++) {
      while (window.find(s[right]) != window.end()) {
        window.erase(s[left]);
        left++;
      }
      window.insert(s[right]);

      result = max(result, right - left + 1);
    }

    return result;
  }
};

int main() {
  string s = "pwwkew";

  Solution solution;
  int result = solution.lengthOfLongestSubstring(s);

  cout << result << endl;

  return 0;
}