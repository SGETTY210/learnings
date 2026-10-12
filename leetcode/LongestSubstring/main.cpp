#include <iostream>
#include <string>

int lengthOfLongestSubstring(std::string s, std::string sub) {

  // std::cout << "s=" << s << " sub= " << sub << std::endl;

  // Base Case - s is empty
  if (s.length() == 0)
    return sub.length();

  // Check the first character of s.
  char c = s[0];
  std::string remaining = s.substr(1);

  // If c is not in substring then its the best of finding a new substring
  // in the remainder of s or its adding this this character to the substring
  if (sub.find(c) == std::string::npos) {
    return std::max(std::max(lengthOfLongestSubstring(remaining, ""),
                             lengthOfLongestSubstring(remaining, sub + c)),
                    (int)sub.length());
  }

  // if c is already in the substring. then this substring was either the best
  // or its
  // another substring later on in remaining
  return std::max(lengthOfLongestSubstring(remaining, ""), (int)sub.length());
}

int lengthOfLongestSubstring(std::string s) {
  return lengthOfLongestSubstring(s, "");
}

int main(int argc, char **argv) {
  std::string example1 = "abcabcbb";
  std::cout << "Example 1: " << example1
            << " Result: " << lengthOfLongestSubstring(example1) << std::endl;

  std::string example2 = "bbbbb";
  std::cout << "Example 2: " << example2
            << " Result: " << lengthOfLongestSubstring(example2) << std::endl;

  std::string example3 = "pwwkew";
  std::cout << "Example 3: " << example3
            << " Result: " << lengthOfLongestSubstring(example3) << std::endl;

  return 0;
}
