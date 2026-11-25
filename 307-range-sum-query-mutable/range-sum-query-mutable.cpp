class NumArray{
    int n;
    vector<int>bit;
    vector<int>arr;
    void add(int i,int val){
       for(;i<=n;i+=i&-i){
            bit[i]+=val;
        }
    }
    int query(int i)const{
      int sum=0;
      for(;i>0;i-=i&-i){
         sum+=bit[i];
      }
      return sum;
    }
public:
    NumArray(vector<int>&nums){
        n=nums.size();
        arr=nums;
        bit.assign(n+1,0);
        for(int i=1;i<=n;i++){
            bit[i]+=nums[i-1];
            int parent=i+(i&-i);
            if(parent<=n){
                bit[parent]+=bit[i];
            }
        }
    }
    void update(int index,int val){
        int delta=val-arr[index];
        arr[index]=val;
        add(index+1,delta);
    }
    int sumRange(int left, int right){
        if(left>right){
            return 0;
        }
        return query(right+1)-query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */