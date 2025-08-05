#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Node {
    long long sum;
    long long prefix_sum;
    long long suffix_sum;
    long long max_sum;
};

class SegmentTree {
    vector<Node> tree;
    int n;

    Node merge(const Node &left, const Node &right) {
        Node result;
        result.sum = left.sum + right.sum;
        result.prefix_sum = max(left.prefix_sum, left.sum + right.prefix_sum);
        result.suffix_sum = max(right.suffix_sum, right.sum + left.suffix_sum);
        result.max_sum = max({left.max_sum, right.max_sum, left.suffix_sum + right.prefix_sum});
        return result;
    }

    void build(int node, int start, int end, const vector<int> &arr) {
        if (start == end) {
            int val = arr[start];
            tree[node] = {val, max(0, val), max(0, val), max(0, val)};
            return;
        }

        int mid = (start + end) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        build(left_child, start, mid, arr);
        build(right_child, mid + 1, end, arr);

        tree[node] = merge(tree[left_child], tree[right_child]);
    }

    void update(int idx, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] = {value, max(0, value), max(0, value), max(0, value)};
            return;
        }

        int mid = (start + end) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        if (idx <= mid) {
            update(idx, value, left_child, start, mid);
        } else {
            update(idx, value, right_child, mid + 1, end);
        }

        tree[node] = merge(tree[left_child], tree[right_child]);
    }

    Node query(int l, int r, int node, int start, int end) {
        if (r < start || l > end) {
            return {0, 0, 0, 0};
        }

        if (l <= start && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        Node left_result = query(l, r, left_child, start, mid);
        Node right_result = query(l, r, right_child, mid + 1, end);

        return merge(left_result, right_result);
    }

public:
    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void update(int idx, int value) {
        update(idx, value, 0, 0, n - 1);
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, n - 1).max_sum;
    }
};

void sol() {
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree segTree(arr);

    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int idx, x;
            cin >> idx >> x;
            segTree.update(idx - 1, x);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << segTree.query(l - 1, r - 1) << endl;
        }
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) sol();
}