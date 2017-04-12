#ifndef _TCSTRING_H
#define TCSTRING_H


typedef struct {
    int len;
    char *data;
} TCString;

/**
 * Get length of raw data.
 *
 * [PARAMS]
 * const char *: raw data
 * [RETURN]
 * int : length
 */
int tc_string_length(const char *);

/**
 * Allocate and copy TCString from raw data.
 *
 * [PARAMS]
 * const char *: raw data
 * [RETURN]
 * TCString *: new string object copied
 */
TCString* tc_string_new(const char *);

/**
 * Allocate TCString.
 *
 * [PARAMS]
 * int: length of raw data
 * [RETURN]
 * TCString *: new string object
 */
TCString* tc_string_alloc(int);

/**
 * Free memory.
 *
 * [PARAMS]
 * TCString *: TCString object
 * [RETURN]
 * void :
 */
void tc_string_free(TCString *);

/**
 * Copy string.
 *
 * [PARAMS]
 * TCString *: destination
 * const char *: source raw data
 * [RETURN]
 * void :
 */
void tc_string_copy(TCString *, const char *);

/**
 * Check if the string is equal to the other.
 *
 * [PARAMS]
 * TCString *: string1
 * const char *: string2 raw data
 * [RETURN]
 * int : 0 if equal 
 */
int tc_string_equal(TCString *, const char *);

#endif

