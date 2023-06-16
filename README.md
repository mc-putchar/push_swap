
![push_swap evaluated Badge](https://github.com/mc-putchar/push_swap/assets/126549052/5c2a8a8a-26f1-4ec2-b0e5-d2b6251d3106)

# Push Swap<br>
## Description<br>
Push Swap is a sorting algorithm project developed as part of the 42 Berlin core curriculum. The goal of the project is to sort a stack of integers using a limited set of instructions.

The push_swap program takes a list of integers as arguments and outputs a series of instructions to sort the stack.

The sorting algorithm used in Push Swap is based on a combination of insertion sort and selection sort. It optimizes the sorting process by minimizing the number of instructions required.

## Rules
The following rules must be followed in the implementation of Push Swap:

You have 2 stacks named a and b.

At the beginning:

The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
The stack b is empty.
The goal is to sort numbers in stack a in ascending order.

## Operations

**sa (swap a)**: Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.<br>
**sb (swap b)**: Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.<br>
**ss**: Perform sa and sb simultaneously.<br>
**pa (push a)**: Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.<br>
**pb (push b)**: Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.<br>
**ra (rotate a)**: Shift up all elements of stack a by 1. The first element becomes the last one.<br>
**rb (rotate b)**: Shift up all elements of stack b by 1. The first element becomes the last one.<br>
**rr**: Perform ra and rb simultaneously.<br>
**rra (reverse rotate a)**: Shift down all elements of stack a by 1. The last element becomes the first one.<br>
**rrb (reverse rotate b)**: Shift down all elements of stack b by 1. The last element becomes the first one.<br>
**rrr**: Perform rra and rrb simultaneously.<br>


## Performance
Under 7000 operations for 500 elements stack

https://github.com/mc-putchar/push_swap/assets/126549052/23bbbcea-020a-4b93-870b-232ef4c0e6ec

