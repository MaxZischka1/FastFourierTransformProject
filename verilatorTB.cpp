#include "verilatorTB.h"
#include <cstdio>

int main_time = 0;
int error_count = 0;

void check(const char *name, int actual, int expected, int cycle){
    if(expected != actual){
        printf("Failed %s at %d Actual: 0x%04X, Expected: 0x%04X\n",
        name,cycle, actual, expected);
        error_count++;
    }
}
void evalEnd(int errorCount){
    if (error_count == 0)
    {
        printf("PassedTB");
    } else{
        printf("Failed with %d error\n", error_count);
    }
}