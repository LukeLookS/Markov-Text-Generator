#include"../IMarkov/IMarkov.h"
#include<string>
#include"../DLL_Markov/DLL_Markov.h"
#include"../IVector/Vector.h"
#include<ctime>
#include<iostream>
#include<fstream>
using namespace std;


void split(const std::string &s, char delim, Vector<std::string> &elems) {
	string temp;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s.at(i) != delim)
		{
			temp.append(s, i, 1);
			if (i == s.size() - 1)
				elems.addback(temp);
		}
		else if (temp != "")
		{
			elems.addback(temp);
			temp = "";
		}
	}
}

int main() {
	srand(time(0));
	IMarkov<string>* markov = new DLL_Markov<string>();
	std::ifstream file("text.txt");
	std::string str;
	Vector<std::string> elems;
	while (std::getline(file, str))
	{
		split(str, ' ', elems);
	}
	for (int i = 0; i < elems.GetSize() - 1; i++)
	{
		markov->add(elems.get(i), elems.get(i + 1));
	}
	cout << markov->generate(20); 
	system("pause");
}