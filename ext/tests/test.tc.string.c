#include "tc.string.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

void
test1()
{
    const char *str = "HELLO WORLD";
    int len;
    TCString *obj;

    len = tc_string_length(str);
    assert(len == 11);

    obj = tc_string_new(str);
    assert(strcmp(obj->data, str) == 0);
    assert(obj->len == 11);

    tc_string_free(obj);

    obj = tc_string_alloc(10);
    assert(obj != NULL);
    assert(obj->len == 10);

    tc_string_free(obj);
}

void
test2()
{
    const char *str = "HELLO WORLD";
    TCString *obj;

    obj = tc_string_new(str);

    assert(strcmp(obj->data, str) == 0);
    assert(obj->len == 11);
    assert(tc_string_equal(obj, str) == 0);
    assert(tc_string_equal(obj, "HELLO") != 0);

    tc_string_free(obj);

}

int
main(int argc, char *argv[])
{
    test1();
    test2();

    return 0;
}

