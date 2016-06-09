#include <iostream>
using namespace std;

int field[4][4];

int empty_x, empty_y;

void create_field()
{
	bool num_is_free[15];				// ������ ���������� ����������; ����������, ������ �� ����� NumIsFree[i]
	int numbers[15];					// ������ ��������
	 					
 	for (int i = 0; i < 15; i++) 	// ��� ������ �������� ��������
  		num_is_free[i] = true;
	 
	bool free;
	int random_number; 
 	for (int i = 0; i < 15; i++) 	// ���������� ��������
 	{
  		free = false;
  		while (!free)
  		{
  			random_number = (rand() %15)+1; 
  			if (num_is_free[random_number-1]) // ���� ����� ����� �������� ��������
  				free = true;
  		}
  		numbers[i] = random_number;
  		num_is_free[random_number] = false;
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
   			if (field[i][j])
    			cout << "++++";
   			else
    			cout << " ";
   		}
  		cout << '\n';
  	
		// ������� ����� ������ ����
		for (int i = 0; i < 4; i++) 		// ����� � �������� �����
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
  	
		// ������ ����� ������ ����
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
			
		}
		draw_field();
	}
}
