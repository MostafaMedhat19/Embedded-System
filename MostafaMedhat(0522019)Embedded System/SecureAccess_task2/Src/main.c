#include <stdint.h>
#include "stm32f401xx.h"
int main(void)
{
	  RCC-> AHB1ENR |= (1<<0);

	  GPIOA -> MODER &= ~(3<<0*2);
	  GPIOA -> MODER &= ~(3<<1*2);
	  GPIOA -> MODER &= ~(3<<2*2);
	  GPIOA -> MODER &= ~(3<<3*2);

	  GPIOA -> MODER |= (0<<0*2);
	  GPIOA -> MODER |= (0<<1*2);
	  GPIOA -> MODER |= (0<<2*2);
	  GPIOA -> MODER |= (0<<3*2);

	  GPIOA -> MODER &= (3<<7*2) ;
	  GPIOA -> MODER |= (0<<7*2) ;


	  GPIOA -> MODER &= ~((3<<4*2) | (3<<5*2) | (3<<6*2) );


	  GPIOA -> MODER |= (1<<4*2) ;
	  GPIOA -> MODER |= (1<<5*2) ;
	  GPIOA -> MODER |= (1<<6*2) ;


	  int  volatile Correct_Seq[4] = {1, 3, 2, 4};
	  int  volatile index = 0 ;
	  int volatile button_Seq[4]= {0};
	  GPIOA-> ODR &= ~((1<<4)|(1<<5)|(1<<6));
   while(1)
   {
	   int  volatile checker =1 ;
	   if(!((GPIOA -> IDR >>0)  & (1) ))
	   {
		    button_Seq[index++]= 1;
		    while(!((GPIOA -> IDR >>0)  & (1) ));
	   }
	   else if(!((GPIOA -> IDR >>1)  & (1) ))
	   {
		   button_Seq[index++]= 2;
		   while(!((GPIOA -> IDR >>1)  & 1 ));
	   }
	   else if(!((GPIOA -> IDR >>2)  & 1 ))
	   {
		   button_Seq[index++]= 3;
		   while(!((GPIOA -> IDR >>2)  & 1 ));
	   }
	   else if(!((GPIOA -> IDR >>3)  & 1 ))
	   {
		   button_Seq[index++]= 4;
		   while(!((GPIOA -> IDR >>3)  & 1 ));
	   }
	   if(index == 4)
	   {
		   for(int i =0 ; i< 4 ;i++ )
		   {
			   if(button_Seq[i]!= Correct_Seq[i])
			   {
				   checker =0 ;
				   break;
			   }
		   }
		      if(checker == 1 )
		  	   {
		  		   GPIOA-> ODR |=  (1<<4);
		  		   GPIOA-> ODR &= ~ ((1<<5) |(1<<6) );

		  	   }
		  	   else
		  	   {

		  		   GPIOA-> ODR &= ~(1<<4);
		  		   GPIOA-> ODR |= ((1<<5) |(1<<6) );
		  	   }
		  	   index =0 ;
		  	   for(int volatile i= 0; i< 4 ;i++)
		  	   {
		  		   button_Seq[i]= 0;
		  	   }

	   }
	   if(!((GPIOA -> IDR >>7)  & 1 ))
	      {
	  		  		   GPIOA-> ODR &= ~ ((1<<4) | (1<<5) |  (1<<6));

	      }

   }
}
