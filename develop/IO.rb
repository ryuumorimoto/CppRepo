ary = []
fp=open("../Algorithm/problem.in")
if fp==nil;  puts "Error: cant open input file. ";  exit -1; end # エラ
fp.each{|line|
    line.chomp!
    next if line.size<1
    ary1=line.split(" ")
    ary1.each{ |v|
        ary.push(v)
    }
    #next if ary.size<4
}
p ary

File.open("RB.txt","w") do |f|
    ary.each{ |v|
        f.puts(v)
    }
    
end
