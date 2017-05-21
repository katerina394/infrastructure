#include <vector>
#include <utility>
std::vector<int> Ksets(std::vector<std::pair<int, int>> a, int n) {
    std::vector<int> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = i;
    for (int i = 0; i < n; ++i)
        if (res[i] == i) {
            for (int j = i+1; j < n; ++j)
                if (res[j] == j) {
                    bool f = 1;
                    for (int k = 0; k < a.size(); ++k)
                        if ( ( (res[a[k].first] == i) && (a[k].second == j) )
                            || ( (a[k].first == j) && (res[a[k].second] == i)))
                            f = 0;
                    if (f == 1) res[j] = i;
                }
        }
    return res;
}
