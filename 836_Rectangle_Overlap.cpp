class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int dx = rec1[2] - rec2[0];
        int dy = rec1[3] - rec2[1];
    
        return (dx >= 0 && dy >= 0 && (dx != 0 && dy != 0)) || (dx <= 0 && dy <= 0 && (dx != 0 && dy != 0));
    }
};