#include <iostream>
using namespace std;

int Field[4][4];

int EmptyX, EmptyY;

void CreateField()
{
	int Nums[15];					// ������ ��������
	 					
 	int RandNum; 
 	for (int i = 0; i < 15; i++) 	// ���������� ��������
 	{
  		RandNum = (rand() %15) + 1; 
  		Nums[i] = RandNum; 
 	}
 	
 	for (int i = 0; i < 15; i++)		// ��������� ������ �������� � ��� �������
  		Field[i % 4][i / 4] = Nums[i]; 
 
 	Field[3][3] = 0;
 	EmptyX = 3; EmptyY = 3;
}




main ()
{
	CreateField ();
	
}
