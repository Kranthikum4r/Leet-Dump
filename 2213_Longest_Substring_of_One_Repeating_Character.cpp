class Solution {
public:
    // Store intervals as {start, end}
    // Each interval represents one group of equal characters.
    set<pair<int, int>> intervals;

    // Store lengths of all intervals
    multiset<int> lengths;

    string s;

    // Add an interval
    void addInterval(int l, int r) {
        intervals.insert({l, r});
        lengths.insert(r - l + 1);
    }

    // Remove an interval
    void removeInterval(int l, int r) {
        intervals.erase({l, r});

        auto it = lengths.find(r - l + 1);
        if (it != lengths.end())
            lengths.erase(it);
    }

    // Find the interval containing position pos
    set<pair<int, int>>::iterator findInterval(int pos) {
        auto it = intervals.upper_bound({pos, INT_MAX});

        if (it == intervals.begin())
            return intervals.end();

        --it;

        if (it->first <= pos && pos <= it->second)
            return it;

        return intervals.end();
    }

    // Change s[pos] to c
    void update(int pos, char c) {
        if (s[pos] == c)
            return;

        // Find the old interval containing pos
        auto it = findInterval(pos);

        int l = it->first;
        int r = it->second;

        removeInterval(l, r);

        // Split old interval around pos
        if (l <= pos - 1)
            addInterval(l, pos - 1);

        if (pos + 1 <= r)
            addInterval(pos + 1, r);

        s[pos] = c;

        // Now create interval [pos, pos]
        int newL = pos;
        int newR = pos;

        // Find interval immediately before pos
        auto next = intervals.lower_bound({pos, INT_MIN});

        if (next != intervals.begin()) {
            auto prev = prev(next);

            if (prev->second == pos - 1 &&
                s[prev->first] == c) {

                newL = prev->first;

                removeInterval(prev->first, prev->second);
            }
        }

        // Find interval immediately after pos
        next = intervals.lower_bound({pos + 1, INT_MIN});

        if (next != intervals.end()) {
            if (next->first == pos + 1 &&
                s[next->first] == c) {

                newR = next->second;

                removeInterval(next->first, next->second);
            }
        }

        addInterval(newL, newR);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        // Build initial intervals
        int start = 0;

        for (int i = 1; i <= n; i++) {
            if (i == n || s[i] != s[i - 1]) {
                addInterval(start, i - 1);
                start = i;
            }
        }

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char c = queryCharacters[i];

            update(pos, c);

            // Largest interval length
            ans.push_back(*lengths.rbegin());
        }

        return ans;
    }
};