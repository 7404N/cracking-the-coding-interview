class Solution {
    public:
        vector<int> findSubstring(string S, vector<string> &L) {
            vector<int> res;
            if (L.empty() || S.empty()) return res;
            int cnt = L.size();
            int win = L[0].size();
            unordered_map<string, int> dict;
            for (auto const& x: L) ++dict[x];

            /*
            for (int start = 0; start + win * cnt <= S.size(); ++start) {
                unordered_map<string, int> temp(dict);
                for (int i = 0; i < cnt; ++i) {
                    string word = S.substr(start + i*win, win);
                    if (temp.find(word) == temp.end() || temp[word] == 0) break;
                    --temp[word];
                    if (temp[word] == 0) temp.erase(word);
                }
                if (temp.empty()) res.push_back(start);
            }
            */

            for (auto start = S.begin(); next(start, win*cnt) <= S.end(); ++start) {
                unordered_map<string, int> temp(dict);
                for (int i = 0; i < cnt; ++i) {
                    auto pos = temp.find(string(next(start, i*win), next(start, (i+1)*win)));
                    if (pos == temp.end() || pos->second == 0) break;
                    --pos->second;
                    if (pos->second == 0) temp.erase(pos);
                }
                if (temp.empty()) res.push_back(distance(S.begin(), start));
            }
            return res;
        }
};
