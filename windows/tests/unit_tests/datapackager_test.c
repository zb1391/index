// include the DataPackager methods
#include "../../headers/DataPackager.h"
#include <check.h>

/* Test numCharsRequired returns right value */
START_TEST (get_num_chars)
{
  UserCredentials *credentials = createUserCredentials("user",
                                             "test","red");
  int expected = 44;
  int results = numCharsRequired(credentials);

  ck_assert_int_eq(expected,results);

  destroyUserCredentials(&credentials);
}
END_TEST

/* Test that the DataPackager can serialize the User Credentials Struct */
START_TEST (serialize_user_credentials)
{
  //create the credentials
  UserCredentials *credentials = createUserCredentials("user",
                                                "test", "red");
  char expected[100] = "username:user\npassword:test\ncolor_type:red\n";

  //serialze the data
  char *packaged = packageUserCredentials(credentials);

  ck_assert_str_eq(packaged,expected);
  
  // free up memory
  destroyUserCredentials(&credentials);
  free(packaged);
}
END_TEST

// create a suite to run the tests
Suite *first_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("My First Test");

  // Core test case
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core,get_num_chars);
  tcase_add_test(tc_core, serialize_user_credentials);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(int arc, char **argv)
{
  int number_failed;
  Suite *s;
  SRunner *sr;

  // instantiate the test suite
  s = first_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return 0;
}
