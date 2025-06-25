```
// -----------------------------------------------------------------------------
// File:        README.md
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------
```

# Chapter 16 | Templates and Generic Programming

## Solution 16.1

Instantiation is, when compiler saw a use of a template function and try to create an instance of that template function.

## Solution 16.8

Probably more class defines `!=` operator than `<` operator. This should be reason.

## Solution 16.9

- A function template is blueprint of a function. Using that one can create same expressions and operations of function but, processing different types.

- Same thing for classes.

## Solution 16.10

Compiler generate a specific class from template with using type argument.

## Solution 16.10

```c++
void insert(ListItem<elemType> *ptr, elemType value);
// instead of 
void insert(ListItem *ptr, elemType value);

ListItem<elemType> *front, *end;
// instead of
ListItem *front, *end;
```

## Solution 16.13

I use the function friendship for accessing `wptr` and `current`. Look at: [ex_12.cpp](ex_12.cpp)

## Solution 16.16

I use the function friendship for accessing `contents`. Look at: [ex_14.cpp](ex_14.cpp)

## Solution 16.17

When we want to inform the compiler that a name represents a type, we must use the keyword typename, not class.

## Solution 16.18

- `template <typename T, U, typename V> void f1(T, U, V);` 
  - illegal, `typename` keyword missing before `U`.
- `template <typename T> T f2(int &T);` 
  - illegal, `int` after `f2` must not be here.
- `inline template <typename T> T foo(T, unsigned int*);`
  - illegal, `inline` keyword must be after `<typename T>`
- `template <typename T> f4(T, T);`
  - illegal, return type is missing
- `typedef char Ctype; template <typename Ctype> Ctype f5(Ctype a);`
  - `template` declaration hides `typedef` statement.

## Solution 16.23

Just once, after the `main`.

## Solution 16.25

- Instantiation declaration, definition will come after.
- Instantiation definition, the compiler generates necessary code at the moment.

## Solution 16.26

We can't because `std::vector<type> t_vec(size_t n)` requires default constructable types.

## Solution 16.27

- Declaration.
- Declaration, reference to type doesn't need instantiation.
- Instantiation.
- Declaration, pointer doesn't require instantiation.
- Instantiation.
- Instantiation.

## Solution 16.30

Look at [ex_12_24_29.cpp](ex_12_24_29.cpp)

## Solution 16.31

The compiler can inline the call to DebugDelete::operator() because it is a template defined inside the class body. This allows the compiler to see the full implementation at the call site. Since the function is small and simple (just a message and delete), the compiler can replace the call with the actual code, eliminating the overhead of the function call. Inlining is especially likely in optimized builds.

## Solution 16.32

During template argument deduction, the compiler uses types of the  arguments in the call to find the template arguments that generate a version of the  function that best matches the given call.

## Solution 16.33

const conversions and array or function to pointer are the only automatic conversions for arguments to parameters with template types.

## Solution 16.34

- It will T for char[3], char[6] and won't compile
- It will T for char[3], char[3] and will compile.

## Solution 16.35

- Legal, char
- Legal, double
- Legal, char
- Illegal, T can't be both double and float.

## Solution 16.36

- `f1<int *>(int *, int *)`
- `f2<int *, int *>(int *, int *)`
- `f1<int const *>(int const *, int const *)`
- `f2<int const *, int const *>(int const *, int const *)`
- conflicting types for `T`
- `f2<int *, int const *>(int *, int const *)`

## Solution 16.37

Can't. T can't be both double and int.

## Solution 16.38

Without knowing type `make_shared` can't allocate required amount of memory.

## Solution 16.40

Legal. Any type that supports `+ 0` operation can be pass and return type is what this operation returns in terms of that type.

## Solution 16.41

```c++
template<typename T>
auto sum(T lhs, T rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}
```

## Solution 16.42

- T&
- const T&
- T&&

## Solution 16.43

- T&

## Solution 16.44

- T / T
- T / T
- T / T

## Solution 16.45

- It will be `int&&` and collapse to `int` so, `vector<T>` will be `vector<T>`.
- It will be `int&` and `vector<int&>` can't be used because standard containers can't hold references.

## Solution 16.46

In every iteration `std::move(*elem++)` casts `lvalue` to `rvalue` in this way move constructor calling instead of copy constructor.

## Solution 16.54

It won't compile.

## Solution 16.55

It won't compile.
  - `error: no matching function for call to ‘print(std::ostream&)’`

## Solution 16.57

### `initializer_list<T>`

#### Advantages

- Simple and clear syntax
- Lower overhead

#### Disadvantages

- All have to be same type
- Manual formatting needed

### `variadic template`

#### Advantages

- Any type

#### Disadvantages

- Complicated syntax
- High instantiation cost

## Solution 16.59

`emplace_back` used a construct an object its place rather than copying like `push_back` but, `s` is a `lvalue` so, it will copy like `push_back` instead of constructing object at its place.

## Solution 16.60

`make_shared` is a variadic template function that process all underlying constructors and create objects in dynamic memory and returns a `shared_ptr` points that object.

## Solution 16.61

```c++
template <typename T, typename... Args>
std::shared_ptr<T> my_make_shared(Args&&... args)
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}
```

## Solution 16.66

### Function overload

#### Advantages

- Simple and localized
- Easy maintenance

#### Disadvantages

- All have to be same type
- Manual formatting needed

### Template specialization

#### Advantages

- Customizable for every type

#### Disadvantages

- Hard maintenance
- Not very clear syntax

## Solution 16.67

Specialization doesn't affect function matching it occurs on when compiler instantiate a template.