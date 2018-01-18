class Solution {
public:
    //整个代码的思路是将数组乘积分成两个部分，以中间元素为界。
    //只需要一次循环就可以分别求出两个乘数，而不必进行循环嵌套
    //第二次循环可以用一个中间变量优化
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size());
        B[0] = 1;
        int i = 0;
        for(i = 1; i < A.size(); i++){
            B[i] = B[i-1] * A[i-1];
        }
        vector<int> C(A.size());
        C[A.size()-1] = 1;
        for(i = A.size() - 2; i >= 0; i--){
            C[i] = C[i+1] * A[i+1];
        }
        for(i = 0; i < A.size(); i++){
            B[i] = B[i] * C[i];
        }
        return B;
    }
    
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size());
        B[0] = 1;
        int i = 0;
        for(i = 1; i < A.size(); i++){
            B[i] = B[i-1] * A[i-1];
        }
        int temp = A[A.size()-1];
        for(i = A.size() - 2; i >= 0; i--){
            B[i] = B[i] * temp;
            temp *= A[i];
        }
        
        return B;
    }
};
