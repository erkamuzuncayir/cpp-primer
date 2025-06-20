```
// -----------------------------------------------------------------------------
// File:        README.md
// Author:      Erkam Uzuncayir
// Date:        19/06/2025
// -----------------------------------------------------------------------------
```

# Chapter 15 | Object-Oriented Programming

## Solution 15.1

A `virtual member` is a function that declared as a `virtual` that inherited classes can `override` that function and create their implementations.

## Solution 15.2

Derived classes can use `protected` members whilst, they can't use `private` members.

## Solution 15.4

- Incorrect, a class can't derive from itself.
- Partially, it is definition.
- Incorrect, missing class body.

## Solution 15.8

Static type is an expression is always known it's type in compile time whilst, dynamic type may not be known in compile time.

## Solution 15.9

Pointer and reference of a static type can be different from its dynamic type.

## Solution 15.10

Because `ifstream` is derived from `istream` and `read` function takes `istream` as a parameter so, user can use `ifstream` also.

## Solution 15.12

It can be useful, if some derived class use both `override` and `final` otherwise it just makes function `final`.

## Solution 15.13

```c++
class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};
class derived : public base {
public:
    void print(ostream &os) override { base::print(os); os << " " << i; }
                         //   this   and this beeded,
private:
    int i;
};
```

## Solution 15.14

- bobj.print(); // compile time
- dobj.print(); // compile time
- bp1->name();  // compile time
- bp2->name();  // compile time
- br1.print();  // runtime
- br2.print();  // runtime

## Solution 15.18

Base *p = &d1;  // legal
p = &d2;        // illegal
p = &d3;        // illegal
p = &dd1;       // legal
p = &dd2;       // illegal
p = &dd3;       // illegal

Those are illegal that because user code can not use `public` members through a `private` or `protected` derived class or, `private` or `protected` inheritance.

## Solution 15.19

Derived-to-base conversion to a direct base class is always accessible to members of a derived class. This means `Pub_Derv`, `Prot_Derv` and `Priv_Derv` are legal.

However, member functions derived from already derived class may use the derived-to-base conversion if already derived class inherits from its base using either public or protected so; `Derived_from_Public` and `Derived_from_Protected` are legal, `Derived_from_Private` is illegal.

## Solution 15.23

Convert this `int fcn(int);` to this `int fcn() override;`

## Solution 15.24

Base classes that have derived classes need a virtual destructor. This needs comes from to be able to destroy derived objects.

## Solution 15.25

Compiler says `Cannot initialize an object of type Bulk_quote: default constructor is deleted`. Because if any derived class wants to define or implicitly generate a default constructor, default constructor of base class needed.

## Solution 15.29

Because first one slices `Bulk_quote` and pass `Quote` part of the object into the vector, but second one uses pointer, so it push just pointer into vector and, when one try to reach and use actual object it can use virtual function.

## Solution 15.31

1. First
   - Or -> Word
     - And -> Word
       - Not -> Word
2. Second
    - Or -> Word
        - And -> Word
            - Not -> Word
3. Third
    - Or ->
      - And -> Word
        - And -> Word
      - And -> Word
        - And -> Word

## Solution 15.32

- for copy operations, the only member `shared_ptr` will be copied into new instance of object so, both instance points same object so, both instances' `shared_ptr` count will be 2.
- for move operations, the only member `shared_ptr` will be moved into new instance of object therefore, new instance shared_ptr reference count will be 1 whereas, old one will point `nullptr`.
- for destroy operation, the only member `shared_ptr` will decrement the reference count. If counts below zero, it will destroy underlying object too.

## Solution 15.33

`Query_base` is an abstract class, so those operations doesn't happen on this class, it is happening class that inherits `Query_base` class.

## Solution 15.34

1. a.
   1. Query
   2. WordQuery
   3. AndQuery
   4. BinaryQuery
   5. Query
   6. OrQuery
   7. BinaryQuery
   8. Query
2. b.
   1. Query
   2. OrQuery
   3. AndQuery
   4. WordQuery
3. c.
    1. Query
    2. OrQuery
    3. AndQuery
    4. WordQuery

## Solution 15.35

I purposefully skip this exercise.

## Solution 15.36

I purposefully skip this exercise.

## Solution 15.37

One will lose operator overloading, copy/move semantics. For this reason one have to change constructors, method calls in various places.

## Solution 15.38

- Illegal, `BinaryQuery` is an abstract class.
- Illegal, operator returns a `Query` and it doesn't have conversion operator to `AndQuery`.
- Illegal, operator returns a `Query` and it doesn't have conversion operator to `OrQuery`.

## Solution 15.39

I purposefully skip this exercise.

## Solution 15.40

Nothing happens, nothing will be added into `std::set`.

## Solution 15.31

I purposefully skip this exercise.

## Solution 15.42

I purposefully skip this exercise.