

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_




#define RCC_BASEADDR		0x40023800
#define GPIOA_BASEADDR      0x40020000
#define GPIOB_BASEADDR      0x40020400
#define GPIOC_BASEADDR      0x40020800
#define ADC1_BASEADDR 		0x40012000



typedef struct
{
	volatile	int	CR;
	volatile	int	PLLCFGR;
	volatile	int	CFGR;
	volatile	int	CIR;
	volatile	int	AHB1RSTR;
	volatile	int	AHB2RSTR;
	volatile	int	RESERVED0[2];
	volatile	int	APB1RSTR;
	volatile	int	APB2RSTR;
	volatile	int	RESERVED1[2];
	volatile	int	AHB1ENR;
	volatile	int	AHB2ENR;
	volatile	int	RESERVED2[2];
	volatile	int	APB1ENR;
	volatile	int	APB2ENR;
}RCC_RegDef_t;


#define RCC	((RCC_RegDef_t*)RCC_BASEADDR)



typedef struct {
    volatile int SR;      /**< ADC status register (offset: 0x00) */
    volatile int CR1;     /**< ADC control register 1 (offset: 0x04) */
    volatile int CR2;     /**< ADC control register 2 (offset: 0x08) */
    volatile int SMPR1;   /**< ADC sample time register 1 (offset: 0x0C) */
    volatile int SMPR2;   /**< ADC sample time register 2 (offset: 0x10) */
    volatile int JOFR1;   /**< ADC injected channel data offset register 1 (offset: 0x14) */
    volatile int JOFR2;   /**< ADC injected channel data offset register 2 (offset: 0x18) */
    volatile int JOFR3;   /**< ADC injected channel data offset register 3 (offset: 0x1C) */
    volatile int JOFR4;   /**< ADC injected channel data offset register 4 (offset: 0x20) */
    volatile int HTR;     /**< ADC watchdog high threshold register (offset: 0x24) */
    volatile int LTR;     /**< ADC watchdog low threshold register (offset: 0x28) */
    volatile int SQR1;    /**< ADC regular sequence register 1 (offset: 0x2C) */
    volatile int SQR2;    /**< ADC regular sequence register 2 (offset: 0x30) */
    volatile int SQR3;    /**< ADC regular sequence register 3 (offset: 0x34) */
    volatile int JSQR;    /**< ADC injected sequence register (offset: 0x38) */
    volatile int JDR1;    /**< ADC injected data register 1 (offset: 0x3C) */
    volatile int JDR2;    /**< ADC injected data register 2 (offset: 0x40) */
    volatile int JDR3;    /**< ADC injected data register 3 (offset: 0x44) */
    volatile int JDR4;    /**< ADC injected data register 4 (offset: 0x48) */
    volatile int DR;      /**< ADC regular data register (offset: 0x4C) */
} ADC_RegDef_t;


typedef struct {
    volatile int MODER;      /**< ADC status register (offset: 0x00) */
    volatile int OTYPER;     /**< ADC control register 1 (offset: 0x04) */
    volatile int OSPEEDR;     /**< ADC control register 2 (offset: 0x08) */
    volatile int PUPDR;   /**< ADC sample time register 1 (offset: 0x0C) */
    volatile int IDR;   /**< ADC sample time register 2 (offset: 0x10) */
    volatile int ODR;   /**< ADC injected channel data offset register 1 (offset: 0x14) */
    volatile int BSRR;   /**< ADC injected channel data offset register 2 (offset: 0x18) */
    volatile int LCKR;   /**< ADC injected channel data offset register 3 (offset: 0x1C) */
    volatile int AFRL;   /**< ADC injected channel data offset register 4 (offset: 0x20) */
    volatile int AFRH;     /**< ADC watchdog high threshold register (offset: 0x24) */
} GPIOA_RegDef_t;
#define ADC1 ((ADC_RegDef_t *)ADC1_BASEADDR)
#define GPIOA	((GPIOA_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB	((GPIOA_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC	((GPIOA_RegDef_t*)GPIOC_BASEADDR)
#endif /* INC_STM32F401XX_H_ */
