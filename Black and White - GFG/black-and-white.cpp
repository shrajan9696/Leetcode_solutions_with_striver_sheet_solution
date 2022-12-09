//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
   
    long long int Mod = 1000000007;
     long long int ans = ((M*N)%Mod*(M*N - 1)%Mod)%Mod;
    //  cout<<ans<<" ";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            // ans+=((N*M)-1);
           
           
            for(int k = -2;k<=2;k++)
            {
                // cout<<k<<" ";
                if(k!=0){
                int row = i+k;
                int col1 = j;
                int col2 = j;
                if(abs(k) == 2) 
                {
                //   col1 = col1-1;
                //   col2 = col2+1;
                col1--;
                col2++;
                }
                 else if(abs(k) == 1) 
                 {
                    col1 = col1-2;
                    col2 = col2+2;
                }
                // cout<<row<<" ";
                // cout<<col1<<" "<<col2<<"\n";
                if(row>=0 and row<N and col1>=0 and col1<M) ans--;
                  if(row>=0 and row<N and col2>=0 and col2<M) ans--;
                }
                
              
            }
            // cout<<ans<<" ";
        }
    }
    return ans;
    
}