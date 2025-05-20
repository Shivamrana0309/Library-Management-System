#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string> load_users(const string& filename ){
    unordered_map<string,string> users;
    ifstream fin(filename);
    string buffer,buffer1,usr,pass;
    while(fin >> buffer >> usr >> buffer1 >> pass){
        users[usr]=pass;
    }
    fin.close();
    return users;
}

void register_user(const string& filename){
    string username,password;
    cout<<"Register->"<<endl;
    cout<<"Enter a username: ";
    cin>>username;
    unordered_map<string,string> users=load_users(filename);
    if(users.find(username)==users.end()){
        cout<<"Enter password: ";
        cin>>password;
        fstream fapp(filename,ios::app);
        fapp <<"username: "<<username<<" "<<"password: "<<password<<endl;
        cout<<"User registered successfully!"<<endl;
        fapp.close();
        return;
    }
    cout<<"User already exists, try logging in!"<<endl;
    return;
}

void login_user(const string& filename){
    cout<<"Login In->"<<endl;
    string username,password;
    cout<<"Enter a username: ";
    cin>>username;
    unordered_map<string,string> users=load_users(filename);
    if(users.find(username)==users.end()){
        cout<<"User do not exist! \nRegister User!"<<endl;
        return;
    }
    cout<<"Enter password: ";
    cin>>password;
    if(users[username]==password){
        cout<<"Login Successful!"<<endl;
        return;
    }
    cout<<"Incorrect password, Try Again!\n"<<endl;
    return;
}

int main(){
    int c;
    const string file="users.txt";
    while(true){
        cout<<"1.Register \n2.Login \n3.Exit \n";
        cout<<"Enter option: ";
        cin>>c;
        switch (c){
            case 1:
                register_user(file);
                break;
            case 2:
                login_user(file);
                break;
            case 3:
                cout<<"Exiting...\n";
                return 0;
            default:
                cout<<"Invalid option!Try Again \n";
                break;
        }
    }
}
