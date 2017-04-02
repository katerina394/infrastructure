#include "ways.h"
#include "math.h"
#include "stdlib.h"
int add(int x, int y) {
  return x + y;
}
char* ways(CNode m) {
    int i = 1;
    int tmpx = 0, tmpy = 0;
    char * res = 0;
    while (tmpx != m.x) {
        tmpx += i;
        res = reinterpret_cast<char*>(realloc(res, abs(i)*sizeof(char)));
        if (i > 0) {
            res[abs(i) - 1] = 'E';
            i = -(i + 1);
        } else {
            res[abs(i) - 1] = 'W';
            i = -(i - 1);
        }
    }
    i = abs(i);
    if (m.y > 0)
        i = -i;
    while (tmpy != m.y) {
        tmpy += i;
        res = reinterpret_cast<char*>(realloc(res, abs(i)*sizeof(char)));
        if (i > 0) {
            res[abs(i) - 1] = 'N';
            i = -(i + 1);
        } else {
            res[abs(i) - 1] = 'S';
            i = -(i - 1);
        }
    }
    res = reinterpret_cast<char*>(realloc(res, abs(i)*sizeof(char)));
    res[abs(i) - 1] = '\0';
    return res;
}
