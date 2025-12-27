#!/bin/sh

#gcc tests/tests.c -o tests/tests.out
#tests/tests.out

gcc -g tests/array_test.c -o tests/tests.out && tests/tests.out