FILE(REMOVE_RECURSE
  "CMakeFiles/tester.dir/my_test1.c.o"
  "tester.pdb"
  "tester"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang C)
  INCLUDE(CMakeFiles/tester.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
