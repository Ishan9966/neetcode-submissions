class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; // If there's only one element, no jumps are needed.

        int jumps = 0;       // Tracks the number of jumps made.
        int farthest = 0;    // Tracks the farthest index reachable in the current range.
        int current_end = 0; // Tracks the end of the current jump range.

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]); // Update the farthest reachable index.

            if (i == current_end) { // If the current index reaches the end of the current jump range:
                jumps++;            // Make a jump.
                current_end = farthest; // Update the range to the farthest reachable index.

                if (current_end >= n - 1) // If the range covers the last index, return the jumps.
                    return jumps;
            }
        }

        return jumps; // In case the end of the array is reachable.
    }
};