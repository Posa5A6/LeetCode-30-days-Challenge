#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to check if valid cuts can be made
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> verticals;   // Stores y-coordinates for vertical cuts
        vector<pair<int, int>> horizontals; // Stores x-coordinates for horizontal cuts
        
        // Extract x and y intervals from rectangles
        for (auto& r : rectangles) {
            horizontals.push_back({r[0], r[2]}); // Store x-range of each rectangle
            verticals.push_back({r[1], r[3]});   // Store y-range of each rectangle
        }
        
        // Check if valid vertical or horizontal cuts exist
        return check(verticals) || check(horizontals);
    }

private:
    // Function to check if we can make two cuts that create three valid sections
    bool check(vector<pair<int, int>>& intervals) {
        ranges::sort(intervals); // Sort intervals by starting coordinate
        int r = 0, res = 0;
        
        // Iterate through intervals to determine if at least three sections exist
        for (auto interval : intervals) {
            if (interval.first >= r) { // New section starts
                res++;
            }
            r = max(r, interval.second); // Update the max right boundary
        }
        
        return res >= 3; // There should be at least three sections
    }
};