class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
    
        vector<int> sizes;

        for(string s:strs) {
            sizes.push_back(s.length());
        }

        string ans = "";

        for(int i=0 ; i<sizes.size() ; i++) {
            ans += to_string(sizes[i])+",";
        }

        ans += "#";

        for(string s:strs)
            ans += s;
        
        return ans;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        vector<int> sizes;

        int j=0;
        for(int i=0 ; i<s.length() ; i++) {
            if(s[i] == '#')
            {
                j = i+1;
                break;
            }

            if(s[i] == ',') {
                string temp = s.substr(j, i-j);
                sizes.push_back(stoi(temp));
                j = i+1;
            }
        }

        vector<string> ans;

        int i = 0;
        while(i<sizes.size()) {
            string temp = s.substr(j, sizes[i]);
            ans.push_back(temp);
            j = j+sizes[i];
            i++;
        }

        return ans;
    }
};
