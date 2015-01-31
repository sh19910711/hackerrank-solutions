gets.to_i.times.map do
  n, k = gets.split.map(&:to_i)
  gets.split.map(&:to_i).select {|x| x <= 0 }.size < k
end.each do |res|
  puts res ? "YES" : "NO"
end
