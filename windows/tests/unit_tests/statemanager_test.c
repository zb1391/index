// include the state manager methods
#include "../../headers/StateManager.h"

#include <check.h>


START_TEST (ask_get_username)
{ 

  // initialize state
  stateType state = GetUsername;

  char *question = getQuestion(state);

  ck_assert_str_eq(question, "Enter your username:");
}
END_TEST

START_TEST(print_question)
{
  // get question
  stateType state = GetUsername;
  char *question = getQuestion(state);
  askQuestion(&question);

  // test that it is NULL
  ck_assert(question == NULL);
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

  tcase_add_test(tc_core, ask_get_username);
  tcase_add_test(tc_core, print_question);
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
