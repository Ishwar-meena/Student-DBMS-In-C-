#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Students_dbms
{
private:
    string password = "password"; // default password
public:
    string file_name = "student_dbms.xls";
    void loading_bar();
    void main_menu();
    void student_function();
    void verification();
    void admin_function();
    void add_data();
    // func--> data_heading(); you can add heading in your excel sheet by this function but it has some issue when you run your code every time
    //  it write heading in the file every time;
    void data_heading();
    void delete_data();
    void update_data();
    void update_password();
    void view_data();
    void quit();

    void set_password(string pass)
    {
        password = pass;
    }
};

void Students_dbms ::loading_bar()
{
    system("cls");
    char a = 177, b = 219;
    cout << "\n\n\n\n";
    cout << "\n\t\t\t\t\t| Welcome to Students Database Management System |" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tCreated By @HACKER X";
    cout << "\n\n\t\t\t\t\t\tLoading...";
    cout << "\n\n\t\t\t\t\t\t";
    for (int i = 0; i < 26; i++)
    {
        cout << a;
    }
    cout << "\r";
    cout << "\t\t\t\t\t\t";
    for (int i = 0; i < 26; i++)
    {
        cout << b;
        Sleep(100);
    }
}

void Students_dbms ::data_heading()
{
    ofstream write(file_name, ios::app);
    if (!write)
    {
        cout << "File Not Opend!!!" << endl;
    }
    write << "Roll_No\tNAME\tCLASS\tCOURSE\tHINDI\tENGLISH\tMATHMETICS\n";
    write.close();
}

void Students_dbms ::main_menu()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\t";
    cout << "\n\n\t\t\t\t\t\t| Login As |";
    cout << "\n\n\t\t\t\t\t\t1. Admin";
    cout << "\n\n\t\t\t\t\t\t2. Student";
    cout << "\n\n\t\t\t\t\t\t3. Exit";
    cout << "\n\n\t\t\t\t\t\tEnter choice : ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        verification();
        admin_function();
        break;
    case 2:
        student_function();
        system("pause");
        main_menu();
        break;
    case 3:
        quit();
        break;
    default:
        cout << "Please Enter a valid choice!!!";
        break;
    }
}

// void Students_dbms :: admin_verification(){}
void Students_dbms ::verification()
{
    system("cls");
    string user_password;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\tEnter Password : ";
    do
    {
        cin >> user_password;

        if (password != user_password)
        {
            cout << "\n\n\t\t\t\t\t\tPlease Enter a vailed password";
            cout << "\n\t\t\t\t\t\tEnter Password : ";
        }
        else
        {
            cout << "\nYou successfully logged in";
        }
    } while (password != user_password);
}

void Students_dbms ::admin_function()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\t";
    cout << "\n\n\t\t\t\t\t\t| Logged In As Admin |";
    cout << "\n\n\t\t\t\t\t\t1. Add Students Data";
    cout << "\n\n\t\t\t\t\t\t2. Delete Data";
    cout << "\n\n\t\t\t\t\t\t3. Update Data";
    cout << "\n\n\t\t\t\t\t\t4. view Data";
    cout << "\n\n\t\t\t\t\t\t5. Main Menu ";
    cout << "\n\n\t\t\t\t\t\t6. Update/Change Password ";
    cout << "\n\n\t\t\t\t\t\t7. Exit ";
    cout << "\n\n\t\t\t\t\t\tEnter choice : ";
    int choice;
    cin >> choice;
    string input;
    switch (choice)
    {
    case 1:
        system("cls");
        add_data();
        cout << "Do You want add more data Y/N : ";
        cin >> input;
        if (input == "Y" || input == "y")
        {
            add_data();
        }
        else
        {
            admin_function();
        }
        admin_function();
        break;
    case 2:
        delete_data();
        admin_function();
        break;
    case 3:
        update_data();
        // admin_function();
        break;
    case 4:
        view_data();
        break;
    case 5:
        main_menu();
        break;
    case 6:
        update_password();
        main_menu();
        break;
    case 7:
        quit();
        break;
    default:
        cout << "Please choose a valid option!!!" << endl;
        break;
    }
}

void Students_dbms ::quit()
{
    cout << "\n\n\n\t\t\t\t\t\tExiting";
    for (int i = 0; i < 4; i++)
    {
        Sleep(200);
        cout << ".";
    }
}

void Students_dbms ::update_password()
{
    system("cls");
    string password;
    cout << "\n\n\n\t\t\t\t\t\tEnter New Password : ";
    cin >> password;
    set_password(password);
    cout << "password successfully changed";
}

// This function take input form admin and add details of students
void Students_dbms ::add_data()
{
    int roll_no;
    string name, cls, course, hindi, english, math;
    ofstream write;
    write.open("student_dbms.xls", ios::app);
    cout << "Enter Student Roll No. : ";
    cin >> roll_no;
    cin.ignore();
    write << roll_no << "\t";
    cout << "Enter Student Name : ";
    getline(cin, name);
    write << name << "\t";
    cout << "Enter Student Class : ";
    getline(cin, cls);
    write << cls << "\t";
    cout << "Enter Student Course : ";
    getline(cin, course);
    write << course << "\t";
    cout << "Enter Student Marks of Hindi : ";
    getline(cin, hindi);
    write << hindi << "\t";
    cout << "Enter Student Marks of English : ";
    getline(cin, english);
    write << english << "\t";
    cout << "Enter Student Marks of Math : ";
    getline(cin, math);
    write << math << "\n";
    write.close();
}

// This fuction show students details
void Students_dbms ::view_data()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\t| Students Details |";
    // cout<<"\n\n\t\t\t\t\t\t"
    cout << "\n\n\n\n\n";
    cout << "Roll No\t\tStudent Name\t\tStudent Class\t\tStudent Course\t\tHindi\t\t\tEnglish\t\t\tMathematics\n";
    ifstream read("student_dbms.xls");
    if (!read)
    {
        cerr << "Error opening file." << endl;
    }

    string roll_no, name, cls, course, hindi, english, math;

    const int roll_no_width = 15;
    const int name_width = 25;
    const int cls_width = 20;
    const int course_width = 30;
    const int marks_width = 25;

    // string skip_line;
    // getline(read, skip_line);  // when we want to add heading in our excel file

    while (getline(read, roll_no, '\t') &&
           getline(read, name, '\t') &&
           getline(read, cls, '\t') &&
           getline(read, course, '\t') &&
           getline(read, hindi, '\t') &&
           getline(read, english, '\t') &&
           getline(read, math, '\n'))
    {
        cout << left << setw(roll_no_width) << roll_no
             << left << setw(name_width) << name
             << left << setw(cls_width) << cls
             << left << setw(course_width) << course
             << left << setw(marks_width) << hindi
             << left << setw(marks_width) << english
             << left << setw(marks_width) << math << endl;
    }

    read.close();
    system("pause");
    admin_function();
}

// Student Function
void Students_dbms ::student_function()
{

    int user;
    system("cls");
    cout << "\n\n\n\n\nPlease Enter Your Roll No. : ";
    cin >> user;
    ifstream read("student_dbms.xls");
    if (!read)
    {
        cout << "File not opend!!!" << endl;
    }
    int roll_no, found = 0;
    string name, tab, cls, course, hindi, english, math;
    while (read >> roll_no)
    {
        getline(read, tab, '\t');
        getline(read, name, '\t');
        getline(read, cls, '\t');
        getline(read, course, '\t');
        getline(read, hindi, '\t');
        getline(read, english, '\t');
        read >> math;
        if (user == roll_no)
        {
            found = 1;
            // cout << "roll no matched" << endl;
            cout << "Student Roll No. : ";
            cout << roll_no << endl;
            cout << "Student Name : ";
            cout << name << endl;
            cout << "Student Class : ";
            cout << cls << endl;
            cout << "Student Course : ";
            cout << course << endl;
            cout << "Marks Obtained in Hindi : ";
            cout << hindi << endl;
            cout << "Marks Obtained in English : ";
            cout << english << endl;
            cout << "Marks Obtained in Mathematics : ";
            // getline(read, math, '\t'); // we give extra roll no.
            cout << math << endl;
        }
    }
    if (!found)
    {
        cout << "Roll No. not mathched in out database!!!" << endl;
    }
    read.close();
}
// This Function Delete A Data Row Once A Time
void Students_dbms ::delete_data()
{
    // system("cls");  // This line clears the screen; it is platform-specific
    int user;
    cout << "Please Enter Your Roll No. : ";
    cin >> user;

    ifstream read("student_dbms.xls");
    if (!read)
    {
        cout << "File not opened!!!" << endl;
    }

    vector<string> lines;
    string line;
    bool found = false;

    // Read all lines from the original file
    while (getline(read, line))
    {
        stringstream ss(line); // Create a string stream from the line
        int roll_no;
        ss >> roll_no; // Extract the roll number from the line
        if (roll_no == user)
        {
            // cout << "Roll No. Matched!!!\n";
            found = true;
            cout << "Roll NO." << roll_no << "'s Details Will be Deleted!!!" << endl;
            continue; // skip this line if roll no matched;
        }
        lines.push_back(line);
    }
    read.close();
    if (!found)
    {
        cout << "Roll No. Not Found" << endl;
    }

    ofstream write("temp.xls");
    if (!write)
    {
        cout << "File not opend!!!" << endl;
    }

    for (auto const &l : lines)
    {
        write << l << endl;
    }
    write.close();
    remove("student_dbms.xls");
    rename("temp.xls", "student_dbms.xls");
    cout << "Record Deleted Successfully!!!" << endl;

    cout << "Loading";
    for (int i = 0; i < 4; i++)
    {
        Sleep(200);
        cout << ".";
    }
}
// This function update students details
void Students_dbms ::update_data()
{
    delete_data();
    system("cls");
    add_data();
    admin_function();
}
// main driver code
int main()
{
    Students_dbms user;
    // user.data_heading();
    user.loading_bar();
    user.main_menu();
    return 0;
}