class Solution{
public:
    void cnt(vector<pair<int,int>>&v,vector<int>&ans,int left,int mid,int right){
        int j=mid+1;
        for(int i=left;i<=mid;i++){
            while(j<=right && v[i].first>v[j].first){
                j++;
            }
            ans[v[i].second]+=j-mid-1;
        }
    }
    void merge(vector<pair<int,int>>&v,vector<int>&ans,int left,int mid,int right){
        int i=left;
        int j=mid+1;
        vector<pair<int,int>>temp;
        while(i<=mid && j<=right){
            if(v[i].first>=v[j].first){
                temp.push_back({v[j].first,v[j].second});
                j++;
            }
            else{
                temp.push_back({v[i].first,v[i].second});
                i++;
            }
        }
        while(i<=mid){
            temp.push_back({v[i].first,v[i].second});
            i++;
        }
         while(j<=right){
            temp.push_back({v[j].first,v[j].second});
            j++;
        }
        for(int k=0;k<temp.size();k++){
            v[left+k].first=temp[k].first;
            v[left+k].second=temp[k].second;
        }
    }
    void mergeSort(vector<pair<int,int>>&v,vector<int>&ans,int left,int right){
        if(left>=right){
            return;
        }
        int mid=left+(right-left)/2;
        mergeSort(v,ans,left,mid);
        mergeSort(v,ans,mid+1,right);
        cnt(v,ans,left,mid,right);
        merge(v,ans,left,mid,right);
    }
    vector<int>countSmaller(vector<int>&nums){
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        vector<int>ans(n);
        mergeSort(v,ans,0,n-1);
        return ans;
    }
};