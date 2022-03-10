# Problem 3 - Placing Antennas (antennas)
## Introduction
While your team is taking part in the **Reply Code Challenge - Teen Edition**, hundreds of other teams are competing in the **Reply Code Challenge - Standard Edition**. Their goal: to build the next generation of telecoms infrastructure by placing 5G antennas over a specific area.

As it is not possible to take part in both challenges at the same time, we would like to give you a similar, but also smaller challenge.

You are given a list of `N` buildings in a city and a list of `N` 5G antennas you can place on top of a building to connect its residents, you cannot place more than one antenna on a building.

Each building `b` has an associated value `B[b]` and, in the same way, each antenna has an associated value `A[a]`. Once you connect a building by placing an antenna on top of it, you will earn a score of `A[a] ∗ B[b]`.

If you place different antennas on different buildings, your total score will equal the sum of each single score.

Unfortunately, each antenna uses considerable power and you only have enough power to place exactly `K` of these antennas in the area.

Write a program that finds both the maximum and the minimum score possible.

## Input data
The first line of the input file contains an integer `T`, the number of test cases to solve, followed by `T` testcases, numbered from `1` to `T`.

In each test case, the first line contains the two integers `N` and `K`: the number of antennas/buildings available and the number of antennas to place.

The second line containts `N` space-separated integers: the array `A[N]` with the antennas scores.

The third line containts `N` space-separated integers: the array `B[N]` with the building scores.

## Output data
The output file must contains `t` lines. For each test case in the input file, the output file must contains a line with the words:

`Case #t: smin smax`

where `t` is the test case number (from `1` to `T`), smin is the minimum possibile score and smax is the maximum possibile score.

## Constraints
 - 1 ≤ `T` ≤ 20.
 - 1 ≤ `N` ≤ 100 000.
 - 1 ≤ `K` ≤ 10 000.
 - 1 ≤ `K` ≤ N for every 0 ≤ *i*< N .
 - -10 000 ≤ `A[i]`, `B[i]` ≤ 10 000.
 - You have to place exactly K antennas.
 - All the solutions fit in a 64 bit signed integer.

## Scoring
 1. **Input 1** : `T` = 5, `N` ≤ 10, `K` = 1 and all values of `A[N]` and `B[N]` are positive.
 2. **Input 2** : `T` = 5, `N` ≤ 50, `K` = 2 and all values of `A[N]` and `B[N]` are positive.
 3. **Input 3** : `T` = 10, `N` = 6 and `K` = 6.
 4. **Input 4** : `T` = 15, `N` ≤ 5 000 and `K` ≤ 100.
 5. **Input 5** : `T` = 20, `N` ≤ 100 000 and `K` ≤ 10 000.

## Examples
**input.txt**
```txt
1
6 2
4 2 5 5 5 5
3 2 5 2 5 5
```
**output.txt**
```
Case #1: 12 50
```

## Explanation
In the example you have to place exactly 2 antennas from a set of 6 possible ones.

To minimize the score you can place the two antennas of scores 2 on top of the two buildings of scores 4 and 2, for a total score of 2 ∗ 2 + 2 ∗ 4 = 12

To maximize the score you can place the two antennas of scores 5 on top of the two buildings of scores 5, for a total score of 5 ∗ 5 + 5 ∗ 5 = 50.