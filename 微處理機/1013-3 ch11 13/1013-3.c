#include <AT89X52.H>

void delay500ms(void);
main()
{
	IT0 = 0;
	EX0 =1;
	EA = 1;
	while(1)
	{
		P2=0xF8;
		delay500ms();
		P2=0x1F;
		delay500ms();
				
	}
}

void int0(void) interrupt 0
{
	unsigned char k;
	for(k=0;k<3;k++)
	{
		P2=0xE7;
		delay500ms();
		P2=0xFF;
		delay500ms();
	}
}

void delay500ms(void)
{
	unsigned char n;
	for(n=0;n<5;n++)
	{
		TMOD = 0x01;
		TH0	= (65536-50000)/256;
		TL0	= (65536-50000)%256;
		TR0 = 1;
		while(TF0 == 0);
			TF0 = 0;
	}
	
	TR0 = 0;
	
	
}
	