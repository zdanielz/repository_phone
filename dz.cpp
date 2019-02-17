#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;
/* sostavlyaet spisok DZ
   i vivodit ego */

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "RUS");
	ifstream domashka;
	domashka.open("./dz.txt");
	domashka.seekg(0,ios_base::beg);
	vector<string> dz;
	if(argc != 1){
		for(int i = 1; i < argc+1; i++){
			if(i == 1){ continue; }
			dz.push_back(argv[i - 1]);
		}
	}
	if(domashka.is_open()){
		string bufer = "-";
		while(!bufer.empty()){
			getline(domashka,bufer);
		        dz.push_back(bufer);
		}	
	}
	else{
		cout << "!!error!!" << endl;
		return 0;
	}
	restart:
	cout << "-----------------------------" << endl;
	for(int i = 0; i < dz.size(); i++){
		cout << dz[i] << endl;
	}
	cout << "\n\n\n" << "udalit chtoto?\nesli net vvedite 0\nesli da to vvedite nomer : ";
	int delet = 0;
	cin >> delet;
	if(delet !=  0){
		dz.erase(dz.begin() + delet - 1);
		cout << "\n\n";
		goto restart;
	}		
	domashka.close();
	remove("dz.txt");
	ofstream domashka2("dz.txt");
	for(int i = 0; i < dz.size(); i++){
		string s = dz[i];
		domashka2 << s << "\n";
	}
	domashka2.close();
}














