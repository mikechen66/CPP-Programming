# Algorithm

## Introduction

The C++ standard library provides a framework for dealing with data as sequences of elements, called the STL, designed by Alex Stepanov. The STL is the part of the ISO C++ standard library that provides containers (such as vector, list, and map) and generic algorithms (such as sort, find, and accumulate). The simplest definition of generic programming in C++ is using templates. Generic programming: Writing code that works with a variety of types presented as arguments, as long as those argument types meet specific syntactic andsemantic requirements
with focus on Algorithms. 

## Algorithm

Standard Template Library: Algorithms. The header <algorithm> defines a collection of functions especially designed to be used on ranges of elements.A range is any sequence of objects that can be accessed through iterators or pointers, such as an array or an instance of some of the STL containers. Notice though that algorithms operate through iterators directly on the values, not affecting in any way the structure of any possible container (it never affects the size or storage allocation of the container). The standard library offers about 80 algorithms. 

## List of Algorithms

/* <algorithm>
 * all_of       test condition on all elements in range
 * any_of       test if any element in range fulfills condition
 * none_of      test if no elements fulfill condition
 * for_each     apply a function to a range
 * find         find a value in a range
 * find_if      find element in range
 * find_if_not
 * find_end
 * find_first_of
 * adjacent_find
 * count
 * count_if
 * mismatch
 * equal
 * is_permutation
 * search
 * search_n
 *
 * copy
 * copy_n
 * copy_if
 * copy_backward
 * move
 * move_backward
 * swap
 * swap_ranges
 * iter_swap
 * transform
 * replace
 * replace_if
 * replace_copy
 * replace_copy_if
 * fill
 * fill_n
 * generate
 * generate_n
 * remove
 * remove_if
 * remove_copy
 * remove_copy_if
 * unique
 * unique_copy
 * reverse
 * reverse_copy
 * rotate
 * rotate_copy
 * random_shuffle
 * shuffle
 *
 * is_partitioned
 * partition
 * stable_partition
 * partition_copy
 * partition_point
 *
 * sort
 * stable_sort
 * partial_sort
 * partial_sort_copy
 * is_sorted
 * is_sorted_until
 * nth_element
 *
 * lower_bound
 * upper_bound
 * equal_range
 * binary_search
 *
 * merge
 * inplace_merge
 * includes
 * set_union
 * set_intersection
 * set_difference
 * set_symmetric_difference
 *
 * push_heap
 * pop_heap
 * make_heap
 * sort_heap
 * is_heap
 * is_heap_until
 *
 * min
 * max
 * minmax
 * min_element
 * max_element
 * minmax_element
 *
 * lexicographical_compare
 * next_permutation
 * prev_permutation 
 */

https://www.cplusplus.com/reference/algorithm/
