class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        vector<int>ans0;
        vector<int>ans1;
        vector<int>winner;
        vector<int>looser;
      for(int row=0;row<matches.size();row++){
        winner.push_back(matches[row][0]); 
      } 
      for(int col=matches[0].size()/2;col<matches[0].size();col++){
        for(int row=0;row<matches.size();row++){
           looser.push_back(matches[row][col]);   
        }
      }
      sort(looser.begin(),looser.end());
      sort(winner.begin(),winner.end());
      for(int i=0;i<winner.size();i++){
            if(!binary_search(looser.begin(),looser.end(),winner[i])){
                ans0.push_back(winner[i]);
            }
      }
      stack<int>s;
      int num=-1;
      s.push(looser[0]);
      for(int i=1;i<looser.size();i++){
        if(!s.empty() && s.top()==looser[i]){
            num=s.top();
            s.pop();
        }
        else{
            if(num!=looser[i])
            s.push(looser[i]);
        }
      }
        while(!s.empty()){
            ans1.push_back(s.top());
            s.pop();
      }
        vector<int>ansZero;
      for(int i=0;i<ans0.size();i++){
        if(!binary_search(ans0.begin()+i+1,ans0.end(),ans0[i])){
            ansZero.push_back(ans0[i]);
        }
      }
        ans.push_back(ansZero);
        sort(ans1.begin(),ans1.end());
        ans.push_back(ans1);
        return ans;
    }
};