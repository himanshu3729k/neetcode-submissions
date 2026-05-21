class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        unordered_map<string, vector<string>> g;
        int n = wordList.size();
        int sz = beginWord.size();

        vector<string> all = wordList;
        all.push_back(beginWord);

        for (int i = 0; i < all.size(); i++) {
            for (int j = i + 1; j < all.size(); j++) {
                int diff = 0;
                for (int k = 0; k < sz; k++) {
                    if (all[i][k] != all[j][k]) diff++;
                    if (diff > 1) break;
                }
                if (diff == 1) {
                    g[all[i]].push_back(all[j]);
                    g[all[j]].push_back(all[i]);
                }
            }
        }

        unordered_map<string, int> dist;
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;

        while (!q.empty()) {
            string curr = q.front(); q.pop();
            if (curr == endWord) return dist[curr];

            for (auto& neigh : g[curr]) {
                if (dist.count(neigh)) continue;
                dist[neigh] = dist[curr] + 1;
                q.push(neigh);
            }
        }

        return dist[endWord];
    }
};
