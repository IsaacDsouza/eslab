#include<LPC17xx.h>

void pwm_init(void);
void PWM1_IRQHandler(void);

unsigned long int i;
unsigned char flag, flag1;

int main(void){
    pwm_init();
    while (1);

}

void pwm_init(void){
    LPC_SC->PCONP = (1<<6);
    LPC_PINCON->PINSEL7 = 0x000C0000;

    LPC_PWM1->PR = 0x00000000;
    LPC_PWM1->PCR = 0x00000400;
    LPC_PWM1->MCR = 0x00000003;
    LPC_PWM1->MR0 = 30000;
    LPC_PWM1->MR2 = 0x00000100;
    LPC_PWM1->LER = 0x000000FF;
    LPC_PWM1->TCR = 0x00000002;
    LPC_PWM1->TCR = 0x00000009;

    NVIC_EnableIRQ(PWM1_IRQHandler);
}

void PWM1_IRQHandler(void){
    LPC_PWM1->IR = 0xFF;
    if(flag==0x00){
        LPC_PWM1->MR2 += 100;
        LPC_PWM1->LER = 0x000000FF;

        if (LPC_PWM1->MR2 >= 27000){
            flag1 = 0xFF;
            flag = 0xFF;
            LPC_PWM1->LER = 0x000000FF;
        }

    }
    else if(flag1==0xff){
        LPC_PWM1->MR2 -=100;
        LPC_PWM1->LER = 0x000000FF;

        if (LPC_PWM1->MR2 <= 0x300)
        {
            flag=0x00;
            flag1=0x00;
            LPC_PWM1->LER = 0x000000FF;
        }
        
    }
}