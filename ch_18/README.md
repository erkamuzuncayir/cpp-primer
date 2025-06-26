```
/***************************************************************************
 *  @file       README.md
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-26
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
```

# Chapter 18 | Tools for Large Programs

## Solution 18.01

- `range_error`
- `range_error`
  - It'll throw pointer itself not the exception object. It is dangerous.

## Solution 18.02

```c++
void exercise(int *b, int *e)
{
    vector<int> v(b, e);        // This will be destroyed by it's destructor
    int *p = new int[v.size()]; // This will be leak.
    ifstream in("ints");        // This will be destroyed by it's destructor
// exception occurs here
}
```

## Solution 18.03

- It can be solved by using class and its destructor.
- Also using smart pointers solves.

## Solution 18.04

- It ordered wrongly. It should be inverted.
- Also `const` and `&` use make block more efficient and prevent object slicing.

## Solution 18.05

```c++
int main()
{
    try 
    {
    
    }
    catch (...) 
    {
    
        throw;
    }
}
```

## Solution 18.07

Look at [ex_07.cpp](ex_07.cpp)

## Solution 18.11

The what() function must not throw because it is typically called while handling an exception, and throwing an exception from what() itself would cause program termination due to exception propagation rules in C++.

## Solution 18.12

I purposefully skip this exercise.

## Solution 18.13

If I want to names in a file will be local ta that particular file, I should use unnamed namespaces.

## Solution 18.14

`mathLib::MatrixLib::matrix mathLib::MatrixLib::operator*`

## Solution 18.15

`using directive` makes all names from the namespace visible in the current scope. Increases the risk of name collisions. But `using declaration` brings only one specific name from a namespace, it is much more safe.

## Solution 18.16

Look at [ex_17.cpp](ex_17.cpp)

## Solution 18.18

- Because `string` is a part of `std` library, it will looks up in `std::string` too and will use;
  - `std::swap(std::string&, std::string&)`
- Because `int` is a builtin type, there is nowhere to look up in besides template `swap` function, so it will use;
  - `std::swap<int>(int&, int&);`

## Solution 18.19

In this time it's completely bypass argument-dependent lookup and can only use template `swap` function.

## Solution 18.20

### Candidates

1. `primerLib::void compute()`
2. `primerLib::void compute(const void *)`
3. `::void compute(int)`
4. `::void compute(double, double=3.4)`
5. `::void compute(char*, char* = 0)`

### Viable

1. `primerLib::void compute(const void *)`
2. `::void compute(int)`
3. `::void compute(double, double=3.4)`

### Match

`::void compute(int)`

### "if the using declaration were located in main before the call to compute?"

Nothing will change, the same applies as above.

## Solution 18.21

- Missing access specifier for `Vehicle`
- Duplicated same class inheritance.
- Valid.

## Solution 18.22

1. `A`
2. `B`
3. `C`
4. `X`
5. `Y`
6. `Z`
7. `MI`

## Solution 18.23

All of them permitted.

## Solution 18.24

```c++
ZooAnimal *pb = new Panda ("ying_yang");

pb->print();        // OK
pb->cuddle();       // ERROR
pb->highlight();    // ERROR
delete pb;          // OK
```

## Solution 18.25

1. `MI`
2. `MI`
3. `MI`
4. `MI` -> `D2` -> `Base2` -> `D1` -> `Base1`
5. `MI` -> `D2` -> `Base2` -> `D1` -> `Base1`
6. `MI` -> `D2` -> `Base2` -> `D1` -> `Base1`

## Solution 18.26

Because `print` implementation of `Derived` hides correct implementation in `Base1`. It can be fixed with calling by scope operator:
```c++
struct MI : public Derived, public Base2 
{
    using Base1::print;

    void print(std::vector<double>);
    ...
};
```

## Solution 18.27

1. a
   - Local: `dval`, `cval`
   - From MI: `ival`, `dvec`, `print(vector)`
   - From Derived: `sval`, `dval`, `print(string)`
   - From Base1: `ival`, `dval`, `cval`, `print(int)`
   - From Base2: `fval`, `print(double)`
2. b
   - Yes.
     - `Base1::dval`
     - `Derived::dval` (hides Base1's) 
     - `print()`: `Base1`, `Base2`, `Derived`, `MI` (with different parameters)
3. `dval = Base1::dval + Derived::dval;`
4. `Base2::fval = dvec.back();`
5. `sval[0] = Base1::cval;`

## Solution 18.28

```c++
struct Base
{
    void bar(int); // Qualification required

protected:
    int ival;
};

struct Derived1 : virtual public Base
{
    void bar(char); // No need
    void foo(char); // No need

protected:
    char cval;      // Ambiguous, qualification required
};
struct Derived2 : virtual public Base
{
    void foo(int);  // No need

protected:
    int  ival;      // Ambiguous, qualification required
    char cval;      // Ambiguous, qualification required
};
class VMI : public Derived1, public Derived2
{
};

```

## Solution 18.29

1. a.
   1. `Base → Class (from Final) → D1 → D2 → MI → Final`
   2. `Final → MI → D2 → D1 → Class → Base`
2. b.
   1. 1 `Base` part due virtual inheritance.
   2. 2 `Class` part due non-virtual inheritance.
3. c.
   1. Downcast, compile-time error.
   2. Upcast, OK.
   3. Downcast, compile-time error.
   4. Upcast, OK.