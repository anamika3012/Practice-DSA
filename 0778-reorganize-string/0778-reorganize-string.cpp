// class Solution {
// public:
//     string reorganizeString(string s) {
//         int hash[26] = {0};

//         for(int i=0; i<s.size(); i++){
//             hash[s[i] - 'a']++;
//         }

//         char max_freq_char;
//         int max_freq = INT_MIN;

//         for(int i=0; i<26 ; i++){
//             if(hash[i] > max_freq ){
//                 max_freq = hash[i];
//                 max_freq_char = i + 'a';
//             }
//         }

//         int index =0;
//         while(max_freq > 0 && index < s.size()){
//             s[index] = max_freq_char;
//             max_freq--;
//             index+=2;
//         }

//         if(max_freq !=0){
//             return "";  
//         }

//         hash[max_freq_char -'a'] =0;

//         for(int i=0; i<26; i++){
//             while(hash[i] >0){
//                 index = index >= s.size() ? 1: index;
//                 s[index] = i + 'a';
//                 hash[i]--;
//                 index +=2;
//             }
//         }
//      return s;
//     }
// };


class Info{
    public:
        char val;
        int count;

    Info(char ch , int cnt){
        this-> val = ch;
        this->count = cnt;
    }
};

class compare{
    public:
          bool operator()(Info a , Info b){
            return a.count < b.count;
          }
};

class Solution{
    public:
        string reorganizeString(string s){
            int freq[26] = {0};

            //count frwequency and update in freq array
            for(int i=0; i<s.length(); i++){
                char ch = s[i];
                freq[ch - 'a']++;
            }

            //push all characters in maxHeap which has frequency greater than 0
            priority_queue<Info, vector<Info> , compare> pq;
            for(int i=0; i<26; i++){
                if(freq[i] > 0){
                    Info newInfo(i+'a' , freq[i]);
                    pq.push(newInfo);
                }
            }

            string ans = "";
            //since we have to push 2 characters at once, so while loop runs jb tk maxheap me at least 2 characters 
            //i.e. 2 or more characters available h
            while(pq.size() > 1){
                Info first = pq.top();
                pq.pop();
                Info second = pq.top();
                pq.pop();
                //insert the two charcaters into ans string
                ans.push_back(first.val);
                first.count--;
                ans.push_back(second.val); 
                second.count--;
                //push the first anbd second characters again into maxheap
                if(first.count > 0){
                    pq.push(first);
                }
                if(second.count > 0){
                    pq.push(second);
                }
            }

            //if only 1 element bacha h , then usko bs 1 baar insert kro
            if(pq.size() == 1){
                Info first = pq.top();
                pq.pop();
                ans.push_back(first.val);
                first.count--;
                //if after insertion still the freq of the element is not zero , then that means the answer is not 
                //possible. 
                if(first.count != 0){
                    return "";
                }
            }
        return ans;
        }
};