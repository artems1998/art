#include<iostream>
#include<fstream>
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

void obmen(char* fname, int n1, int n2) {
	MyStruct aa, bb;
	int l = sizeof aa;
	std::ifstream fout(fname, std::ifstream::binary);
	fout.seekg(l*(n2 - 1), ios::beg);
	fout.read((char*)&aa, sizeof aa);
	fout.seekg(l*(n1 - 1), ios::beg);
	fout.read((char*)&bb, sizeof bb);
	fout.close();
	ofstream s;
	s.open(fname, ios::in | ios::binary);
	s.seekp(l*(n2 - 1), ios::beg);
	s.write((char*)&bb, sizeof bb);
	s.seekp(l*(n1 - 1), ios::beg);
	s.write((char*)&aa, sizeof aa);
	s.close();
}


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "rus");
	input_text(argv[1], argv[2]);
	screenout(argv[2]);
	int n1;
    int n2;
	cin >> n1 >> n2;
	cout << "После преобразования" << endl;
	obmen(argv[2], n1, n2);
	screenout(argv[2]);
	system("pause");
	return 0;
}
 