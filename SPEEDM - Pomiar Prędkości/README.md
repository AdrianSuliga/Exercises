# SPOJ_exercise_1_speed_test
This is my solution for an exercise from SPOJ  

Current progress:

Program gives correct answer for simple tests given by SPOJ and more complicated ones, but in latter case it is too slow. Idealy it should run in less than 1.00 s.

Update: Speed problem should be solved now (probably), but for large inputs like k >= 2048 I receive an error "STACK OVERFLOW" (bruh). I suspect that I created too long string variable in my code.

Update: ,,Too long string" problem was solved as well, there is still a bug to find in recursive function (it gives wrong answers in specific cases). I do not find any more problems with speed.

Update: I was unable to solve the problem, I leave it as it is.

Details:

You are given an array of numbers [n1, n2, n3, ..., nk]. You start from 0 and may both add and substract numbers from the array to it. You have to use all of the numbers in a way that in the end will give you number that is as close to 0 as possible.

My ressoning:

S := n1 + n2 + n3 + ... + nk

We change the table [n1, n2, ..., nk] into a table [2 * n1, 2 * n2, ..., 2 * nk] = [a1, a2, ..., ak]

Now we want to substract those numbers from the array [a1, a2, ..., ak] from a sum S so that we get as close to 0 as possible. We do not have to use all of the numbers.
In my solution I used dynamic programming - I created a recursive function and put an unordered_map into it in order to memoize it

Download the newest solution [HERE](https://github.com/AdrianSuliga/SPOJ_exercise_1_speed_test/releases/tag/Third)

