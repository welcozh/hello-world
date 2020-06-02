#include <stdio.h>
#include <string.h>


using namespace std;

int main(int argc, char* argv[])
{
    char* str1 = "hello world!";
    char* str2 = "";

    printf("%d\n",strlen(strstr(str1,str2)));

    return 1;
}
