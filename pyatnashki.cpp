#include <iostream>
#include <conio.h>
using namespace std;

int field[4][4];

int empty_x, empty_y;					

enum keys {LEFT, RIGHT, UP, DOWN};

void create_field()
{
	bool num_is_free[15];				// ������ ���������� ����������; ����������, �������� �� ����� NumIsFree[i]
	int numbers[15];					// ������ ��������
	 					
 	for (int i = 0; i < 15; i++) 		
  		num_is_free[i] = true;			// ��� ������ �������� ��������
	 
	bool free;
	int random_number; 
 	for (int i = 0; i < 15; i++) 		// ���������� ��������
 	{
  		free = false;
  		while (!free)
  		{
  			random_number = (rand() %15)+1; 
  			if (num_is_free[random_number-1]) // ���� ����� ����� �������� ��������
  				free = true;
  		}
  		numbers[i] = random_number;
  		num_is_free[random_number-1] = false;
 	}
 	
 	int mess = 0;		// ���������� �����������
 	int curr_numb;		// ������� ��������
 	for (int i=0; i<14; i++)		// ��� ������ �������� ������� ���������� �����������
 	{
 		curr_numb = numbers[i];
 		for (int j = i; j < 15; j++)
 		{
 			if (curr_numb > numbers[j])
 				mess++;
		}
		
		if (mess%2 == 1)		// ���� ���������� ����������� ��������
			swap (numbers[13], numbers[14]);	// ������ ������� 2 ��������� ��������
	}
 	 
	for (int i = 0; i < 15; i++)		// ��������� ������ �������� � ��� �������
  		field[i % 4][i / 4] = numbers[i]; 
 
 	field[3][3] = 0;
 	empty_x = 3; empty_y = 3;
}

void draw_field() 
{
	system("cls"); 
	
	for (int j = 0; j < 4; j++) 		// ������ 4 ������ ��������
  	{
  		// ������� ����� ������ ����
  		for (int i = 0; i < 4; i++) 
   		{
   			if (field[i][j] != 0)
    			cout << "++++";
   			else
    			cout << " ";
   		}
  		cout << '\n';
  	
		// ������� ����� ������ ����
		for (int i = 0; i < 4; i++) 		// ����� � �������� �����
   		{
   			if (field[i][j] != 0)
    		{
    			cout << "+";
    			cout.width(2);
    			cout << field[i][j] << "+";
    		}
   			else
    			cout << " ";
   		}
  		cout << '\n';
  	
		// ������ ����� ������ ����
		for (int i = 0; i < 4; i++) 
   		{
   			if (field[i][j] != 0)
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
   			if (empty_x < 3)		// ���� ������ �������� ����� �� ���������� �����
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
		c = getch ();		// ��������� ��� �������
		switch(c)
		{
			case 75: shift(LEFT); break; 		// "�����"		
			case 72: shift(UP); break; 			// "�����"
			case 77: shift(RIGHT); break; 		// "������"
			case 80: shift(DOWN); break; 		// "����"
		}
		draw_field();
	}
	cout << "�����������! ������� Enter, ����� �����";
}
