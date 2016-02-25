#include <iostream>
#include <string.h>
#include "functions.h"

using namespace std ;

int sz;
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
        cout << "6.Exit" << endl;
        cout << "------------------" << endl;
        cout << "Enter you option: "<< endl;
        cin >> option;
        switch (option) {
            case 1:
                int n,i;
                char Name[255], Date[255], Time[255];
                cout << "Enter number of file :";
                cin >> n;
                cout << ""<<endl;
                f = (File **) realloc(f, n*sizeof(File*));
                for (i=0;i<n;i++){
                    f[i] = new File;
                    readData(i,Name,Date,Time,sz);
                    setFile(f[i],Name,Date,Time,sz);
                }
                break;

            case 2:
                for (i=0;i<n;i++){
                    writeData(i,f[i]);
                }
                break;

            case 3:
                int num;
                cout << "Which file you want to edit ? " ;
                cin >> num;
                init(f[num-1]);
                readData(num-1,Name,Date,Time,sz);
                setFile(f[num-1],Name,Date,Time,sz);
                break;

            case 4:
                char ch;
                int j;
                File *tmp;
                cout << "Want to sort files ?(y/n) ";
                cin >> ch;
                if (ch == 'y'){
                    for (j=0;j<n-1;j++){
                        for(i=0;i<n-j-1;i++){
                            if(strcmp(f[i]->Name,f[i+1]->Name) > 0){
                                tmp = f[i];
                                f[i] = f[i+1];
                                f[i+1] = tmp;
                            }
                        }
                    }
                }

            case 5:
                for(i=0;i<n;i++){
                    Destroy(f[i]);
                }
                break;

            default:break;
        }
    }


    return 0;
}




