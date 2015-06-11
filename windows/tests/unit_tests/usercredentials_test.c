// include the DataPackager methods
#include "../../headers/UserCredentials.h"

#include <check.h>

/* Test that we can create user credentials struct */
START_TEST (create_full_user_credentials)
{
  char username[20]= "test_user";
  char password[20]= "password";
  char colorType[20] = "red";

  UserCredentials *credentials = createFullUserCredentials(username, password, colorType);

  ck_assert_str_eq(username, credentials->username);
  ck_assert_str_eq(password, credentials->password);
  ck_assert_str_eq(colorType, credentials->colorType);
  
  // free up memory
  destroyUserCredentials(&credentials);
}
END_TEST

START_TEST (delete_user_credentials)
{
  // create a user credentials struct
  UserCredentials *credentials = createFullUserCredentials("test", "test", "red");

  // delete it
  destroyUserCredentials(&credentials);

  // test that it is NULL
  ck_assert(credentials == NULL);
}
END_TEST

START_TEST (send_user_credentials) 
{
 char username[20] = "test_user";
 char password[20] = "password"; 
 checkValidUsername(username);
 sendUserCredentials(username, password);
 
 StateManager *testmanager = ChangeState("VerifyCredentials");
 testmanager
}


// create a suite to run the tests
Suite *first_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("My First Test");

  // Core test case
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, create_full_user_credentials);
  tcase_add_test(tc_core, delete_user_credentials);
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
