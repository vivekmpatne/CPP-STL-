# C++17 Vector Notes --- `std::vector`

> **Purpose:** Quick DSA/OA revision. These notes cover vector
> fundamentals, STL operations, common pitfalls, 2D vectors, and common
> DSA patterns.
>
> **Header:** `#include <bits/stdc++.h>` (common in competitive
> programming; not standard C++)\
> **Namespace:** `using namespace std;` (optional)

------------------------------------------------------------------------

## 1. What is a vector?

`vector<T>` is a **dynamic-size sequence container** that stores
elements contiguously in memory.

``` cpp
vector<int> v = {10, 20, 30};
```

Conceptual layout:

``` text
Index:    0     1     2
        ┌────┬────┬────┐
Value:  │ 10 │ 20 │ 30 │
        └────┴────┴────┘
```

Key properties: - Elements have an order and are accessed by index. -
Indexing is zero-based. - The vector can grow or shrink. - Elements are
contiguous in memory. - Random access by index is `O(1)`. - Appending
with `push_back()` is amortized `O(1)`. - Inserting/erasing in the
middle is `O(n)` because elements may need to shift.

### When should I use a vector?

Use it when you need: - An ordered sequence of values. - Fast indexing
and traversal. - A flexible replacement for a fixed-size array. - A base
structure for sorting, prefix sums, two pointers, sliding windows, and
many DSA problems.

------------------------------------------------------------------------

## 2. Declaration and initialization

``` cpp
vector<int> a;                 // empty vector
vector<int> b(5);              // five zero-initialized ints
vector<int> c(5, 7);           // five elements, each 7
vector<int> d = {1, 2, 3};     // initializer list
vector<int> e(d);              // copy of d
```

  Code                         Meaning                         Initial size
  ---------------------------- ----------------------------- --------------
  `vector<int> v;`             Empty vector                               0
  `vector<int> v(5);`          Five ints, initialized to 0                5
  `vector<int> v(5, 7);`       Five values of 7                           5
  `vector<int> v = {2,4,6};`   Given values                               3

------------------------------------------------------------------------

## 3. Size, capacity, and empty

  -----------------------------------------------------------------------
  Member                              Meaning
  ----------------------------------- -----------------------------------
  `v.size()`                          Number of elements currently stored

  `v.empty()`                         `true` if `size() == 0`

  `v.capacity()`                      Number of elements that can fit in
                                      allocated storage before
                                      reallocation is needed

  `v.reserve(n)`                      Requests capacity of at least `n`;
                                      does not change size

  `v.resize(n)`                       Changes size to `n`; new elements
                                      are value-initialized

  `v.clear()`                         Removes all elements; size becomes
                                      0
  -----------------------------------------------------------------------

Example:

``` cpp
vector<int> v;
v.reserve(10);
cout << v.size();     // 0, not 10
cout << v.capacity(); // at least 10
```

Compare:

``` cpp
v.resize(10); // size becomes 10; ten elements exist
```

**Remember:** `reserve()` changes capacity, not the number of elements.
`resize()` changes the number of elements.

------------------------------------------------------------------------

## 4. Adding and removing elements

  ------------------------------------------------------------------------------
  Operation                   What it does                    Typical complexity
  --------------------------- --------------------- ----------------------------
  `v.push_back(x)`            Adds `x` to the end               Amortized `O(1)`

  `v.emplace_back(args...)`   Constructs an element             Amortized `O(1)`
                              at the end            

  `v.pop_back()`              Removes last element                        `O(1)`

  `v.insert(pos, x)`          Inserts before                   `O(n)` in general
                              iterator `pos`        

  `v.erase(pos)`              Removes element at               `O(n)` in general
                              iterator `pos`        

  `v.erase(first, last)`      Removes range                    `O(n)` in general
                              `[first, last)`       

  `v.clear()`                 Removes all elements             `O(n)` in general
  ------------------------------------------------------------------------------

Example:

``` cpp
vector<int> v = {10, 20, 30};

v.push_back(40);       // {10, 20, 30, 40}
v.pop_back();          // {10, 20, 30}
v.insert(v.begin()+1, 15); // {10, 15, 20, 30}
v.erase(v.begin()+2);  // {10, 15, 30}
```

### Iterator positions

-   `v.begin()` points to the first element.
-   `v.end()` is the **past-the-end** iterator, not the last element.
-   To insert at the beginning: `v.insert(v.begin(), x)`.
-   To insert at the end, normally use `push_back()` or
    `emplace_back()`.
-   `v.begin() + i` points to index `i`, provided that index is valid.

**Never dereference `v.end()`**. For the last element, use `v.back()`
when the vector is not empty.

------------------------------------------------------------------------

## 5. Accessing elements safely

  -----------------------------------------------------------------------
  Expression              Meaning                 Bounds checked?
  ----------------------- ----------------------- -----------------------
  `v[i]`                  Element at index `i`    No

  `v.at(i)`               Element at index `i`    Yes; throws
                                                  `std::out_of_range` if
                                                  invalid

  `v.front()`             First element           No empty check

  `v.back()`              Last element            No empty check
  -----------------------------------------------------------------------

``` cpp
vector<int> v = {10, 20, 30};

cout << v[1];      // 20
cout << v.at(2);   // 30
cout << v.front(); // 10
cout << v.back();  // 30
```

If `i >= v.size()`, using `v[i]` is **undefined behaviour**. `v.at(i)`
performs a bounds check and throws an exception if the index is out of
range.

Also, `front()` and `back()` require a non-empty vector.

------------------------------------------------------------------------

## 6. Looping through a vector

### Index-based loop

``` cpp
for (int i = 0; i < (int)v.size(); i++) {
    cout << v[i] << ' ';
}
```

Useful when the index is needed.

### Range-based loop

``` cpp
for (int x : v) {
    cout << x << ' ';
}
```

`x` is a copy of each element.

``` cpp
for (int& x : v) {
    x *= 2; // modifies original vector
}
```

``` cpp
for (const int& x : v) {
    cout << x << ' '; // read without copying
}
```

  Loop form                  Effect
  -------------------------- ----------------------------------------
  `for (int x : v)`          Copies each element into `x`
  `for (int& x : v)`         Reference; can modify original element
  `for (const int& x : v)`   Read-only reference; avoids copying

### Iterators

``` cpp
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << ' ';
}
```

`*it` accesses the element the iterator points to.

------------------------------------------------------------------------

## 7. Sorting and reversing

``` cpp
sort(v.begin(), v.end());                 // ascending
sort(v.begin(), v.end(), greater<int>()); // descending
reverse(v.begin(), v.end());              // reverses current order
```

-   `sort()` is typically `O(n log n)`.
-   `reverse()` is `O(n)`.
-   `reverse()` does not sort; it simply reverses the existing order.

Other useful functions:

``` cpp
auto mn = *min_element(v.begin(), v.end());
auto mx = *max_element(v.begin(), v.end());

int total = accumulate(v.begin(), v.end(), 0);
int occurrences = count(v.begin(), v.end(), 5);

auto it = find(v.begin(), v.end(), 5);
if (it != v.end()) {
    cout << "Found";
}
```

Notes: - `min_element()` / `max_element()` return iterators; dereference
them to get values. - Do not dereference the result on an empty
vector. - `accumulate(..., 0)` accumulates as `int`; use `0LL` when you
need a `long long` sum.

------------------------------------------------------------------------

## 8. `insert()`, `erase()`, and erase-remove

``` cpp
vector<int> v = {10, 20, 30, 40};

v.insert(v.begin() + 1, 15); // {10, 15, 20, 30, 40}
v.erase(v.begin() + 2);      // removes 20
```

`erase()` takes an iterator, not an index. For index `i`, use
`v.erase(v.begin() + i)` only when `i` is valid.

### Remove all occurrences of a value

The classic erase-remove idiom:

``` cpp
vector<int> v = {1, 2, 2, 3, 2};

v.erase(remove(v.begin(), v.end(), 2), v.end());
// v is now {1, 3}
```

`remove()` does not itself shrink the vector. It moves the retained
elements toward the beginning and returns a new logical end. `erase()`
removes the leftover tail.

### Remove duplicates using sort + unique

``` cpp
vector<int> v = {3, 1, 3, 2, 1};

sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
// v is {1, 2, 3}
```

Important: - `unique()` only removes **consecutive duplicates** from the
logical range. - Sorting first groups equal values together if order
does not matter. - `unique()` alone does not shrink the vector; erase
the tail.

------------------------------------------------------------------------

## 9. Binary search: `binary_search`, `lower_bound`, `upper_bound`

These algorithms require the range to be sorted (under the relevant
ordering).

``` cpp
sort(v.begin(), v.end());

bool exists = binary_search(v.begin(), v.end(), x);

auto lo = lower_bound(v.begin(), v.end(), x);
auto hi = upper_bound(v.begin(), v.end(), x);
```

  Function               Meaning
  ---------------------- ----------------------------------
  `binary_search(...)`   Returns `true` if `x` exists
  `lower_bound(...)`     Iterator to first element `>= x`
  `upper_bound(...)`     Iterator to first element `> x`

If using a returned iterator:

``` cpp
int smallerOrEqualCount = upper_bound(v.begin(), v.end(), x) - v.begin();
```

For a sorted vector, `upper_bound(...) - begin()` gives the number of
elements `<= x`.

For the count of occurrences of `x` in a sorted vector:

``` cpp
int freq = upper_bound(v.begin(), v.end(), x)
         - lower_bound(v.begin(), v.end(), x);
```

Do not use binary-search algorithms on an unsorted vector and expect
correct results.

------------------------------------------------------------------------

## 10. Iterator/reference invalidation

A vector can reallocate when its capacity is insufficient. Reallocation
moves its elements to new storage, invalidating pointers, references,
and iterators to its elements.

  -----------------------------------------------------------------------
  Operation                           Common invalidation rule
  ----------------------------------- -----------------------------------
  `push_back()` / `emplace_back()`    All iterators, pointers, references
  with reallocation                   invalidated

  `push_back()` without reallocation  Existing element
                                      iterators/references remain valid;
                                      old `end()` is invalidated

  `insert()`                          Iterators/references at or after
                                      insertion point are invalidated;
                                      all if reallocation occurs

  `erase()`                           Iterators/references at or after
                                      erased position are invalidated

  `reserve()` that changes capacity   All iterators, pointers, references
                                      invalidated

  `clear()`                           Iterators/references to erased
                                      elements invalidated

  `resize()`                          May invalidate all if reallocation
                                      happens; removing elements
                                      invalidates references to removed
                                      elements and end iterator
  -----------------------------------------------------------------------

**Practical rule:** after an operation that may invalidate an iterator,
do not keep using the old iterator. Recompute it when necessary.

------------------------------------------------------------------------

## 11. `vector<pair<...>>`

Useful for storing pairs, coordinates, intervals, and `(value, index)`.

``` cpp
vector<pair<int, int>> vp;
vp.push_back({2, 5});
vp.emplace_back(3, 7);

cout << vp[0].first;  // 2
cout << vp[0].second; // 5
```

Sorting a vector of pairs by default sorts: 1. First by `.first`. 2. If
equal, by `.second`.

``` cpp
vector<pair<int,int>> vp = {{2,5}, {1,9}, {2,3}};
sort(vp.begin(), vp.end());
// {(1,9), (2,3), (2,5)}
```

------------------------------------------------------------------------

## 12. 2D vectors: `vector<vector<int>>`

A 2D vector is a vector whose elements are themselves vectors.

### Rectangular vector

``` cpp
vector<vector<int>> grid(3, vector<int>(4, 0));
```

Creates 3 rows and 4 columns, all initialized to zero.

``` text
grid
┌───────────────┐
│ row 0: 0 0 0 0│
│ row 1: 0 0 0 0│
│ row 2: 0 0 0 0│
└───────────────┘
```

-   `grid.size()` → number of rows (`3`).
-   `grid[i].size()` → number of elements in row `i` (`4` here).

### Jagged vector

Rows can have different lengths:

``` cpp
vector<vector<int>> v = {
    {1, 2},
    {3, 4, 5},
    {6}
};
```

Here `v.size() == 3`, but row sizes are `2`, `3`, and `1`.

### Safe traversal

``` cpp
for (int i = 0; i < (int)v.size(); ++i) {
    for (int j = 0; j < (int)v[i].size(); ++j) {
        cout << v[i][j] << ' ';
    }
}
```

### Out-of-bounds trap

-   `v[0][2]` is invalid if row `0` has fewer than 3 elements; accessing
    it with `[]` is undefined behaviour.
-   `v.at(0).at(2)` throws `std::out_of_range` if the row/column index
    is invalid.
-   Always check both the outer row and inner column bounds.

------------------------------------------------------------------------

## 13. Passing a vector to a function

### Pass by value: copies the vector

``` cpp
void change(vector<int> v) {
    v[0] = 100;
}
```

Changes are made to the copy, not the caller's original vector.

### Pass by reference: can modify original

``` cpp
void change(vector<int>& v) {
    if (!v.empty()) v[0] = 100;
}
```

### Pass by const reference: read without copying

``` cpp
void print(const vector<int>& v) {
    for (int x : v) cout << x << ' ';
}
```

For large vectors, `const vector<int>&` is usually preferred for
read-only function parameters to avoid copying.

------------------------------------------------------------------------

## 14. `next_permutation`, `partial_sort`, `nth_element`

These are useful STL tools for some DSA problems.

### Next permutation

``` cpp
vector<int> v = {1, 2, 3};
do {
    // use current permutation
} while (next_permutation(v.begin(), v.end()));
```

`next_permutation()` transforms the range into the next
lexicographically greater permutation and returns `false` when no next
permutation exists (resetting to the first permutation). Starting from
sorted order is a common way to enumerate all permutations.

### Partial sort

``` cpp
partial_sort(v.begin(), v.begin() + k, v.end());
```

Sorts the first `k` elements so they are the smallest `k` elements in
sorted order. Ensure `k` is valid.

### Nth element

``` cpp
nth_element(v.begin(), v.begin() + k, v.end());
```

Places the element that would be at index `k` in sorted order into that
position; elements before it are not necessarily sorted, but are no
greater than it (under the default ordering). Ensure `k < v.size()`.

------------------------------------------------------------------------

## 15. Common vector DSA patterns

### Prefix sums

``` cpp
vector<int> a = {2, 4, 1};
vector<long long> pref(a.size() + 1, 0);

for (int i = 0; i < (int)a.size(); ++i) {
    pref[i + 1] = pref[i] + a[i];
}

// sum of inclusive range [l, r]:
long long rangeSum = pref[r + 1] - pref[l];
```

With a prefix array of length `n + 1`, range sum `[l, r]` is
`pref[r+1] - pref[l]`.

Use `long long` if sums might exceed `int`.

### Two pointers

Useful when a problem has a monotonic condition, often on sorted arrays
or positive numbers. Two indices move through the vector instead of
trying all pairs.

### Sliding window

Useful for contiguous subarrays/substrings when adding/removing elements
maintains a condition. The standard sum-based shrinking window is
generally suitable for non-negative numbers; negative numbers can break
its monotonic logic. Prefix sum + hashing can handle negative numbers
for tasks such as counting subarrays with sum `k`.

### Sort + unique

Useful when the goal is to remove duplicate values and order does not
need to be preserved.

### Coordinate compression

Useful when values are huge but only their relative sorted order
matters: 1. Copy values into a vector. 2. Sort. 3. Remove duplicates
with `unique` + `erase`. 4. Replace each value by its index in the
compressed sorted vector (often via `lower_bound`).

### Frequency counting

For small, bounded non-negative values, a frequency vector may be
simpler and faster than a hash map:

``` cpp
vector<int> freq(maxValue + 1, 0);
for (int x : a) freq[x]++;
```

Use `unordered_map` when the key range is large/sparse or keys are not
convenient array indices.

------------------------------------------------------------------------

## 16. Complexity cheat sheet

Let `n = v.size()`.

  Operation                                                   Complexity
  --------------------------------------------- ------------------------
  `v[i]`, `front()`, `back()`                                     `O(1)`
  `size()`, `empty()`                                             `O(1)`
  `push_back()` / `emplace_back()`                      Amortized `O(1)`
  `pop_back()`                                                    `O(1)`
  Traversal                                                       `O(n)`
  `find()` / `count()`                                            `O(n)`
  `sort()`                                                  `O(n log n)`
  `reverse()`                                                     `O(n)`
  `min_element()` / `max_element()`                               `O(n)`
  `accumulate()`                                                  `O(n)`
  `insert()` / `erase()` near middle/front                        `O(n)`
  `binary_search()` on sorted vector              `O(log n)` comparisons
  `lower_bound()` / `upper_bound()` on vector     `O(log n)` comparisons

------------------------------------------------------------------------

## 17. Common mistakes checklist

-   [ ] Forgetting that vector indices start at `0`.
-   [ ] Accessing `v[i]` when `i >= v.size()`.
-   [ ] Calling `front()` or `back()` on an empty vector.
-   [ ] Confusing `size()` with `capacity()`.
-   [ ] Thinking `reserve(n)` creates `n` elements (it does not).
-   [ ] Thinking `resize(n)` only reserves memory (it changes size).
-   [ ] Dereferencing `v.end()`.
-   [ ] Using old iterators after `insert()`, `erase()`, or
    reallocation.
-   [ ] Assuming `erase()` takes an index rather than an iterator.
-   [ ] Thinking `remove()` shrinks the vector by itself.
-   [ ] Using `unique()` without grouping duplicates when full duplicate
    removal is needed.
-   [ ] Calling `lower_bound()` / `binary_search()` on an unsorted
    vector.
-   [ ] Forgetting that `v.size()` is unsigned; mixing it carelessly
    with negative integers can cause bugs.
-   [ ] Passing a large vector by value unintentionally when a reference
    is intended.
-   [ ] Assuming every sliding-window sum technique works with negative
    numbers.
-   [ ] Forgetting that `grid.size()` counts rows, while
    `grid[i].size()` counts elements in row `i`.

------------------------------------------------------------------------

## 18. Final quick revision

1.  Vector = dynamic-size, contiguous sequence.
2.  Index access is `O(1)`; `push_back()` is amortized `O(1)`.
3.  `size()` counts elements; `capacity()` counts available storage.
4.  `reserve()` changes capacity; `resize()` changes size.
5.  `v[i]` is unchecked; `v.at(i)` checks bounds.
6.  `begin()` points to first element; `end()` is past-the-end.
7.  Middle insert/erase can shift elements and cost `O(n)`.
8.  `sort()` + `unique()` + `erase()` removes duplicates.
9.  Binary search algorithms require sorted data.
10. `vector<vector<int>>`: outer size = rows; each inner size = that
    row's length.
11. Pass by `const&` to read a large vector without copying.
12. Watch iterator invalidation after insertions, erasures, and
    reallocation.
13. Common patterns: prefix sums, two pointers, sliding windows,
    frequency counts, coordinate compression.
14. Negative numbers can break ordinary sum-based sliding-window logic;
    prefix sum + hashing is often useful.

**Recommended revision method:** Read one section, predict the output of
your matching `.cpp` example, run it, and explain why each line behaves
that way.
