#include <stdio.h>
#include <assert.h>

#include "tcstring.h"

void
test1()
{
    const char *str = "HELLO WORLD";
    int len;
    TCString *obj;

    len = tc_string_length(str);
    printf("[%s] len:%d\n", str, len);

    obj = tc_string_new(str);
    printf("[%s] len:%d\n", obj->data, obj->len);

    tc_string_free(obj);

    obj = tc_string_alloc(10);
    printf("[%s] len:%d\n", obj->data, obj->len);

    tc_string_free(obj);
}

void
test2()
{
    const char *str = "HELLO WORLD";
    TCString *obj;

    obj = tc_string_new(str);
    printf("[%s] len:%d\n", obj->data, obj->len);

    printf("[%s] == [%s] : %d\n", obj->data, "HELLO WORLD", 
            tc_string_equal(obj, "HELLO WORLD"));

    printf("[%s] == [%s] : %d\n", obj->data, "HELLO ", 
            tc_string_equal(obj, "HELLO "));

    tc_string_free(obj);

}

int
main(int argc, char *argv[])
{
    test1();
    test2();

    return 0;
}

