#include <iostream>
#include <string.h>
#include <cstring>

using namespace std ;
/////////////
//Structure//
/////////////
struct File {
    char *Date;
    char *Time;
    char *Name;
    int Size;
};
int sz;



/*void init(File *f) {
    f->Name = NULL;
    f->Date = NULL;
    f->Time = NULL;
}*/

void readData(int i,int n, char *Name, char *Date, char *Time){

        cout << "Enter name of file " << i+1 << ": ";
        cin >> Name;
        cout << "Enter date of file " << i+1 << ": ";
        cin >> Date;
        cout << "Enter time of file " << i+1 << ": ";
        cin >> Time;
        cout << "Enter size of file " << i+1 << ": ";
        cin >> sz;
        cout << "" << endl;

    return ;
}
void writeData(int n,File *f){
    int i;
    for (i = 0; i < n; i++) {
        cout << "Name of file " << i + 1 << " is " << f->Name << endl;
        cout << "Date of file " << i + 1 << " is " << f->Date << endl;
        cout << "Time of file " << i + 1 << " is " << f->Time << endl;
        cout << "Size of file " << i + 1 << " is " << f->Size << endl;
        cout << endl;
    }
}
void setFile(File *f, char *newN, char *newD, char *newT, int newS){

    if(f->Name)
        delete[]f->Name;
    f->Name = new char[strlen(newD)+1];
    strcpy(f->Name, newN);

    if(f->Date)
        delete[]f->Date;
    f->Date = new char[strlen(newT)+1];
    strcpy(f->Date, newD);

    if(f->Time)
        delete[]f->Time;
    f->Time = new char[strlen(newN)+1];
    strcpy(f->Time, newT);

    f->Size = newS;

}

void Destroy(File *f){
    delete[] f->Date;
    f->Date = NULL;

    delete[] f->Time;
    f->Time = NULL;

    delete[] f->Name;
    f->Name = NULL;
}

int main(){
    int option;
    File **f = NULL;
    f = (File **) malloc(sizeof(File*));

    while (true) {
        cout << "    -= Menu =-" << endl;
        cout << "------------------" << endl;
        cout << "1.Set files" << endl;
        cout << "2.Show database" << endl;
        cout << "3.Edit files" << endl;
        cout << "4.Sort" << endl;
        cout << "5.Delete database" << endl;
        cout << "5.Exit" << endl;
        cout << "------------------" << endl;
        cout << "Enter you option: "<< endl;
        cin >> option;
        switch (option) {
            case 1:
                int n,i;
                char Name[255], Date[255], Time[255];
                cout << "Enter number of file :";
                cin >> n;
                f = (File **) realloc(f, n*sizeof(File*));
                if(f){
                    cout << sizeof(f)<< endl;
                }
                for (i=0;i<n;i++){
                    //init(f[i]);
                    readData(i,n,Name,Date,Time);
                    setFile(f[i],Name,Date,Time,sz);
                }
                break;

            case 2:
                writeData(n,f[i]);
                break;

            default:break;
        }
    }


    return 0;
}




