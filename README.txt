
This is a solution to coding excercise sent to Roman Kostin on 2/3/2021,
quoted below.

The guidelines were applied to the requested functions only. Test
cases do use malloc and recursion.

Most common sanity checks (null and empty strings, invalid numbers) are done.

Filenames with parts of the excercise per se are capitalized: 
CGREP.c
WORDS.c
BTREE.c

Script demo_run.sh builds the cases and runs tests.

Tested on Linux (Ubuntu 18.04 LTS) and MacOS (Catalina 10.15.7) 

Thanks,

--
rqk (Roman Kostin)

________Quoted mail start___________

Guidelines for all screening questions:

a. Do not allocate memory using malloc()
b. Avoid recursion
c. Do not create global variables
d. Submit answers that can be compiled and run on a standard Linux/macOS system.
e. Provide test vectors and code to unit test the solution
f. All corner cases should be handled. For example: Please handle NULL pointers, parameter checking, etc.
g. Candidates should submit their responses within one business day.

1. Implement context grep

See documentation for context control for an explanation of the expected behavior: https://www.gnu.org/software/grep/manual/grep.html#Context-Line-Control

To simplify the implementation, assume the following function declaration which should be implemented by the candidate:

void context_grep(int argc, char **argv, int context, char *expr);

argc = number of elements in argv array
argv = Array of character pointers containing the input to be searched
context = number of context lines to be printed
expr = search string

For example:

char *argv[] = {
"Hello world",
"Welcome to California",
"Goodbye",
"Big sky",
"Nice job",
"Blue sky",
"Hey Joe"
};

Calling the function: context_grep(6, argv, 2, "sky") should print:
====
Welcome to California
Goodbye
Big sky
Nice Job
Blue sky
Hey Joe
====

2. Reverse the order of words in a string

Reverse the order of words in a string.

For example:
Input: I love San Diego
Output: Diego San love I

3. Write functions to insert and search for an element in a binary search tree

________Quoted mail end_____________
 

 

 

