#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tcstring.h"

#define BUFLEN 1024

char g_buf[BUFLEN];

TCString*
trim_tag(const char *str)
{
    int i, len, cnt;
    char ch;
    TCString *obj;

    len = tc_string_length(str);
    obj = tc_string_alloc(len);
    cnt = 0;
    for (i = 0; i < len; i++) {
        ch = str[i];
        if (ch == '<' || ch == '>' || ch == '/') {
            continue;
        }
        if (ch == ' ') {
            break;
        }
        obj->data[cnt] = ch;
        cnt++;
    }
    obj->len = cnt;
}

int
is_end_tag(const char *str)
{
    int i, len, end;
    char ch;

    len = tc_string_length(str);
    end = 0;
    for (i = 0; i < len; i++) {
        ch = str[i];
        if (ch == '\"' || ch == '\'') {
            break;
        }
        if (ch == '/') {
            end = 1;
            break;
        }
    }
    return end;
}


int main(int argc, char *argv[])
{
    FILE *fp;
    TCString *tag, *tag2;
    char ch;
    int offset, found;
    
    tag = tc_string_new(argv[1]);

    if (tag->len == 0) {
        return 0;
    }

    fp = stdin;

    while ((ch = fgetc(fp)) > 0) {
        if (found) {
            fputc(ch, stdout);
        }

        if (ch == '<') {
            offset = 0;
            memset(g_buf, 0, BUFLEN);
        } else if (ch == '>') {
            g_buf[offset] = ch;

            tag2 = trim_tag(g_buf);

            if (tc_string_equal(tag, tag2->data) == 0) {
                if (is_end_tag(g_buf)) {
                    found = 0;
                } else {
                    fputs(g_buf, stdout);
                    found = 1;
                }
            }
            continue;
        }

        g_buf[offset] = ch;
        offset++;
    }

    fclose(fp);

    return 0;
}
