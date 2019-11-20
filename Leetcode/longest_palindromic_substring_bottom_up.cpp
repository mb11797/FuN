class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()){
            return "";
        }

        int dp[1001][1001]={};

        int start;
        int end;
        int max_len = 1;

        //for len=1
        for(int i=0; i<s.size(); i++){
            dp[i][i] = 1;
            start = i;
            end = i;
            max_len=1;
        }

        //for len=2
        for(int i=0; i<s.size()-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = 1;
                start = i;
                end = i+1;
                max_len = 2;
            }
        }

        //for len>=3
        for(int len=3; len<=s.size(); len++){
            for(int i=0; i<s.size()-len+1; i++){
                int be = i;
                int en = i+len-1;
                if(s[be]==s[en] && dp[be+1][en-1]){
                    dp[be][en]=1;
                    if(len>max_len){
                        max_len = len;
                        start = be;
                        end = en;
                    }
                }
            }
        }

        return s.substr(start, end-start+1);
    }
};
