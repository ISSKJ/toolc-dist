#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "tc.string.h"

int
show_usage(const char *program)
{
    printf("\
%s [filename]\n\
Trim space, tab, and new line.\n\
Input file shouldn't contain any comment.\n\
", program);
    return 1;
}

int
tc_trimmable(int ch)
{
    return ch == ' ' || ch == '\t' || ch == '\n';
}

const char* const KEYWORDS[] = {
    "break",
    "case",
    "catch",
    "const",
    "continue",
    "debugger",
    "default",
    "delete",
    "do",
    "else",
    "finally",
    "for",
    "function",
    "if",
    "in",
    "instanceof",
    "new",
    "return",
    "switch",
    "throw",
    "try",
    "typeof",
    "var",
    "void",
    "while",
    "with",
    "abstract",
    "boolean",
    "byte",
    "char",
    "class",
    "double",
    "enum",
    "export",
    "extends",
    "final",
    "float",
    "goto",
    "implements",
    "import",
    "int",
    "interface",
    "long",
    "native",
    "package",
    "private",
    "protected",
    "public",
    "short",
    "static",
    "super",
    "synchronized",
    "throws",
    "transient",
    "volatile",
    "return",
    "new",
    "delete",
    "throw",
    "else",
    "case",
    "false",
    "null",
    "true",
    "undefined",
    "in",
    "instanceof",
    "typeof",
    "new",
    "void",
    "delete"
};

int
tc_keyword(const char *word)
{
    int i;
    int len = sizeof(KEYWORDS) / sizeof(*KEYWORDS);

    for (i = 0; i < len; i++) {
        const char *keyword = KEYWORDS[i];
        if (strcmp(word, keyword) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        return show_usage(argv[0]);
    }

    FILE *fp, *tmp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror(argv[0]);
        return 1;
    }

    tmp = fopen("tc.trim_space.tmp", "w");
    if (tmp == NULL) {
        perror(argv[0]);
        return 1;
    }

    int ch, string;

    string = 0;
    while ((ch = fgetc(fp)) > 0) {
        if (ch == '\\') {
            fputc(ch, tmp);
            continue;
        }

        if (ch == '"') {
            string = !string;
            fputc(ch, tmp);
            continue;
        }

        if (string) {
            fputc(ch, tmp);
            continue;
        }

        if (tc_trimmable(ch)) {
            fputc('\n', tmp);
            continue;
        }

        fputc(ch, tmp);
    }

    fclose(fp);
    fclose(tmp);

    tmp = fopen("tc.trim_space.tmp", "r");
    if (tmp == NULL) {
        perror(argv[0]);
        return 1;
    }


    char *data;
    while ((data = read_line(tmp)) != NULL) {
        fputs(data, stdout);
        if (tc_keyword(data)) {
            fputc(' ', stdout);
        }
    }

    fclose(tmp);

    /*
    if (unlink("./tc.trim_space.tmp") != 0) {
        perror(argv[0]);
        return 1;
    }
    */

    return 0;
}
