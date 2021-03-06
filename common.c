#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int put(const char *v) {
    printf("%s\n", v);
    fflush(stdout);
    return 0;
}

char *get() {
    ssize_t len;
    char *buf = calloc(MAX_REPLY_LEN, 1);
    if (buf == NULL)
        return NULL;

    len = read(0, buf, MAX_REPLY_LEN - 1);
    if (len <= 0) {
        free(buf);
        return NULL;
    }

    /* clear any newlines */
    buf[len--] = '\0';
    while (buf[len] == '\n')
        buf[len--] = '\0';
    return buf;
}
