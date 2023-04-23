#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>

using namespace std;

struct Medicine
{
    string medId;
    string name;
    int available;
    double price;
};

class MedicineList
{
public:
    vector <Medicine*> vec;
    int quantity = 0;
    int topIndex;

    MedicineList ()
    {
        Medicine *tmp = new Medicine();
        tmp->name = "";
        tmp->medId = "NULL";
        tmp->available=0;
        tmp->price = 0.00;

        topIndex = 1;
        vec.push_back (tmp);
    }

    void addMedicine (string nm, int avl, double price)
    {
        Medicine* tmp = new Medicine ();

        tmp->name = nm;

        string st = "MED" + to_string (topIndex);
        topIndex++;

        tmp->medId = st;

        tmp->available = avl;
        tmp->price = price;
        quantity++;

        vec.push_back (tmp);
    }

    void updateMedicine (int &i)
    {
        system ("cls");

        int choice;
        bool cond = true;
        while (cond)
        {
            system("cls");
            cout<<"\t\t\t    MEDICINE UPDATE MENU \n";
            cout<<"\t\t=========================================================\n\n";
            cout<<"\t\t---------------------------------------------------------\n";
            cout<<"\t\t||\t1. Update the Medicine Name. \t\t\t||\n";
            cout<<"\t\t||\t2. Update the Medicine Price.\t\t\t||\n";
            cout<<"\t\t||\t3. Update the stock available in the medicine.\t||\n";
            cout<<"\t\t||\t4. Exit\t\t\t\t\t\t||\n";
            cout<<"\t\t---------------------------------------------------------\n";
            cout<<"Enter choice: ";
            fflush(stdin);
            cin>>choice;

            switch (choice)
            {
            case 1:
                {
                    cout << "The current Medicine name of the chosen Medicine ID is : " << vec[i]->name << endl;
                    cout << "Enter the name with which you want to update it : ";
                    string str;
                    cin >> str;
                    vec[i]->name = str;
                    cout << "\nMedicine Name updated successfully...\n";
                    cout << "Re-directing to Medicine Update Menu\n";
                    system ("PAUSE");
                    break;
                }

            case 2:
                {
                    cout << "The current Medicine price of the chosen Medicine ID is : " << vec[i]->price << endl;
                    cout << "Enter the price with which you want to update it : ";
                    double pr;
                    cin >> pr;
                    vec[i]->price = pr;
                    cout << "\nMedicine Price updated successfully...\n";
                    cout << "Re-directing to Medicine Update Menu\n";
                    system ("PAUSE");
                    break;
                }

            case 3:
                {
                    cout << "The current available stock of the chosen Medicine ID is : " << vec[i]->available << endl;
                    cout << "Enter the stock availabality with which you want to update it : ";
                    int r;
                    cin >> r;
                    vec[i]->available = r;
                    cout << "\nMedicine Stock availabality updated successfully...\n";
                    cout << "Re-directing to Medicine Update Menu\n";
                    system ("PAUSE");
                    break;
                }

            case 4:
                cond = false;
                break;

            default:
                cout << "Invalid Input. Please Try Again.\n";
                system ("PAUSE");
                break;

            }
        }
        cout << endl << endl << "THANK YOU !!!" << endl;
        system ("PAUSE");
    }

    void deleteMedicine (int &i)
    {
        system ("cls");

        cout << "You entered the Medicine ID : " << vec[i]->medId << endl;
        cout << "You are about to delete '" << vec [i]->name << "' from the database." << endl;

        vec[i]->available = 0;
        vec[i]->name = "";
        vec[i]->price = 0.0;
        vec[i]->medId = "NULL";

        quantity--;
        cout << "Medicine deleted from Database successfully.\n";
        cout << endl << endl << "THANK YOU !!!" << endl;
        system ("PAUSE");
    }

    void printMedicine ()
    {
        if (quantity == 0)
        {
            cout << "There are no medicines added to the database.\n";
            cout << endl << endl << "THANK YOU !!!" << endl;
            system ("PAUSE");
            return;
        }
        cout <<"***************************************************************************************************\n";
        cout<<"MEDICINE ID"<<"\tMEDICINE NAME"<<"   \t\tQUANTITY AVAILABLE"<<"   \t\tPRICE"<<endl;
        cout <<"***************************************************************************************************\n";

        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i]->medId != "NULL")
                cout<<vec[i]->medId<<"\t\t"<<vec[i]->name<<"\t\t\t\t"<<vec[i]->available<<"\t\t\t\t"<<vec[i]->price<<endl;
        }
        cout << endl << endl << "THANK YOU !!!" << endl;
        system ("PAUSE");
    }

};

class Users
{
public:
    string name;
    virtual ~Users ()  { }
};


class Admin : public Users
{
protected:
    string password;

    Admin (const string& str, const string& pass)
    {
        name = str;
        password = pass;
    }

public:
    static Admin* onlyAdmin;
    static const Admin& adminCreate (const string& str, const string& pass)
    {
        if (!onlyAdmin)
        {
            onlyAdmin = new Admin (str, pass);
            return *onlyAdmin;
        }
        else
        {
            return *onlyAdmin;
        }
    }

    void existingAdmin (MedicineList &med);
};

Admin *Admin::onlyAdmin = NULL;

void Admin::existingAdmin(MedicineList &med)
{
    system ("cls");
    system("COLOR 4");

    if (onlyAdmin == NULL)
    {
        cout << "No Existing Admin. Create a New Admin First.\n";
        cout << endl << "You are being redirected to the Main-Menu";
        cout << endl << endl << "THANK YOU !!!" << endl;

        system ("PAUSE");
        system ("cls");
        return;
    }

    cout << "Welcome " << name << " !!! \n";
    cout << "Enter your Password : ";
    string pass;
    cin >> pass;

    while (pass != onlyAdmin->password)
    {
        cout << "\nPassword you entered is wrong.\nTRY AGAIN!!!.";
        cout <<"Enter your password : ";
        cin >> pass;
    }

    cout << "\nCorrect Password...\n";
    cout << "Re-directing you to the Admin Menu.\n";

    system ("PAUSE");

    int choice;
    bool cond = true;
    while (cond)
    {
        system("cls");
        cout<<"\t\t\t    ADMIN MENU \n";
        cout<<"\t\t==================================================\n\n";
        cout<<"\t\t--------------------------------------------------\n";
        cout<<"\t\t||\t1. Add a new Medicine \t\t\t||\n";
        cout<<"\t\t||\t2. Update a existing Medicine\t\t||\n";
        cout<<"\t\t||\t3. Delete a existing Medicine\t\t||\n";
        cout<<"\t\t||\t4. Print the Medicine List\t\t||\n";
        cout<<"\t\t||\t5. Exit\t\t\t\t\t||\n";
        cout<<"\t\t--------------------------------------------------\n";
        cout<<"Enter choice: ";
        fflush(stdin);
        cin>>choice;

        switch (choice)
        {
        case 1:
            {
                system ("cls");
                cout << "Enter the Medicine Name: ";
                string n;
                cin >> n;

                cout << "\nEnter the number of medicines available in stock : ";
                double avl;
                cin >> avl;

                cout << "\nEnter the price of one Medicine : ";
                double pr;
                cin >> pr;

                med.addMedicine (n, avl, pr);

                cout << endl << "New Medicine added to database successfully..." << endl;
                cout << endl << "You are being redirected to the Admin-Menu";
                cout << endl << endl << "THANK YOU !!!" << endl;

                system ("PAUSE");
                break;
            }

        case 2:
            {
                system ("cls");
                cout << "Enter the Medicine ID you would like to update : ";
                string cid;
                cin >> cid;

                int id;
                string tmp = "";
                for (int i = 3; i < cid.size(); i++)
                {
                    tmp += cid [i];
                }

                id = stoi (tmp);

                med.updateMedicine (id);

				break;
            }

        case 3:
            {
                system ("cls");
                cout << "Enter the Medicine ID you would like to delete : ";
                string cid;
                cin >> cid;

                int id;
                string tmp = "";
                for (int i = 3; i < cid.size(); i++)
                {
                    tmp += cid [i];
                }

                id = stoi (tmp);

                med.deleteMedicine (id);

                break;
            }

		case 4:
		    {
		        med.printMedicine ();
				break;
		    }

        case 5:
            {
                cond = false;
                break;
            }

        default:
            {
                cout << "Invalid Input. Please Try Again.\n";
                system ("PAUSE");
                break;
            }
        }
    }
    cout << "We hope " << onlyAdmin->name << " enjoyed our services.";
    cout << endl << "You are being redirected to the Main-Menu";
    cout << endl << endl << "THANK YOU !!!" << endl;
    system ("PAUSE");
}

class OrderList
{
private:
    vector <Medicine*> od;
    string billName;
    int size;
    int topIndex;

public:
    OrderList()
    {
        Medicine* tmp = new Medicine();

        tmp->name = "";
        tmp->medId = "NULL";
        tmp->price = 0.00;
        tmp->available = 0;

        od.push_back (tmp);

        billName = "";

        size = 0;
        topIndex = 1;
    }

    void createOrderList (MedicineList &med)
    {
        system ("cls");

        cout << "Welcome to The Portal of Ordering Medicines.\n";
        cout <<"_________________________________________________________________________________ \n\n";

        cout << "The List of Medicines available with us are :~ \n\n";
        med.printMedicine ();

        cout << "\n\nEnter the Billing Name : ";
        cin >> billName;

        cout <<"\nEnter the number of unique Medicines you would like to order : ";
        int num;
        fflush(stdin);
        cin >> num;

        while (num--)
        {
            cout <<"\nEnter the Medicine ID you would like to purchase : ";
            string tmp;
            cin >> tmp;

            int index;
            string ind = "";

            for (int i = 3; i < tmp.size(); i++)
            {
                ind += tmp[i];
            }

            index = stoi (ind);

            if (index > med.topIndex && index < 0)
            {
                cout << "\n\nInvalid Medicine ID. TRY AGAIN !!!\n";
                num++;
                system ("PAUSE");
                continue;
            }

            if (med.vec[index]->medId == "NULL")
            {
                cout << "\n\nThe Medicine ID that you entered has been recently deleted. TRY AGAIN !!!\n";
                num++;
                system ("PAUSE");
                continue;
            }

            cout << "\nEnter the quantity of that medicine you require : ";
            fflush(stdin);
            int qty;
            cin >> qty;

            if (qty > med.vec[index]->available)
            {
                cout << "\n\nYou ordered quantity larger than available. TRY AGAIN with lesser quantity !!!\n";
                num++;
                system ("PAUSE");
                continue;
            }

            Medicine* ptr = new Medicine();

            ptr->medId = med.vec[index]->medId;
            ptr->name = med.vec[index]->name;
            ptr->available = qty;
            ptr->price = qty*(med.vec[index]->price);

            cout << "\nThe amount you have to pay is : " << ptr->price;

            od.push_back (ptr);

            med.vec[index]->available -= qty;
            topIndex++;
            cout << endl;
            system ("PAUSE");
        }

        size++;
        cout<<"==========================================================================="<<endl;
        cout << "Order Taken Successfully"<<endl;
        cout<<"==========================================================================="<<endl;
        cout << "Go to CUSTOMER MENU to Pay The Bill"<<endl;
        cout<<"==========================================================================="<<endl;
        cout << "Thank you for ordering from our store" << endl;
        cout << "We hope you enjoyed our services.";
        cout << endl << "You are being redirected to the CUSTOMER MENU";
        cout << endl << endl << "THANK YOU !!!" << endl;
        system ("PAUSE");
    }

    void printReceipt (MedicineList &med)
    {
        system ("cls");

        if (topIndex == 1)
        {
            cout << "There is no pending order requests.\n";
            cout << "Re-directing you to the CUSTOMER MENU...\n";
            cout << "\nTHANK YOU !!!\n";
            system ("PAUSE");
            return;
        }

        string reid = "OD" + to_string (size);

        cout <<"Reciept Number : "<< reid;
		cout <<"\n";
		cout<<"Customer Name: "<< billName <<endl;

		cout<<"__________________________________________________________________________________________________"<<endl;

		cout << "===============================================================================" << endl;
		cout << "|  MEDICINE ID |     MEDICINE NAME    |  	QUANTITY     |    TOTAL PRICE |" << endl;
		cout << "=======++==================++================++===============++===============" << endl;

		double total = 0;
		for (int i = 1; i < od.size(); i++)
		{
			cout << od[i]->medId <<"  \t\t";
			cout<< od[i]->name <<"\t\t\t  ";
			cout<< od[i]->available <<"\t\t";
			cout<< od[i]->price <<endl;
			cout<<"_________________________________________________________________________________"<<endl;

			total += od[i]->price;
		}

		od.clear();

		cout<<"Total Bill is : "<< total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
		fflush(stdin);
		int num;
        cin >> num;

        while (num != total)
        {
            cout << "You entered wrong amount. TRY AGAIN !!!\n";
            fflush(stdin);
            cin >> num;
        }

        cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done.\nThank You.\n";
		cout << "Re-directing you to the Customer Menu\n";
		system ("PAUSE");


    }
};

class Customer : public Users
{
public:
    string customerId;
    Customer (string str, string id)
    {
        name = str;
        customerId = id;
    }
};

class Customers
{
private:
    vector <Customer*> cust;
    int size;
    int topIndex;

public:
    Customers ()
    {
        Customer* tmp = new Customer ("", "NULL");
        cust.push_back (tmp);
        size = 0;
        topIndex = 1;
    }

    void createNewCustomer ()
    {
        system ("cls");

        cout << "Enter your name : ";
        string nm;
        cin >> nm;

        string cid = "CUST" + to_string (topIndex);

        Customer* tmp = new Customer (nm, cid);
        cust.push_back (tmp);

        cout << endl << "New Customer Account created..." << endl << "Your Customer Id is : " << cid;
        cout << endl << "Please keep a note of your customer ID always.";
        cout << endl << "You are being redirected to the Main-Menu";
        cout << endl << endl << "THANK YOU !!!" << endl;

        topIndex++;
        size++;

        system ("PAUSE");
        system ("cls");
    }

    void existingCustomers (MedicineList &med, OrderList &old)
    {
        system ("cls");
        system("COLOR 2");

        if (size == 0)
        {
            cout << "No Existing Customer. Create your new customer ID.\n";
            cout << endl << "You are being redirected to the Main-Menu";
            cout << endl << endl << "THANK YOU !!!" << endl;

            system ("PAUSE");
            system ("cls");
            return;
        }

        cout << "Enter you Customer ID : ";
        string str;
        cin >> str;

        int index;
        string tmp = "";

        for (int i = 4; i < str.size(); i++)
        {
            tmp += str[i];
        }

        index = stoi (tmp);

        if (index > topIndex || index < 1)
        {
            cout << "\nThe Customer ID is invalid.\nWe are re-directing you to the Main Menu.";
            cout << "\n1. If you have forgotten you Customer ID, choose 5 from the MAIN MENU and then find your name from the list along with your Customer ID";
            cout << "\n2. If you have entered the wrong Customer ID by mistake, choose 2 from MAIN MENU to come back to the previous page.";

            cout << endl << endl << "THANK YOU !!!" << endl;
            system ("PAUSE");
            return;
        }

        cout << "Welcome " << cust[index]->name << " !!! \n";
        cout << "\nRe-directing you to the CUSTOMER MENU.\n";

        system ("PAUSE");

        int choice;
        bool cond = true;
        while (cond)
        {
            system("cls");
            cout<<"\t\t\t    CUSTOMER MENU \n";
            cout<<"\t\t===================================================================\n\n";
            cout<<"\t\t-------------------------------------------------------------------\n";
            cout<<"\t\t||\t1. Print the Medicine List \t\t\t\t ||\n";
            cout<<"\t\t||\t2. Place new Medicine order\t\t\t\t ||\n";
            cout<<"\t\t||\t3. Print Order Receipt and Make Payment\t\t\t ||\n";
            cout<<"\t\t||\t4. Exit\t\t\t\t\t\t\t ||\n";
            cout<<"\t\t-------------------------------------------------------------------\n";
            cout<<"Enter choice: ";
            fflush(stdin);
            cin>>choice;

            switch (choice)
            {
            case 1:
                {
                    med.printMedicine ();
                    system ("PAUSE");
                    break;
                }

            case 2:
                {
                    system ("cls");
                    old.createOrderList (med);
                    system("PAUSE");
                    break;
                }

            case 3:
                {
                    system ("cls");
                    old.printReceipt(med);
                    system ("PAUSE");
                    break;
                }

            case 4:
                {
                    system ("PAUSE");
                    cond = false;
                    break;
                }

            default:
                {
                    cout << "Invalid Input. Please Try Again.\n";
                    system ("PAUSE");
                    break;
                }
            }
        }
    }

    void printCustomers ()
    {
        if (size == 0)
        {
            cout << "NO EXISTING CUSTOMERS YET !!!"<< endl;
            cout << endl << "You are being redirected to the Main-Menu";
            cout << endl << endl << "THANK YOU !!!" << endl;
            system ("PAUSE");
            return;
        }

        cout<<"\t\t\t    LIST OF CUSTOMERS \n";
        cout <<"**************************************************************************\n";
        cout<<"CUSTOMER ID"<<"   \t\tCUSTOMER NAME"<<endl;
		cout <<"**************************************************************************\n";
        for (int i = 1; i < cust.size(); i++)
        {
            cout<<cust[i]->customerId<<"\t"<<"\t\t"<<cust[i]->name<<endl;
        }

        cout << endl << "You are being redirected to the Main-Menu";
        cout << endl << endl << "THANK YOU !!!" << endl;
        system ("PAUSE");
    }
};

int main ()
{
    system("COLOR 3");
    Customers c;
    MedicineList med;
    OrderList ol;


    int menu;
    bool cond = true;
	while (cond)
	{
		system("cls");
		system ("COLOR 3");
		cout<<"\t\t\t    Medicine Shop Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1. New Customer \t\t\t ||\n";
		cout<<"\t\t||\t2. Existing Customer \t\t\t ||\n";
		cout<<"\t\t||\t3. New Admin \t\t\t\t ||\n";
		cout<<"\t\t||\t4. Existing Admin \t\t\t ||\n";
		cout<<"\t\t||\t5. Print Customer List \t\t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";
        fflush(stdin);
		cin>>menu;

		switch (menu)
		{
		case 1:
		    {
		        c.createNewCustomer ();
				break;
		    }

		case 2:
				c.existingCustomers(med,ol);
				system("PAUSE");
				break;

		case 3:
			{
				if ((Admin::onlyAdmin) != NULL)
                {
                    cout << "\nAdmin already exists. You cannot create a new one !!!";
                    cout << "\nUse the option Existing Admin to login using the existing credentials\n";
                }

                else
                {
                    system ("cls");
                    cout << "Enter the username of admin : ";
                    string st;
                    cin >> st;

                    string ps = "";
                    string tmp = "";

                    while (ps != tmp || ps == "")
                    {
                        if (ps != "")
                        {
                            cout << "The passwords do not match !!!";
                            cout << "\nTRY AGAIN";
                            cout << endl;
                            system ("PAUSE");
                        }

                        system ("cls");
                        cout << "Enter your password : ";
                        cin >> ps;

                        system ("cls");
                        cout << "Re-enter the password : ";
                        cin >> tmp;
                    }

                    Admin::adminCreate (st,ps);

                    system ("cls");
                    cout << "Your Admin Account is created.\n";
                    cout << "Username : ";
                    cout << st << endl;
                    cout << "Password : ";
                    for (int i = 0; i < ps.length(); i++)
                        cout << "*";

                    cout << endl << "You are being redirected to the Main-Menu";
                    cout << endl << endl << "THANK YOU !!!" << endl;
                    system ("PAUSE");
                }

				break;
			}	//end case 3

		case 4:
			{
			    Admin::onlyAdmin->existingAdmin (med);
				break;
			}	//end case 4
		case 5:
			{
				c.printCustomers ();
				system("PAUSE");
				break;
			}	//end case 5
        case 6:
			{
				cond = false;
				break;
			}	//end case 6


		default:
			{
				cout<<"You enter invalid input\nRe-enter the input\n"<<endl;
				break;
			}
		}
	}


    return 0;
}
