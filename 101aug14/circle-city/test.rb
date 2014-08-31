r = 25

1000.times do |x|
  puts "#{x + 1} % 4 = #{(x + 1) % 4}" if ( ( r ** 1 ) % ( x + 1 ) ) == 0
end

1000.times do |x|
  1000.times do |y|
    puts "#{x}^2 + #{y}^2 == #{r}^2" if x**2 + y**2 == r**2
  end
end
