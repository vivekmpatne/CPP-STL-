# C++17 Hashing Notes --- `unordered_map`

> **Purpose:** Quick DSA/OA revision notes. Use these notes to remember
> *what*, *why*, and *when*. If a code example feels unclear, open the
> matching `.cpp` file in your repo and dry-run it.
>
> **Header:** `#include <bits/stdc++.h>` (common in competitive
> programming; not standard C++)\
> **Namespace:** `using namespace std;` (optional)

------------------------------------------------------------------------

## 1. What is hashing?

Hashing maps a key to a hash value, which is used to place/find the key
in a bucket.

``` text
key  ──hash function──> hash value ──> bucket
                                      │
                                      └── stores/locates an element
```

In C++, `unordered_map<Key, Value>` stores **key-value pairs** and uses
hashing for lookup.

``` cpp
unordered_map<int, int> mp;
mp[5] = 50;  // key 5, mapped value 50
```

-   **Key:** `5`
-   **Mapped value:** `50`
-   Keys are unique.
-   Iteration order is **not guaranteed**; do not rely on a particular
    order.
-   Average lookup/insert/erase is usually **O(1)**; worst case can be
    **O(n)**.

### `vector` vs `unordered_map`

  Need                                        Common choice
  ------------------------------------------- -----------------
  Store values in sequence, access by index   `vector`
  Count occurrences / look up by key          `unordered_map`
  Need keys sorted and ordered traversal      `map`
  Need unique values only                     `unordered_set`

------------------------------------------------------------------------

## 2. Basic declaration and initialization

``` cpp
unordered_map<int, int> mp;
mp[5] = 50;

unordered_map<string, int> age;
age["Asha"] = 20;
```

Conceptual representation:

``` text
mp
┌─────┬───────┐
│ key │ value │
├─────┼───────┤
│  5  │  50   │
└─────┴───────┘
```

For an `unordered_map`, a key can appear only once. A mapped value can
be updated.

------------------------------------------------------------------------

## 3. Most important operations --- quick table

Assume `unordered_map<int, int> mp;`.

  ----------------------------------------------------------------------------------------------------
  Operation                   What it does         If key exists? If key is missing?    Inserts?
  --------------------------- -------------------- -------------- --------------------- --------------
  `mp[key]`                   Access mapped value  Returns value; Inserts key with      **Yes, if
                                                   can be         value-initialized     missing**
                                                   assigned       mapped value (`0` for 
                                                                  `int`)                

  `mp.at(key)`                Checked access       Returns value  Throws                No
                                                                  `std::out_of_range`   

  `mp.find(key)`              Finds element        Iterator to    Returns `mp.end()`    No
                                                   element                              

  `mp.count(key)`             Counts matching keys `1` for        `0`                   No
                                                   unique-key map                       

  `mp.contains(key)`          Tests existence      `true`         `false`               No
                              (C++20)                                                   

  `mp.insert({key, value})`   Inserts if key is    Does not       Inserts new pair      Only if
                              absent               overwrite                            missing

  `mp.emplace(key, value)`    Constructs/inserts   Does not       Inserts new pair      Only if
                              element if absent    overwrite                            missing

  `mp.erase(key)`             Erases by key        Removes it     Removes nothing       No

  `mp.erase(it)`              Erases element at    Removes        N/A: iterator must be No
                              iterator             pointed        valid                 
                                                   element                              

  `mp.size()`                 Number of unique     ---            ---                   No
                              keys                                                      

  `mp.empty()`                Checks whether map   ---            ---                   No
                              is empty                                                  

  `mp.clear()`                Removes all elements ---            ---                   No
  ----------------------------------------------------------------------------------------------------

**C++17 note:** `contains()` is C++20, not C++17. For C++17, use
`find()` or `count()`.

### The most important trap: `mp[key]` inserts

``` cpp
unordered_map<int, int> mp;
cout << mp[7] << '\n';  // prints 0; inserts {7, 0}
cout << mp.size() << '\n'; // 1
```

For `int`, the inserted mapped value is `0`. For other types, the mapped
value is value-initialized (for example, an empty `string`).

By contrast:

``` cpp
auto it = mp.find(99);  // no insertion
if (it == mp.end()) {
    cout << "Not found";
}
```

Use `find()` when you only want to check whether a key exists.

------------------------------------------------------------------------

## 4. `find()`, `count()`, and `at()` --- exact behaviour

``` cpp
unordered_map<int, int> mp;
mp[2] = 20;

auto it = mp.find(2);
if (it != mp.end()) {
    cout << it->first << ' ' << it->second; // 2 20
}
```

-   `find(key)` returns an iterator to the element or `end()` if absent.
-   `end()` is a **past-the-end marker**, not the last element. Never
    dereference it.
-   `count(key)` returns `0` or `1` for `unordered_map`, because keys
    are unique.
-   `at(key)` does not insert. It throws `std::out_of_range` when the
    key is absent.

  Expression      Key exists            Key absent
  --------------- --------------------- -----------------------------------------
  `mp.find(k)`    Iterator to element   `mp.end()`
  `mp.count(k)`   `1`                   `0`
  `mp.at(k)`      Existing value        Throws exception
  `mp[k]`         Existing value        Inserts default/value-initialized value

------------------------------------------------------------------------

## 5. `insert()` vs `emplace()`

Both preserve the existing value when the key is already present.

``` cpp
unordered_map<int, int> mp;

auto a = mp.emplace(1, 10); // inserted
auto b = mp.emplace(1, 20); // duplicate key: not inserted
```

Both return `pair<iterator, bool>`.

  -----------------------------------------------------------------------
  Return member                       Meaning
  ----------------------------------- -----------------------------------
  `result.first`                      Iterator to the inserted element,
                                      or to the existing element if
                                      insertion failed

  `result.second`                     `true` if insertion happened;
                                      `false` if key already existed
  -----------------------------------------------------------------------

``` cpp
cout << a.second << '\n';         // 1 (true)
cout << b.second << '\n';         // 0 (false)
cout << b.first->second << '\n';  // 10, not 20
cout << mp.size() << '\n';        // 1
```

Iterator expressions:

  -----------------------------------------------------------------------
  Expression                          Meaning
  ----------------------------------- -----------------------------------
  `it->first`                         Key

  `it->second`                        Mapped value

  `result.first->first`               Key of element referenced by
                                      returned iterator

  `result.first->second`              Value of that element
  -----------------------------------------------------------------------

**Remember:** `result.second` is a `bool`; it is **not** the map value.
The map value is accessed through `result.first->second`.

`insert()` vs `emplace()`: - `insert()` inserts a value/pair you
provide. - `emplace()` constructs the element in place from its
arguments. - For everyday OA code, the key lesson is that neither
overwrites an existing key.

------------------------------------------------------------------------

## 6. Updating values and iterator behaviour

``` cpp
unordered_map<int, int> mp;
mp[1] = 10;

auto it = mp.find(1);
mp[1] = 100;

cout << it->second; // 100
```

The iterator points to the actual map element; it is not a copy of its
value. Updating the mapped value does not invalidate that iterator.

But:

``` cpp
auto it = mp.find(1);
mp.erase(1);
// Do not use it now: it was invalidated by erasing its element.
```

Dereferencing or otherwise using an invalid iterator is **undefined
behaviour (UB)**. It may appear to print an old value, print something
else, or crash; none is guaranteed.

------------------------------------------------------------------------

## 7. Erasing safely

### Erase by key

``` cpp
size_t removed = mp.erase(5);
```

For `unordered_map`, this returns `1` if the key was erased and `0` if
it was absent.

### Erase by iterator

``` cpp
auto it = mp.find(2);
if (it != mp.end()) {
    it = mp.erase(it);
}
```

`erase(iterator)` returns an iterator to the next element in the
container's iteration sequence, or `end()` if there is no next element.
Since `unordered_map` order is unspecified, **do not assume which key
comes next**.

### Safe erase loop

``` cpp
for (auto it = mp.begin(); it != mp.end(); ) {
    if (/* condition on *it */) {
        it = mp.erase(it); // use returned iterator
    } else {
        ++it;
    }
}
```

Do not do this:

``` cpp
mp.erase(it);
cout << it->second; // UB: it is invalid
```

------------------------------------------------------------------------

## 8. Iterating through a map

``` cpp
for (const auto& p : mp) {
    cout << p.first << " -> " << p.second << '\n';
}
```

-   `auto p` makes a copy of each pair.
-   `auto& p` refers to the actual pair and can allow changes.
-   `const auto& p` avoids copying and prevents modification through
    `p`; good for reading.
-   Iteration order is unspecified, so output order can vary.

------------------------------------------------------------------------

## 9. Size, buckets, load factor, `reserve()` and `rehash()`

Hash-based containers organize elements into buckets.

  -----------------------------------------------------------------------
  Member                              Meaning
  ----------------------------------- -----------------------------------
  `mp.size()`                         Number of stored elements/keys

  `mp.bucket_count()`                 Number of buckets currently
                                      allocated

  `mp.load_factor()`                  Approx. `size() / bucket_count()`

  `mp.max_load_factor()`              Load-factor threshold used to
                                      decide when to rehash

  `mp.reserve(n)`                     Prepares capacity for at least `n`
                                      elements, based on max load factor

  `mp.rehash(n)`                      Requests a bucket count of at least
                                      `n`, subject to container
                                      requirements
  -----------------------------------------------------------------------

``` cpp
mp.max_load_factor(0.7);
mp.reserve(1000); // reserve capacity for about 1000 elements
```

-   `reserve()` does **not** insert elements; `size()` stays unchanged.
-   `bucket_count()` may be larger than the number requested.
-   `rehash()` may change bucket layout; do not assume an exact bucket
    count.
-   The default max load factor is commonly `1.0`, but do not rely on a
    specific implementation value when it has not been set.

### Iterator invalidation cheat sheet

  -----------------------------------------------------------------------
  Operation                           Iterator effect
  ----------------------------------- -----------------------------------
  Change existing mapped value,       Iterator remains valid
  e.g. `mp[k] = newValue`             

  `erase(key)` / `erase(it)`          Only iterator(s) to erased element
                                      become invalid

  `rehash()`                          **All iterators are invalidated**

  Insert/emplace without rehash       Existing iterators remain valid

  Insert/emplace that causes rehash   All iterators are invalidated
  -----------------------------------------------------------------------

After rehash, get a **fresh iterator**:

``` cpp
mp.rehash(100);
auto it = mp.find(1); // fresh iterator
```

Important nuance: rehash invalidates iterators, but pointers/references
to existing elements remain valid. Do not use an old iterator just
because it seems to work in a test run.

------------------------------------------------------------------------

## 10. Hash collisions

A collision occurs when different keys produce the same hash value or
map to the same bucket.

``` text
key A ──> hash/bucket 4 ──┐
                          ├── same bucket (collision)
key B ──> hash/bucket 4 ──┘
```

**Same hash does not mean same key.** The container also checks key
equality to distinguish keys.

For example, `{2,3}` and `{4,5}` can have the same hash but still be two
distinct keys if pair equality says they are different.

-   Good hash distribution usually supports average `O(1)` operations.
-   Many collisions can degrade performance; worst-case operations can
    be `O(n)`.

------------------------------------------------------------------------

## 11. Custom hash for `pair<int,int>` (C++17)

In C++17, `std::hash<pair<int,int>>` is not provided by the standard
library. Supply a custom hasher:

``` cpp
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first)
             ^ (hash<int>{}(p.second) << 1);
    }
};

unordered_map<pair<int, int>, int, PairHash> mp;

mp[{2, 3}] = 10;
mp[{3, 2}] = 20;

cout << mp.size(); // 2
```

-   `p.first` and `p.second` are the pair's two values.
-   `const pair<int,int>&` passes by reference without copying and
    prevents modification through `p`.
-   `<< 1` means left shift by one bit.
-   `^` is bitwise XOR.
-   `{2,3}` and `{3,2}` are different keys with normal pair equality.
-   Hash collisions are allowed; equality still distinguishes keys.
-   This hash combiner is a simple example, not a guarantee of
    collision-free hashing.

------------------------------------------------------------------------

## 12. Pattern 1 --- Frequency counting

``` cpp
vector<int> v = {2, 3, 2, 5, 3, 2};
unordered_map<int, int> freq;

for (int x : v) {
    freq[x]++;
}
```

Result conceptually:

``` text
2 -> 3
3 -> 2
5 -> 1
```

Why it works: 1. If `x` is missing, `freq[x]` inserts it with value `0`.
2. `++` increments its count. 3. `freq.size()` is the number of distinct
keys, not the number of array elements.

**Trap:** Reading `freq[missingKey]` also inserts that key. If you want
to check without inserting, use `find()`.

Common uses: - Count duplicates/frequencies. - Find first/most frequent
elements (may need extra logic). - Anagram checks. - Compare frequency
distributions.

------------------------------------------------------------------------

## 13. Pattern 2 --- Two Sum / complement lookup

Example: find whether two different positions can add up to `target`.

``` cpp
vector<int> v = {2, 7, 11, 15};
int target = 9;
unordered_map<int, int> seen;

for (int x : v) {
    int need = target - x;

    if (seen.find(need) != seen.end()) {
        cout << "Found";
        break;
    }

    seen[x] = 1;
}
```

Dry run: - `x = 2`: need `7`; not seen, so record `2`. - `x = 7`: need
`2`; already seen, so found.

**Order matters:** check the complement before recording the current
value when you want the matching value to come from an earlier position.
This also handles duplicates such as `{3,3}` with target `6`.

If the task asks for indices, store `value -> index` instead of
`value -> 1`.

------------------------------------------------------------------------

## 14. Pattern 3 --- Prefix sum + hashing: Subarray Sum Equals K

Goal: count contiguous subarrays whose sum equals `k`. This works with
**negative numbers too**, unlike many sliding-window approaches.

``` cpp
vector<int> nums = {1, 2, 3};
int k = 3;

unordered_map<int, int> freq;
freq[0] = 1; // one empty prefix before the array begins

int prefixSum = 0;
int count = 0;

for (int x : nums) {
    prefixSum += x;
    int need = prefixSum - k;

    auto it = freq.find(need);
    if (it != freq.end()) {
        count += it->second;
    }

    freq[prefixSum]++;
}

cout << count; // 2
```

### Why the formula works

Let: - `currentPrefix` = sum from the beginning through the current
position. - `previousPrefix` = a prefix sum before the subarray starts.

Then:

``` text
subarray sum = currentPrefix - previousPrefix
k            = currentPrefix - previousPrefix
previousPrefix = currentPrefix - k
```

So we look up `need = prefixSum - k`.

### Why `freq[0] = 1`?

It represents the empty prefix sum before any array element. It allows a
subarray starting at index `0` to be counted.

For example, with `nums = {3}`, `k = 3`: - `prefixSum = 3`,
`need = 0`. - `freq[0]` is `1`, so `[3]` gets counted.

### Why `count += freq[need]` instead of `count++`?

The same prefix sum may have occurred multiple times. Each previous
occurrence can define a different valid subarray ending at the current
position, so add the entire frequency.

### Verified example with negative numbers

``` cpp
nums = {1, -1, 1};
k = 1;
```

The valid subarrays are: 1. `[1]` at index 0 2. `[1, -1, 1]` 3. `[1]` at
index 2

Answer: **3**.

Prefix-sum progression: - After first `1`: sum `1`, need `0`, add
`freq[0] = 1` → count `1`. - After `-1`: sum `0`, need `-1`, no match →
count `1`. - After last `1`: sum `1`, need `0`, now `freq[0] = 2` → add
`2`, count `3`.

**Update the frequency after counting** the current prefix. This ensures
the current prefix is treated as a *previous* prefix only for future
elements.

Typical complexity: average `O(n)` time and `O(n)` extra space.

------------------------------------------------------------------------

## 15. Complexity cheat sheet

  Operation                                     Average   Worst case
  -------------------------- -------------------------- ------------
  `find()`                                       `O(1)`       `O(n)`
  `count()`                                      `O(1)`       `O(n)`
  `insert()` / `emplace()`     `O(1)` amortized/average       `O(n)`
  `erase(key)`                           `O(1)` average       `O(n)`
  `operator[]`                           `O(1)` average       `O(n)`
  Full traversal                                 `O(n)`       `O(n)`

Worst-case costs can happen when many keys collide. A single insertion
that triggers rehash can take linear time.

------------------------------------------------------------------------

## 16. Common mistakes checklist

-   [ ] Assuming `unordered_map` iteration order is sorted or stable.
-   [ ] Forgetting that `mp[key]` inserts a missing key.
-   [ ] Thinking `find()` inserts a missing key (it does not).
-   [ ] Thinking `emplace()` overwrites an existing value (it does not).
-   [ ] Confusing `result.second` (`bool`) with `result.first->second`
    (mapped value).
-   [ ] Dereferencing `mp.end()`.
-   [ ] Using an iterator after erasing its element.
-   [ ] Using an iterator after `rehash()`.
-   [ ] Assuming same hash means same key.
-   [ ] Forgetting a custom hasher for `pair<int,int>` in C++17.
-   [ ] Forgetting `freq[0] = 1` in prefix-sum counting.
-   [ ] Using `count++` when multiple previous prefix sums may match;
    use `count += freq[need]`.
-   [ ] Updating prefix-sum frequency before checking `need`, which can
    create self-matching errors for some formulations.

------------------------------------------------------------------------

## 17. Final quick revision

1.  **Check without insertion:** `find()` / `count()`.
2.  **Access and insert if missing:** `mp[key]`.
3.  **Checked access, no insertion:** `at()`.
4.  **Insert only if key is absent:** `insert()` / `emplace()`.
5.  **`result.second`:** insertion success boolean.
6.  **`result.first->second`:** mapped value.
7.  **`erase(it)`:** use the returned iterator; don't use the erased
    iterator.
8.  **`rehash()`:** reacquire iterators afterwards.
9.  **Frequency:** `freq[x]++`.
10. **Two Sum:** look up `target - x`.
11. **Subarray sum equals K:** `need = prefixSum - k`, then
    `count += freq[need]`.
12. **Prefix sum initialization:** `freq[0] = 1`.
13. **Collisions:** same hash is allowed for different keys.
14. **Complexity:** average `O(1)` for basic map operations, worst case
    `O(n)`.

**Recommended revision method:** Read one section, predict the output of
your corresponding `.cpp` file, run it, then explain why each line
behaves that way.
