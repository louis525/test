#include <AT89X52.H>
#include <INTRINS.H>
void scan(unsigned char k);
void delayms(unsigned int time);

code char table[] = {0xa4,0xc0,0xa4,0xa4,0xf9,0xc0,0xc0,0x82};

int main()
{
	while(1)
		{
			scan(0);
		}
}
void scan(unsigned char k)
{
	unsigned char m;
	unsigned char com;
	com=0x00;
	for(m=0;m<8;m++)
	{
		P2=~table[k];
		P1=com;
		delayms(1);
	//	P1=0xff;
		com++;
		k++;
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
