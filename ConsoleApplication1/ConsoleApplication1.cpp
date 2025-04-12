#include <stdio.h>
#include <locale.h>
#include <cstdlib>
int binaryNum[32];
void decToBinary(int n)
{
	// counter for binary array
	int i = 0;
	while (n > 0) {
		// storing remainder in binary array
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
}
int outputEax()
{
	
	printf("\nStepping ID:%d%d%d%d", binaryNum[3], binaryNum[2], binaryNum[1], binaryNum[0]);
	printf("\nModel:%d%d%d%d", binaryNum[7], binaryNum[6], binaryNum[5], binaryNum[4]);
	printf("\nFamily ID:%d%d%d%d", binaryNum[11], binaryNum[10], binaryNum[9], binaryNum[8]);
	printf("\nProcessor Type:%d%d", binaryNum[13], binaryNum[12]);
	printf("\nExtended Model ID:%d%d%d%d", binaryNum[19], binaryNum[18], binaryNum[17], binaryNum[16]);
	printf("\nExtended Family ID:%d%d%d%d%d%d%d%d", binaryNum[27], binaryNum[26], binaryNum[25], binaryNum[24], binaryNum[23], binaryNum[22], binaryNum[21], binaryNum[20]);
	printf("\n");
	return 0;
}
int func_eax0()
{
	printf("\n________EAX=0_________\n");
	int a[3];
	_asm
	{
		mov eax, 0
		cpuid;
		mov esi, 0;
		mov a[esi], ebx;
		mov a[esi + 4], edx;
		mov a[esi + 8], ecx;
	}
	printf("%.*s%.*s%.*s\n", 4, &a[0], 4, &a[1], 4, &a[2]);
	return 0;
}
int func_eax1() 
{
	printf("\n________EAX=1_________\n");
	int a[4];
	_asm
	{
		mov eax, 1;
		cpuid;
		mov esi, 0;
		mov a[esi], eax;
		mov a[esi + 4], ebx;
		mov a[esi + 8], ecx;
		mov a[esi + 12], edx;
	}
	decToBinary(a[0]);
	outputEax();
	return 0;
}
int func_eax2() 
{
	printf("\n________EAX=2_________\n");
	int a[4];
	_asm
	{
		mov eax, 2;
		cpuid;
		mov esi, 0;
		mov a[esi], eax;
		mov a[esi + 4], ebx;
		mov a[esi + 8], ecx;
		mov a[esi + 12], edx;
	}
	printf("eax=%x\n", a[0]);
	printf("ebx=%x\n", a[1]);
	printf("ecx=%x\n", a[2]);
	printf("edx=%x\n", a[3]);
	return 0;
}
int func_eax3() 
{
	printf("\n________EAX=3_________\n");
	int a[4];
	for (int b = 0; b < 3; b++)
	{
		if (b==0 )
			_asm
		{
			mov eax, 80000002h;// 80000003h, 80000004h
		}
		if (b == 1)
		_asm
		{
			mov eax, 80000003h;// 80000003h, 80000004h
		}
		if (b == 2)
		_asm
		{
			mov eax, 80000004h;// 80000003h, 80000004h 
		}
		_asm{
			cpuid;
			mov esi, 0;
			mov a[esi], eax;
			mov a[esi + 4], ebx;
			mov a[esi + 8], ecx;
			mov a[esi + 12], edx;
		}
		printf("%.*s%.*s%.*s%.*s", 4, &a[0], 4, &a[1], 4, &a[2], 4, &a[3]);
	}
	
	printf("\n");
	return 0;
}

int main()
{

	func_eax0();
	func_eax1();
	func_eax2();
	func_eax3();
	return 0;
}