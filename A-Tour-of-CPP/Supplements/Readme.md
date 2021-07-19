# Supplements - Vector, Container and Algorithm
 
Bjarne Stroustrup

## Introduction

The C++ standard library provides a framework for dealing with data as sequences of elements, called the STL, designed by Alex Stepanov. The STL is the part of the ISO C++ standard library that provides containers (such as vector, list, and map) and generic algorithms (such as sort, find, and accumulate). The simplest definition of generic programming in C++ is “using templates. Generic programming: Writing code that works with a variety of types presented as arguments, as long as those argument types meet specifi c syntactic andsemantic requirements. It is originally No.19 ~ No.21 Chapters, Porogramming Principles and Practice Using C++ 2nd Edition.

## Vector

Vector is the most common and most useful STL container. Vectors are sequence containers representing arrays that can change in size. Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.


## Container

A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements. The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers). The C++ containers include vector, list, deque, map, multimap, unordered_map, unordered_multimap, set, multiset, unordered_set, unordered_multiset and array. 

## Algorithm

Standard Template Library: Algorithms. The header <algorithm> defines a collection of functions especially designed to be used on ranges of elements.A range is any sequence of objects that can be accessed through iterators or pointers, such as an array or an instance of some of the STL containers. Notice though that algorithms operate through iterators directly on the values, not affecting in any way the structure of any possible container (it never affects the size or storage allocation of the container). The standard library offers about 80 algorithms. 

Vector: 

https://www.cplusplus.com/reference/vector/vector/?kw=vector

Container:

https://www.cplusplus.com/reference/stl/

Algorithm

https://www.cplusplus.com/reference/algorithm/
