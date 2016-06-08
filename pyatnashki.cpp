#include <iostream>
using namespace std;

int Field[4][4];

int EmptyX, EmptyY;

void CreateField()
{
	bool NumIsFree[15];				// массив логических переменных; показывает, занято ли число NumIsFree[i]
	int Nums[15];					// массив костяшек
	 					
 	for (int i = 0; i < 15; i++) 	// все номера костяшек свободны
  		NumIsFree[i] = true;
	 
	bool free;
	int RandNum; 
 	for (int i = 0; i < 15; i++) 	// генерируем костяшки
 	{
  		free = false;
  		while (!free)
  		{
  			RandNum = (rand() %15) + 1; 
  			if (NumIsFree[RandNum - 1]) // если такой номер костяшки свободен
  				free = true;
  		}
  		Nums[i] = RandNum;
  		NumIsFree[RandNum - 1] = false;
 	}
 	
 	for (int i = 0; i < 15; i++)		// переводим список костяшек в вид матрицы
  		Field[i % 4][i / 4] = Nums[i]; 
 
 	Field[3][3] = 0;
 	EmptyX = 3; EmptyY = 3;
}

void DrawField() 
{
	system("cls"); 
 	
	
	for (int j = 0; j < 4; j++) 		// рисуем 4 строки костяшек
  	{
  		// верхняя часть одного ряда
  		for (int i = 0; i < 4; i++) 
   		{
   			if (Field[i][j])
    			cout << "++++";
   			else
    			cout << " ";
   		}
  		cout << '\n';
  	
		// средняя часть одного ряда
		for (int i = 0; i < 4; i++) 		// сроки с номерами ячеек
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
  	
		// нижняя часть одного ряда
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
