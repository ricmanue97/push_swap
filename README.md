Sort a random list of integers using the smallest number of moves, 2 stacks and a limited set of operations.


You start with two empty stacks: a and b. You are given a random list of integers via command line arguments.


Allowed Moves:

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

![image](https://github.com/user-attachments/assets/27a766fe-6856-4419-adff-d016966b2b06)


pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

![image](https://github.com/user-attachments/assets/f1b6aa07-62ce-4493-87f9-781131194ac8)


ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

![image](https://github.com/user-attachments/assets/2c08617d-1aa2-4d78-8c7c-c0a5e28b16c8)


rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

rrr : rra and rrb at the same time.

![image](https://github.com/user-attachments/assets/4d081725-7204-42c6-ba52-8ee496c612aa)


At the end, stack b must empty empty and all integers must be in stack a, sorted in ascending order. The challenge of this project is really teaching you that we not only have to code, but we also need to optimize every aspect of our code, in order to have the fastest and smoothest experience.

In order to do this i used an algorithm called turk algorithm ,i will link an article on it after, which the base idea is to have on stack A 3 numbers and order them in ascending order, and when sending numbers to stack B, sending them in descending order.
https://medium.com/@ayogun/push-swap-c1f5d2d41e97



Bonus Part
Make a checker program that verifies if a certain set of commands, given by standard input, sorts the integers given.
