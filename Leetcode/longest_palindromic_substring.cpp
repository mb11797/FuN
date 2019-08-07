class Solution {
public:
    int memo[100][100] = {};
    int max_len=0;
    int start_len;
    int end_len;

    bool is_pal(string s, int be, int en){
        if(memo[be][en] != 0)
            return (memo[i][j]==1);

        if(be == en){                 //len=1
            memo[be][en]=1;
            return true;
        }

        if(be+1 == en){               //len=2
            if(s[be] == s[en]){
                memo[be][en]=1;
                return true;
            }
            memo[be][en]=-1;
            return false;
        }

        if(s[be] == s[en]){             //len>=3
            bool res = is_pal(s, be+1, en-1);
            memo[be][en] = res ? 1 : 0;
            return res;
        }

        memo[be][en] = 0;
        return false;
    }


    //update if whole string from be to en is palindrome
    void max_len_palindrom(string s, int be, int en){
        if(is_pal(s, be, en)){
            if(en-be+1>max_len){
                max_len = en - be + 1;
                start_len = be;
                end_len = en;
            }
        }
        else{
            max_len_palindrome(s, be+1, en);
            max_len_palindrome(s, be, en-1);
        }

        return;
    }

//     int max_len_palindrome(string s, int be, int en){
//         if(be>en)
//             return 0;

//         if(memo[be][en] != -1)
//             return memo[be][en];

//         int q1, q2, q3;
//         if(s[be]==s[en] ){
//             q1 = 1 + max_len_palindrome(s, be+1, en-1);
//         }
//         else{
//             q2 = max_len_palindrome(s, be+1, en);
//             q3 = max_len_palindrome(s, be, en-1);
//         }

//         memo[be][en] = max(q1, max(q2, q3));

//         return memo[be][en];
//     }

    string longestPalindrome(string s) {

        int n = s.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                memo[i][j] = 0;
            }
        }

        max_len_palindrome(s, 0, n-1);
        string lon_pal_substr = s.substr(start_len, max_len);

        return lon_pal_substr;
    }
};
