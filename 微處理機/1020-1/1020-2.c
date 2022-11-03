#include <AT89X52.H>
void delayms(unsigned int time);

unsigned char tone;
unsigned char hi;
unsigned char tone;
unsigned char low;
code char table[] = { 0xf9,0xe5,0xfb,0xee};

main()
{
	unsigned char k;
	while(1)
	{
	TMOD = 0x01;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
		
	for(k=0;k<20;k++)
		{
			tone = 0;
			delayms(25);
			tone = 1;
			delayms(25);
		}
	

	
	while(P3_4==0);
	TR0 = 0;
	delayms(2000);
	}
}

void timer0_int(void) interrupt 1
{
	hi = tone*2;
	low = hi+1;
	TH0 = table[hi];
	TL0 = table[low];
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