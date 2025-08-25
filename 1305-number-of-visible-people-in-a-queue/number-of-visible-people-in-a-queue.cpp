class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
    int n=arr.size();
    vector<int> ans(n,0);
    stack<int> st;
    st.push(arr[n-1]);
    //because it not sees anything in its right
    ans[n-1]=0;
    for(int i=n-2;i>=0;i--){
        // count is answer which store visible person in his right
        int count=0;
        //pop with count
        while(st.size()>0 && arr[i]>st.top()){
            st.pop();
            count++;
        }
        if(st.size()!=0) count++; // becuse uske thik right vala tho dekh hi sakta hai na use 
        ans[i]=count;
        //push
        st.push(arr[i]);
    }
    return ans;



    }
};