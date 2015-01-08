Testing Suite in C
--------------------

We are using the Check library to write unit tests in C
Check is an open source library to do exactly what we want - write tests

http://check.sourceforge.net/doc/check_html/check_3.html

-------------------

WHY WRITE TESTS?

We are writing tests to confirm our code does exactly what we want it to do.
It also helps us stay focused on the tast at hand. We are going to try our best to follow the Red Green Refactor Paradigm.
RED      - write a test before you start coding. The test should fail
GREEN    - write code to make the specific test pass. 
REFACTOR - improve upon what you wrote to simplify, make more readable, provide abstractions that can be used for future code.

By writing tests first we write code to accomplish definitive tasks, and it also helps us see if any changes to our code breaks things we already accomplished. 

---------------
WRITING OUR FIRST TEST

We will be using CMAKE to build and compile our testing suite. First create a directory to hold all of the tests
```
$ mkdir my_tests
```
$ cd my_tests


Next, we will be writing our test file, my_test1.c:

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

Above is a very simple example of how tests are formatted. The code block is surrounded by START_TEST ... END_TEST. Inside we test that our variable n1 should equal 0. Because we set n1 =1, this test will fail by default.

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

Above is how we create a test suite. Each test must be add to the test suite in order for it to be run.

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

Above is the main file where we instantiate our test suite and run it. Thats it!

Next we will create the CMakeLists.txt file. This is a file that is interpreted by CMAKE to create a makefile for us. Paste the three lines below into your CMakeLists.txt file:
--
project("Tester") # This is the name of our project. it is arbitrary

add_executable(tester my_test1.c) # Here we are creating an executable called 'tester'. it is compiled by using our code included in my_test1.c

target_link_libraries(tester check m pthread rt) # to build tester, we need to link some libraries
--

Typically when using CMAKE, we separate the source code from the build (the makefile and executables)

$ mkdir build && cd build

Run this line to create the makefile using CMAKE

$ cmake -G "Unix Makefiles" ..

This will create our makefile for us automatically. Now we can compile and build the executable

$ make

$ ./tester <-- run the code we wrote

Thats it for now!

