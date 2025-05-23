#include <LPC21xx.H>
#include "header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)
void uart0_init(unsigned int baud)
{
int a[]={15,60,30,15,15};
unsigned int PCLK,result;
PCLK= a[VPBDIV]*1000000;
result=PCLK/(16*baud);
PINSEL0|=0X05;
U0LCR=0X83;
U0DLL=result&0xff;
U0DLM=(result>>8)&0xff;
U0LCR=0x03;
}
void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}
unsigned char uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}
void uart0_tx_string(signed char *p)
{
	while(*p!='\0')
	{
		U0THR=*p;
		while(THRE==0);
		p++;
	}
}
void uart0_rx_string(signed char *p, signed int len)
{
int i;
char ch;
for(i=0;i<len;i++)
	{
	while(RDR==0)
	ch=U0RBR;
	uart0_tx(ch);
	if(p[i]!='\n')
	break;
	p[i]='\0';
	}
}
void uart0_integer(int num)
{
int i;
char a[10];
	if(num<0)
	{
		uart0_tx('-');
		num=-num;
	}
	if(num==0)
	{
		uart0_tx('0');
	return;
	}
for(i=0;num;num=num/10)
a[i]=num%10+48;
for(i=i-1;i>=0;i--)
uart0_tx(a[i]);
}
void uart0_tx_float(float num)
{
int temp;
if(num<0)
	{
	num=-num;
	uart0_tx('-');
	}
if(num==0)
	{
	uart0_tx_string("0.0");
	return;
	}
temp=num;
uart0_integer(temp);
uart0_tx('.');
num=(temp-num)*1000000;
uart0_integer(num);
}
void uart0_tx_hex(signed int num)
{
	unsigned char temp;
	uart0_tx_string("0x");
	temp=(num&0x0f)>>4;
	if(temp>9)
	uart0_tx('A'+temp-10);
	else
	uart0_tx(temp+48);
	temp=num&0x0f;
	if(temp>9)
	uart0_tx('A'+temp-10);
	else
	uart0_tx(temp+48);
}
void uart0_binary(signed int num)
{
int i,pos;
for(pos=31;pos>=0;pos--)
	{
	i=num>>pos&1;
	uart0_tx(i+48);
	}
}
