#ifndef LINUXCOMPAT_H
#define LINUXCOMPAT_H
#pragma once

#include <strings.h>

#define APIENTRY
#define stricmp strcasecmp
#define vsprintf_s vsprintf
#define sprintf_s snprintf
typedef int errno_t;

inline void OutputDebugStringA(char buffer[2048]) {
        printf("%s", buffer);
}

inline errno_t fopen_s(FILE **f, const char *name, const char *mode) {
    *f = fopen(name, mode);
    return f ? 0 : errno;
}

#endif
