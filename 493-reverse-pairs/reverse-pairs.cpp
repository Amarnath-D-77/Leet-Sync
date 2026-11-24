class Solution{
public:
long long cntpairs(vector<int>&arr,int left,int mid,int right){
  int j=mid+1;
  long long cnt=0;
  for(int i=left;i<=mid;i++){
    while(j<=right && (long long)arr[i]>2LL*arr[j]){
        j++;
    }
    cnt+=j-mid-1;
  }
  return cnt;
}
void merge(vector<int>&arr,int left,int mid,int right){
    vector<int>temp;
    int i=left;
    int j=mid+1;
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=right){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k=0;k<temp.size();k++){
        arr[left+k]=temp[k];
    }
}

long long mergeSort(vector<int>&arr,int left, int right){
     if(left>=right){
       return 0;
    }
    int mid=left+(right-left)/2;
    long long cnt=0;
    cnt+=mergeSort(arr,left,mid);
    cnt+=mergeSort(arr,mid+1,right);
    cnt+=cntpairs(arr,left,mid,right);
    merge(arr,left,mid,right);
    return cnt;
}
int reversePairs(vector<int>&arr){
        int inv=mergeSort(arr,0,arr.size()-1);
        return inv;    
    }
};