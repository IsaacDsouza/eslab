#include <LPC17xx.h>

void EINT3_IRQHandler(void);

unsigned char int3_flag = 0;

int main(void){
    LPC_PINCON->PINSEL4 |= 0x04000000;
    LPC_PINCON->PINSEL4 = 0xFCFFFFFF;
    LPC_GPIO2->FIODIR = 0x00000100;
    LPC_SC_EXTINT = 0x00000008;
    LPC_SC_EXTPOLAR = 0x00000008;
    NVIC_EnableIRQ(EINT3_IRQn);
    while(1);
}

void EINT3_IRQHandler(void){
    LPC_SC->EXTINT = 0x00000008;
    if(int3_flag==0x00){
        LPC_GPIO2->FIOCLR=0x00001000;
        int3_flag=0xFF;
    }
    else{
        LPC_GPIO2->FIOSET = 0x00001000;
        int3_flag=0;
    }
}