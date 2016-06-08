#include <iostream>
using namespace std;

int Field[4][4];

int EmptyX, EmptyY;

void CreateField()
{
	bool NumIsFree[15];				// ������ ���������� ����������; ����������, ������ �� ����� NumIsFree[i]
	int Nums[15];					// ������ ��������
	 					
 	for (int i = 0; i < 15; i++) 	// ��� ������ �������� ��������
  		NumIsFree[i] = true;
	 
	bool free;
	int RandNum; 
 	for (int i = 0; i < 15; i++) 	// ���������� ��������
 	{
  		free = false;
  		while (!free)
  		{
  			RandNum = (rand() %15) + 1; 
  			if (NumIsFree[RandNum - 1]) // ���� ����� ����� �������� ��������
  				free = true;
  		}
  		Nums[i] = RandNum;
  		NumIsFree[RandNum - 1] = false;
 	}
 	
 	for (int i = 0; i < 15; i++)		// ��������� ������ �������� � ��� �������
  		Field[i % 4][i / 4] = Nums[i]; 
 
 	Field[3][3] = 0;
 	EmptyX = 3; EmptyY = 3;
}

void DrawField() 
{
	system("cls"); 
 	
	
	for (int j = 0; j < 4; j++) 		// ������ 4 ������ ��������
  	{
  		// ������� ����� ������ ����
  		for (int i = 0; i < 4; i++) 
   		{
   			if (Field[i][j])
    			cout << "++++";
   			else
    			cout << " ";
   		}
  		cout << '\n';
  	
		// ������� ����� ������ ����
		for (int i = 0; i < 4; i++) 		// ����� � �������� �����
   		{
   			if (Field[i][j])
    		{
    			cout << "+";
    			cout.width(2);
    			cout << Field[i][j] << "+";
    		}
   			else
    			cout << " ";
   		}
  		cout << '\n';
  	
		// ������ ����� ������ ����
		for (int i = 0; i < 4; i++) 
   		{
   			if (Field[i][j])
    			cout << "++++";
   			else
    			cout << " " ;
   		}
  		cout << '\n';
  }
}


main ()
{
	CreateField ();
	DrawField ();
}
