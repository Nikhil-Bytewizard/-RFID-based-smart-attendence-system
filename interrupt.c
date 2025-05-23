#include <LPC21XX.H>
#include "header_all.h"
void eint0_handler(void)__irq
{
count2++;
EXTINT=1;
VICVectADDR=0;
}
void config_vic_for_eint0(void)
{
VICIntSelect=0;											//all intr's are irq's
VICVectCntl=141|(1<<15);						//slot0 init
VICVectAddr0=(int)eint0_handler;		
VICVectADDR=(1<<14);								//enable Eint0
}
void config_eint0(void)
{
PINSEL |=1;					//p0.16 is eint0
EXTMODE=1;					//eint0 is edge triggering
EXTPOLAR=0;					//eint0 is level handling
}
