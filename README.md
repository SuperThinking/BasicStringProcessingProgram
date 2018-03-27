# BasicStringProcessingProgram

dictionary encoding: 
"hello world hello everyone" 
would map to 
[0 1 0 2] 
where 0 = "hello", 1 = "world", and 2 = "everyone" if we were encoding words.

one-hot dictionary encoding: 
"hello world hello everyone" 
would map to
    [[1 0 1 0]
     [0 1 0 0]
     [0 0 0 1]]
