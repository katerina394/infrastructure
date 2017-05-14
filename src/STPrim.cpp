#include <vector>
#include <utility>
#include "FiveHeap.h"
#define pair std::pair
#define vector std::vector
vector<vector<pair<int, int>>> STPrim(vector<vector<pair<int, int>>> gr) {
    vector<vector<pair<int, int>>> ST(gr.size());
    FiveHeap<pair<int, pair<int, int>>> h;
    vector<bool> f(gr.size(), 0);
    int mST = 0;
    for (int i = 0; i < static_cast<int>(gr[0].size()); ++i)
        h.Insert(pair<int, pair<int, int>>(gr[0][i].second,
        pair<int, int>(0, gr[0][i].first)));
    f[0] = 1;
    while (!h.empty()) {
        pair<int, pair<int, int>> tmp = h.Min();
        h.DeleteMin();
        if (f[tmp.second.second] == 0) {
            mST++;
            ST[tmp.second.first].push_back(pair<int, int>(tmp.second.second,
            tmp.first));
            ST[tmp.second.second].push_back(pair<int, int>(tmp.second.first,
            tmp.first));
            for (int i = 0; i < static_cast<int>(gr[tmp.second.second].size());
            ++i)
                h.Insert(pair<int, pair<int, int>>(
                gr[tmp.second.second][i].second, pair<int, int>(
                tmp.second.second, gr[tmp.second.second][i].first)));
            f[tmp.second.second] = 1;
        }
    }
    if (mST < static_cast<int>(gr.size())-1)
        throw std::logic_error("graph is disconnected");
    return ST;
}
