class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        map<char, bool>freq;

        int j=0;
        int max_len=0;
        int len=0;
        while(j<s.length()){

            if(freq[s[j]]==0){
                freq[s[j]]=1;
                len++;
                max_len = max(max_len, len);
                j++;
            }
            else{
                freq[s[i]]=0;
                i++;
                len=len-1;
                // for(int k=i; k<j; k++){
                //     len++;
                //     if(s[k]==s[j]){
                //         j=k;
                //         break;
                //     }
                // }
                // max_len=max(len, max_len);


            }
        }
        return max_len;

    }
};
