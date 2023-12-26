#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>

class DATA
{
	protected:
		int **arr;
		int M_rows, N_cols;
	public:
		DATA();
		DATA(const int M_rows, const int N_cols);
		~DATA();
		void show ();
		virtual void setter(std::string obj) = 0;
};


class File : public DATA
{
	public:
		virtual void setter(std::string obj) override;
		File(int M, int N, std::string obj);
};

/*class Http : public DATA
{
public:
		virtual void setter(std::string obj) override;
		Http(int M, int N, std::string obj);
};*/

class Search : public File
{
	public:
		virtual void search_the_element(int value) = 0 ;
		Search(int M, int N, std::string obj);
};

class linear_search : public Search
{
	public:
		void search_the_element(int value) override;
		linear_search(int M, int N, int value, std::string obj);
};

class gradient_search : public Search
{
	public:
		void search_the_element(int value) override;
		gradient_search(int M, int N, int value, std::string obj);
};

class binary_search : public Search
{
	public:
		void search_the_element(int value) override;
		binary_search(int M, int N, int value, std::string obj);
};
#endif