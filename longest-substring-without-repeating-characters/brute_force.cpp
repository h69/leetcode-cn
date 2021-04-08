#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
      string substr;
      for (int j = i; j < s.length(); j++) {
        substr = s.substr(i, j - i + 1);
        if (substr.find(s[j + 1]) != string::npos) {
          break;
        }
      }

      if (substr.length() > result) {
        result = substr.length();
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