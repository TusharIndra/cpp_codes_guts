class Solution{
  public:
    vector<int> PosNegPair(int a[], int n) {
        vector<int>v,ret;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(a[i]<0)v.push_back(a[i]);
            else mp[a[i]]++;
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            int pos=abs(v[i]);
            //auto x=mp.find(pos);
            if(mp[pos]>0){
                ret.push_back(v[i]);
                ret.push_back(pos);
                mp[pos]-=1;
            }
        }
        return ret;
    }
};