# Factorial Modulo-N

## Description

Given a number. Find the factorial of the number and under modulo 5.

## Boundary Conditions

1 <= number <= 10^18

## Test Case

### Input

5

### Output

0

### Explanation

Factorial of 5 is 120. Applying modulo-5 gives 0.

## Approach

### Naive

The naive approach is to find factorial of the number and then apply modulo. Let's consider the number as 30. Then
30! = 265252859812191058636308480000000 which results in overflow of data type. Hence we cannot apply modulo after
factorial.

### Optimized

The optimized approach is to apply the modulo operation each time we find factorial of the number. This way, the factorial
is kept small till the end and hence we get our required answer.
