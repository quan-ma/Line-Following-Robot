//****************************************************
// HEader file including reflectance sensor implementation
// Each of the functions returns a hexadecimal 
// which represents the position of the actual reflectance sensor 
// from left to right. 
// Returned from each funtion is a hex value 0x1000,0x0100,0x0010, 0x0001
//******************************************************
#include <stdbool.h>  // importated library used for booleans
uint32_t sensor_1000()
{
	  int8_t count;
	  uint8_t color[2];

		color[0] = 'B';
		color[1] = 'W';
		//First reflective sensor (PA11)
		GPIOA->MODER &= ~(0x03 << (2*11));
		GPIOA->MODER |= (0x01 << (2*11));
		GPIOA->ODR = 0x1 << 11;    // turn on the pin  then delay it
		Delay(50);                 
		
		count = 0;
		GPIOA->MODER &= ~(0x03 << (2*11));
		
		while (GPIOA->IDR & 0x800) 
			count++;
		Delay(50);
		if (count > 10){
			
		//	LCD_WriteChar(&color[0],0,0,3);  //***************** LCD Testing uncomment if want to use 
			return 0x1000; // value returned to use in final move
		}
		else{
			
		//	LCD_WriteChar(&color[1],0,0,3);  //***************** LCD Testing uncomment if want to use 
			return 0x0000; // value returned to use in final move
		}
}
uint32_t sensor_0100()
{
	  int8_t count;
	  uint8_t color[2];

		color[0] = 'B';
		color[1] = 'W';
		//Second reflective sensor (PA12)
		GPIOA->MODER &= ~(0x03 << (2*12));
		GPIOA->MODER |= (0x01 << (2*12));
		GPIOA->ODR = 0x1 << 12;      // turn on the pin  then delay it
		Delay(50);
		
		count = 0;
		GPIOA->MODER &= ~(0x03 << (2*12));
		
		while (GPIOA->IDR & 0x1000) 
			count++;
		Delay(50);
		if (count > 10){	
			//LCD_WriteChar(&color[0],0,0,4); //***************** LCD Testing uncomment if want to use 
			return 0x0100; // value returned to use in final move
		
		}
		else{
			//LCD_WriteChar(&color[1],0,0,4); //***************** LCD Testing uncomment if want to use 
			return 0x0000; // value returned to use in final move
		}
}

uint32_t sensor_0010()
{
      int8_t count;
	  uint8_t color[2];

		color[0] = 'B';
		color[1] = 'W';
		//Third reflective sensor (PB6)
		GPIOB->MODER &= ~(0x03 << (2*6));
		GPIOB->MODER |= (0x01 << (2*6));
		GPIOB->ODR = 0x1 << 6;        // turn on the pin  then delay it
		Delay(50);
		
		count = 0;
		GPIOB->MODER &= ~(0x03 << (2*6));
		
		while (GPIOB->IDR & 0x40) 
			count++;
		Delay(50);
		if (count > 10){   
			
			//LCD_WriteChar(&color[0],0,0,5);   //***************** LCD Testing uncomment if want to use 
			return 0x0010; // value returned to use in final move
		}
		else{
			
			//LCD_WriteChar(&color[1],0,0,5);   //***************** LCD Testing uncomment if want to use 
			return 0x0000; // value returned to use in final move
		}
}
uint32_t sensor_0001()
{
	  int8_t count;
	  uint8_t color[2];

		color[0] = 'B';
		color[1] = 'W';
				//Fourth reflective sensor (PB7)
		GPIOB->MODER &= ~(0x03 << (2*7));
		GPIOB->MODER |= (0x01 << (2*7));
		GPIOB->ODR = 0x1 << 7;     // turn on the pin  then delay it
		Delay(50); 
		
		count = 0;
		GPIOB->MODER &= ~(0x03 << (2*7));
		
		while (GPIOB->IDR & 0x80) 
			count++;
		Delay(50);
		if (count > 10){
			
			//LCD_WriteChar(&color[0],0,0,6);  //***************** LCD Testing uncomment if want to use 
			return 0x0001;  // value returned to use in final move
		}
		else{
			
			//LCD_WriteChar(&color[1],0,0,6);  //***************** LCD Testing uncomment if want to use 
			return 0x0000;  // value returned to use in final move
		}
}

