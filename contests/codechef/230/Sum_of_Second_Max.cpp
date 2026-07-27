#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int64> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        // previous greater (pg) and next greater (ng)
        vector<int> pg(n, -1), ng(n, -1);
        {
            // pg: nearest greater to left
            vector<int> st;
            for (int i = 0; i < n; ++i)
            {
                while (!st.empty() && a[st.back()] < a[i])
                    st.pop_back();
                pg[i] = st.empty() ? -1 : st.back();
                st.push_back(i);
            }
        }
        {
            // ng: nearest greater to right
            vector<int> st;
            for (int i = n - 1; i >= 0; --i)
            {
                while (!st.empty() && a[st.back()] < a[i])
                    st.pop_back();
                ng[i] = st.empty() ? -1 : st.back();
                st.push_back(i);
            }
        }

        long long answer = 0;
        for (int i = 0; i < n; ++i)
        {
            int L1 = pg[i];
            int R1 = ng[i];

            // If there is a greater on the left, count subarrays where that left greater is the max
            if (L1 != -1)
            {
                int L2 = pg[L1];                                   // previous greater of L1 (may be -1)
                int Rbound = (R1 == -1 ? n : R1);                  // first greater to right of i (or n)
                long long left_choices = (long long)(L1 - L2);     // number of choices for left boundary that include L1 but exclude any greater left of L1
                long long right_choices = (long long)(Rbound - i); // right boundary choices that include i but exclude any greater right of i
                answer += left_choices * right_choices * a[i];
            }

            // If there is a greater on the right, count subarrays where that right greater is the max
            if (R1 != -1)
            {
                int R2 = ng[R1]; // next greater of R1 (may be -1, treat as n)
                int Lbound = (L1 == -1 ? -1 : L1);
                long long left_choices = (long long)(i - Lbound);                // left boundaries that include i but exclude greater left of i
                long long right_choices = (long long)((R2 == -1 ? n : R2) - R1); // right boundary choices that include R1 but exclude any greater right of R1
                answer += left_choices * right_choices * a[i];
            }
        }

        cout << answer << '\n';
    }
    return 0;
}