#include "search.h"
#include <iostream>
#include <string>
#include <fstream>
using std::cout;

DATA::DATA()
{
	M_rows = 1;
	N_cols = 1;
	arr = new int *[M_rows];
	arr[0] = new int[N_cols];
	arr[0][0] = 0;
}

DATA::DATA(const int M_rows, const int N_cols)
{
	this -> M_rows = M_rows;
	this -> N_cols = N_cols;
	arr = new int *[M_rows];
	for(int i=0; i < M_rows; ++i)
	{
		arr[i] = new int[N_cols];
	}
	if(!arr)
		cout << "Exeption!";
}
DATA::~DATA()
{
	for(int i=0; i < N_cols ; ++i) 
	{
		delete [] arr[i];
	}
	delete [] arr;
}

void DATA::show()
{
	for(int i = 0; i < M_rows; ++i )
		{
			for(int j = 0; j < N_cols; ++j)
				{
					cout << arr[i][j] ;
				}
		}
}

void File::setter(std::string obj)
{
	std::ifstream pf(obj);
	if (!pf.is_open())
	{
		cout << "Error of the opening File!" << std::endl;
	}
	else
	{
		for (int i = 0; i < M_rows; ++i)
		{
			for(int j = 0; j < N_cols; ++j)
			{
					pf >> arr[i][j];
			}
		}
	}
	pf.close();
}

File::File(int M, int N, std::string obj):DATA(M,N)
{
	setter(obj);
}

void linear_search::search_the_element(int value) 
{
	for (int i = 0; i < M_rows; ++i)
		{
			for(int j=0; j < N_cols; ++j)
				{
					if (arr[i][j] == value)
						{
							cout << "Number " << value << " is located at intersection of the row = " << i << " and column = "<< j << std::endl;
							break;
						}
				}
		}
	
}

Search::Search(int M, int N, std::string obj) : File(M, N, obj) {};

linear_search::linear_search(int M, int N, int value, std::string obj):Search(M, N, obj)
{
	search_the_element(value);
}


void gradient_search::search_the_element(int value) 
{
	int r = 0;
	int c = N_cols - 1;
	while (r < M_rows && c >= 0)
		{
			if (arr[r][c] == value)
				{
					cout << "Number " << value << " is located at intersection of the row = " << r << " and column = "<< c << std::endl;
					break;
				}
			else if (arr[r][c] > value)
				c--;
			else
				r++;
		}
}

gradient_search::gradient_search(int M, int N, int value, std::string obj):Search(M, N, obj)
{
	search_the_element(value);
}

void binary_search::search_the_element(int value)
{
	int a = 0;
	int b = M_rows*N_cols;
	while (abs(a-b)>0)
	{
		int mid = (a + b) / 2;
		int r = mid / N_cols;
		int c = mid % N_cols;
		int tmp = *(*(arr + r) + c);
		if (value == tmp)
		{
			cout << " Number " << value << " is located at intersection of row = " <<  r << " and column =  " << c << std::endl;
			break;
		}
		else if (value > tmp)
		{
			a = mid ;
		}
		else
		{
			b = mid;
		}
	}
}

binary_search::binary_search(int M, int N, int value, std::string obj):Search(M, N, obj)
{
	search_the_element(value);
}




						
