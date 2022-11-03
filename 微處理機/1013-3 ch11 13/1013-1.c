#include <AT89X52.H>

void delay500ms(void);
main()
{
	while(1)
	{
		P2=0xF0;
		delay500ms();
		P2=0x0F;
		delay500ms();
				
	}
}

void delay500ms(void)
{
	unsigned char n;
	//n<20 ¬O¤@¬í 
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
	
