class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev(1, 1);
        if(rowIndex == 0) return prev;

        // vector<int>
        for(int i = 2; i <= rowIndex + 1; i++) {
            vector<int> row(rowIndex, 1);
            
            for(int j = 1; j < i - 1; j++) {
                row[j] = prev[j - 1] + prev[j];
                // if()
            }
            prev = row;
        }

        return prev;
    }
};