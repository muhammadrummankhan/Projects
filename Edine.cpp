#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

using namespace std;

short int option;
char ch;

void choose();
void wrong_entry();
void title();
void main_page();
// -----------------------
void manager_portal();
void order_history();
// -----------------------
void menu_management();
void view_menu();
// -----------------------
void staff();
void staff_input();
void find_member();
void savefm();
// -----------------------
void customer();


struct staffs 
{
    int ID;
    string fname;
    string lname;
    string DOB;
    // string mm,dd,yyyy;
    string Address;
    string Phone;
    string DOJ;
    string line;
    int fid;
};

int main()
{
    main_page();
    // getch();
    return 0;
}
// --------------------------------MAIN PAGE--------------------------------------------------------------------------------------------------------------------
void main_page()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO E-DINE CAFE*****\n\n";
    cout << "\t<1> MANAGER\n\n\t<2> CUSTOMER\n\n\t<3> KITCHEN\n\n\tEnter any key to exit...";
    choose();
    cin >> option;
    if (option == 1)
    {
        manager_portal();
    }
    else if (option == 2)
    {
        /* customer */
    }
    else if (option == 3)
    {
        /* chef */
    }
}
// -----------------------------MANAGER PORTAL MAIN PAGE--------------------------------------------------------------------------------------------------------
void manager_portal()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO MANAGER PORTAL*****\n\n";
    cout << "\t<1> Menu Management\n\n\t<2> Staff\n\n\t<3> Order History\n\n\t<4> Change Password\n\n\t<0> Back To Main Page";
    choose();
    cin >> option;
    if (option == 1)
    {
        // pswd
        menu_management();
    }
    else if (option == 2)
    {
        staff();
    }
    else if (option == 3)
    {
        order_history();
    }
    else if (option == 4)
    {
        // code
    }
    else if (option == 0)
    {
        main_page();
    }
    else
    {
        wrong_entry();
        manager_portal();
    }
}
// ---------------------------------CHOOSE OPTION---------------------------------------------------------------------------------------------------------------
void choose()
{
    cout << "\n\n\t\tChoose any one option: ";
}
// ----------------------------------WRONG ENTRY-----------------------------------------------------------------------------------------------------------------
void wrong_entry()
{
    cout << "\n\n\t\tIncorrect Option! Please choose from the given option.\n\tPress any key to try again...";
    getch();
}
// -----------------------------------PASSWORD-------------------------------------------------------------------------------------------------------------------

// --------------------------------CHANGE PASSWORD---------------------------------------------------------------------------------------------------------------

// --------------------------------title-----------------------------------------------------------------
void title(string t)
{
    cout<< "------------------------------------------"<<endl;
    cout<< "                "<<t<<"                     "<<endl;
    cout<< "------------------------------------------";
}
// -----------------------------------MENU MANAGEMENT------------------------------------------------------------------------------------------------------------
fstream viewd("drinks.txt", ios :: in | ios::out | ios::app);
fstream viewf("fastfood.txt", ios :: in | ios::out | ios::app);
fstream viewdt("dessert.txt", ios :: in | ios::out | ios::app);
void menu_management()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO MENU MANAGEMENT*****\n\n";
    cout << "\t<1> View Menu\n\n\t<2> Edit/Update Menu\n\n\t<0> Back";
    choose();
    cin >> option;

    if (option == 1)
    {
        system("cls");
        view_menu();
    }
    else if (option == 2)
    {
        ofstream edit("menu.txt", ios ::out);
        cout << "<1> Add Item\n\n<2> Remove Item";
        choose();
        cin >> option;
        edit.close();
    }
    else if (option == 0)
    {
        manager_portal();
    }
    else
    {
        wrong_entry();
        menu_management();
    }
}
// View Menu----------------------------------------------------
void view_menu()
{
    string drink_line, fastfood_line, dessert_line;
    while((!viewd.eof()) && (!viewf.eof()) && (!viewdt.eof()))
    {
        getline(viewd,drink_line);
        getline(viewd,fastfood_line);
        getline(viewd,dessert_line);
        cout << fastfood_line << setw(5) << drink_line << setw(5) << dessert_line <<endl;
    }
    viewd.close();
    viewf.close();
    viewdt.close();
}

// -----------------------------------ORDER HISTORY---------------------------------
void order_history()
{
    fstream order_history_file("order history.txt", ios ::in | ios ::out);
    cout << "\t\t\t\t\t\t\t\t\t*****ORDER HISTORY*****\n\n";
    cout << "\t<1> View\n\n\t<2> Delete\n\n\t<0> Back";
    if (option == 1)
    {
        while (!order_history_file.eof())
        {
            order_history_file.get(ch);
            cout << ch;
        }
        cout << "\n\n\tPress any key to go back...";
        getch();
        manager_portal();
    }
    else if (option == 2)
    {
        order_history_file.trunc;
        order_history_file << "\\t\t\tORDER HISTORY\n";
    }
    else if (option == 0)
    {
        manager_portal();
    }
    else
    {
        wrong_entry();
        order_history();
    }
    order_history_file.close();
}
// --------------------------------------STAFF---------------------------------------------------------------------------------------------------------------------
fstream staff_file("staff.txt", ios::in | ios ::out | ios::app);
void staff()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****STAFF MANAGEMENT*****\n\n";
    cout << "\t<1> View Member List\n\n\t<2> Add Member \n\n\t<3> Remove Member\n\n\t<4> Update Member Data\n\n\t<5> Find Member\n\n\t<0> Back";
    choose();
    cin >> option;
    if (option == 1)
    {
        while (!staff_file.eof())
        {
            staff_file.get(ch);
            cout << ch;
        }
        cout << "\n\n\tPress any key to back...";
        getch();
        staff();
    }
    else if (option == 2)
    {
        staff_input();
    }
    else if (option == 3)
    {
        /* code */
    }
    else if (option == 4)
    {
        // -----
    }
    else if (option == 5)
    {
        find_member();
    }
    else if (option == 0)
    {
        manager_portal();
    }
    else
    {
        wrong_entry();
        staff();
    }
}

// ---------------------------------STAFF- ADD MEMEBER-------------------------------
void staff_input()
{
    system("cls");
    struct staffs v;
    cout << "ID: ";
    cin >> v.ID;
    cout << "First Name: ";
    cin >> v.fname;
    cout << "last Name: ";
    cin >> v.lname;
    cout << "DOB(dd/mm/yyyy): ";
    cin >> v.DOB;
    // cin >> v.dd >> v.mm >> v.yyyy;
    cout << "Address: ";
    cin >> v.Address;
    cout << "Phone: ";
    cin >> v.Phone;
    cout << "DOJ(dd/mm/yyyy): ";
    cin >> v.DOJ;
    v.line = v.fname + " " + v.lname+ " " + v.DOB + " " + v.Phone + " " + v.DOJ+ " " + v.Address;
    do
    {
        cout << "\nDo you want to Save y/n: ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            // staff_file.app;
            staff_file << "\n"
                       << v.ID << " " << v.line;
            cout << "Successfully Saved! Press any key to go back...";
            getch();
            staff_file.close();
            break;
        }
        else if (ch == 'n' || ch == 'N')
        {
            cout << "Not Saved in file! Press any key to go back...";
            getch();
            break;
        }
        else
            cout << "INCORRECT OPTION! PLEASE ENTER Y/N...";
    } while (true);
}

// ------------------------------FIND STAFF MEMBER--------------------------------
void find_member()
{
    system("cls");
    // cout<< "\t\t\t------------------------------------------"<<endl;
    // cout<< "\t\t\t               MEMBER FINDER              "<<endl;
    // cout<< "\t\t\t------------------------------------------"<<endl;
    title("MEMBER FNDER");
    struct staffs x;
    cout <<"\n\n\t\tEnter ID: ";
    cin >> x.fid;
    // staff_file.beg;
    while(!staff_file.eof())
    {
        getline(staff_file,x.line);
        stringstream xs(x.line);
        xs >> x.ID >> x.fname >> x.lname >> x.DOB >> x.Phone >> x.DOJ >> x.Address;
        
        if(x.line.length()!= 0)
        {
            if(x.fid == x.ID)
            {
                cout <<"\tID: "<<x.ID<<endl;
                cout <<"\tName: "<<x.fname<<" "<<x.lname<<endl;
                cout << "\tDOB: "<<x.DOB<<endl;
                cout << "\tPhone: "<<x.Phone<<endl;
                cout << "\tDOJ: "<<x.DOJ<<endl;
                cout << "\tAddress: "<<x.Address<<endl;
                savefm();
            }
        }   
        else
        {
            staff_file.seekg(0 , ios :: beg);
        }
    }
    if(x.fid != x.ID)
    {
        cout << "\n\t\tInvalid ID! Please enter correct ID number."<<endl;
        savefm();
    }
}
// --------------save function(Find Member)-------------------
void savefm()
{
    do
    {
        cout << "\n\t\tDo you want to Find again y/n: ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            staff_file.seekg(0 , ios :: beg);
            find_member();
        }
        else if (ch == 'n' || ch == 'N')
        {
            cout << "\n\t\tPress any key to go back...";
            getch();
            staff();
            break;
        }
        else
            cout << "\n\t\tINCORRECT OPTION! PLEASE ENTER Y/N...";
    } while (true);
}
// -------------------------------------CUSTOMER-----------------------------------------------------------------------------------------------------------------------
void customer()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO E-DINE CAFE*****\n\n";
    cout << "\t<1> View Menu\n\n\t<2> Place Order\n\n\t<0> Back\n";
    choose();
    cin >> option;
    switch (option)
    {
    case 1:
    {
        system("cls");
        char view_menu;
        ifstream view("menu.txt", ios ::in);
        while (!view.eof())
        {
            view.get(view_menu);
            cout << view_menu;
        }
        view.close();
        break;
    }
    case 2:
    {
        // code
        break;
    }
    case 0: 
    {
        main_page();
        break;
    }
    default:
        wrong_entry();
        customer();
        break;
    }
}
