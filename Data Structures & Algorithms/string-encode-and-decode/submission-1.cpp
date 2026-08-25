class Solution {
public:
    string encode(vector<string>& strs) {
        string s;
        int curr_str_size = 0;

        for(string str:strs){
            s+=to_string(str.size());
            s+='#';
            s+=str;
        }

        // cout<<s<<endl;
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i=0;
        while(i<s.size()){
            string curr_str;
            int curr_size = 0;

            while(s[i]>='0' && s[i]<='9'){
                curr_size *= 10;
                curr_size += (s[i]-'0');
                i++;
            }
            i++;

            for(int j=i;j<i+curr_size;j++){
                curr_str+=s[j];
            }

            res.push_back(curr_str);
            i += curr_size;
        }

        return res;
    }
};
