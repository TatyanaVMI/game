#include <iostream>
using namespace std;

int field[4][4];

int empty_x, empty_y;

enum keys {LEFT, RIGHT, UP, DOWN};

void create_field()
{
	bool num_is_free[15];				// массив логических переменных; показывает, зан€то ли число NumIsFree[i]
	int numbers[15];					// массив кост€шек
	 					
 	for (int i = 0; i < 15; i++) 	// все номера кост€шек свободны
  		num_is_free[i] = true;
	 
	bool free;
	int random_number; 
 	for (int i = 0; i < 15; i++) 	// генерируем кост€шки
 	{
  		free = false;
  		while (!free)
  		{
  			random_number = (rand() %15)+1; 
  			if (num_is_free[random_number-1]) // если такой номер кост€шки свободен
  				free = true;
  		}
  		numbers[i] = random_number;
  		num_is_free[random_number-1] = false;
 	}
 	
 	for (int i = 0; i < 15; i++)		// переводим список кост€шек в вид матрицы
  		field[i % 4][i / 4] = numbers[i]; 
 
 	field[3][3] = 0;
 	empty_x = 3; empty_y = 3;
}

void draw_field() 
{
	system("cls"); 
	
	for (int j = 0; j < 4; j++) 		// рисуем 4 строки кост€шек
  	{
  		// верхн€€ часть одного р€да
  		for (int i = 0; i < 4; i++) 
   		{
   			if (field[i][j])
    			cout << "++++";
   			else
    			cout << " ";
   		}
  		cout << '\n';
  	
		// средн€€ часть одного р€да
		for (int i = 0; i < 4; i++) 		// сроки с номерами €чеек
   		{
   			if (field[i][j])
    		{
    			cout << "+";
    			cout.width(2);
    			cout << field[i][j] << "+";
    		}
   			else
    			cout << " ";
   		}
  		cout << '\n';
  	
		// нижн€€ часть одного р€да
		for (int i = 0; i < 4; i++) 
   		{
   			if (field[i][j])
    			cout << "++++";
   			else
    			cout << " " ;
   		}
  		cout << '\n';
  }
}

bool field_is_right()
{
	for (int i = 0; i < 15; i++)
  	if (field[i % 4][i / 4] != i+1)
   		return false; 
 	return true;
}

void shift (keys k)
{
	switch (k)
	{
		case LEFT:
		{
   			if (empty_x < 3)
    		{
    			field[empty_x][empty_y] = field[empty_x + 1][empty_y];
    			field[empty_x + 1][empty_y] = 0;
    			empty_x++;
    		}
   		} break;
  
  		case UP:
   		{
   			if (empty_y < 3)
    		{
    			field[empty_x][empty_y] = field[empty_x][empty_y + 1];
    			field[empty_x][empty_y + 1] = 0;
    			empty_y++;
    		}
   		} break;
  
  		case RIGHT:
   		{
   			if (empty_x > 0)
    		{
    			field[empty_x][empty_y] = field[empty_x - 1][empty_y];
    			field[empty_x - 1][empty_y] = 0;
    			empty_x--;
    		}
  		} break;
  
  		case DOWN:
   		{
   			if (empty_y > 0)
    		{
    			field[empty_x][empty_y] = field[empty_x][empty_y - 1];
    			field[empty_x][empty_y - 1] = 0;
    			empty_y--;
    		}
   		} break;
  	}
}

main ()
{
	create_field();
	draw_field();
	
	char c;
	while (!field_is_right())
	{
		cin >> c;
		switch(c)
		{
			case 75: shift(LEFT); break; 		// "влево"		
			case 72: shift(UP); break; 			// "вверх"
			case 77: shift(RIGHT); break; 		// "вправо"
			case 80: shift(DOWN); break; 		// "вниз"
			case 27: return 0; 					// "ESC"
		}
		draw_field();
	}
}
