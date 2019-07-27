# mrspec   [![Build Status](https://travis-ci.org/ore-public/mrspec.svg?branch=master)](https://travis-ci.org/ore-public/mrspec)
FizzBuzz class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'yuukis234/mrspec'
end
```
## example
```ruby
p FizzBuzz.hi
#=> "hi!!"
t = FizzBuzz.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
