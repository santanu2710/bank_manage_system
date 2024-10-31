# include <iostream>
# include <vector>
# include <string>                                              // header files

# define n 100                                                  //define n as 100 for entire code file

using namespace std;

class account{                                                  //class account and class elements name id password and balance
    public:
    string name;
    string id;
    string password;
    int balance;
};


account accounts[n];                                           // array named accounts of type account

int f_empty_block =0 ;                                         // integer declearation 


bool admin_login(string id , string pass){                     // bool function to check it is an admin or not
    if (id == "000000" and pass == "admin")
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}
bool user_login(string id, string pass){                      // boll function to check it is an user or not
    for (int i = 0; i < n; i++)
    {
        if (id == accounts[i].id && pass == accounts[i].password) 
        {
            return true;
        }        
    }

    return false;
}


void ask_id_pass(){                                             // function to print for asking id and password
    cout << "please enter your id and password: " << endl;
}
void ask_id(){
    cout << "id: ";
}
void ask_pass(){
    cout << "password: ";
}


void add_acc(int k){                                        // function to add account 
    cout << "Enter details of new user: " <<endl;
    cout<< "Name: ";
    cin >> accounts[k].name;
            
    cout << "id: ";
    cin >> accounts[k].id;

    cout << "password: ";
    cin >> accounts[k].password;

    cout << "mony diposite: ";
    cin >> accounts[k].balance;
}
void del_acc(string id){
    for (int i = 0; i < n; i++)
    {
        if (id == accounts[i].id)
        {
            for (int j = i; j < n-1; j++)
            {
                accounts[j].name = accounts[j+1].name;
                accounts[j].id = accounts[j+1].id;
                accounts[j].password = accounts[j+1].password;
                accounts[j].balance = accounts[j+1].balance;
            }
            return;
        }
        
    }
    cout << "sorry invalid id";
}
void acc_info_for_admin(string id){
    for (int i = 0; i < n; i++)
    {
        if (id == accounts[i].id) 
        {
            cout << "name: " << accounts[i].name << endl;
            cout << "id: " << accounts[i].id << endl;
            cout << "password: " << accounts[i].password << endl;
            cout << "available balance: " << accounts[i].balance << endl;
            return;
        }
           
    }
    cout << "sorry invalid id";
}



void diposite(string id, int f){
    for (int i = 0; i < n; i++)
    {
        if (id == accounts[i].id)
        {
            accounts[i].balance += f;
            cout << "successfull diposited--";
            break;
        }
        
    }    
}
void withdraw(string id, int wf){
    for (int i = 0; i < n; i++)
    {
        if (id == accounts[i].id)
        {
            if (accounts[i].balance < wf)
            {
                cout << "sorry insufficient balance!!!" << endl;
            }
            else{
                accounts[i].balance -= wf;
                cout << "successfull diposited--";
            }
            return;
        }     
    }
}
void check_balance(string id){
    for (int i = 0; i < n; i++)
    {
        if (id == accounts[i].id)
        {
            cout << "balance Rs/. " << accounts[i].balance << endl;
            return;
        }
    }
}



int main(){

    

    string id;
    string password;

    ask_id_pass();
    ask_id();
    cin >> id;
    ask_pass();
    cin >> password;

    cout << endl << endl;

    int admin_choose = 0;
    int user_choose = 0;

    string id_to_delete;
    string id_get_info;

    int dipo_or_withdraw_money;

    if (admin_login(id, password))
    {
        while (admin_choose != 4)
        {
            cout << "-----You are an admin. you can do following operations-----" << endl;
            cout << "1. Add account" << endl << "2. Delete account" << endl << "3. Get info" << endl << "4. Log out" << endl;

    
            cout << "enter your choice: ";
            cin >> admin_choose;

            if (admin_choose == 1)
            {
                add_acc(f_empty_block);
                f_empty_block++;
                cout << "accout added successfully" << endl;
            }
            else if (admin_choose == 2)
            {
                cout << "enter id you want to delete: ";
                cin >> id_to_delete;
                del_acc(id_to_delete);
                cout << "accout deleted successfully" << endl;
                f_empty_block--;
            }
            else if (admin_choose == 3)
            {
                cout << "enter id you want to get info: ";
                cin >> id_get_info;
                acc_info_for_admin(id_get_info);
            }
            else{
                cout << "Sorry, wrong selection. Try again" << endl;
            }
        }
        
        cout << "thank you. you are sucessfully logged out!" << endl;
            
    }


    else if (user_login(id, password))
    {
        while (user_choose != 4)
        {
            cout << "-----You are an user. you can do following operations-----" << endl;
            cout << "1. Diposite" << endl << "2. withdraw" << endl << "3. check balance" << "4. log out" << endl;

            cout << "enter your choice: ";
            cin >> user_choose;

            if (user_choose == 1)
            {
                cout << "amount money you want to diposite: ";
                cin >> dipo_or_withdraw_money;
                diposite(id,dipo_or_withdraw_money);

            }
            else if (user_choose == 2)
            {
                cout << "amount money you want to diposite: ";
                cin >> dipo_or_withdraw_money;
                withdraw(id,dipo_or_withdraw_money);

            }
            else if (user_choose == 3)
            {
                check_balance(id);
            }
            else{
                cout << "Sorry, wrong selection. Try again" << endl;
            }
        }
        cout << "thank you. you are sucessfully logged out!" << endl;

    }
    
    
    int exit_or_not;

    cout << "-------- do you want to off the system --------" << endl;
    cout << "1. YES" << endl << "2. NO" << endl;
    cin >> exit_or_not;

    if (exit_or_not == 1)
    {
        return 0;
    }
    else{
        main();
    }

}