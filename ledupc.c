#include <LPC17XX.H>

int main(){
    LPC_PINCON -> PINSLE1 = 0X00000000;
    LPC_GPIO0 -> FIODIR = 0X03000000;
    while (1)
    {
        if (!(LPC_GPIO2 -> FIOPIN & 0X00000800))
        {
            LPC_GPIO0 -> FIOSET = 0X03000000;
        }
        else
        {
            LPC_GPIO0 -> FIOCLR = 0X03000000;
        }
        
        
    }
    
}