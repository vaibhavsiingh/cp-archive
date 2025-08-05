#include <bits/stdc++.h>
using namespace std;
 

const long long MOD = 998244353;
 
// Global vector for powers of 2 mod MOD.
vector<long long> pow2Arr;
 
// Treap Node structure.
struct Node {
    int key;    // the element's value
    int id;     // unique id (for tie-breaking when equal values occur)
    int priority; // random priority
    Node *left, *right;
    int sz;    // subtree size
    // Aggregated data for the "segment" (i.e. the sorted order of this subtree)
    long long A;   // = sum_{i=0}^{sz-1} a[i]*2^(sz-i-1)
    long long B;   // = sum_{i=0}^{sz-1} a[i]*2^(i)
    long long f;   // the “Case A” sum over pairs in the segment
    long long adj; // the “Case B” sum: sum of adjacent products in the segment
    int first;  // the first element in this segment (smallest)
    int last;   // the last element (largest)
    
    Node(int _key, int _id) {
        key = _key;
        id = _id;
        priority = rand();
        left = right = nullptr;
        sz = 1;
        // For a single element, the segment is just that element.
        A = _key % MOD;
        B = _key % MOD;
        f = 0;    // no pair inside one element
        adj = 0;  // no adjacent pair in a one–element segment
        first = _key;
        last = _key;
    }
};
 
// Helper: return subtree size (0 if null)
int getSize(Node* t) {
    return t ? t->sz : 0;
}
 
// The recalc function recomputes all aggregated values from a node’s children and its own value.
// We view the in–order (sorted) sequence in the subtree as a “segment” and we want to compute:
//
//   - Combined size: sz = size(left) + 1 + size(right)
//   - f   = (left.f + right.f + (left.A * right.B)) mod MOD   [this is the “Case A” contribution]
//   - A   = (left.A * 2^(size(right)+1) + self + ... ) … see below
//   - B   = (left.B + right.B * 2^(size(left)+1)) mod MOD
//   - adj = (left.adj + right.adj + (left.last * right.first)) mod MOD
//
// We “merge” three segments: left, then the current node as a one–element segment, then right.
// (Recall that for a one–element segment with value x, we define A = x, B = x, f = 0, and adj = 0.)
//
void recalc(Node* t) {
    if (!t) return;
    // Start with the “self” segment.
    int selfSize = 1;
    long long selfA = t->key % MOD;
    long long selfB = t->key % MOD;
    long long selff = 0;
    long long selfAdj = 0;
    int selfFirst = t->key;
    int selfLast = t->key;
    
    // We'll merge from left then self then right.
    int segSize = 0;
    long long segA = 0, segB = 0, segf = 0, segAdj = 0;
    int segFirst = 0, segLast = 0;
    
    // First, if there is a left child, use its aggregated segment.
    if(t->left) {
        segSize = t->left->sz;
        segA = t->left->A;
        segB = t->left->B;
        segf = t->left->f;
        segAdj = t->left->adj;
        segFirst = t->left->first;
        segLast = t->left->last;
        // Merge left segment with the one–element "self" segment.
        int newSize = segSize + selfSize;
        long long newf = ( segf + (segA * selfB) % MOD ) % MOD;
        long long newA = ( segA * pow2Arr[selfSize] + selfA ) % MOD;
        long long newB = ( segB + selfB * pow2Arr[segSize] ) % MOD;
        int newFirst = segFirst; // the left segment already is sorted so its first is smallest.
        int newLast = selfLast;    // current node becomes the last of this merged segment.
        long long newAdj = ( segAdj + ((long long) segLast * selfFirst) % MOD ) % MOD;
        
        segSize = newSize;
        segf = newf;
        segA = newA;
        segB = newB;
        segFirst = newFirst;
        segLast = newLast;
        segAdj = newAdj;
    } else {
        // If no left child, the merged segment so far is just "self".
        segSize = selfSize;
        segA = selfA;
        segB = selfB;
        segf = selff;
        segAdj = selfAdj;
        segFirst = selfFirst;
        segLast = selfLast;
    }
    
    // Then, merge with the right child’s segment (if any).
    if(t->right) {
        int rSize = t->right->sz;
        long long rA = t->right->A;
        long long rB = t->right->B;
        long long rf = t->right->f;
        long long rAdj = t->right->adj;
        int rFirst = t->right->first;
        int rLast = t->right->last;
        
        int newSize = segSize + rSize;
        long long newf = ( segf + rf + (segA * rB) % MOD ) % MOD;
        long long newA = ( segA * pow2Arr[rSize] + rA ) % MOD;
        long long newB = ( segB + rB * pow2Arr[segSize] ) % MOD;
        int newFirst = segFirst;
        int newLast = rLast;
        long long newAdj = ( segAdj + rAdj + ((long long) segLast * rFirst) % MOD ) % MOD;
        
        segSize = newSize;
        segf = newf;
        segA = newA;
        segB = newB;
        segFirst = newFirst;
        segLast = newLast;
        segAdj = newAdj;
    }
    
    t->sz = segSize;
    t->A = segA;
    t->B = segB;
    t->f = segf;
    t->adj = segAdj;
    t->first = segFirst;
    t->last = segLast;
}
 
// Standard treap merge: merge two treaps L and R (all keys in L are <= those in R).
Node* mergeTreap(Node* L, Node* R) {
    if(!L) return R;
    if(!R) return L;
    if(L->priority > R->priority) {
        L->right = mergeTreap(L->right, R);
        recalc(L);
        return L;
    } else {
        R->left = mergeTreap(L, R->left);
        recalc(R);
        return R;
    }
}
 
// Split treap t into L and R so that every node in L is strictly less than (v, id)
// (comparison is lexicographical: first by key then by id)
void splitTreap(Node* t, int v, int id, Node*& L, Node*& R) {
    if(!t) { L = R = nullptr; return; }
    if( (t->key < v) || (t->key == v && t->id < id) ) {
        splitTreap(t->right, v, id, t->right, R);
        L = t;
        recalc(L);
    } else {
        splitTreap(t->left, v, id, L, t->left);
        R = t;
        recalc(R);
    }
}
 
// Insert a new node "item" into treap t.
Node* insertTreap(Node* t, Node* item) {
    if(!t) return item;
    if(item->priority > t->priority) {
        splitTreap(t, item->key, item->id, item->left, item->right);
        recalc(item);
        return item;
    } else if( (item->key < t->key) || (item->key == t->key && item->id < t->id) ) {
        t->left = insertTreap(t->left, item);
        recalc(t);
        return t;
    } else {
        t->right = insertTreap(t->right, item);
        recalc(t);
        return t;
    }
}
 
// Erase the node with value v and id from treap t.
Node* eraseTreap(Node* t, int v, int id) {
    if(!t) return nullptr;
    if(t->key == v && t->id == id) {
        Node* res = mergeTreap(t->left, t->right);
        delete t;
        return res;
    } else if( v < t->key || (v == t->key && id < t->id) ) {
        t->left = eraseTreap(t->left, v, id);
        recalc(t);
        return t;
    } else {
        t->right = eraseTreap(t->right, v, id);
        recalc(t);
        return t;
    }
}
 
// Global treap root pointer.
Node* treapRoot = nullptr;
 
// We'll keep an array (1-indexed) of Node* pointers so that when an update occurs we can quickly remove the old node.
vector<Node*> nodePtr;
 

void sol(){
 
    srand((unsigned)time(NULL));
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }
    
   
    pow2Arr.resize(N+5);
    pow2Arr[0] = 1;
    for (int i = 1; i < (int)pow2Arr.size(); i++){
        pow2Arr[i] = (pow2Arr[i-1] * 2) % MOD;
    }
    
    
    nodePtr.resize(N+1, nullptr);
    treapRoot = nullptr;
    for (int i = 1; i <= N; i++){
        Node* newNode = new Node(A[i], i);
        nodePtr[i] = newNode;
        treapRoot = insertTreap(treapRoot, newNode);
    }
    
   
    long long initialAnswer = 0;
    if (treapRoot) {
        initialAnswer = (treapRoot->f + treapRoot->adj) % MOD;
    }
    cout << initialAnswer << "\n";

    // Process Q updates.
    for (int i = 0; i < Q; i++){
        int x, v;
        cin >> x >> v;
        
        Node* oldNode = nodePtr[x];
        treapRoot = eraseTreap(treapRoot, oldNode->key, oldNode->id);
       
        Node* newNode = new Node(v, x);
        nodePtr[x] = newNode;
        treapRoot = insertTreap(treapRoot, newNode);
 
        long long ans = 0;
        if(treapRoot) {
            ans = (treapRoot->f + treapRoot->adj) % MOD;
        }
        cout << ans << "\n";
    }
 
    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long t;
    cin >> t;
    while(t--) sol();
}
