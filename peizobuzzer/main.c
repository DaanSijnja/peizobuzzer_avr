/*
 */

#include <avr/io.h>
#include "peizo.h"


int main(void)
{
    peizo_init();
    int array[] = {500,100,500,10};
    // Insert code
    playtune(array,sizeof array/sizeof array[0]);
    while(1)
    {


    }

    ;

    return 0;
}
