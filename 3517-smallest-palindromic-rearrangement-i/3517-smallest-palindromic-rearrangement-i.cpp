class Solution {
public:
    string smallestPalindrome(string s) {
        int half=s.length()/2;
        string first_half=s.substr(0,half);
        sort(first_half.begin(),first_half.end());
        string second_half=first_half;
        reverse(second_half.begin(),second_half.end());
        if(s.length()%2!=0)
        {
            char mid=s[half];
            return first_half+mid+second_half;
        }
        return first_half+second_half;
    }
};