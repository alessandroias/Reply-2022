# Problem 1 - Gadgets kits (kits)
For each Reply Challenge, the Reply Social Network Team has to prepare thousands of gadget kits to send to Challenge players all around the world.

In our Social Network warehouse right now, we have `N` types of gadgets like t-shirts, books and stickers and we know how many of each type of gadget we have available.

To simplify managing the team, we want to organise the preparation of gadget kits we need to send in advance. To automate preparation, we will put the same number of gadgets of each available type in
every single gadget kit.

Because we do not want to waste any of the gadgets during preparation, each type of available gadget has to be equally distributed in each of the kits with no leftovers.

Given the number of gadgets available for each of the `N` types, how many possible configurations of gadgets kits can the Reply Social Network Team prepare?

## Input data
The first line of the input file contains an integer `T`, the number of test cases to solve, followed by `T` testcases, numbered from `1` to `T`.

In each test case, the first line contains the integer `N` representing the number of distinct kinds of gadgets.

The second line containts `N` space-separated integers, the array `G[N]` with the number of gadgets available for each kind.

## Output data
The output file must contains `t` lines. For each test case in the input file, the output file must contains a line with the words:

`Case #t: k`

where `k` is the number of different possible type of gadgets kits that can be prepared.

## Constraints
 - 1 ≤ `T` ≤ 20.
 - 1 ≤ `N` ≤ 100 000.

## Scoring
 1. **input 1** : `T` = 1, `N` ≤ 10.
 2. **input 2** : `T` = 5, `N` ≤ 100.
 3. **input 3** : `T` = 10, `N` ≤ 1 000.
 4. **input 4** : `T` = 15, `N` ≤ 10 000.
 5. **input 5** : `T` = 20, `N` ≤ 100 000.

## Examples
**input.txt**
```
3
4
1 2 3 5
4
4 4 6 8
8
40 88 32 40 48 32 40 24
```
**output.txt**
```
Case #1: 1
Case #2: 2
Case #3: 4
```

## Explanation
In the **first example** only one possible type of kit can be prepared with (1, 2, 3, 5) number of gadgets for each kind.
 
In the **second example** two possible type of kits can be prepared, the first one with (4, 4, 6, 8) number of gadgets for each kind and the second one with (2, 2, 3, 4) number of gadgets for each kind.