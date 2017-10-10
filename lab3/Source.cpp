#include<iostream>
#include<fstream>
#include<io.h>
using namespace std;

struct MyStruct
{
	long int a1, a2, a3, a4, a5;
}; 

void input_text(char* fin1,char* fout1){
	MyStruct a;
	ifstream fin(fin1);
	ofstream fout(fout1, ios::binary | ios::out);
	while (!fin.eof()) {
		fin >> a.a1;
		fin >> a.a2;
		fin >> a.a3;
		fin >> a.a4;
		fin >> a.a5;
		fout.write((char*)&a, sizeof a);
	}
    fout.close();
	fin.close();
}
void screenout(char *fname){
	MyStruct a;
	ifstream in(fname, ios::binary | ios::in);
	while (!in.eof()) {
		in.read((char*)&a, sizeof a);
		cout << a.a1 << " ";
		cout << a.a2 << " ";
		cout << a.a3 << " ";
		cout << a.a4 << " ";
		cout << a.a5 << endl;
	}
	in.close();
};


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "rus");
	input_text(argv[1], argv[2]);
	screenout(argv[2]);
	cout << "После преобразования" << endl;
	/*MyStruct aa,bb,cc;
	int n1 = 1;
	int n2 = 2; 
	std::ifstream fout(argv[2], std::ifstream::binary);
	int l = sizeof aa;
	fout.seekg(l*(n1-1) , ios::beg);
	fout.read((char*)&aa, sizeof aa);
	cc = aa;
	fout.seekg(l*(n2 - 1), ios::beg);
	fout.read((char*)&bb, sizeof bb);
	aa = bb; 
	fout.seekg(l*(n2 - 1), ios::beg);
	fout.write((char*)&cc, sizeof cc);
	fout.seekg(l*(n2 - 1), ios::beg);
	fout.write((char*)&bb, sizeof bb);
	fout.close();
	fout.close();
	screenout(argv[2]);*/
	system("pause");
	return 0;
}
 