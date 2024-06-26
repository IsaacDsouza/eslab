#include <LPC17xx.h>

unsigned int delay, count=0, switchcount=0, j;

unsigned int Disp[16]={0x000003f0, 0x00000060, 0x000005b0, 0x000004f0, 0x00000660, 0x000006d0, 0x000007d0, 0x00000070,
                    0x000007f0, 0x000006f0, 0x00000770, 0x000007c0, 0x00000390, 0x000005e0, 0x00000790, 0x00000710};

#define ALLDISP 0X00100000
#define DATAPORT 0x00000ff0

int main(void){
    LPC_PINCON->PINSEL0 = 0x00000000;
    LPC_PINCON->PINSEL1 = 0x00000000;
    LPC_GPIO->FIODIR = 0x00180ff0;

    while(1){
        LPC_GPIO0->FIOSET |=ALLDISP;
        LPC_GPIO0->FIOCLR = 0x00000ff0;
        LPC_GPIO0->FIOSET = Disp[switchcount];

            for(j=0; j<3; j++)
        for(delay=0, delay<30000; delay++);
            switchcount++;

        if(switchcount==0x10){
            switchcount=0;
            LPC_GPIO0->FIOCLR = 0x00180ff0;
        }
    }
}