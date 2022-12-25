//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();

        long long int sum = 0;

        long long int prev_sum = -1;

            int r = -1;

            int c = -1;

        for(int i=0;i<n;++i)

        {

            long long int row_sum = 0;

            int f = 0;

            for(int j=0;j<n;++j)

            {

                if(matrix[i][j] == 0)

                {

                    f=1;

                    r = i;

                    c = j;

                }

                else

                {

                    row_sum += matrix[i][j];

                }

            }

            

            if(f == 0)

            {

                if(prev_sum == -1)

                {

                    prev_sum = row_sum;

                }

                else if(prev_sum != row_sum)

                return -1;

            }

            else

            {

                sum = row_sum;

            }

        }

        long long int val = prev_sum - sum;

        prev_sum = -1;

        

        for(int j=0;j<n;++j)

        {

            long long int col_sum = 0;

            

            for(int i=0;i<n;++i)

            {

                if(i==r && j==c)

                col_sum += val;

                else

                col_sum += matrix[i][j];

            }

            

            

            if(prev_sum != -1)

            {

                if(col_sum != prev_sum)

                return -1;

            }

            else{

                prev_sum = col_sum;

            }

        }

        

        long long int sum1 = 0;

        

        for(int i=0;i<n;++i)

        {

            if(i==r && i==c)

            sum1 += val;

            else

            sum1 += matrix[i][i];

        }

        

        long long int sum2 = 0;

        

        for(int i=0;i<n;++i)

        {

            if(i==r && n-i-1 == c)

            sum2 += val;

            else

            sum2 += matrix[i][n-i-1];

        }

        

        if(sum1 != sum2 || val <= 0)

        return -1;

        

        

        return val;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends