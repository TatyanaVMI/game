#include <iostream>

int field[4][4];

int EmptyX, EmptyY;

void CreateField()
{
	int Nums[15]; 					// ������ ��������
 	int RandNum; 
 	for (int i = 0; i < 15; i++) 	// ���������� ��������
 	{
  		RandNum = (rand() %15) + 1; 
  		Nums[i] = RandNum; 
 	}
}

main ()
{
	CreateField ();
	
}