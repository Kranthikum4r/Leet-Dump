class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int mostCommon = 0;
        int answer = 0;

        for(int right = 0; right < s.size(); right++) {
            int index = s[right] - 'A';
            freq[index]++;
            mostCommon = max(mostCommon, freq[index]);

            while(right - left + 1 - mostCommon > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};