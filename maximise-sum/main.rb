class Tree

  N_MAX = 2 ** 20
  
  attr_reader :n
  attr_reader :data
  attr_reader :mod

  def initialize(n, mod)
    @n = n
    @mod = mod
    @data = ::Array.new(N_MAX, identity_node)
  end

  def update_single_node(k, node)
    data[k] = node
  end

  def range_update(root, l, r, u, v, node)
    return update_single_node(root, node) if u <= l && r <= v
    mid = ( l + r ) / 2
    left_child = root * 2
    right_child = left_child + 1
    if u < mid
      range_update left_child, l, mid, u, v, node
    end
    if mid < v
      range_update r, mid, r, u, v, node
    end
    data[root].merge data[left_child], data[right_child]
  end

  def update(k, x)
    range_update 1, n, 2 * n, n + k, n + k + 1, x
  end

  def range_query(root, l, r, u, v)
    # p "range_query: #{root}, #{l}, #{r}, #{u}, #{v}"
    return data[root] if u <= l && r <= v
    mid = ( l + r ) / 2
    left_child = root * 2
    right_child = left_child + 1
    left_node = identity_node
    right_node = identity_node
    if u < mid
      left_child = range_query(left_child, l, mid, u, v)
    end
    if mid < v
      right_child = range_query(r, mid, r, u, v)
    end
    res = identity_node
    res.merge left_node, right_node
    res
  end

  def query(l, r)
    range_query 1, n, 2 * n, n + l, n + r
  end

end

class Node

  attr_reader :segment_sum
  attr_reader :best_prefix
  attr_reader :best_suffix
  attr_reader :best_sum
  attr_reader :mod

  def initialize(x, mod)
    @mod = mod
    @segment_sum = x % mod
    @best_prefix = x % mod
    @best_suffix = x % mod
    @best_sum = x % mod
  end

  def merge(left, right)
    @segment_sum = ( left.segment_sum + right.segment_sum ) % mod
    @best_prefix = [(left.segment_sum + right.best_prefix) % mod, left.best_prefix].max
    @best_suffix = [(right.segment_sum + left.best_suffix), right.best_suffix].max
    @best_sum = [left.best_sum, right.best_sum, (left.best_suffix + right.best_prefix) % mod].max
  end

end

class Tree

  def identity_node
    Node.new(0, mod)
  end

end

def solve(n, m, a)
  tree = Tree.new(n, m)
  a.each.with_index {|x, k| tree.update k, Node.new(x, m) }
  tree.query(0, n)
end

gets.to_i.times do
  n, m = gets.split.map(&:to_i)
  a = gets.split.map(&:to_i)
  puts solve(n, m, a).best_sum
end
