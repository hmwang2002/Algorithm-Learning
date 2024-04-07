#ifndef FREAD_H
#define FREAD_H
#include <iostream>

namespace Fread
{
    const int L = 1 << 15;
    char buffer[L], *S, *T;
    inline char Getchar()
    {
        if (S == T)
        {
            T = (S = buffer) + fread(buffer, 1, L, stdin);
            if (S == T)
                return EOF;
        }
        return *S++;
    }
    template <class T>
    inline void read(T &X)
    {
        char ch;
        T op = 1;
        for (ch = Getchar(); ch > '9' || ch < '0'; ch = Getchar())
            if (ch == '-')
                op = -1;
        for (X = 0; ch >= '0' && ch <= '9'; ch = Getchar())
            X = (X << 1) + (X << 3) + ch - '0';
        X *= op;
    }
}

#endif
