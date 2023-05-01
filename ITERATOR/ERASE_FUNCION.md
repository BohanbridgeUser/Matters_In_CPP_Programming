# This is a problem I encounted when I using `erase` included in `<vector>`
Let's codes at first.
```
#include <iostream>
#include <vector>
int main()
{
    using namespace std;
    vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i);
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        if (*iter == 5) iter = v.erase(iter);
        else {
            std::cout << *iter << std::endl;
        }
    }
    return 0;
}
```
When I compiled this code, compiler didn't report any error.\
But when I ran the program, the result didn't meet my expectations.\
So, what's wrong with it?\
We need to look at the SC of `erase()` in `<vector>`.\
\
There are two simple template of erase, they can be used to explain the reason:\
```
iterator erase( iterator pos );
iterator erase( iterator first, iterator last );    
```

Return Value:\
Iterator following the last removed element.
1. If `pos` refers to the last element, then the end() iterator is returned.\
2. If `last == end()` prior to removal, then the updated end() iterator is returned.
If [`first`, `last`) is an empty range, then `last` is returned.

It is not difficult to figure out that `erase()` returned the next iterator of sequence.\
Therefore, when we use `erase()`, we should be careful about the iterator.\
In case it leads to the unexpected result.
