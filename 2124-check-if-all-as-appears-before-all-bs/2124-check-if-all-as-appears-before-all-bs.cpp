class Solution {
public:
    bool checkString(string s) {
        bool seenb=false;
        for(char i:s)
        {
            if(i=='b')
            {
                seenb=true;
            }
            else if(seenb)
            {
                return false;
            }
        }
        return true; 
    }
};