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

-----------------

Setting up Check in a UNIX environment

1. INSTALL CHECK

$ sudo apt-get install check 

2. INSTALL CMAKE

$ sudo apt-get install cmake-curses-gui


Setting up Check in a Windows environment
This process takes a little bit longer because we need to install cygwin.
Cygwin is a program for windows that simulates a Unix shell and provides access to Unix libraries (like Check and others). 

1. Download Cygwin -> visit https://cygwin.com/install.html and choose the proper type (x86 for 32-bit machines, x64 for 64 bit machines)

2. Run the setup.exe file you downloaded
   a) Choose Install from Internet
   b) keep the root directory as is.
   c) leave the local package directory as is
   d) choose direct connection
   e) choose a mirror (i found cygwin.mirror.constant.com to be fastest)

3. Now you will be on the Package Manager. At any time if you need to install more packages for your cygwin environment, just run the setup.exe and proceed to this step. Here we need to install some packages for our environment.
  I found it easier to use the search bar at top to filter for packages

  a) Search for Check -> it is in the Devel dropdown
  b) Search for binutils -> in the Devel dropdown
  c) Search for cmake -> in Devel choose cmake and cmake-gui
  d) Search for gcc -> in Devel choose
       i. cygwin32-gcc-core
      ii. cygwin32-gcc-g++
     iii. gcc-core
      iv. gcc-g++
  e) Search for  make -> in Dev
  f) Search for m4 -> in Interpreters dropdown

4. Click Next and it should install everything for you.

5. Now you can launch cygwin

6. Access your C: Drive
   cygwin uses Linux commands to navigate
   ls    <- shows whats in ur current directory
   cd <dir>   <- change to directory dir
   cd ..      <- go to directory above
   cd -       <- go to previously visited directory
   mkdir <name> <- make a directory named <name>
   
   you can access your c drive by running:
   cd /cygdrive/c

   you can access your Documents by cd to /cygdrive/c/Users/USERNAME/Documents  


---------------
WRITING OUR FIRST TEST

We will be using CMAKE to build and compile our testing suite. First create a directory to hold all of the tests

$ mkdir my_tests

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

