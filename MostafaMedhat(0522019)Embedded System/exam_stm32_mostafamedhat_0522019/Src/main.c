#include "stm32f401xx.h"
int main(void)
{
    RCC-> AHB1ENR |= (1<<0);
    RCC-> APB2ENR |= (1<<8);

		// PA4         // PA5      // PA6
	// green PA0   // yellow PA2  // red  PA3   // warm motor // hot motor  // buzzer
    GPIOA-> MODER &=~((3<<0*2) | (3<<2*2) |    (3<<3*2) |  (3<<4*2)   | (3<<5*2)   | (3<<6*2)) ;
    GPIOA-> MODER &=~((3<<1*2) | (3<<7*2) ) ;

                                                                 // PA4         // PA5      // PA6
                  // green PA0   // yellow PA2  // red  PA3   // warm motor // hot motor  // buzzer
    GPIOA-> MODER |=((1<<0*2) | (1<<2*2) |       (1<<3*2) |     (1<<4*2)   | (1<<5*2)   | (1<<6*2)) ;
    GPIOA-> MODER |= (0<<7*2) ;


    GPIOA->MODER |=(3<<1*2);
    ADC1-> CR1 |= (0b10<<24);
    ADC1-> CR2 |= (1<<0);
    for(int volatile i= 0; i< 10000 ;i++);
    ADC1-> SQR3 = 1 ; // 256

    while(1)
    {
    	  ADC1-> CR2 |= (1<<30);
    	  while(!(ADC1-> SR & (1<<1)));
    	  int value = ADC1-> DR ;
    	  int temp = ((value * 3.3) / 256) *100;
          if(temp <= 26)
          {
        	  GPIOA-> ODR |=  (1<<0);
        	  GPIOA-> ODR &= ~(1<<2);
        	  GPIOA-> ODR &= ~(1<<3);
        	  GPIOA-> ODR |=  (1<<4);
        	  GPIOA-> ODR &= ~(1<<5);
        	  GPIOA-> ODR &= ~(1<<6);
          }
          if( temp > 26 && temp <35  )
          {
        	  GPIOA-> ODR &= ~(1<<0);
        	  GPIOA-> ODR  |= (1<<2);
        	  GPIOA-> ODR &= ~(1<<3);
        	  GPIOA-> ODR &= ~(1<<4);
        	  GPIOA-> ODR &= ~(1<<5);
        	  GPIOA-> ODR &= ~(1<<6);
          }
          if(temp >= 35 && temp < 45)
          {
        	  GPIOA-> ODR &= ~(1<<0);
        	  GPIOA-> ODR &= ~(1<<2);
        	  GPIOA-> ODR |=(1<<3);
        	  GPIOA-> ODR &= ~ (1<<4);
        	  GPIOA-> ODR |=(1<<5);
        	  GPIOA-> ODR &= ~(1<<6);
          }
          if(temp >= 45)
          {
        	  GPIOA-> ODR &= ~(1<<0);
        	  GPIOA-> ODR &= ~(1<<2);
        	  GPIOA-> ODR |=  (1<<3);
        	  GPIOA-> ODR &= ~(1<<4);
        	  GPIOA-> ODR &= ~(1<<5);
        	  GPIOA-> ODR |= (1<<6);
          }

          if(!((GPIOA -> IDR >>7 ) &1 ))
          {
        	  GPIOA-> ODR &=  ~(1<<5);
        	  while(!((GPIOA -> IDR >>7) &1 ));
          }

    }




}
