#include <LPC17xx.h>

void clock_wise(void);
void anti_clock_wise(void);

unsigned long int var1, var2;
unsigned int i=0, j=0, k=0;

int main(void){
    LPC_PINCON->PINSEL4 = 0x00000000;
    LPC_GPIO2->FIODIR = 0x0000000F;

    while(1){
        for(j=0; j<50; j++)
            clock_wise();

        for(k=0; k<50000; k++);

        for(j=0; j<50; j++);
            anti_clock_wise();

        for(k=0; k<50000; k++);

    }
}

void clock_wise(void){
    var1 = 0x00000001;
    for(i=0; i<3; i++){
        LPC_GPIO2->FIOCLR=0x0000000F;
        LPC_GPI02->FIOSET=var1;
        var1=var1<<1;
        for(k=0; k<15000; k++);
    }
}

void anti_clock_wise(void){
    var2= 0x00000008;
    for(i=0; i<3; i++){
        LPC_GPIO2->FIOCLR = 0x0000000F;
        LPC_GPIO2->FIOSET = var2;
        var2=var2<<1;
        for(k=0; k<15000; k++);
    }
}