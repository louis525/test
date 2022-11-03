#include <AT89X52.H>

void delayms(unsigned int time);

int main()
{
	while (1)
	{
		P0 = 0x7f;
		switch (P0)
		{
		case 0x7e:
		{
			P2 = 0x7e;
			delayms(200);
			P2 = 0xff;
			delayms(200);
			break;
		}
		case 0x7d:
		{
			P2 = 0x3c;
			delayms(200);
			P2 = 0xff;
			delayms(200);
			break;
		}
		case 0x7c:
		{
			P2 = 0x18;
			delayms(200);
			P2 = 0xff;
			delayms(200);
			break;
		}
		case 0xff:
		{
			P2 = 0x00;
			delayms(200);
			P2 = 0xff;
			delayms(200);
			break;
		}
		}
	}
}
void delayms(unsigned int time)
{
	unsigned int n;
	while (time > 0)
	{
		n = 120;
		while (n > 0)
			n--;
		time--;
	}
}