/*
 * RAMIE_RECEIVER.c
 *
 *  Created on: 03.05.2020
 *      Author: User
 */
/*ASCII characters begin and end the "Frame" output frame
Beginning characters:
65- "A"
68- "D"
69- "E"
70	"F"
The 66- "B" always indicates the end of the transmission
The use of this frame is caused by the application created for arduino.

Frame construction:
"ASCII(65/67/68/69/)""NUMBER(0-180)""ASCII(66)"
*/
#include "ARM_RECEIVER.h"
void ARM_RECEIVER(uint8_t Frame[3],uint8_t Received[10])
{
	uint8_t number_of_digits=0;	//Variable storing the number of digits in the number determining the transmitted angle
	uint8_t i=0,beginning=0; //Where "i" is the for loop operator and "beginning" finds the beginning of the target Frame
	for(i=0;i<10;i++)
		{
			if(Received[i]==65)
			{
				Frame[0]=65;
				beginning=i;
				for(i=beginning+1;i<10;i++)
				{
					if(Received[i]!=66)
						number_of_digits++;
					else
						break;
				}
				break;
			}
			if(Received[i]==67)
			{
				Frame[0]=67;
				beginning=i;
				for(i=beginning+1;i<10;i++)
				{
					if(Received[i]!=66)
						number_of_digits++;
					else
						break;
				}
				break;
			}
			if(Received[i]==68)
			{
				Frame[0]=68;
				beginning=i;
				for(i=beginning+1;i<10;i++)
				{
					if(Received[i]!=66)
						number_of_digits++;
					else
						break;
				}
				break;
			}
			if(Received[i]==69)
			{
				Frame[0]=69;
				beginning=i;
				for(i=beginning+1;i<10;i++)
				{
					if(Received[i]!=66)
						number_of_digits++;
					else
						break;
				}
				break;
			}
			if(Received[i]==70)
					{
						Frame[0]=70;
						beginning=i;
						for(i=beginning+1;i<10;i++)
						{
							if(Received[i]!=66)
								number_of_digits++;
							else
								break;
						}
						break;
					}
		}
		switch (number_of_digits)	//Creates an output data frame for the arm
					{
					case 1:	//Angle=(0;9)
						Frame[1]=Received[beginning+1]-48;//-48 (ASCII correction)
						Frame[2]=66;
						number_of_digits=0;
						break;
					case 2:	//Angle=(10;99)
						Frame[1]=10*(Received[beginning+1]-48)+Received[beginning+2]-48;
						Frame[2]=66;
						number_of_digits=0;
						break;
					case 3:	//Angle=(100;180)
						Frame[1]=100*(Received[beginning+1]-48)+10*(Received[beginning+2]-48)+Received[beginning+3]-48;
						Frame[2]=66;
						number_of_digits=0;
						break;
					default:
						Frame[1]=Frame[1];
						Frame[2]=66;
						number_of_digits=0;
					}
}

