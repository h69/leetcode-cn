#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
      int t = 1;

      for (int j = i + 1; j < s.length(); j++) {
        if (s.substr(i, j - i).find(s[j]) != string::npos) {
          break;
        }
        t++;
      }

      if (t > result) {
        result = t;
      }
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