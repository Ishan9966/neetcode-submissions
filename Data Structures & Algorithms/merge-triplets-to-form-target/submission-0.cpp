class Solution {
   public:
    bool mergeTriplets(vector<vector<int>>& triplet, vector<int>& target) {
        bool x = false, y = false, z = false;

        for (int i = 0; i < triplet.size(); i++) {
            if (triplet[i][0] > target[0] || triplet[i][1] > target[1] || triplet[i][2] > target[2])
                continue;

            if (triplet[i][0] == target[0]) x = true;

            if (triplet[i][1] == target[1]) y = true;

            if (triplet[i][2] == target[2]) z = true;
        }

        return x && y && z;
    }
};
