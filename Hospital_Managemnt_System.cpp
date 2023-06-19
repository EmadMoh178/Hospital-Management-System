#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct doctor{
    int id, age;
    char name[30], spec[30];
};


void writeDoctor(){
    fstream f("Doctor.txt", ios::app);
    doctor d1;
    char c;
    do{
        cout << "Enter ID: ", cin >> d1.id;
        cin.ignore();
        cout << "Enter name: "; cin.getline(d1.name, 30);
        cout << "Enter age: ", cin >> d1.age;
        cin.ignore();
        cout << "Enter Specialization: ", cin.getline(d1.spec, 30);
        f.write((char*) &d1, sizeof(d1));
        cout << "Do you want to add another doctor Y/N? ";
        cin >> c;
    }while(tolower(c) == 'y');
    f.close();
}

void readDoctors(){
    doctor d1;
    ifstream f;
    f.open("Doctor.txt", ios::in);
    if(f.is_open()){
        cout << "----------------------------------\n";
        cout << "ID\tName\tAge\tSpeciality\n";
        cout << "----------------------------------\n";
        f.read((char*) &d1, sizeof(d1));
        while(!f.eof()){
            cout << d1.id << "\t" << d1.name << "\t" << d1.age << "\t" <<  d1.spec <<  "\n";
            f.read((char*) &d1, sizeof(d1));
        }
        f.close();
    }
    else cout << "Cannot open the file!\n";
}

void searchDoctors(){
    doctor d1;
    ifstream f;
    f.open("Doctor.txt", ios::in);
    cout << "Enter Doctor ID: ";
    int key;                cin >> key;
    if(f.is_open()){
        f.read((char*) &d1, sizeof(d1));
        while(!f.eof()){
            if(d1.id == key){
                cout << "ID\tName\tAge\tSpeciality\n";
                cout << "----------------------------------\n";
                cout << d1.id << "\t" << d1.name << "\t" << d1.age << "\t" <<  d1.spec <<  "\n";
                f.close();
                return;
            }
            f.read((char*) &d1, sizeof(d1));
        }
        cout << "Not found !\n";
        f.close();
    }
    else cout << "Cannot open the file!\n";
}

void updateDoctor(){
    doctor d1;
    fstream f;
    f.open("Doctor.txt", ios::in | ios::out);
    cout << "Enter Doctor ID: ";
    int key;                cin >> key;
    if(f.is_open()){
        f.read((char*) &d1, sizeof(d1));
        while(!f.eof()){
            if(d1.id == key){
                cout << "Enter New ID: ";
                cin >> d1.id;
                cin.ignore();
                cout << "Enter new Name: ";
                cin.getline(d1.name, 30);
                cout << "Enter New Age: ";
                cin >> d1.age;
                cin.ignore();
                cout << "Enter new specialization: ";
                cin.getline(d1.spec, 30);
                int pos = f.tellg(), size = sizeof(d1);
                f.seekp(pos - size, ios::beg);
                f.write((char*) &d1, sizeof(d1));
                f.close();
                return;
            }
            f.read((char*) &d1, sizeof(d1));
        }
        cout << "Not found !\n";
        f.close();
    }
    else cout << "Cannot open the file!\n";
}

void deleteDoctor(){
    doctor d1;
    ifstream in;
    ofstream out;
    in.open("Doctor.txt", ios::in);
    out.open("Doctor2.txt", ios::out);
    cout << "Enter Doctor ID: ";
    int key;                cin >> key;
    if(in.is_open()){
        in.read((char*) &d1, sizeof(d1));
        while(!in.eof()){
            if(d1.id != key)
                out.write((char*) &d1, sizeof(d1));
            in.read((char*) &d1, sizeof(d1));
        }
        in.close(), out.close();
        remove("Doctor.txt");
        rename("Doctor2.txt", "Doctor.txt");
    }
    else cout << "Cannot open the file!\n";
}

struct patient{
    int id, age;
    char name[30], disease[20];
};

void writePatient(){
    fstream f("Patient.txt", ios::app);
    patient p1;
    char c;
    do{
        cout << "Enter ID: ", cin >> p1.id;
        cin.ignore();
        cout << "Enter name: "; cin.getline(p1.name, 30);
        cout << "Enter age: ", cin >> p1.age;
        cin.ignore();
        cout << "Enter disease: "; cin.getline(p1.disease, 30);
        f.write((char*) &p1, sizeof(p1));
        cout << "Do you want to add another patient Y/N? ";
        cin >> c;
    }while(tolower(c) == 'y');
    f.close();
    
}

void readPatients(){
    patient p1;
    ifstream f;
    f.open("Patient.txt", ios::in);
    if(f.is_open()){
        cout << "-------------------------------\n";
        cout << "ID\tName\tAge\tDisease\n";
        cout << "-------------------------------\n";
        f.read((char*) &p1, sizeof(p1));
        while(!f.eof()){
            cout << p1.id << "\t" << p1.name << "\t" << p1.age << "\t" <<  p1.disease <<  "\n";
            f.read((char*) &p1, sizeof(p1));
        }
        f.close();
    }
    else cout << "Cannot open the file!\n";
}

void searchPatients(){
    patient p1;
    ifstream f;
    f.open("Patient.txt", ios::in);
    cout << "Enter patient ID: ";
    int key;                cin >> key;
    if(f.is_open()){
        f.read((char*) &p1, sizeof(p1));
        while(!f.eof()){
            if(p1.id == key){
                cout << "ID\tName\tAge\tDisease\n";
                cout << "-------------------------------\n";
                cout << p1.id << "\t" << p1.name << "\t" << p1.age << "\t" <<  p1.disease <<  "\n";
                f.close();
                return;
            }
            f.read((char*) &p1, sizeof(p1));
        }
        cout << "Not found !\n";
        f.close();
    }
    else cout << "Cannot open the file!\n";
}

void updatePatient(){
    patient p1;
    fstream f;
    f.open("Patient.txt", ios::in | ios::out);
    cout << "Enter patient ID: ";
    int key;                cin >> key;
    if(f.is_open()){
        f.read((char*) &p1, sizeof(p1));
        while(!f.eof()){
            if(p1.id == key){
                cout << "Enter new ID: ";
                cin >> p1.id;
                cin.ignore();
                cout << "Enter new name: "; 
                cin.getline(p1.name, 30);
                cout << "Enter new age: ";
                cin >> p1.age;
                cin.ignore();
                cout << "Enter new disease: "; 
                cin.getline(p1.disease, 30);
                int pos = f.tellg(), size = sizeof(p1);
                f.seekp(pos - size, ios::beg);
                f.write((char*) &p1, sizeof(p1));
                f.close();
                return;
            }
            f.read((char*) &p1, sizeof(p1));
        }
        cout << "Not found !\n";
        f.close();
    }
    else cout << "Cannot open the file!\n";
}

void deletePatient(){
    patient p1;
    ifstream in;
    ofstream out;
    in.open("Patient.txt", ios::in);
    out.open("Patient2.txt", ios::out);
    cout << "Enter patient ID: ";
    int key;                cin >> key;
    if(in.is_open()){
        in.read((char*) &p1, sizeof(p1));
        while(!in.eof()){
            if(p1.id != key){
                out.write((char*) &p1, sizeof(p1));
            }
            in.read((char*) &p1, sizeof(p1));
        }
        in.close();
        out.close();
        remove("Patient.txt");
        rename("Patient2.txt", "Patient.txt");
    }
    else cout << "Cannot open the file!\n";
}

struct adminstrator{
    int id, age;
    char name[30], password[30];
};

void writeAdminstrator(){
    fstream f("Adminstrators.txt", ios::app);
    adminstrator a1;
    char c;
    do{
        cout << "-----------\n";
        cout << "|Add admin|\n";
        cout << "-----------\n";
        cout << "Enter ID: ", cin >> a1.id;
        cin.ignore();
        cout << "Enter name: "; cin.getline(a1.name, 30);
        cout << "Enter age: "; cin >> a1.age;
        cin.ignore();
        cout << "Enter password: "; cin.getline(a1.password, 30);
        f.write((char*) &a1, sizeof(a1));
        cout << "Do you want to add another adminstrator Y/N? ";
        cin >> c;
    }while(tolower(c) == 'y');
    f.close();
    
}

void readAdminstrator(){
    adminstrator a1;
    ifstream f;
    f.open("Adminstrators.txt", ios::in);
    if(f.is_open()){
        cout << "--------------------------------\n";
        cout << "ID\tName\tAge\tPassword\n";
        cout << "--------------------------------\n";
        f.read((char*) &a1, sizeof(a1));
        while(!f.eof()){
            cout << a1.id << "\t" << a1.name << "\t" << a1.age << "\t" <<  a1.password <<  "\n";
            f.read((char*) &a1, sizeof(a1));
        }
        f.close();
    }
    else cout << "Cannot open the file!\n";
}

void searchAdminstrators(){
    adminstrator a1;
    ifstream f;
    f.open("Adminstrators.txt", ios::in);
    cout << "Enter adminstrator ID: ";
    int key;                cin >> key;
    if(f.is_open()){
        f.read((char*) &a1, sizeof(a1));
        while(!f.eof()){
            if(a1.id == key){
                cout << "ID\tName\tAge\tPassword\n";
                cout << "-------------------------------\n";
                cout << a1.id << "\t" << a1.name << "\t" << a1.age << "\t" <<  a1.password <<  "\n";
                f.close();
                return;
            }
            f.read((char*) &a1, sizeof(a1));
        }
        cout << "Not found !\n";
        f.close();
    }
    else cout << "Cannot open the file!\n";
}

void updateAdminstrator(){
    adminstrator a1;
    fstream f;
    f.open("Adminstrators.txt", ios::in | ios::out);
    cout << "Enter adminstrator ID: ";
    int key;                cin >> key;
    if(f.is_open()){
        f.read((char*) &a1, sizeof(a1));
        while(!f.eof()){
            if(a1.id == key){
                cout << "Enter new ID: ";
                cin >> a1.id;
                cin.ignore();
                cout << "Enter new name: "; 
                cin.getline(a1.name, 30);
                cout << "Enter new password: "; 
                cin.getline(a1.password, 30);
                int pos = f.tellg(), size = sizeof(a1);
                f.seekp(pos - size, ios::beg);
                f.write((char*) &a1, sizeof(a1));
                f.close();
                return;
            }
            f.read((char*) &a1, sizeof(a1));
        }
        cout << "Not found !\n";
        f.close();
    }
    else cout << "Cannot open the file!\n";
}

void deleteAdminstrator(){
    adminstrator a1;
    ifstream in;
    ofstream out;
    in.open("Adminstrators.txt", ios::in);
    out.open("Adminstrators2.txt", ios::out);
    cout << "Enter adminstrator ID: ";
    int key;                cin >> key;
    if(in.is_open()){
        in.read((char*) &a1, sizeof(a1));
        while(!in.eof()){
            if(a1.id != key){
                out.write((char*) &a1, sizeof(a1));
            }
            in.read((char*) &a1, sizeof(a1));
        }
        in.close();
        out.close();
        remove("Adminstrators.txt");
        rename("Adminstrators2.txt", "Adminstrators.txt");
    }
    else cout << "Cannot open the file!\n";
}

bool isAdminstrator(int ID, char password[]){
    adminstrator a1;
    ifstream f;
    f.open("Adminstrators.txt", ios::in);
    if(f.is_open()){
        f.read((char*) &a1, sizeof(a1));
        while(!f.eof()){
            if(a1.id == ID && strcmp(a1.password, password) == 0){
                f.close();
                return true;
            }
            f.read((char*) &a1, sizeof(a1));
        }
        f.close();
    }
    else cout << "Cannot open the file!\n";
    return false;
}

int main()
{
    // If you're using it for the first time remove comment to add the first Admin
    // writeAdminstrator();
    int id;
    char password[30];
    cout << "Enter adminstrator ID: ";
    cin >> id;
    cout << "Enter adminstrator password: ";
    cin.ignore();
    cin.getline(password, 30);
    if(isAdminstrator(id, password)){
        cout << "---------\n";
        cout << "|Welcome|\n";
        cout << "---------\n";
        int choice = 0;
        while(choice != 4){
            cout << "------------------\n";
            cout << "Choose department\n1. Doctors\n2. Patients\n3. Adminstrators\n4. Exit\n"; 
            cin >> choice;
            switch(choice){
                case 1:{      
                    int ch1 = 0;
                    while(ch1 != 6){
                        cout << "---------\n";
                        cout << "|Doctors|\n";
                        cout << "---------\n";
                        cout << "1. View Doctors\n2. Add Doctors\n3. Search Doctors\n4. Update Doctor\n5. Delete Doctor\n6. Back\n";
                        cin >> ch1;
                        switch(ch1){
                            case 1: 
                                readDoctors();
                                break;
                            case 2: 
                                writeDoctor();
                                break;
                            case 3: 
                                searchDoctors();
                                break;
                            case 4: 
                                updateDoctor();
                                break;
                            case 5: 
                                deleteDoctor();
                                break;
                            case 6: break;
                            default: cout << "Invalid choice!";
                        }
                    }
                }
                break;
                case 2:{
                    int ch2 = 0;
                    while(ch2 != 6){
                        cout << "----------\n";
                        cout << "|Patients|\n";
                        cout << "----------\n";
                        cout << "1. View Patients\n2. Add Patients\n3. Search Patients\n4. Update Patient\n5. Delete Patient\n6. Back\n";  
                        cin >> ch2;
                        switch(ch2){
                            case 1: 
                                readPatients();
                                break;
                            case 2: 
                                writePatient();
                                break;
                            case 3: 
                                searchPatients();
                                break;
                            case 4: 
                                updatePatient();
                                break;
                            case 5: 
                                deletePatient();
                                break;
                            case 6: break;
                            default: cout << "Invalid choice!";
                        }
                    }
                }
                break;
                case 3:{
                    int ch3 = 0;
                    while(ch3 != 6){
                        cout << "---------------\n";
                        cout << "|Adminstrators|\n";
                        cout << "---------------\n";
                        cout << "1. View Adminstrators\n2. Add Adminstrators\n3. Search Adminstrators\n4. Update Adminstrator\n5. Delete Adminstrator\n6. Back\n";
                        cin >> ch3;
                        switch(ch3){
                            case 1: 
                                readAdminstrator();
                                break;
                            case 2: 
                                writeAdminstrator();
                                break;
                            case 3: 
                                searchAdminstrators();
                                break;
                            case 4: 
                                updateAdminstrator();
                                break;
                            case 5: 
                                deleteAdminstrator();
                                break;
                            case 6: break;
                            default: cout << "Invalid choice!";
                        }
                    }
                }
                break;
                case 4: break;
                default: cout << "Invalid choice!\n";
            }
        }
    }
    else cout << "Wrong ID or password\n";

    return 0;
}
