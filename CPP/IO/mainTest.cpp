#include "asciiIO_t.h"
#include "binIO_t.h"

template <class T>
void writeTest(virtIO_t* vir){
	T i;	
	char c=' ';
	cin >> i;
	(*vir)<< i << c;
}

template <class T>
void readTest(virtIO_t* vir){
	T i;	
	(*vir) >> i;
	cout << i << " ";
}

void vpTestWrite(virtIO_t* vir){
	binIO_t* fp=dynamic_cast<binIO_t*>(vir);
	if(fp!=0){
		char arr[10]={'a','b','c','d','e','f','g','h','i','j'};		
		(*fp)<<arr,sizeof(arr);
	}
	else{
		cout << "wrong operation" << endl;
	}
}

void vpTestRead(virtIO_t* vir){
	binIO_t* fp=dynamic_cast<binIO_t*>(vir);
	if(fp!=0){	
		char arr[10];
		(*fp)>>arr,sizeof(arr);
		for (unsigned int i=0; i<sizeof(arr);i++){
			cout << arr[i];
		}
	}
	else{
		cout << "wrong operation";
	}
	cout << endl;
}

int chooseVar(){ 
	cout << "0.exit" << endl;
	cout << "1.int" << endl; 
	cout << "2.long" << endl; 
	cout << "3.float" << endl; 
	cout << "4.char" << endl; 
	cout << "5.double" << endl; 
	cout << "6.pointer" << endl;
	int i; 
	cin >> i;
	return i;
}

void readToFile(virtIO_t* vir){	
	int i;	
	do{
		i=chooseVar();
		switch (i){
			case 1: readTest<int>(vir); break;
			case 2: readTest<long>(vir); break;
			case 3: readTest<float>(vir); break;
			case 4: readTest<char>(vir); break;
			case 5: readTest<double>(vir); break;
			case 6: vpTestRead(vir); break;
			default: break;
		}
	}while(i);
}

void writeToFile(virtIO_t* vir){	
	int i;	
	do{
		i=chooseVar();
		switch (i){
			case 1: writeTest<int>(vir); break;
			case 2: writeTest<long>(vir); break;
			case 3: writeTest<float>(vir); break;
			case 4: writeTest<char>(vir); break;
			case 5: writeTest<double>(vir); break;
			case 6: vpTestWrite(vir); break;
			default: break;
		}
	}while(i);
}


void fileTest(virtIO_t* vir){
	string fname;
	string faccess;
	cout << "enter filename" << endl;
	cin >> fname;
	cout << "enter access" << endl;
	cin >> faccess;
	vir->Fopen(fname.c_str(),faccess.c_str());
	if (vir->getStatus()!=virtIO_t::ok_e){
		cout << "wrong name or access" << endl;
		vir->Fclose();
		return;
	}
	char c;
	while(1){
		cout << "read(r) || write(w) || get pos(g) || set pos(s) || get length(l) || back(b)? " << endl;
		cin >> c;
		bool f=0;
		try{
			switch (c){
				case 'r': readToFile(vir); break;
				case 'w': writeToFile(vir); break;
				case 'g': cout << vir->getPosition() << endl; break;
				case 's': size_t s; cin >> s; vir->setPosition(s); break;
				case 'l': cout << vir->getfileLen() << endl; break;
				default: f=1; break;
			}
		}catch(int ex){
				cout << "bad access" << endl;
			}
		if(f) break;
	}
	vir->Fclose();	
}
int main(){
	int i = 1;
	while(i){
		cout << "choose a - ascii | b - binary | e - exit " << endl;
		char c;
		cin >> c;
		if(c=='a'){
			asciiIO_t a1;
			fileTest(&a1);
		}
		else if(c=='b'){
			binIO_t b1;
			fileTest(&b1);
		}
		else{
			i = 0;
			
		}
	}
	return 0;
}