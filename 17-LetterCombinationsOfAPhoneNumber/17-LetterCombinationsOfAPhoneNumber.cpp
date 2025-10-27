// Last updated: 10/27/2025, 7:10:30 PM
class Solution {
public:
    void function(vector<vector<string>>&sample,string&temp,int index,vector<string>&ans){
        if(index==sample.size()){
            ans.push_back(temp);
            return;
        }
        for(auto& ch:sample[index]){
            temp+=ch;
            function(sample,temp,index+1,ans);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<string>> mp;
        mp['2'] = vector<string>{"a", "b", "c"};
        mp['3'] = vector<string>{"d", "e", "f"};
        mp['4'] = vector<string>{"g", "h", "i"};
        mp['5'] = vector<string>{"j", "k", "l"};
        mp['6'] = vector<string>{"m", "n", "o"};
        mp['7'] = vector<string>{"p", "q", "r", "s"};
        mp['8'] = vector<string>{"t", "u", "v"};
        mp['9'] = vector<string>{"w", "x", "y", "z"};

        vector<string>ans;
        if(digits.empty()) return ans;
        else if(digits.size()==1) return mp[digits[0]];

        vector<vector<string>>sample;
        for (char d : digits) {
            sample.push_back(mp[d]);
        }
        string temp;
        function(sample, temp, 0, ans);
        return ans;
    }
};