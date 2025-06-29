// class Solution {
// public:
//     string longestDiverseString(int a, int b, int c) {
//       string result;
//     vector<pair<int, char>> counts = {{a, 'a'}, {b, 'b'}, {c, 'c'}};

//     while (true) {
//         sort(counts.rbegin(), counts.rend());
//         bool added = false;

//         for (int i = 0; i < 3; ++i) {
//             if (counts[i].first > 0 && (result.size() < 2 || !(result[result.size() - 1] == counts[i].second && result[result.size() - 2] == counts[i].second))) {
//                 result += counts[i].second;
//                 counts[i].first--;
//                 added = true;
//                 break;
//             }
//         }

//         if (!added) break;
//     }

//     return result;  
//     }
// };


class Info{
    public:
    char val;
    int count;

    Info(char ch , int cnt){
        this->val = ch;
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
        string longestDiverseString(int a, int b, int c) {
            priority_queue<Info , vector<Info> , compare> pq;
            if(a>0){
                Info temp('a', a);
                pq.push(temp);
            }
            if(b>0){
                Info temp('b', b);
                pq.push(temp);
            }
            if(c>0){
                Info temp('c', c);
                pq.push(temp);
            }

            string ans = "";
            while(pq.size() > 1){
                Info first = pq.top();
                pq.pop();
                Info second = pq.top();
                pq.pop();

                if(first.count >= 2){
                    ans.push_back(first.val);
                    ans.push_back(first.val);
                    first.count -=2;
                }
                else{
                    ans.push_back(first.val);
                    first.count --;
                }
                if(second.count >= 2 && second.count >= first.count){
                    ans.push_back(second.val);
                    ans.push_back(second.val);
                    second.count -=2;
                }
                else{
                    ans.push_back(second.val);
                    second.count--;
                }

                if(first.count > 0){
                    pq.push(first);
                }
                if(second.count > 0){
                    pq.push(second);
                }
            }

            if(pq.size() == 1){
                Info first = pq.top();
                pq.pop();

                if(first.count >= 2){
                    ans.push_back(first.val);
                    ans.push_back(first.val);
                    first.count -=2;
                }
                else{
                    ans.push_back(first.val);
                    first.count--;
                }
            }
        return ans;
        }
};