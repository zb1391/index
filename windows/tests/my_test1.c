// linux setup: sudo apt-get install check
// windows setup: pending
// compile: gcc -o test my_test1.c -lcheck -lm -lpthread -lrt
#include <check.h>


START_TEST (test_one)
{
  // implementation inside here
  // this test should fail 
  int n1, n2;

  n1 = 1;
  n2 = 2;
  ck_assert_int_eq(n1,0);
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

  tcase_add_test(tc_core, test_one);
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
