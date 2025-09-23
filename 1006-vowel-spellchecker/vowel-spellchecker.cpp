class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactSet(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap; 
        unordered_map<string, string> vowelMap;

        auto normalizeVowels = [](string s) {
            for (char &c : s) {
                if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c='*';
            }
            return s;
        };

        for (auto &w : wordlist) {
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (!caseMap.count(lower)) caseMap[lower] = w;

            string v = normalizeVowels(lower);
            if (!vowelMap.count(v)) vowelMap[v] = w;
        }

        vector<string> ans;
        for (auto &q : queries) {
            if (exactSet.count(q)) { 
                ans.push_back(q);
                continue;
            }

            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
                continue;
            }

            string v = normalizeVowels(lower);
            if (vowelMap.count(v)) {
                ans.push_back(vowelMap[v]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }
};
