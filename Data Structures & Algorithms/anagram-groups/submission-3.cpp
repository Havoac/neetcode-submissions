class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;
        int len = strs.size();

        for(int i=0 ; i<len ; i++) {
            vector<int> freq(26, 0);

            for(char ch:strs[i]) 
            freq[ch-'a']++;

            string temp = "";
            for(int i=0 ; i<26 ; i++) {
                if(freq[i] > 0)
                    temp += to_string(freq[i]) + to_string('a'+i);
            }

            mp[temp].push_back(i);
        }

        vector<vector<string>> ans;

        for(auto &itr:mp) {
            vector<string> temp;
            for(int index:itr.second) {
                temp.push_back(strs[index]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
