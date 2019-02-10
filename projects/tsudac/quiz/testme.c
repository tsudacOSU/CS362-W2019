/***********************************************************************************************
 * Carly Tsuda (tsudac)
 * CS362 Software Engineering W 2019
 * Random Testing Quiz
 * February 10, 2019
 * ********************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

const int MAX_STRING = 10;
const int CHANCE = 10;
char inputChar()
{
    char c;
// will produce a random input from the ASCII table (1-33, 162 excluded)
    c = (rand() % 129) + 32;
    return c;
}

char *inputString()
{
    // 1/CHANCE chance that the test will produce a string that contains "reset", triggering the final test case
    // otherwise, generates a random string of size max string
   char string[MAX_STRING];
   int testCase = (rand() % CHANCE);
   if(testCase == 0)
       strcpy(string, "reset");
   else
   {
        for(int i = 0; i < MAX_STRING; i++)
        {
            string[i] = (rand() % 126) + 33; //this particular formula gives some unprintable characters; it does not seem to affect testing but looks kind of gross
        }
   }
   
   
    return string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));

   /**********************************
    * for testing 
    for(int i=0; i < 100; i++)
    {
        printf("%c \n", inputChar());
    }
    **********************************/

    testme();
    return 0; //if this return statement is commented out, the gcov test reports 100% coverage.
}
