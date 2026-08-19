class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            reserved[row] |= (1 << col);
        }
        
        int maxFamilies = n * 2;
        
        for (const auto& [row, mask] : reserved) {
            maxFamilies -= 2;
            
            bool left = !(mask & 60);  
            bool right = !(mask & 960); 
            bool middle = !(mask & 240); 
            
            if (left && right) {
                maxFamilies += 2; 
            } else if (left || right || middle) {
                maxFamilies += 1; 
            }
        }
        
        return maxFamilies;
    }
};