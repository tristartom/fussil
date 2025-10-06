Lab F1: Checking number-comparison by using SPIN
===

You are given a program with a function `int* comp(int st, int ta)`.

Your task is to prove the following: for any `st`, `ta`, and `st1 = comp(st, ta)`, prove `st1 > st`.

You are required to use **SPIN** ([https://spinroot.com/spin/Man/](https://spinroot.com/spin/Man/)) to mechanize this proof. In all exercises in this lab, you will be given two C programs:

```c
int* comp1(int st, int ta){
    static int st;
    if (st < ta) st = ta;
    return st;
}

int* comp2(int st, int ta){
    static int st2;
    if (st < ta && st != 0) st = ta;
    return st;
}
```

**Exercise 1:**
Define `int` to be 2-bit long in SPIN. Implement a checker to verify the target property (`(*comp(st, ta)) > st`) and model `comp` in SPIN.

**Exercise 2:**
Analyze your SPIN checker in Exercises 1 and 2. Describe how many states it explored.

**Exercise 3:**
Think about how you can reduce the explored states soundly, that is, without violating the correctness of the checker.


