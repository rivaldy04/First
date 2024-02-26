#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Biodata{
    public:
    string nama;
    string cita;
    string hobi;

        Biodata(string inputnama, string inputcita, string inputhobi){
            Biodata::nama = inputnama;
            Biodata::cita = inputcita;
            Biodata::hobi = inputhobi;
        }

        string DidalamFile(){
            return "\n" + nama + " " + cita + " " + hobi;
        }    
};

class DaBase{
    public:
    ifstream in;
    ofstream out;
    string file;

        DaBase(const char* file){
            DaBase::file = file;
        }

        void simpan(Biodata data){
            DaBase::out.open(DaBase::file,ios::app);
            DaBase::out << data.DidalamFile();
            DaBase::out.close();
        }

        void tampil(){
            DaBase::in.open(DaBase::file,ios::in);
            string nama,cita,hobi;
            int index = 1;
            
            while(!DaBase::in.eof()){
                DaBase::in >> nama;
                DaBase::in >> cita;
                DaBase::in >> hobi;
                cout << index++ << ".\t";
                cout << nama << "\t";
                cout << cita << "\t";
                cout << hobi << endl;
            }
            DaBase::in.close();
        }

};

int main(){

DaBase Data = DaBase("Data.txt");

char jawaban;
    e10 :
    string nama, cita, hobi;
    cout << "BIODATA" << endl;
    cout << "Nama : "; cin >> nama;
    cout << "Cita-cita : "; cin >> cita;
    cout << "Hobi : "; cin >> hobi;
    Biodata manusia = Biodata(nama,cita,hobi);

    cout<<endl;
    Data.simpan(manusia);

    e20 :
    cout << "Ingin tambah lagi? (Y/N)" << endl;
    cout << "Jawaban : ";cin>>jawaban;
    cout << endl;
    if(jawaban == 'Y' || jawaban == 'y'){
        goto e10;
    }else if (jawaban == 'N' || jawaban == 'n'){
        Data.tampil();
    }else {
        cout<< "salah" << endl;
        goto e20;
    }

return 0;
}