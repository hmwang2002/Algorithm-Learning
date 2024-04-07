#ifndef FWRITE_H
#define FWRITE_H
#include <iostream>

namespace Fwrite
{
    const int L = 1 << 15;
    char buf[L], *pp = buf;
    void Putchar(const char c)
    {
        if (pp - buf == L)
            fwrite(buf, 1, L, stdout), pp = buf;
        *pp++ = c;
    }
    template <typename T>
    void print(T x)
    {
        if (x < 0)
        {
            Putchar('-');
            x = -x;
        }
        if (x > 9)
            print(x / 10);
        Putchar(x % 10 + '0');
    }
    void fsh()
    {
        fwrite(buf, 1, pp - buf, stdout);
        pp = buf;
    }
    template <typename T>
    inline void write(T x, char ch = 0)
    {
        print(x);
        if (ch != 0)
            Putchar(ch);
        fsh();
    }
}

#endif