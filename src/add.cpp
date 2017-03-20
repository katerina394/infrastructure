#include <stack>
int add(int x, int y) {
  return x + y;
}
int* arrays(int* a, int n) {
    std::stack <int> s;
    s.push(1);
    int temp, tmp = 1;
	int *res = reinterpret_cast<int*>(malloc(sizeof(int)*n));
    for (int i = 0; i < n - 1; ++i) {
        temp = s.top();
        s.push(temp*a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        res[i] = s.top()*tmp;
        s.pop();
        tmp *= a[i];
    }
    return res;
}
