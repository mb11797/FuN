class Solution {
public:
    #define ll long long
    int myAtoi(string str) {
        ll len = str.size();
        ll arr[1000];
        ll cnt=0;
        ll neg_flag=0;
        ll empty_arr_flag=1;
        int ek_sign_aa_gaya = 0;
        int zero_flag=0;
        for(ll i=0; i<len; i++){

            if(str[i] == ' ' and empty_arr_flag==1 and ek_sign_aa_gaya==0 and zero_flag==0){
                continue;
            }
            if(zero_flag==1 and str[i]==' '){
                break;
            }

            if(str[i] == '-' and ek_sign_aa_gaya==0 and zero_flag==0 and cnt==0){
                neg_flag = 1;
                ek_sign_aa_gaya = 1;
                continue;
            }
            else if(str[i] == '-' and ek_sign_aa_gaya==1 and zero_flag==1){
                break;
            }
            if(str[i] == '+' and ek_sign_aa_gaya==0 and zero_flag==0 and cnt==0){
                neg_flag = 0;
                ek_sign_aa_gaya = 1;
                continue;
            }
            else if(str[i] == '+' and ek_sign_aa_gaya==1 and zero_flag==1){
                break;
            }

            ll digit = str[i] - '0';

            if(empty_arr_flag and digit==0){
                zero_flag=1;
                continue;
            }

            if(digit >=0 and digit <= 9){
                arr[cnt++] = digit;
                empty_arr_flag = 0;
            }
            else{
                break;
            }
        }

        // for(int i=0; i<cnt; i++){
        //     cout<<arr[i]<<" ";
        // }

        ll int_extracted = 0;
        if(cnt<=10){
            ll place=0;
            for(ll i=cnt-1; i>=0; i--){
                int_extracted += arr[i]*(pow(10, place));
                place++;
            }
        }
        else{
            int_extracted = 2147483648;
        }
        if(neg_flag){
            if(int_extracted < 2147483648){
                int_extracted = -int_extracted;
            }
            else{
                int_extracted = INT_MIN;
            }
        }
        else{
            if(int_extracted >= 2147483647){
                int_extracted = INT_MAX;
            }
        }


        return int_extracted;
    }
};

