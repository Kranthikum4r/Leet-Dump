class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> prefixSum(13, 0);
        for(int i = 1; i < 13; i++) {
            prefixSum[i] = days[i] + prefixSum[i-1];
        }

        int A1 = stoi(arriveAlice.substr(0, 2));
        int A2 = stoi(arriveAlice.substr(3, 2));
        int A3 = stoi(leaveAlice.substr(0, 2));
        int A4 = stoi(leaveAlice.substr(3, 2));

        int B1 = stoi(arriveBob.substr(0, 2));
        int B2 = stoi(arriveBob.substr(3, 2));
        int B3 = stoi(leaveBob.substr(0, 2));
        int B4 = stoi(leaveBob.substr(3, 2));

        int low = max(prefixSum[A1 - 1] + A2, prefixSum[B1 - 1] + B2);
        int high = min(prefixSum[A3 - 1] + A4, prefixSum[B3 - 1] + B4);

        return max(0, high - low + 1);
    }
};