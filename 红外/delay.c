#include <intrins.h>
void Delay1ms(unsigned int xms)
{
    unsigned char data i, j;
    while (xms--)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}