#include<AT89X52.H>
char keypad(void);


void delayms(unsigned int time);

int main()
{
	char n;
	while(1)
	{
		n = keypad();
		P2 = n;
	}

}
char keypad(void)
{
	char key = 0xff;
	P0 = 0x7f;
	if(P0_0==0) key = 0xfc;
	if(P0_1==0) key = 0xf3;
	if(P0_2==0) key = 0xcf;
	if(P0_3==0) key = 0x3f;
	
	P0 = 0xbf;
	if(P0_0==0) key = 0x7e;
	if(P0_1==0) key = 0xbd;
	if(P0_2==0) key = 0xdb;
	if(P0_3==0) key = 0xe7;
	
	P0 = 0xdf;
	if(P0_0==0) key = 0xe7;
	if(P0_1==0) key = 0xc3;
	if(P0_2==0) key = 0x81;
	if(P0_3==0) key = 0x00;
	
	P0 = 0xef;
	if(P0_0==0) key = 0x18;
	if(P0_1==0) key = 0x3c;
	if(P0_2==0) key = 0x7e;
	if(P0_3==0) key = 0xff;
	
	return key;
}