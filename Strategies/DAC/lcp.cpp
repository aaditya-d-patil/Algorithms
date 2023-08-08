//LCP = Longest Common Prefix
#include<iostream>
using namespace std;

string lcp(string s1, string s2){
    int n;

    //Chooses the shortest string
    if(s1.length() < s2.length()){
        n = s1.length();
    }
    else{
        n = s2.length();
    }

    string ans = "";

    //Comparison for-loop
    for(int i=0;i<n;i++){
        if(s1[i] != s2[i]){
            break;
        }
        ans += s1[i];
    }
    return ans;
}

string divideArr(string arr[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        string s1 = divideArr(arr, l, mid);
        string s2 = divideArr(arr, mid+1, r);

        //returning the longest common prefix between s1 and s2
        return lcp(s1,s2);
    }
    //returning single element after dividing
    return arr[l];
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    //Invalid edge case
    if(!n){
        cout<<"Invalid";
        return 0;
    }
    
    string arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(divideArr(arr, 0, n-1).length())
        cout<< divideArr(arr, 0, n-1);
    else
        //if there is no LCP
        cout<<"No LCP";

    return 0;
}
