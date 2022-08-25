/**
 * @file main.c
 * @author Aaron Meek (aharon.meek@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-24 
 */

#define PER_BASE			(0x40000000UL)

#define AHB1_PER_OFFSET		(0x00020000UL)
#define AHB1_PER_BASE		(PER_BASE + AHB1_PER_OFFSET)

#define GPIOA_OFFSET		(0x00UL)
#define GPIOA_BASE			(AHB1_PER_BASE + GPIOA_OFFSET)

#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1_PER_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int*)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET		(0X00UL)
#define GPIOA_MODE_R		(*(volatile unsigned int*)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET			(0x14UL)
#define GPIOA_OD_R			(*(volatile unsigned int*)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN				(1U<<0)

#define PIN5				(1U<<5)
#define LED_PIN				(PIN5)

#define WAIT				(125000)
#define DASH				(250000)
#define DOT					(10000)

void n_calls(void (*fptr)(), unsigned n);
void space();
void init_blink();
void dot();
void dash();
void A();
void B();
void C();
void D();
void E();
void F();
void G();
void H();
void I();
void J();
void K();
void L();
void M();
void N();
void O();
void P();
void Q();
void R();
void S();
void T();
void U();
void V();
void W();
void X();
void Y();
void Z();
void display(char *str);

int main()
{
	char char_arr[] = "Hello my friends!";
	// 1. Enable clock access to GPIOA
	RCC_AHB1EN_R |= GPIOAEN;

	// 2. Set PA5 as output pin
	GPIOA_MODE_R |= (1U<<10); // set only bit 10 to 1
	GPIOA_MODE_R &=~(1U<<11); // set only bit 11 to 0
	n_calls(space, 3);
	init_blink();
	n_calls(space, 3);

	display(char_arr);
}

/********************************************************/
void n_calls(void (*fptr)(), unsigned n)
{
	for(int i = 0; i < n; ++i)
	{
		fptr();
	}
}

void space()
{
	for(unsigned int i = 0; i < WAIT; ++i);
}
void init_blink()
{
	GPIOA_OD_R &=~LED_PIN;
	for(int i = 0; i < 6; ++i)
	{
		GPIOA_OD_R ^= LED_PIN;
		space();
	}
}
void dot()
{
	GPIOA_OD_R ^= LED_PIN;
	for(int i = 0; i < DOT; ++i);
	GPIOA_OD_R ^= LED_PIN;
	n_calls(space, 2);
}
void dash()
{
	GPIOA_OD_R ^= LED_PIN;
	for(int i = 0; i < DASH; ++i);
	GPIOA_OD_R ^= LED_PIN;
	n_calls(space, 2);
}
void A()
{
	dot();
	dash();
	n_calls(space, 2);
}
void B()
{
	dash();
	n_calls(dot, 3);
	n_calls(space, 2);
}
void C()
{
	dash();
	dot();
	dash();
	dot();
	n_calls(space, 2);
}
void D()
{
	dash();
	n_calls(dot, 2);
	n_calls(space, 2);
}
void E()
{
	dot();
	n_calls(space, 2);
}
void F()
{
	n_calls(dot, 2);
	dash();
	dot();
	n_calls(space, 2);
}
void G()
{
	n_calls(dash, 2);
	dot();
	n_calls(space, 2);
}
void H()
{
	n_calls(dot, 4);
	n_calls(space, 2);
}
void I()
{
	n_calls(dot, 2);
	n_calls(space, 2);
}
void J()
{
	dot();
	n_calls(dash, 3);
	n_calls(space, 2);
}
void K()
{
	dash();
	dot();
	dash();
	n_calls(space, 2);
}
void L()
{
	dot();
	dash();
	n_calls(dot, 2);
	n_calls(space, 2);
}
void M()
{
	n_calls(dash, 2);
	n_calls(space, 2);
}
void N()
{
	dash();
	dot();
	n_calls(space, 2);
}
void O()
{
	n_calls(dash, 3);
	n_calls(space, 2);
}
void P()
{
	dot();
	n_calls(dash, 2);
	dot();
	n_calls(space, 2);
}
void Q()
{
	n_calls(dash, 2);
	dot();
	dash();
	n_calls(space, 2);
}
void R()
{
	dot();
	dash();
	dot();
	n_calls(space, 2);
}
void S()
{
	n_calls(dot, 3);
	n_calls(space, 2);
}
void T()
{
	dash();
	n_calls(space, 2);
}
void U()
{
	n_calls(dot, 2);
	dash();
	n_calls(space, 2);
}
void V()
{
	n_calls(dot, 3);
	dash();
	n_calls(space, 2);
}
void W()
{
	dot();
	n_calls(dash, 2);
	n_calls(space, 2);
}
void X()
{
	dash();
	n_calls(dot, 2);
	dash();
	n_calls(space, 2);
}
void Y()
{
	dash();
	dot();
	n_calls(dash, 2);
	n_calls(space, 2);
}
void Z()
{
	n_calls(dash, 2);
	n_calls(dot, 2);
	n_calls(space, 2);
}

void display(char *str)
{
	for(int i = 0; str[i]; ++i)
	{
		switch (str[i])
		{
		case 'A':
			A();
			break;
		case 'B':
			B();
			break;
		case 'C':
			C();
			break;
		case 'D':
			D();
			break;
		case 'E':
			E();
			break;
		case 'F':
			F();
			break;
		case 'G':
			G();
			break;
		case 'H':
			H();
			break;
		case 'I':
			I();
			break;
		case 'J':
			J();
			break;
		case 'K':
			K();
			break;
		case 'L':
			L();
			break;
		case 'M':
			M();
			break;
		case 'N':
			N();
			break;
		case 'O':
			O();
			break;
		case 'P':
			P();
			break;
		case 'Q':
			Q();
			break;
		case 'R':
			R();
			break;
		case 'S':
			S();
			break;
		case 'T':
			T();
			break;
		case 'U':
			U();
			break;
		case 'V':
			V();
			break;
		case 'W':
			W();
			break;
		case 'X':
			X();
			break;
		case 'Y':
			Y();
			break;
		case 'Z':
			Z();
			break;
		default:
			break;
		}
	}
}
