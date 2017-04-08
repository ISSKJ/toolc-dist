#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("%s [filename]\n", argv[0]);
        return 1;
    }

    FILE *fp;
    int ch, isCommentTag, isDoubleSlash;

    isCommentTag = isDoubleSlash = 0;

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror(argv[0]);
        return 1;
    }

    while ((ch = fgetc(fp)) > 0) {
        if (ch == '\\') {
            fputc(ch, stdout);
            ch = fgetc(fp);
            fputc(ch, stdout);
            continue;
        }
        if (isCommentTag) {
            if (isDoubleSlash) {
                if (ch == '\n') {
                    isCommentTag = 0;
                    isDoubleSlash = 0;
                }
            } else {
                if (ch == '*') {
                    ch = fgetc(fp);
                    if (ch == '/') {
                        isCommentTag = 0;
                        isDoubleSlash = 0;
                    }
                }
            }
            continue;
        }

        if (ch == '/') {
            ch = fgetc(fp);
            if (ch == '*') {
                isCommentTag = 1;
                isDoubleSlash = 0;
                continue;
            } else if (ch == '/') {
                isCommentTag = 1;
                isDoubleSlash = 1;
                continue;
            }
        }
        fputc(ch, stdout);
    }
    fclose(fp);

    return 0;
}
