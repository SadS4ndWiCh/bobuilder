# 🏡 bobuilder

With a sequence of commands you can have your dream house! At least if you're a 2D 
person or just a minimalist one.

## take it!

Start the building with `house` command and pipe your desires! Finish with `build` 
to build it!

You want a house with 2 floors?

```
$ house | floor 2 | build
```

```
   ___   
  /,-,\  
 / |_| \ 
/_______\
|,^, ,^,|
||_| |_||
|,^, ,^,|
||_| |_||
|    ,-,|
|    | ||
'======='
```

You want a house with 2 floors and 3 garages?

```
$ house | floor 2 | garage 3 | build
```

```
                                    ___   
                                   /,-,\  
                                  / |_| \ 
                                 /_______\
                                 |,^, ,^,|
                                 ||_| |_||
 _________  _________  _________ |,^, ,^,|
/,-------,\/,-------,\/,-------,\||_| |_||
||       ||||       ||||       |||    ,-,|
||   -   ||||   -   ||||   -   |||    | ||
'=========''=========''=========''======='
```
