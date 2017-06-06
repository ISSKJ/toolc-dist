#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char*
read_line(FILE *fp)
{
    int ch, len, eof;
    char *data = (char*)malloc(1);

    len = 0;
    eof = 1;
    while ((ch = fgetc(fp)) > 0) {
        eof = 0;
        if (ch == '\n') {
            break;
        }
        len++;
        data = (char*)realloc(data, len);
        data[len-1] = ch;
    }

    if (eof) {
        free(data);
        return NULL;
    }
    len++;
    data = (char*)realloc(data, len);
    data[len-1] = '\0';
    return data;
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("\
%s [filename]\n\
Markdown like document generator.\n\
keywords:\n\
  @function, @class, @method, @param, @throws, @return, @property\n\
", argv[0]);
        return 1;
    }

    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror(argv[0]);
        return 1;
    }

    char *data, *found, *out;
    int isComment;

    isComment = 0;
    while ((data = read_line(fp)) != NULL) {
        if (strstr(data, "/**") != NULL) {
            isComment = 1;
            continue;
        }
        if (strstr(data, "*/") != NULL) {
            isComment = 0;
            printf("\n");
            continue;
        }
        if (isComment) {
            found = strstr(data, "*");
            if (found) {
                out = found + 2;
            } else {
                out = data;
            }

            found = strstr(data, "@function");
            if (found) {
                out = found;
                printf("## %s\n", out);
                continue;
            }

            found = strstr(data, "@class");
            if (found) {
                out = found;
                printf("# %s\n", out);
                continue;
            }

            found = strstr(data, "@method");
            if (found) {
                out = found;
                printf("## %s\n", out);
                continue;
            }

            found = strstr(data, "@param");
            if (found) {
                out = found;
                printf("* %s\n", out);
                continue;
            }

            found = strstr(data, "@return");
            if (found) {
                out = found;
                printf("* %s\n", out);
                continue;
            }

            found = strstr(data, "@throws");
            if (found) {
                out = found;
                printf("* %s\n", out);
                continue;
            }

            found = strstr(data, "@property");
            if (found) {
                out = found;
                printf("## %s\n", out);
                continue;
            }

            printf("%s\n", out);
        }
        if (data) {
            free(data);
        }
    }

    fclose(fp);

    return 0;
}
