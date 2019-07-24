##
## FizzBuzz Test
##

assert("FizzBuzz#hello") do
  t = FizzBuzz.new "hello"
  assert_equal("hello", t.hello)
end

assert("FizzBuzz#bye") do
  t = FizzBuzz.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("FizzBuzz.hi") do
  assert_equal("hi!!", FizzBuzz.hi)
end
