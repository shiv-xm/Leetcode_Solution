class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        //using concepts of prefix sum and largest rect in histogram

        // tc = O(n*m) + O(n*2m)
        // sc = O(n*m) + O(n) for p_sum and stack
        
        int n = matrix.size();
        int m = matrix[0].size();

        int Maxarea = 0;
        int sum;
        vector<vector<int>> p_sum(n, vector<int>(m, 0));
 //to store values after calculating sum of each row for bar, changing original input is not advisable.

        //computations of prefix sum
        for(int j = 0; j < m ; j++){ //O(M * N)

            sum = 0;
            for(int i = 0; i < n; i++){

                sum += matrix[i][j] == '1' ? 1 : 0 ; 
                if(matrix[i][j] == '0'){
                    sum = 0;
                }
                p_sum[i][j] = sum;
            }
        }

        //traversing through each row and computing max rect 
        for(int i = 0; i < n ; i++){ //O(N * 2M)

           Maxarea = max(Maxarea, lHist(p_sum[i]));
        }
        return Maxarea;
    }
    
    int lHist(vector<int> arr){

        //tc = O(2N) n for loop, n for pop operation
        
        stack<int> st;
        int maxRect = 0;
        int nse, pse, n = arr.size();

        for(int i = 0 ; i<n ; i++){ //O(N)

            while(!st.empty() && arr[st.top()] > arr[i]){

                int ele = arr[st.top()];
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();

                maxRect = max(maxRect, ele*(nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele = arr[st.top()];
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();

            maxRect = max(maxRect, ele*(nse - pse - 1));
        }

        return maxRect;
    }
};