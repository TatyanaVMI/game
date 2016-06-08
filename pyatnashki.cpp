#include <iostream>
using namespace std;

int Field[4][4];

int EmptyX, EmptyY;

void CreateField()
{
	int Nums[15];					// массив кост€шек
	 					
 	int RandNum; 
 	for (int i = 0; i < 15; i++) 	// генерируем кост€шки
 	{
  		RandNum = (rand() %15) + 1; 
  		Nums[i] = RandNum; 
 	}
 	
 	for (int i = 0; i < 15; i++)		// переводим список кост€шек в вид матрицы
  		Field[i % 4][i / 4] = Nums[i]; 
 
 	Field[3][3] = 0;
 	EmptyX = 3; EmptyY = 3;
}

void DrawField() 
{
	system("cls"); 
 	
	
	for (int j = 0; j < 4; j++) 		// рисуем 4 строки кост€шек
  	{
  		// верхн€€ часть одного р€да
  		for (int i = 0; i < 4; i++) 
   		{
   			if (Field[i][j])
    			cout << "++++";
   			else
    			cout << " ";
   		}
  		cout << '\n';
  	
	
		// средн€€ часть одного р€да
		for (int i = 0; i < 4; i++) 		// сроки с номерами €чеек
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
  	
  	
		// нижн€€ часть одного р€да
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
