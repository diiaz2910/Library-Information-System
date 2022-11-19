//Libraries declaration
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <conio.h>
#include <locale.h>



using namespace std;

//Prototype of functions
void init();
void login();
void regUser();
int veriUser(string user);
void editUser();
void deleteUser();
void checkUser();
void adminOptions();
void guestOptions();
void preBook();
void showMenu();
void guestOptions();
void regBook();
void checkCatalogue();
void editBook();
void deleteBook();
void catalogueLoan();


int main (){
    //setlocale(LC_CTYPE,"Spanish"); Tool that will help to add special characters.
	system("COLOR 70");
	init();

	return 0;
}



void init(){
	int op, error = 0;
	string usr, key;

	do{
		system("cls");
		cout << "\t\t\t\t\t     =======================================" << endl;
		cout << "\t\t\t\t\t            Library Information System.     " << endl;
		cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
		cout << "MAIN MENU" << endl;
		cout << "--------------" << endl << endl;
		cout << "1. Login" << endl << endl;
		cout << "2. Register" << endl << endl;
		cout << "3. Close Program" << endl << endl;
		cout << "Choose an option: ";
		cin >> op;
	}while(op < 0 || op > 3);
	cin.ignore();

	if(op == 1){
		login();
	}

	if(op == 2){
        regUser();
	}

	if(op == 3){
        exit(0);
	}
}

void adminOptions(){
	int op, error = 0;
	string usr, key;

	do{
		system("cls");
		cout << "\t\t\t\t\t     =======================================" << endl;
		cout << "\t\t\t\t\t            Library Information System.     " << endl;
		cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
		cout << "OPTIONS" << endl;
		cout << "---------" << endl << endl;
		cout << "1. Admin Menu" << endl << endl;
		cout << "2. Log Out" << endl << endl;
		cout << "Choose an option: ";
		cin >> op;
	}while(op < 0 || op > 2);
	cin.ignore();

	if(op == 2) init();
	if(op == 1){
		do{
			system("cls");
            cout << "\t\t\t\t\t     =======================================" << endl;
            cout << "\t\t\t\t\t            Library Information System.     " << endl;
            cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
			cout << "USERS MENU" << endl;
			cout << "-------------" << endl << endl;
			cout << "1. User Registration" << endl << endl;
			cout << "2. Edit User" << endl << endl;
			cout << "3. Delete User" << endl << endl;
			cout << "4. Users List" << endl << endl;
			cout << "5. Add Book" << endl << endl;
			cout << "6. Delete Book" << endl << endl;
			cout << "7. Edit Book" << endl << endl;
			cout << "8. Book's Catalogue" << endl << endl;
			cout << "9. Log Out" << endl << endl;
			cout << "0. Back to admin menu" << endl << endl;
			cout << "Choose an option: ";
			cin >> op;
		}while(op < 0 || op > 9);
		cin.ignore();

		if(op == 1){
            regUser();
		}

		if(op == 2){
            editUser();
		}

		if(op == 3){
            deleteUser();
		}

		if(op == 4){
            checkUser();
		}

		if(op == 5){
            regBook();
		}

		if(op == 6){
            deleteBook();
		}

		if(op == 7){
            editBook();
		}

		if(op == 8){
            checkCatalogue();
		}

		if(op == 9){
            init();
		}
		if(op == 0){
            adminOptions();
		}
	}
}

void guestOptions(){
	int op, error = 0;
	string usr, key;

	do{
		system("cls");
		cout << "\t\t\t\t\t     =======================================" << endl;
		cout << "\t\t\t\t\t            Library Information System.     " << endl;
		cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
		cout << "OPTIONS" << endl;
		cout << "---------" << endl << endl;
		cout << "1. Coming Soon Books" << endl << endl;
		cout << "2. Pre - Book" << endl << endl;
        cout << "3. Loan a Book" << endl << endl;
		cout << "4. Log Out" << endl << endl;
		cout << "Choose an option: ";
		cin >> op;
	}while(op < 0 || op > 4);
	cin.ignore();

	if(op == 1) showMenu();
	if(op == 2) preBook();
	if(op == 3) catalogueLoan();
	if(op == 4) init();
}


void showMenu(){
        system("cls");
        int op;
		cout << "\t\t\t\t\t     =======================================" << endl;
		cout << "\t\t\t\t\t            Library Information System.     " << endl;
		cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
        cout << "BOOK'S COMING SOON" << endl;
        cout << "--------------" << endl << endl;
        cout << "- 1 . In Search of Lost Time by Marcel Proust" << endl << endl;
        cout << "- 2 . Ulysses by James Joyce" << endl << endl;
        cout << "- 3 . Don Quixote by Miguel de Cervantes" << endl << endl;
        cout << "- 4 . One Hundred Years of Solitude by Gabriel Garcia Marquez" << endl << endl;
        cout << "- 5 . The Great Gatsby by F. Scott Fitzgerald" << endl << endl;
        cout << "- 6 . Moby Dick by Herman Melville" << endl << endl;
        cout << "- 7 . War and Peace by Leo Tolstoy" << endl << endl;
        cout << "- 8 . Hamlet by William Shakespeare" << endl << endl;
        cout << "- 9 . The Odyssey by Homer" << endl << endl;
        cout << "- 10 . Madame Bovary by Gustave Flaubert" << endl << endl;
        cout << " Would you like to Pre-Book? Enter 1 (Yes) / 2 (No) :" << endl << endl;
        cin >> op;
        if(op == 1) preBook();
        if(op == 2) guestOptions();
        if(op != 1 && op!= 2){
            cout << "Please enter a correct choice, Would you like to Pre-Book? Enter 1 (Yes) / 2 (No) : ";
            cin >> op;
            showMenu();
        }

        system("pause");
        guestOptions();
}


void login(){
    int error = 0, aux = 0;
    string name, key, user, pass;
    ifstream file;
    int type;
    int op;

    do{
        system("cls");
		cout << "\t\t\t\t\t     =======================================" << endl;
		cout << "\t\t\t\t\t            Library Information System.     " << endl;
		cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
        cout << "SYSTEM LOGIN" << endl;
        cout << "-----------------" << endl << endl;

        cout << "Enter Username:    ";
        getline(cin, user);

        cout << endl;
        cout << "Enter Password: ";
        getline(cin, pass);


        file.open("databaseUsrs.txt", ios::in); //Abrimos el file en modo lectura

        if(file.fail()){
            cout << "Error, file can't be opened." << endl;
            system("pause");
            init();
        }

        file >> name;
        while(!file.eof()){
            file >> key;
            file >> type;

            if(user == name && pass == key){
                aux++;
                cout << endl;
                cout << "MESSAGE: Data entered correct. Logining ..." << endl;
                file.close();
                system("pause");

                if(type == 1){
                    adminOptions();
                }
                else{
                    guestOptions();
                }
            }
            file >> name;
        }

        if(aux == 0){
            error++;

            if(error == 3){
                cout << endl;
                cout << "MESSAGE: Attention! You have exceeded the number of attempts. The program will redirect you to main menu..." << endl << endl << endl;
                system("pause");
                init();
                //exit(0);
            }

            else{
                cout << endl;
                cout << "MESSAGE: Attention! The data entered is incorrect. Try again ..." << endl << endl << endl;
                system("pause");
                file.close();
            }
        }
    }while(error != 3);
}


void regUser(){
	string name, key;
	int type, aux, op;

    ofstream file;
    file.open("databaseUsrs.txt",ios::app);

    if(file.fail()){
        cout << "Error, file can't be opened." << endl;
        system("pause");
        init();
    }

    do{
        system("cls");
        cout << "\t\t\t\t\t     =======================================" << endl;
        cout << "\t\t\t\t\t            SCHOOL LUNCH ORDERING SYSTEM  " << endl;
        cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
        cout << "USER REGISTRATION" << endl;
        cout << "-----------------" << endl << endl;
        cout << endl;
        cout << "Enter User Name: ";
        getline(cin, name);
        aux = veriUser(name);

        if(aux == 1){
            cout << endl;
            cout << "MESSAGE: Error! This User Name has been already registered." << endl;
            system("pause");
        }
    }while(aux == 1);


    cout << endl;
    cout << "Enter a password: ";
    getline(cin, key);
    cout << endl;


    cout << endl;
    cout << "Choose a user type to be registered" << endl << endl;
    cout << "1. Administrator" << endl << endl;
    cout << "2. Client" << endl << endl;
    do{
        cout << "Choose an option: ";
        cin >> op;
    }while(op < 0 || op > 2);

    if(op == 1){
        type = 1;
    }
    else{
        type = 2;
    }

    file << name << " " << key << " " << type << "\n";
    file.close();

    cout << endl;
    cout << "MESSAGE: User succesfully registered." << endl;
    system("pause");
    init();

}

void regBook(){
    string name;
    char id [50];
	//string id;
	int type, aux, op;

    ofstream file;
    file.open("databaseBooks.txt",ios::app);

    if(file.fail()){
        cout << "Error, file can't be opened." << endl;
        system("pause");
        init();
    }

    do{
        system("cls");
		cout << "\t\t\t\t\t     =======================================" << endl;
		cout << "\t\t\t\t\t            Library Information System.     " << endl;
		cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
        cout << "BOOK REGISTRATION" << endl;
        cout << "-----------------" << endl << endl;
        cout << endl;
        cout << "Enter Book's Title and Author (Book's name - Author): ";
        getline(cin, name);
        aux = veriUser(name);

        if(aux == 1){
            cout << endl;
            cout << "MESSAGE: Error! This Book has been already registered." << endl;
            system("pause");
        }
    }while(aux == 1);
    cout << endl;
    cout << "Enter an ID: ";
    cin.getline(id,50);
    cout << endl;


    cout << endl;
    cout << "Choose a Book's Categorie" << endl << endl;
    cout << "1. Horror" << endl << endl;
    cout << "2. Fiction" << endl << endl;
    do{
        cout << "Choose an option: ";
        cin >> op;
    }while(op < 0 || op > 2);

    if(op == 1){
        type = 3;
    }
    else{
        type = 4;
    }

    file << name << " " << id << " " << type << "\n";
    file.close();

    cout << endl;
    cout << "MESSAGE: Book succesfully registered." << endl;
    fflush(stdin);
    system("pause");
    adminOptions();

}

int veriUser(string user){
    ifstream file;
    int qtd = 0, aux = 0;
    string usrs[50];
    string name, key;

    file.open("databaseBooks.txt", ios::in);

    if(file.fail()){
        cout << "Error, file can't be opened." << endl;
        system("pause");
        init();
    }

    file >> name;
    while(!file.eof()){
        file >> key;

        usrs[qtd] = name;
        qtd++;

        file >> name;
    }
    file.close();

    for(int i = 0; i < qtd && aux == 0; i++){
            if(user == usrs[i]){
                aux = 1;
            }
    }

    return aux;
}

void editUser(){
    ifstream file;
    int qtd = 0, exist = 0;
    string usrs[50];
    string keys[50];
    int types[50];

    string name, key, user;
    int type, op;

    file.open("databaseUsrs.txt", ios::in);

    if(file.fail()){
        cout << "Error, file can't be opened." << endl;
        system("pause");
        init();
    }


    file >> name;
    while(!file.eof()){
        file >> key;
        file >> type;

        usrs[qtd] = name;
        keys[qtd] = key;
        types[qtd] = type;
        qtd++;

        file >> name;
    }
    file.close();

    system("cls");
		cout << "\t\t\t\t\t     =======================================" << endl;
		cout << "\t\t\t\t\t            Library Information System.     " << endl;
		cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
        cout << "EDIT USER" << endl;
        cout << "-----------------" << endl << endl;
        cout << "Enter User Name: ";
        getline(cin, user);

    for(int i = 0; i < qtd && exist == 0; i++){
            if(user == usrs[i]){
                do{
                    system("cls");
                    cout << "\t\t\t\t\t     =======================================" << endl;
                    cout << "\t\t\t\t\t            Library Information System.     " << endl;
                    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
                    cout << "EDIT USER" << endl;
                    cout << "-----------------" << endl << endl;
                    cout << "1. Change User Name" << endl << endl;
                    cout << "2. Change Password" << endl << endl;
                    cout << "Enter an option: ";
                    cin >> op;
                }while(op < 0 || op > 2);
                cin.ignore();

                if(op == 1){
                    system("cls");
                    cout << "\t\t\t\t\t     =======================================" << endl;
                    cout << "\t\t\t\t\t            Library Information System.     " << endl;
                    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
                    cout << "EDIT USER NAME" << endl;
                    cout << "---------------------------" << endl << endl;
                    cout << "Enter a new user name: ";
                    getline(cin, usrs[i]);
                    cout << endl;
                    cout << "MESSAGE: User name succesfully updated." << endl;
                    system("pause");
                }

                else{
                    system("cls");
                    cout << "\t\t\t\t\t     =======================================" << endl;
                    cout << "\t\t\t\t\t            Library Information System.     " << endl;
                    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
                    cout << "EDIT USER PASSWORD" << endl;
                    cout << "---------------------------" << endl << endl;
                    cout << "Enter new password: ";
                    getline(cin, keys[i]);
                    cout << endl;
                    cout << "MESSAGE: Password succesfylly updated." << endl;
                    system("pause");
                }

                ofstream aux("Auxiliar.txt",ios::out);
                if(aux.fail()){
                    cout << "File can not be opened." << endl;
                    exit(1);
                }

                if(!aux.eof()){
                    for(int i = 0; i < qtd; i++){
                        aux << usrs[i] << " " << keys[i] << " " << types[i] << "\n";
                    }
                }
                aux.close();
                remove("databaseUsrs.txt");
                rename("Auxiliar.txt", "databaseUsrs.txt");

                exist = 1;
            }
    }

    if(exist == 0){
        cout << endl;
        cout << "MESSAGE: User name could not be found." << endl;
        system("pause");
    }


    adminOptions();
}


void editBook(){
    ifstream file;
    int qtd = 0, exist = 0;
    string usrs[50];
    string keys[50];
    int types[50];

    string name, key, user;
    int type, op;

    file.open("databaseBooks.txt", ios::in);

    if(file.fail()){
        cout << "Error, file can't be opened." << endl;
        system("pause");
        init();
    }


    file >> name;
    while(!file.eof()){
        file >> key;
        file >> type;

        usrs[qtd] = name;
        keys[qtd] = key;
        types[qtd] = type;
        qtd++;

        file >> name;
    }
    file.close();

    system("cls");
    cout << "\t\t\t\t\t     =======================================" << endl;
    cout << "\t\t\t\t\t            Library Information System.     " << endl;
    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
    cout << "EDIT BOOKS" << endl;
    cout << "-----------------" << endl << endl;
    cout << "Enter Book's Name: ";
    getline(cin, user);

    for(int i = 0; i < qtd && exist == 0; i++){
            if(user == usrs[i]){
                do{
                    system("cls");
                    cout << "\t\t\t\t\t     =======================================" << endl;
                    cout << "\t\t\t\t\t            Library Information System.     " << endl;
                    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
                    cout << "EDIT USER" << endl;
                    cout << "-----------------" << endl << endl;
                    cout << "1. Change Book's Name" << endl << endl;
                    cout << "2. Change ID" << endl << endl;
                    cout << "Enter an option: ";
                    cin >> op;
                }while(op < 0 || op > 2);
                cin.ignore();

                if(op == 1){
                    system("cls");
                    cout << "\t\t\t\t\t     =======================================" << endl;
                    cout << "\t\t\t\t\t            Library Information System.     " << endl;
                    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
                    cout << "EDIT USER NAME" << endl;
                    cout << "---------------------------" << endl << endl;
                    cout << "Enter a new name: ";
                    getline(cin, usrs[i]);
                    cout << endl;
                    cout << "MESSAGE: User name succesfully updated." << endl;
                    system("pause");
                }

                else{
                    system("cls");
                    cout << "\t\t\t\t\t     =======================================" << endl;
                    cout << "\t\t\t\t\t            Library Information System.     " << endl;
                    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
                    cout << "EDIT BOOK'S PASSWORD" << endl;
                    cout << "---------------------------" << endl << endl;
                    cout << "Enter new ID: ";
                    getline(cin, keys[i]);
                    cout << endl;
                    cout << "MESSAGE: ID succesfylly updated." << endl;
                    system("pause");
                }

                ofstream aux("Auxiliar.txt",ios::out);
                if(aux.fail()){
                    cout << "File can not be opened." << endl;
                    exit(1);
                }

                if(!aux.eof()){
                    for(int i = 0; i < qtd; i++){
                        aux << usrs[i] << " " << keys[i] << " " << types[i] << "\n";
                    }
                }
                aux.close();
                remove("databaseBooks.txt");
                rename("Auxiliar.txt", "databaseBooks.txt");

                exist = 1;
            }
    }

    if(exist == 0){
        cout << endl;
        cout << "MESSAGE: Book's name could not be found." << endl;
        system("pause");
    }


    init();
}


void deleteUser(){
    ifstream file;
    int qtd = 0, exist = 0, j;
    string usrs[50];
    string keys[50];
    int types[50];

    string name, key, user;
    int type, op;

    file.open("databaseUsrs.txt", ios::in);

    if(file.fail()){
        cout << "Error, file can't be opened." << endl;
        system("pause");
        init();
    }

    system("cls");
    cout << "\t\t\t\t\t     =======================================" << endl;
    cout << "\t\t\t\t\t            Library Information System.     " << endl;
    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
    cout << "DELETE USER" << endl;
    cout << "-----------------" << endl << endl;
    cout << "Enter User Name: ";
    getline(cin, user);

    file >> name;
    while(!file.eof()){
        file >> key;
        file >> type;

        if(user != name){
            usrs[qtd] = name;
            keys[qtd] = key;
            types[qtd] = type;
            qtd++;
        }
        else{
            exist = 1;
        }


        file >> name;
    }
    file.close();


    if(exist == 0){
        cout << endl;
        cout << "MESSAGE: User not found." << endl;
        system("pause");
    }

    else{
        ofstream aux;
        aux.open("Auxiliar.txt",ios::out);

        if(aux.fail()){
            cout << "Error, file can't be opened." << endl;
            system("pause");
            init();
        }

        else{
            for(int i = 0; i < qtd; i++){
                aux << usrs[i] << " " << keys[i] << " " << types[i] << "\n";
            }
            aux.close();
        }

        remove("databaseUsrs.txt");
        rename("Auxiliar.txt", "databaseUsrs.txt");
        cout << endl;
        cout << "MESSAGE: User succesfully deleted." << endl;
        system("pause");
    }


    adminOptions();
}


void deleteBook(){
    ifstream file;
    int qtd = 0, exist = 0, j;
    string usrs[50];
    string keys[50];
    int types[50];

    string name, key, user;
    int type, op;

    file.open("databaseBooks.txt", ios::in);

    if(file.fail()){
        cout << "Error, file can't be opened." << endl;
        system("pause");
        init();
    }

    system("cls");
    cout << "\t\t\t\t\t     =======================================" << endl;
    cout << "\t\t\t\t\t            Library Information System.     " << endl;
    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
    cout << "DELETE BOOK" << endl;
    cout << "-----------------" << endl << endl;
    cout << "Enter Book's Name: ";
    getline(cin, user);

    file >> name;
    while(!file.eof()){
        file >> key;
        file >> type;

        if(user != name){
            usrs[qtd] = name;
            keys[qtd] = key;
            types[qtd] = type;
            qtd++;
        }
        else{
            exist = 1;
        }

        file >> name;
    }
    file.close();


    if(exist == 0){
        cout << endl;
        cout << "MESSAGE: Book not found." << endl;
        system("pause");
    }

    else{
        ofstream aux;
        aux.open("Auxiliar.txt",ios::out);

        if(aux.fail()){
            cout << "Error, file can't be opened." << endl;
            system("pause");
            init();
        }

        else{
            for(int i = 0; i < qtd; i++){
                aux << usrs[i] << " " << keys[i] << " " << types[i] << "\n";
            }
            aux.close();
        }

        remove("databaseBooks.txt");
        rename("Auxiliar.txt", "databaseBooks.txt");
        cout << endl;
        cout << "MESSAGE: Book succesfully deleted." << endl;
        system("pause");
    }


    adminOptions();
}

void checkUser(){
    ifstream file;
    int qtd = 0, aux = 0, type;
    string name, key;

    file.open("databaseUsrs.txt", ios::in);

    if(file.fail()){
        cout << "Error, file can't be opened." << endl;
        system("pause");
        init();
    }

    system("cls");
    cout << "\t\t\t\t\t     =======================================" << endl;
    cout << "\t\t\t\t\t            Library Information System.     " << endl;
    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
    cout << "REGISTERED USERS" << endl;
    cout << "--------------------" << endl << endl;
    cout << "USER NAME                                         TYPE OF USER" << endl;
    cout << "--------------------------------------------------------------" << endl;

    file >> name;
    while(!file.eof()){
        file >> key;
        file >> type;

        cout << name;
        int user_length = name.size();

        for(int i = 0; i < (47 - user_length); i ++){
                cout << " ";
        }

        if(type == 1){
            cout << "Administrator";
        }
        else{
            cout << "Member";
        }

        cout << endl;
        file >> name;
    }

    file.close();
    cout << endl << endl;
    system("pause");
    adminOptions();
}


void checkCatalogue(){
    ifstream file;
    int qtd = 0, aux = 0, type;
    string name, id;

    file.open("databaseBooks.txt", ios::in);

    if(file.fail()){
        cout << "Error, file can't be opened." << endl;
        system("pause");
        init();
    }

    system("cls");
    cout << "\t\t\t\t\t     =======================================" << endl;
    cout << "\t\t\t\t\t            Library Information System.     " << endl;
    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
    cout << "CATALOGUE" << endl;
    cout << "--------------------" << endl << endl;
    cout << "BOOK'S NAME                                       BOOK ID     " << endl;
    cout << "--------------------------------------------------------------" << endl;

    file >> name;
    while(!file.eof()){
        file >> id;
        file >> type;

        cout << name;
        int user_length = name.size();

        for(int i = 0; i < (47 - user_length); i ++){
                cout << " ";
        }

        if(type == 3){
            cout << "Horror";
        }
        if(type == 4){
            cout << "Fantasy";
        }
        else{
            cout << "Other";
        }

        cout << endl;
        file >> name;
    }

    file.close();
    cout << endl << endl;
    system("pause");
    adminOptions();
}


void catalogueLoan(){
    ifstream file;
    int qtd = 0, aux = 0, type, advance;
    string name, id;

    file.open("databaseBooks.txt", ios::in);

    if(file.fail()){
        cout << "Error, file can't be opened." << endl;
        system("pause");
        init();
    }

    system("cls");
    cout << "\t\t\t\t\t     =======================================" << endl;
    cout << "\t\t\t\t\t            Library Information System.     " << endl;
    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
    cout << "BOOKS AVAILABLE" << endl;
    cout << "--------------------" << endl << endl;
    cout << "BOOKS NAMES                                       BOOK ID     " << endl;
    cout << "--------------------------------------------------------------" << endl;

    file >> name;
    while(!file.eof()){
        file >> id;
        file >> type;

        cout << name;
        int user_length = name.size();

        for(int i = 0; i < (47 - user_length); i ++){
                cout << " ";
        }

        if(type == 3){
            cout << "Horror";
        }
        if(type == 4){
            cout << "Fantasy";
        }
        else{
            cout << "Other";
        }

        cout << endl;
        file >> name;
    }
    cout<< endl << endl;
    cout << "Do you want to loan a book? Enter 1 (Yes) / 2 (No) : ";
    cin >> advance;



    file.close();
    cout << endl << endl;
    system("pause");
    init();
}



void preBook(){
    float subtotal = 0, total = 0;
    int op, qtd, advance, book1 = 0, book2 = 0, book3 = 0, book4 = 0, book5 = 0, book6 = 0, book7 = 0, book8 = 0, book9 = 0, book10 = 0;
    string type;

    do{
        do{
            system("cls");
            cout << "\t\t\t\t\t     =======================================" << endl;
            cout << "\t\t\t\t\t            Library Information System.     " << endl;
            cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
            cout << "--------------" << endl << endl;
            cout << "BOOK TO PRE-BOOK" << endl;
            cout << "--------------" << endl << endl;
            cout << "- 1 . In Search of Lost Time by Marcel Proust" << endl << endl;
            cout << "- 2 . Ulysses by James Joyce" << endl << endl;
            cout << "- 3 . Don Quixote by Miguel de Cervantes" << endl << endl;
            cout << "- 4 . One Hundred Years of Solitude by Gabriel Garcia Marquez" << endl << endl;
            cout << "- 5 . The Great Gatsby by F. Scott Fitzgerald" << endl << endl;
            cout << "- 6 . Moby Dick by Herman Melville" << endl << endl;
            cout << "- 7 . War and Peace by Leo Tolstoy" << endl << endl;
            cout << "- 8 . Hamlet by William Shakespeare" << endl << endl;
            cout << "- 9 . The Odyssey by Homer" << endl << endl;
            cout << "- 10 . Madame Bovary by Gustave Flaubert" << endl << endl;
            cout << "- 11 . Go to Main Menu" << endl << endl;
            cout << "Enter an option: ";
            cin >> op;
            if(op == 11){
                init();
            }
        }while(op < 1 || op > 11);

        cout << endl;
        cout << "Enter Quantity: ";
		cin >> qtd;

    	switch(op){
			case 1:
				subtotal = qtd * 10.00;
				book1 += qtd;
			break;

			case 2:
				subtotal = qtd * 10.00;
				book2 += qtd;
			break;

			case 3:
				subtotal = qtd * 10.00;
				book3 += qtd;
			break;

			case 4:
				subtotal = qtd * 10.00;
				book4 += qtd;
			break;

			case 5:
				subtotal = qtd * 10.00;
				book5 += qtd;
			break;

			case 6:
				subtotal = qtd * 10.00;
				book6 += qtd;
			break;

			case 7:
				subtotal = qtd * 10.00;
				book7 += qtd;
			break;

			case 8:
				subtotal = qtd * 10.00;
				book8 += qtd;
			break;

			case 9:
				subtotal = qtd * 10.00;
				book9 += qtd;
			break;

			case 10:
				subtotal = qtd * 10.00;
				book10 += qtd;
			break;
		}

		cout << endl;
		cout << "Do you want to Pre-Book more? Enter 1 (Yes) / 2 (No) : ";
		cin >> advance;
	}while(advance == 1);


	do{
        system("cls");
		cout << "\t\t\t\t\t     =======================================" << endl;
		cout << "\t\t\t\t\t            Library Information System.     " << endl;
		cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
        cout << "Payment Method" << endl;
        cout << "---------" << endl << endl;
        cout << "Choose Payment Method" << endl << endl;
        cout << "1. Card" << endl << endl;
        cout << "2. Cash" << endl << endl;
        cout << "Enter an option: ";
        cin >> op;
    }while(op < 1 || op > 2);

    if(op == 1){
        type = "Card";
	}
	else{
        type = "Cash";
	}

    ofstream file;
    file.open("Invoice.txt",ios::out);
    if(file.fail()){
        cout << "File can not be opened." << endl;
        exit(1);
    }


    system("cls");
    cout << "\t\t\t\t\t     =======================================" << endl;
    cout << "\t\t\t\t\t            Library Information System.     " << endl;
    cout << "\t\t\t\t\t     =======================================" << endl << endl << endl;
    cout << endl << endl;
    cout    << "PRINTING INVOICE............." << endl;
    file << "PRINTING INVOICE..............." << endl;
    cout    << "-------" << endl << endl;
    file << "-------" << endl << endl;
    cout    << "BOOKS                                            QUANTITY" << endl;
    file << "BOOKS                                              QUANTITY" << endl;
    cout    << "----------------------------------------------------------" << endl;
    file << "-------------------------------------------------------------" << endl;
    cout    << "In Search of Lost Time by Marcel Proust...................." << book1 << endl;
    file << "In Search of Lost Time by Marcel Proust......................." << book1 << endl;

    cout    << "Ulysses by James Joyce....................................." << book2 << endl;
    file << "Ulysses by James Joyce........................................" << book2 << endl;

    cout    << "Don Quixote by Miguel de Cervantes........................." << book3 << endl;
    file << "Don Quixote by Miguel de Cervantes............................" << book3 << endl;

    cout    << "One Hundred Years of Solitude by Gabriel Garcia Marquez...." << book4 << endl;
    file << "One Hundred Years of Solitude by Gabriel Garcia Marquez......." << book4 << endl;

    cout    << "The Great Gatsby by F. Scott Fitzgerald...................." << book5 << endl;
    file << "The Great Gatsby by F. Scott Fitzgerald......................." << book5 << endl;

    cout    << "Moby Dick by Herman Melville..............................." << book6 << endl;
    file << "Moby Dick by Herman Melville.................................." << book6 << endl;

    cout    << "War and Peace by Leo Tolstoy..............................." << book7 << endl;
    file << "War and Peace by Leo Tolstoy.................................." << book7 << endl;

    cout    << "Hamlet by William Shakespeare.............................." << book8 << endl;
    file << "Hamlet by William Shakespeare................................." << book8 << endl;

    cout    << "The Odyssey by Homer......................................." << book9 << endl;
    file << "The Odyssey by Homer.........................................." << book9 << endl;

    cout    << "Madame Bovary by Gustave Flaubert.........................." << book10 << endl;
    file << "Madame Bovary by Gustave Flaubert............................." << book10 << endl;


    cout    << "............................Subtotal:       $" << subtotal << endl ;
    file << "...............................Subtotal:       $" << subtotal << endl;
    cout    << "............................Total Payment:  $" << total << endl;
    file << "...............................Total Payment:  $" << total << endl;
    cout    << "............................Payment Method:  " << type << endl << endl;
    file << "...............................Payment Method:  " << type << endl << endl ;
    cout << endl << "Thanks for choosing us!!!" << endl << endl;

    file.close();
    system("pause");
    guestOptions();
}
