#include <iostream>
#include <algorithm>
using namespace std;

namespace tree {
  template <class Node, int TREE_SIZE> class Tree {
  public:
    virtual Node get_identity() = 0;

    void init( const int& new_nodes ) {
      N = new_nodes;
      std::fill(list + 0, list + TREE_SIZE, this->get_identity());
    }
    
    void update_single_node( const int& node_id, const Node& new_node ) {
      list[node_id] = new_node;
    }
    
    void range_update( const int& root, const int& left_most_leaf, const int& right_most_leaf, const int& u, const int& v, const Node& new_node ) {
      if ( u <= left_most_leaf && right_most_leaf <= v )
        return update_single_node(root, new_node);
      int mid = ( left_most_leaf + right_most_leaf ) / 2;
      int left_child_root = root * 2;
      int right_child_root = left_child_root + 1;
      if ( u < mid )
        range_update(left_child_root, left_most_leaf, mid, u, v, new_node);
      if ( mid < v )
        range_update(right_child_root, mid, right_most_leaf, u, v, new_node);
      list[root].merge(list[left_child_root], list[right_child_root]);
    }
    
    void update( const int& pos, const Node& new_node ) {
      range_update(1, N, 2 * N, N + pos, N + pos + 1, new_node);
    }
    
    Node range_query( const int& root, const int& left_most_leaf, const int& right_most_leaf, const int& u, const int& v ) {
      if ( u <= left_most_leaf && right_most_leaf <= v )
        return list[root];
      int mid = ( left_most_leaf + right_most_leaf ) / 2;
      int left_child_root = root * 2;
      int right_child_root = left_child_root + 1;
      Node left_node = this->get_identity();
      Node right_node = this->get_identity();
      if ( u < mid )
        left_node = range_query(left_child_root, left_most_leaf, mid, u, v);
      if ( mid < v )
        right_node = range_query(right_child_root, mid, right_most_leaf, u, v);
      Node res = this->get_identity();
      res.merge(left_node, right_node);
      return res;
    }
    
    Node query( const int& l, const int& r ) {
      return range_query(1, N, 2 * N, N + l, N + r);
    }
    
    Node list[TREE_SIZE];
    int N;
  };
}

// ---

typedef long long Int;
const Int SIZE = 100000 + 11;
const Int TREE_SIZE = SIZE * 3 + 11;

Int N;
Int M;
Int A[SIZE];

struct Node {

  Int segmentSum;
  Int bestPrefix;
  Int bestSuffix;
  Int bestSum;

  Node() {
    segmentSum = 0;
    bestPrefix = 0;
    bestSuffix = 0;
    bestSum = 0;
  }

  Node( const Int& x ) {
    segmentSum = x % M;
    bestPrefix = x % M;
    bestSuffix = x % M;
    bestSum = x % M;
  }
  
  void merge( const Node& left, const Node& right ) {
    segmentSum = (left.segmentSum + right.segmentSum) % M;
    bestPrefix = std::max((left.segmentSum + right.bestPrefix) % M, left.bestPrefix);
    bestSuffix = std::max((right.segmentSum + left.bestSuffix) % M, right.bestSuffix);
    bestSum    = std::max(std::max(left.bestSum, right.bestSum), (left.bestSuffix + right.bestPrefix) % M);
  }
  
};

class Tree: public tree::Tree<Node, TREE_SIZE> {
  Node get_identity() {
    Node res(0);
    return res;
  }
};

bool input() {
  if ( cin >> N >> M ) {
    for ( int i = 0; i < N; ++ i ) {
      cin >> A[i];
    }
    return true;
  }
  return false;
}

Node create_node( const Int& x ) {
  Node res(x);
  return res;
}

Tree t;

Int solve() {
  t.init(N);
  for ( int i = 0; i < N; ++ i ) {
    t.update(i, A[i]);
  }
  Int res = 0;
  for ( int i = 0; i < TREE_SIZE; ++ i ) {
    res = std::max(res, t.list[i].bestSum);
  }
  return res;
}

int main() {
  int tests;
  cin >> tests;
  for ( int i = 0; i < tests; ++ i ) {
    if ( input() ) {
      cout << solve() << endl;
    }
  }
  return 0;
}
