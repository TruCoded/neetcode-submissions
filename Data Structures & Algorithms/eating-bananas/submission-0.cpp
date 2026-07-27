class Solution {
public:

    long long calculateTotalHours(vector<int>& piles, long long hourly) {
        long long totalH = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalH += (piles[i] + hourly - 1) / hourly;
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = INT_MIN;

        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }

        long long low = 1;
        long long high = maxi;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};