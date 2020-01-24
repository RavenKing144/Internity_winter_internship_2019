class Solution {
public:
    int largestRectangleArea(vector<int> &A) {
    int n = A.size();
    vector<int> posRight(n);
    stack<int> S;
    for (int i = n-1; i >= 0; i--) {
        while (!S.empty() && A[S.top()] >= A[i])
            S.pop();
        posRight[i] = S.empty() ? n-1 : S.top() - 1;
        S.push(i);
    }
    
    while (!S.empty()) S.pop();
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        while (!S.empty() && A[S.top()] >= A[i])
            S.pop();
        long long area = A[i] * (posRight[i] + 1 - (S.empty() ? 0 : S.top() + 1));
        if (area > maxArea)
            maxArea = area;
        S.push(i);
    }
    return maxArea;
}
};