class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        int n = strs.size();

        sort(strs.begin(),strs.end());

        int idx = 0;

        string str0 = strs[0];
        string strn = strs[n-1];

        for(int i=0;i<min(str0.size(),strn.size());i++) {
            if(str0[i]!=strn[i]) 
                return str;
            str +=str0[i];
        }
        
        return str;
    }
};