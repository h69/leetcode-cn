#include <iostream>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string result;

    for (int i = 0; i < s.length(); i++) {
      for (int j = i; j < s.length(); j++) {
        string substr = s.substr(i, j - i + 1);

        if (substr.length() > result.length() && substr == string(substr.rbegin(), substr.rend())) {
          result = substr;
        }
      }
    }

    return result;
  }
};

int main() {
  string s = "babad";

  Solution solution;
  string result = solution.longestPalindrome(s);

  cout << result << endl;

  return 0;
}