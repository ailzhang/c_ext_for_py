/* swig_example.i */
%module swig_example

%{
/* Put header files here or function declarations like below */
extern int my_add(int a, int b);
%}

extern int my_add(int a, int b);
