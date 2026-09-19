class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int px = max(x1,min(x2,xCenter));
        int py = max(y1,min(y2,yCenter));
        int dx = xCenter - px;
        int dy = yCenter - py;
        int d = dx * dx + dy * dy;
        if(d <= radius*radius) return true;
        return false;
    }
};