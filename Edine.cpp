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
// -----------------------
void customer();


struct staffs
{
    int ID;
    string name;
    string DOB;
    // string mm,dd,yyyy;
    string Address;
    string Phone;
    string DOJ;
    string line;
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
        getch();
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
    cout << "\n\n\t\tIncorrect Option! Please choose from the given option...";
}
// -----------------------------------PASSWORD-------------------------------------------------------------------------------------------------------------------

// --------------------------------CHANGE PASSWORD---------------------------------------------------------------------------------------------------------------

// -----------------------------------MENU MANAGEMENT------------------------------------------------------------------------------------------------------------
fstream viewd("drinks.txt", ios :: in | ios::out | ios::app);
fstream viewf("fastfood.txt", ios :: in | ios::out | ios::app);
fstream viewdt("dessert.txt", ios :: in | ios::out | ios::app);
void menu_management()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO MENU MANAGEMENT*****\n\n";
    cout << "<1> View Menu\n\n<2> Edit/Update Menu\n\n<0> Back";
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
        getch();
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
    cout << "<1> View\n\n<2> Delete\n\n<0> Back";
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
    cout << "<1> View Member List\n\n<2> Add Member \n\n<3> Remove Member\n\n<4> Update Member Data\n\n<4> Find Member\n\n<0> Back";
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
        find_member();
    }
    else if (option == 0)
    {
        manager_portal();
    }
    else
    {
        wrong_entry();
        getch();
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
    cout << "Name: ";
    cin >> v.name;
    cout << "DOB(dd/mm/yyyy): ";
    cin >> v.DOB;
    // cin >> v.dd >> v.mm >> v.yyyy;
    cout << "Address: ";
    cin >> v.Address;
    cout << "Phone: ";
    cin >> v.Phone;
    cout << "DOJ(dd/mm/yyyy): ";
    cin >> v.DOJ;
    // v.line = v.name + "   " + v.DOB + "   " + v.Phone + "   " + v.DOJ+ "   " + v.Address;
    ostringstream sos(v.line);
    sos << v.name <<v.DOB;

    do
    {
        cout << "\nDo you want to Save y/n: ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
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
    //-----file
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
        getch();
        customer();
        break;
    }
}