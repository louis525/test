#include <AT89X52.H>
void delayms(unsigned int time);

main()
{
	while(1)
	{
	TMOD = 0x01;
	TH0 = 0xfb;
	TL0 = 0x1e;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	
	delayms(500);
	
	while(P3_4==0);
	TR0 = 0;
	delayms(500);
	}
}

void timer0_int(void) interrupt 1
{
	TH0 = 0xfb;
	TL0 = 0x1e;
	P3_4 =! P3_4;
}

void delayms(unsigned int time)
{
	unsigned int n;
	while(time>0)
	{
		n=120;
		while(n>0) n--;
		time--;
	}
}
