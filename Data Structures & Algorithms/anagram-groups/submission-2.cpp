class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int len = strs.size();

        unordered_map<string, vector<int>> stringData;

        for(int i=0 ; i<len ; i++) {
            vector<int> freq(26, 0);
            for(char ch:strs[i])
                freq[ch-'a']++;

            string s = "";

            for(int j=0 ; j<26 ; j++)
                s += to_string(freq[j])+"_";

            stringData[s].push_back(i);

            //cout<<s<<"\n";
        }



        for(auto &itr:stringData) {
            vector<string> tempAns;
            vector<int> indexes = itr.second;
            
            for(int index:itr.second)
                tempAns.push_back(strs[index]);
            
            sort(tempAns.begin(), tempAns.end());

            ans.push_back(tempAns);
        }
        
        return ans;
    }
};
