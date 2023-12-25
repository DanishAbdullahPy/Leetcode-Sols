class Solution {
public:
        string longestPalindrome(string s) {
        string res;
        int resLen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome
            //Considering every position to be the centre of the palindrome
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > resLen) {
                    res = s.substr(left, right - left + 1);
                    resLen = right - left + 1;
                }
                //Expanding outwards to check for even a greater length
                left--;
                right++;
            }

            // Even length
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > resLen) {
                    res = s.substr(left, right - left + 1);
                    resLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return res;
    }
};