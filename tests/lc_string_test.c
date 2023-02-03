#include<criterion/criterion.h>
#include "../src/lc_string.h"

Test(lc_string_test_suite,lc_string_isempty_test_with_null_text)
{
    char *text = NULL;
    bool result = isempty(text);
    cr_assert(result == true);
}

Test(lc_string_test_suite, lc_string_isempty_test_with_blank_text)
{
    char *text = "";
    bool result = isempty(text);
    cr_assert(result == true);

    text = " ";
    result = isempty(text);
    cr_assert(result == true);
}


Test(lc_string_test_suite, lc_string_isempty_test_with_non_blank_text)
{
    char *text = "   abc  ";
    bool result = isempty(text);
    cr_assert(result == false);

    text = "abcdefg";
    result = isempty(text);
    cr_assert(result == false);
}

Test(lc_string_test_suite,lc_string_trim_test_with_null_text)
{
    char *text = NULL;
    cr_assert(trim(text) == NULL);
}

Test(lc_string_test_suite,lc_string_trim_test_with_no_space_text)
{
    char *text = "rahul";
    char *result = trim(text);
    cr_assert(strcmp(text, result)==0);
}

Test(lc_string_test_suite,lc_string_trim_test_with_space_text)
{
    char text[] = "  rahul  ";
    char *result = trim(text);
    cr_assert(strcmp(result, "rahul")==0);
}