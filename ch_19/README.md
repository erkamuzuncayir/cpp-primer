```
/***************************************************************************
 *  @file       README.md
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-26
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
```

# Chapter 19 | Specialized Tools and Techniques

## Solution 19.01

```c++
void *operator new(size_t size) 
{
    if (void *mem = malloc(size))
        return mem;
    else
        throw bad_alloc();
}
void operator delete(void *mem) noexcept { free(mem); }
```

## Solution 19.02

I purposefully skip this exercise.

## Solution 19.03

- Succeeds
- Fails due to downcast
- Fails due to ambiguity

## Solution 19.04

```c++
try 
{
    C& rc = dynamic_cast<C&>(*pa);
    // use C’s members with rc
} catch (const std::bad_cast& e) 
{
    // use A’s members with *pa
}
```

## Solution 19.05

If you can achieve same thing with `virtual functions` do not use `dynamic_cast`.

## Solution 19.11

Unlike ordinary pointers, a pointer to member also incorporates the class that contains the member.

## Solution 19.14

No, it is not legal if `get_cursor` and `get` have different function signatures (different return types or parameter lists).

## Solution 19.15

| Ordinary Function Pointer                   | Pointer to Member Function                                                      |
| ------------------------------------------- | ------------------------------------------------------------------------------- |
| Points to a **free** (non-member) function. | Points to a **member** function of a class.                                     |
| Has type like `RetType (*)(ArgTypes...)`    | Has type like `RetType (ClassName::*)(ArgTypes...)`                             |
| Called as `f(args...)`                      | Called on an object or pointer: `(obj.*pmf)(args...)` or `(ptr->*pmf)(args...)` |
| No implicit `this` pointer                  | Requires an object instance to call (needs `this` pointer)                      |

## Solution 19.16

`using AvgPricePtr = double Sales_data::*;`

## Solution 19.17

```c++
class Screen {
public:
    typedef std::string::size_type pos;

    char get_cursor() const;
    char get() const;
    char get(pos ht, pos wd) const;
};

int main()
{
    using GetCursorMemFn = char (Screen::*)() const;
    using GetNoParamMemFn = char (Screen::*)() const;
    using GetWithPosMemFn = char (Screen::*)(Screen::pos, Screen::pos) const;
}
```

## Solution 19.26

It's not legal. The C language does not support function overloading, so a C linkage directive can be specified for only one function in a set of overloaded functions. If one function among a set of overloaded functions is a C function, the other functions must all be C++ functions.