#include<iostream>
#include<fstream>
// #include<bits/stdc++.h>
using namespace std;

class personalDetails{
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

    public:
        void login();
        void signUp();
        void forgotPassword();
}obj;


//signup function logic
void personalDetails :: signUp(){
    cout << "\nEnter Your Name :: ";
    getline(cin,userName);
    cout << "Enter Your Email Address :: ";
    getline(cin,Email);
    cout << "Enter Your Password :: ";
    getline(cin,password);

    file.open("loginData.txt", ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}


//login logic
void personalDetails :: login(){
    cout<<"----------LOGIN---------"<<endl;
    cout<<"Enter Your User Name :: "<<endl;
    getline(cin,searchName);
    cout<<"Enter Your Password :: "<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(userName == searchName){
            if(password == searchPass){
                cout<<"\nAccount Login Succesfull...!";
                cout<<"\nUsername :: "<<userName<<endl;
                cout<<"\nEmail :: "<<Email<<endl;
            }else{
                cout<<"Password is Incorrect...!";
            }
        }else{
            cout << "\nUser Name Not found...!";
            break;
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    }
    file.close();
}


//forgot password logic
void personalDetails :: forgotPassword(){
    cout<<"\nEnter Your UserName :: ";
    getline(cin,searchName);
    cout<<"\nEnter Your Email Address :: ";
    getline(cin,searchEmail);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(userName == searchName){
            if(Email == searchEmail){
                cout<<"\nAccount Found...!"<<endl;
                cout<<"Your Password is :: "<<password<<endl;
            }else{
                cout<<"Not found...!\n";
            }
        }else{
            cout<<"\nNot fount...!\n";
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    }
    file.close();
}


int main(){
    char choice;
    cout << "\n1-Login" << endl;
    cout << "\n2-Sign Up" << endl;
    cout << "\n3-Forgot Password" << endl;
    cout << "\n4-Exit" << endl;
    cout << "\n5-Enter Your Choice :: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.login();
        break;
        
    case '2': 
        cin.ignore();
        obj.signUp();
        break;

    case '3':
        cin.ignore();
        obj.forgotPassword();
        break;

    case '4': 
        return 0;
        break;
    
    default:
        cout << "Invalid Selection...!" << endl;
    }

    return 0;
}


