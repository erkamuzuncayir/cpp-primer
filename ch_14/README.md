```
// -----------------------------------------------------------------------------
// File:        README.md
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
// -----------------------------------------------------------------------------
```

# Chapter 14 | Overloaded Operations and Conversions

## Solution 14.1

### Difference

- Overloaded operators can call as a function too.
- Parameters of overloaded operators must be a member of a class type or have at least one parameters have to be class type.

### Same

- Precedence and associativity rules of both type of operators are same. 

## Solution 14.2

- neither, `const char *`
- `string`
- `vector`
- `string`

## Solution 14.3

1. symmetric, not member
2. changing state of object, member
3. changing state of object, member
4. `->`, `=`, `[]`, `()`; all of them must be member.
5. not member
6. symmetric, not member
7. symmetric, not member
8. `->`, `=`, `[]`, `()`; all of them must be member.


## Solution 14.7

```c++
std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    for (char *ptr = str.first_ch; ptr < str.last_ch; ++ptr)
        os << *ptr;
    return os;
}
```

## Solution 14.7

If other way around used, one more copy of `Sales_data` will be wasted in `operator +`.

## Solution 14.15

Unfortunately there is no meaning to any arithmetic operation on `Vehicle` class because none of the variables makes sense to manipulate with arithmetic operations.

## Solution 14.29

Because those operations change state of the object, so `const` versions will be meaningless.

## Solution 14.31

Because there is no dynamic allocation that synthesized versions can't handle.

## Solution 14.33

It should be at least `256`, more than one should use.

## Solution 14.41

If it'll be very verbose and clear using lambda to create a solution, it can use. Otherwise, creating a class can be much clearer.

## Solution 14.42

```c++
std::count_if(i_vec.begin(), i_vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 1024));
std::find_if(s_vec.begin(), s_vec.end(), std::bind(std::not_equal_to<std::string>(), std::placeholders::_1, "pooh"));
std::transform(i_vec.begin(), i_vec.end(), std::bind(std::multiplies<int>(), std::placeholders::_1, 2));
```

## Solution 14.43

```c++
std::find_if(i_vec.begin(), i_vec.end(), std::bind(std::divides<int>(), std::placeholders::_1, 2));
```

## Solution 14.46

I think this conversion operators are misleading but, they should be explicit.

## Solution 14.47

- First one can modify inside conversion function and, it returns `const int`, so one can't modify returned object.
- Second one can't modify inside conversion but can modify returned object.

## Solution 14.48

I don't think there is a meaningful outcome for converting `Vehicle` class to `bool`.

## Solution 14.50

- First one is ambiguous because both `double` and `float` are viable candidates.
- Second one is use `float()`, there is no ambiguity. 

## Solution 14.51

`void calc(int)` will be used because `dval` to `int` conversion will be standard conversion and, standard conversions have higher rank than user defined conversions.

## Solution 14.52

- First one is no viable function.
- Second one is uses `LongDouble operator+(LongDouble&, double);`

## Solution 14.51

Illegal, because it is ambiguous. For making legal `3.14` should be explicitly cast to `SmallInt` like this: `double d = s1 + SmallInt(3.14);`