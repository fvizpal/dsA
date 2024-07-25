/*
  SEGEMNT TREE
    
   
*/

class SegmentTree {
    private:
    vector<int> tree;
    int n;
                                    // ind of node // s to e range
    void build(const vector<int>& arr, int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
        }
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }    
    
    int query(int node, int start, int end, int l, int r) {
        if(r < start || end > l) {
            return 0;
        }
        if(l <= start && end <= r) {
            return tree[node];
        }
        
        int mid = (start + end) / 2;
        
        int leftSum = query(2 * node + 1, start, mid, l, r);
        int rightSum = query(2 * node + 2, mid + 1, end, l, r);
        
        return leftSum + rightSum;
    }

    void update(int node, int start, int end, int ind, int val) {
        if(start == end) {
            tree[node] = val;
        }
        else {
            int mid = (start + end) / 2;
            if(ind >= start && ind <= mid) {
                update(2 * node + 1, start, mid, ind, val);
            }
            else {
                update(2 * node + 2, mid + 1, end, ind, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int ind, int val) {
        update(0, 0, n - 1, ind, val);
    }
};