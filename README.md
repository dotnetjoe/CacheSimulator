# Cache Simulator
[isort-trace.txt](https://github.com/adamalston/Cache-Simulation/blob/master/isort-trace.txt) represents a cache.

[dmc.c ](https://github.com/adamalston/Cache-Simulation/blob/master/dmc.c) is the program used to analyze this cache.

This program will simulate a direct-mapped cache with a C program.
You will read a list of addresses collected from the MIPS simulator
running the insertion sort code. You will simulate the cache by comparing
the tag for each address to the tag stored in an array. If the tag is there
you got a HIT and add 1 to cycles. If the tag is not there, you got a MISS
so you insert the tag into the array and add 100 to the number of cycles. After
reading all the addresses you are to report the number of `hits` and `misses`, and
the number of `cycles`.

Once you get your code written, you'll run it like this: 

```
./dmc linesize cachelines < isort-trace.txt.
```

For example, to simulate a cache with 8 lines of 16 bytes each you'd use:

```
./dmc 16 8 < isort-trace.txt
```

## Below you can answer questions about the results you see from running your simulation on the given data.

1.  How many cycles are required if every access misses?
    - You can measure this by setting linesize=4 and cachelines=1. This is
equivalent to not having the cache.

2.  How many cycles are required for linesize=4 cachelines=16?

3.  What was the hit rate for the cache above?
    * Express as a number between 0 and 1.

4.  How many cycles are required for linesize=16 cachelines=4?

5.  What was the hit rate for the cache above?
Express as a number between 0 and 1.

6.  How many cycles are required for linesize=16 cachelines=16?

7. What was the hit rate for the cache above?
Express as a number between 0 and 1.

8. What is the speedup provided by the last cache over no caching?

