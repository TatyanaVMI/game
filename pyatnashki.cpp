#include <iostream>
using namespace std;

int field[4][4];

int EmptyX, EmptyY;

void CreateField()
{
	int Nums[15]; 					// массив кост€шек
 	int RandNum; 
 	for (int i = 0; i < 15; i++) 	// генерируем кост€шки
 	{
  		RandNum = (rand() %15) + 1; 
  		Nums[i] = RandNum; 
 	}
}

main ()
{
	CreateField ();
	
}
