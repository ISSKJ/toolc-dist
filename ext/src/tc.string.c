#include "tc.string.h"

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int
tc_string_length(const char *raw)
{
    if (raw) {
        return strlen(raw);
    } else {
        return 0;
    }
}


TCString*
tc_string_new(const char *orig)
{
    TCString *obj;
    if (orig) {
        obj = tc_string_alloc(strlen(orig));
        tc_string_copy(obj, orig);
    } else {
        obj = tc_string_alloc(0);
    }
    return obj;
}

TCString*
tc_string_alloc(int len)
{
    TCString *obj;

    obj = (TCString*)malloc(sizeof(TCString));
    obj->len = len;
    obj->data = (char*)malloc(len+1);
    memset(obj->data, 0, obj->len);
    return obj;
}


void
tc_string_free(TCString *obj)
{
    if (obj) {
        if (obj->data) {
            free(obj->data);
        }
        free(obj);
    }
}

void
tc_string_copy(TCString *dst, const char *src)
{
    if (src && dst && dst->len > 0) {
        memcpy(dst->data, src, strlen(src)+1);
    }
}

int
tc_string_equal(TCString *str1, const char *str2)
{
    if (str1 && str2) {
        return strcmp(str1->data, str2);
    }
    return -1;
}


char*
read_line(FILE *fp)
{
    int ch, len, eof;
    char *data = (char*)malloc(sizeof(char));
    if (!data) {
        perror("read_line in tc.string");
        exit(1);
    }

    len = 0;
    eof = 1;
    while ((ch = fgetc(fp)) > 0) {
        eof = 0;
        if (ch == '\n') {
            break;
        }
        len++;
        data = (char*)realloc(data, len);
        if (!data) {
            perror("read_line in tc.string");
            exit(1);
        }
        data[len-1] = ch;
    }

    if (eof) {
        free(data);
        return NULL;
    }
    len++;
    data = (char*)realloc(data, len);
    if (!data) {
        perror("read_line in tc.string");
        exit(1);
    }

    data[len-1] = '\0';
    return data;
}

