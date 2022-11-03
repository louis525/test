#include <AT89X52.H>

void scan(unsigned char k);
void delayms(unsigned int time);

code char table[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};

int main()
{
	while(1)
	{
		unsigned char k;
		for(k=0;k<10;k++)
		{
			
			P2=~table[k];
			P1=0x03;
			delayms(500);
		}
	}
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