# Longest Common Subsequence

You are given two strings X and Y and their length xL and yL. Your program has to calculate length of their longest common subsequence. What is a subsequence? 
For example, for string "abc" we have { "a", "b", "c", "ab", "ac", "bc", "abc", "" }.

Approach
---
I used recursive function. Naive solution without any optimaization technic was of course way too slow. I wanted to speed it up by using memoization. I used
unordered_map as my memo object. It uses xL and yL converted into string "xL.yL" as a key and int number as value. My solution turned out to be correct but 
(unfortunately) still too slow. My attempt managed to pass 42 of 47 unit tests on Leetcode. I am planning to replace memoization with tabulation in the future. 
Hopefully it will work.
