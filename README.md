# VERBIO TEST

Executable that takes a string as a parameter and prints the same string, but converting the words that represents numbers in digits.


Build
-------------

The build sytem is cmake. It has been compiled and tested under linux distribution, but it could also be compiled and run under windows. To buid it with cmake: 

mkdir build

cd build

cmake ..

cmake --build

Run Application
-----------------

cd build/src

./verbio_run "your paragraph" (the paragraph must be passed as parameter in quotes)

* there is also an already compiled version for linux, it can be found on bin/Linux, in case the building process is not sucessfully completed.

Run unit test
-------------------

There are some unit tests that can be run to test different cases.

cd build/test

./verbio_test

Notes
-----------------

There are still some improvements to be done, as taking into account comas and special characters next to a number. For instance, ¨three, four, five" will not be processed correctly. 
