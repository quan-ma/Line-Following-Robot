 //******************** Line Following Robot ******************************
// Contains LCD and Reflectance sensor implementation
//*****************************************************************************

#include "stm32l1xx.h"
#include "math.h"
#include <stdbool.h>
#include "motor_header.h"
//#include "LCD_header.h"   //***************** LCD Testing uncomment if want to use 
#include "system_clock.h"
#include "reflector_sensors_header.h"

//void LCD_Display_Result(void);

int main(void) {
	uint32_t  final_move = 0x0000;  // hexadeximal number used to determine each case
	uint32_t move[4];

  static int check =0;   // checking which case statement is met

  int i=0;
	Motor motor_right; //RIGHT MOTOR
	Motor motor_left; //LEFT MOTOR
	
	//Delays for speed testing 
	int motor_delay = 5;  
	int led_delay =2;
	
	
	
	//LCD_Clock_Init();   //***************** LCD Testing uncomment if want to use 
	 if (SysTick_Config(SystemCoreClock / 1000)) { /* SysTick 1 msec interrupts  */
    while (1);                                  /* Capture error              */
  }
	

	Motor_Init();  // initilozing the PB AND PC PINS FOR MOTOR
	motor_right.step = 0;        // right motor
	motor_right.totalSteps = 0;  //right motor
	
	motor_left.step = 0;        // left motor
	motor_left.totalSteps = 0;  //left motor
//	LCD_PIN_Init();    //***************** LCD Testing uncomment if want to use 
//	LCD_Configure();   //***************** LCD Testing uncomment if want to use 
 while(1)
 {
	final_move =0;   // final move variable clearing to move to the next move
	move[0] = sensor_1000();  // sensor 1 
	move[1] = sensor_0100();  //sensor 2
	move[2] = sensor_0010();  // sensor 3
	move[3] = sensor_0001();  // sensor 4
	  
	//this is for led motor testing 
	  GPIOA->MODER &= ~(0xF0);  //pa2 and 3
		GPIOA->MODER |= 0x50;

	 // this is the driver of the system , the robot reacts based on the 
	 // hexadecimal number that comes in for final_move
	final_move = move[0]| move[1]| move[2] | move[3];    // check wich condition is met based on the hexadecimal combination
		
	 switch(final_move)    // This Checks the final move to see what the motors need to do
		 {                   // based on the comination for final move Hexadecimal number it does the case corresponding
			case 0x0000:       // the motor turns the amount of loops in each for loop so some cases might go longer than others                         
				  for( i=0; i<30; i++)     // depending on the condition of the robot.
					{		
					 StepMotor_half_left_reverse(&motor_left);
					 Delay(motor_delay);
					 StepMotor_half_right_reverse(&motor_right);
					 Delay(motor_delay);
					}
						check = 1;
					break; 
					
			case 0x0001  :
					for( i=0; i<30; i++)
					{		
					 StepMotor_half_left(&motor_left); 
					 Delay (motor_delay);
					 StepMotor_half_right_reverse(&motor_right); 
					 Delay (motor_delay);
					}
					for( i=0; i<50; i++)
					{		
					 StepMotor_half_left(&motor_left); 
					 Delay (motor_delay);
					 StepMotor_half_right(&motor_right); 
					 Delay (motor_delay);
					}
						check = 2;
					break; 
					
			case 0x0010  :
					for( i=0; i<20; i++)
					{		
					 StepMotor_half_left_reverse(&motor_left); 
					 Delay (motor_delay);
					 StepMotor_half_right(&motor_right); 
					 Delay (motor_delay);
					}
					for( i=0; i<50; i++)
					{		
					 StepMotor_half_left(&motor_left); 
					 Delay (motor_delay);
					 StepMotor_half_right(&motor_right); 
					 Delay (motor_delay);
					}
						check = 3;
					break; 
					
			case 0x0011  :
					for( i=0; i<50; i++)
					{		
						StepMotor_half_left(&motor_left); 
						Delay (motor_delay);
						StepMotor_half_right_reverse(&motor_right); 
						Delay (motor_delay);
					}
					for( i=0; i<60; i++)
					{		
						StepMotor_half_left(&motor_left); 
						Delay (motor_delay);
						StepMotor_half_right(&motor_right); 
						Delay (motor_delay);
					}
						check = 4;
					break; 
					
			case 0x0100 :
					for( i=0; i<20; i++)
					{		
					 StepMotor_half_right(&motor_right); 
					 Delay(motor_delay);
					StepMotor_half_left_reverse(&motor_left); 
					 Delay(motor_delay);
					}
					for( i=0; i<50; i++)
					{		
					 StepMotor_half_right(&motor_right); 
					 Delay(motor_delay);
					 StepMotor_half_left(&motor_left); 
					 Delay(motor_delay);
					}
					
					GPIOA->ODR = 0x1 << 2;
					Delay(2);
						check = 5;
					break; 
					
				case 0x0101  :
					for( i=0; i<30; i++)
					{		
					 StepMotor_half_right(&motor_right); 
					 Delay(motor_delay);
					 StepMotor_half_left(&motor_left); 
					 Delay(motor_delay);
					}
					GPIOA->ODR = 0x1 << 3;
					Delay(2);
			
					check = 6;
					break; 
					
	    case 0x0110  :
					for( i=0; i<110; i++)
					{		
					 StepMotor_half_left(&motor_left);
					 Delay(motor_delay);
					 StepMotor_half_right(&motor_right);  
					 Delay (motor_delay);
					}
						check = 7;
					break; 
					
		  case 0x0111  :
						
	      	for( i=0; i<50; i++)
		       {		
		         StepMotor_half_left(&motor_left); 
		         Delay (motor_delay);
						 StepMotor_half_right_reverse(&motor_right); 
		         Delay (motor_delay);
					 }
					 for( i=0; i<100; i++)
		       {		
		         StepMotor_half_left(&motor_left); 
		         Delay (motor_delay);
						 StepMotor_half_right(&motor_right); 
		         Delay (motor_delay);
					 }
					
					GPIOA->ODR = 0x1 << 3;	
					Delay(2);
						check = 8;
					break; 
					
			case 0x1000:
						
						 for( i=0; i<30; i++)
							{		
							 StepMotor_half_right(&motor_right);   			
							 Delay (motor_delay);
							 StepMotor_half_left_reverse(&motor_left);   			
							 Delay (motor_delay);	
							}
						 for( i=0; i<90; i++)
							{		
							 StepMotor_half_right(&motor_right);   			
							 Delay (motor_delay);
							 StepMotor_half_left(&motor_left);   			
							 Delay (motor_delay);	
							}
							GPIOA->ODR = 0x1 << 2;
							Delay(2);
								check = 10;
							break; 
				
			case 0x1001:		
		     for( i=0; i<30; i++)
		      {		
           StepMotor_half_right(&motor_right);   			
		       Delay (motor_delay);
					 StepMotor_half_left(&motor_left);   			
		       Delay (motor_delay);
				  }
					GPIOA->ODR = 0x1 << 2;
					Delay(2);
						check = 10;
					break; 
				 
					case 0x1010  :
		     for( i=0; i<30; i++)
		      {		
           StepMotor_half_right_reverse(&motor_right);   
		       Delay (motor_delay);
					 StepMotor_half_left(&motor_left);   			
		       Delay (motor_delay);
				  }
					for( i=0; i<50; i++)
					{		
           StepMotor_half_right(&motor_right);   			
		       Delay (motor_delay);
					 StepMotor_half_left(&motor_left);   			
		       Delay (motor_delay);
				  }
					GPIOA->ODR = 0x1 << 2;
					Delay(2);
						check = 11;
					break; 
					
					case 0x1011  :
				 for( i=0; i<20; i++)
		      {		
           StepMotor_half_right(&motor_right);   			
		       Delay (motor_delay);
					 StepMotor_half_left_reverse(&motor_left);   			
		       Delay (motor_delay);
				  }
					for( i=0; i<50; i++)
		      {		
           StepMotor_half_right(&motor_right);   			
		       Delay (motor_delay);
					 StepMotor_half_left(&motor_left);   			
		       Delay (motor_delay);
				  }
					GPIOA->ODR = 0x1 << 2;
					Delay(2);
						check = 12;
					break; 
					
					case 0x1100  :
		     	for( i=0; i<30; i++)
		      {		
           StepMotor_half_right(&motor_right);   			
		       Delay (motor_delay);
					 StepMotor_half_left_reverse(&motor_left);   			
		       Delay (motor_delay);
					}
					for( i=0; i<50; i++)
		      {		
           StepMotor_half_right(&motor_right);   			
		       Delay (motor_delay);
					 StepMotor_half_left(&motor_left);   		
		       Delay (motor_delay);
					}
				 
					GPIOA->ODR = 0x1 << 2;
					Delay(2);
					check = 13;
					break;
					
					case 0x1101  :
				for( i=0; i<30; i++)
					{		
					 StepMotor_half_right(&motor_right);   			
					 Delay (motor_delay); 
						StepMotor_half_left_reverse(&motor_left);   			
					 Delay (motor_delay);
					}
					for( i=0; i<50; i++)
					{		
					 StepMotor_half_right(&motor_right);   			
					 Delay (motor_delay); 
						StepMotor_half_left(&motor_left);   			
					 Delay (motor_delay);
					}

					GPIOA->ODR = 0x1 << 2;
					Delay(2);
						check = 14;
					break; 
					
					case 0x1110  :
					for( i=0; i<40; i++)
					{		
					 StepMotor_half_right(&motor_right);   			
					 Delay (motor_delay);
					StepMotor_half_left_reverse(&motor_left);   			
					 Delay (motor_delay);
					}
					for( i=0; i<50; i++)
					{		
					 StepMotor_half_right(&motor_right);   			
					 Delay (motor_delay);
					StepMotor_half_left(&motor_left);   			
					 Delay (motor_delay);
					}
					GPIOA->ODR = 0x1 << 2;
					Delay(2);
						check = 15;
					break; 
				 
					case 0x1111  :
					for( i=0; i<50; i++)
					{		
					 StepMotor_half_right(&motor_right);  
					 Delay (motor_delay);
					 StepMotor_half_left(&motor_left);  
					 Delay (motor_delay);			 
					}
						check = 16;
					break; 
		}
		i=0;
 }
}


