/*

                                OOPS PROJECT

Question: 
Write a C++ program to create a shopping mall system. Program should facilitate the end user to create a separte file for each store in mall with store name as the file name. store record details should be :sname,regno,and quantity of items .Provide a menu driven o/p with following options for the program:                                                                                                                                                                      option 1-> To enter store details and display separately each file as o/p                                                                                                                option 2-> To edit quantity of items and also display the updated content                                                       option 3-> To append the floor-no to a store file & display appended content on screen												
												
Group: G10

Members: 
- Sohal Shantesh Sawardekar     [22B-CO-058]
- Soham Sanjog Bhatkuly         [22B-CO-059]																		
- Sphoorti Nippanikar           [22B-CO-060]																		
- Srideep Sunil Kavlekar        [22B-CO-061]																		
- Sushant Govind Shetti         [22B-CO-062]																		
- T.S. Vivek                    [22B-CO-063]	

*/											

//Code: 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#if defined(_WIN32)
    #define clear system("cls");
#else
    #define clear system("clear");
#endif
using namespace std;

class store_Details {
    string sname;
    unsigned int reg_no;
    unsigned int quantity;
    string floorLevel;
public:
    store_Details() {
        sname = "";
        reg_no = 0;
        quantity = 0;
        floorLevel = "";
    }
    bool fileExists(string filename) {
        ifstream file(filename.c_str());
        return file.good();
    }
    friend istream& operator>>(istream& i, store_Details& d) {
        cout.width(27);
        cout << "Store Name : ";
        i >> d.sname;

        cout.width(27);
        cout << "Reg_No. : ";
        i >> d.reg_no;

        cout.width(27);
        cout << "Quantity Of Items : ";
        i >> d.quantity;

        return i;
    }
    
    friend ostream& operator<<(ostream& dout, store_Details& d) {
        dout << "\nName\t : " << d.sname << endl;
        dout << "Reg_no\t : " << d.reg_no << endl;
        dout << "Quantity : " << d.quantity << endl;
        dout << "Floor\t : " << d.floorLevel << endl;
        return dout;
    }

    void writeToFile() {
        string filename = sname + ".txt";
        ofstream file(filename.c_str());
        if (!file.good()) {
            cout << "ERROR : File Creation Unsuccessful !!" << endl;
            return;
        }

        file << sname << endl;
        file << reg_no << endl;
        file << quantity << endl;
        file << floorLevel << endl;
        floorLevel="";
        file.close();
        cout <<"File Named "<< sname << ".txt ";    
    }

    bool readFile(string temp) {

        ifstream file(temp.c_str());
        
        if (!file.good()) {
            cout <<"File Named "<< temp << " Doesn't Exists" << endl;
            return false;
        }

        file >> sname >> reg_no >> quantity >> floorLevel;
        file.close();
        return true;
    }

    void editQuantity() {
        cout.width(27);
        cout<<"Current Quantity : " << quantity <<endl;
        cout.width(27);
        cout << "Enter NEW Quantity: ";
        cin >> quantity;
        writeToFile();
    }

    void addFloor() {
        cout << "Enter the floor Number: ";
        cin >> floorLevel;
        writeToFile();
    }

    void displayFileContent() {
        string temp;
        cout << "Enter the store name: ";
        cin >> temp;
        temp += ".txt";
        ifstream file(temp.c_str());

        if (!file.good()) {
            cout << "ERROR : Can't Open File || File Doesn't Exists !" << endl;
            return;
        }

        string line;
        readFile(temp);
        cout.width(27);
        cout<<"Store Name : " << sname << endl;
        cout.width(27);
        cout<<"Reg_No. : " << reg_no << endl;
        cout.width(27);
        cout<<"Quantities: " << quantity << endl;
        cout.width(27);
        if(floorLevel!="")
            cout<<"Floor : " << floorLevel << endl;
        floorLevel="";
        sname = "";

        file.close();
    }
};

void Menu(){
    cout.fill(' ');
    cout.width(15);cout << "MENU : \n";
    cout.width(9);cout << "[1] " << ": Enter Details for New Store" << endl;  
    cout.width(9);cout << "[2] " << ": Edit Store Items" << endl;  
    cout.width(9);cout << "[3] " << ": Append Floor Details" << endl;  
    cout.width(9);cout << "[4] " << ": Display Store Details" << endl;  
    cout.width(9);cout << "[5] " << ": Exit" << endl;  
    cout.width(91); cout.fill('-'); cout<<"\n\n";
    cout.fill(' ');
}

void header()
{
        cout.width(90); cout.fill('_'); cout<<"\n";
        cout.width(91); cout.fill('"'); cout<<"\n\n";

        cout.fill(' '); cout.width(27); cout<<" ";
        cout.fill('*'); cout.width(25); cout<<" SHOPPING MALL SYSTEM "; cout.width(5); cout<<" \n";
        cout.fill(' '); cout.width(30); cout<<" "; cout.width(24); cout.fill('^'); cout<<" \n";
        cout.width(9); cout.fill(' '); cout<<" "<< cout.fill('-'); cout.width(72);cout<<" \n";
        cout.width(30); cout.fill(' '); cout<<" "<<"Project Group : [G - 10]"<<endl;
        cout.width(27); cout.fill(' '); cout<<" ";cout.width(33); cout.fill('~'); cout<<" \n";
        cout.width(21); cout.fill(' '); cout<<" "<<"-> (22B-CO-058) : Sohal Shantesh Sawardekar \n";
        cout.width(21); cout.fill(' '); cout<<" "<<"-> (22B-CO-059) : Soham Sanjog Bhatkuly \n";
        cout.width(21); cout.fill(' '); cout<<" "<<"-> (22B-CO-060) : Sphoorti Nippanikar \n";
        cout.width(21); cout.fill(' '); cout<<" "<<"-> (22B-CO-061) : Srideep Sunil Kavlekar \n";
        cout.width(21); cout.fill(' '); cout<<" "<<"-> (22B-CO-062) : Sushant Govind Shetti \n";
        cout.width(21); cout.fill(' '); cout<<" "<<"-> (22B-CO-063) : T.S. Vivek \n";
        cout.width(9); cout.fill(' '); cout<<" "<< cout.fill('-'); cout.width(73);cout<<" \n\n";
        cout.width(90); cout.fill('_'); cout<<"\n";
        cout.width(92); cout.fill('"'); cout<<"\n\n\n";
        cout.width(91); cout.fill('_'); cout<<"\n\n";
        cout.fill(' ');
}


int main() {
    store_Details d;
    int x;
    char y;
    while (true) {
        
        clear
        header();
        Menu();
        cout << "Select your choice: ";
        cin >> x;
        cout << endl;
        switch (x) {
            case 1: {
                clear
                header();
                string temp;
                cout.width(60);
                cout<<"Option : 1 } ENTER NEW STORE DETAILS \n\n";
                cout << "Enter store name to check if it exists : ";
                cin >> temp;
                temp += ".txt";
                if (!d.fileExists(temp)) {
                    cout << ": " << endl;
                    cin >> d;
                    d.writeToFile();
                    cout <<"created Successfully !!" << endl;
                } else {
                    cout.width(33);
                    cout << "! Store with Name "<<temp<<" already Exits !\n ";
                    cout.width(45);
                    cout << "Enter a different Name\n";
                }
                cout << "\n\nPress any to continue.\n";
                cin >> y;
                break;
            }
            case 2: {
                clear
                header();
                string temp;
                cout.width(60);
                cout<<"Option : 2 } EDIT QUANTITIES\n\n";
                cout << "Enter the Store Name : ";
                cin >> temp;
                temp += ".txt";
        
                if(d.readFile(temp))
                {
                    d.editQuantity();
                    cout <<"edited Successfully !!" << endl;
                }
                cout << "\n\nPress any to continue.\n";
                cin >> y;
                break;
            }
            case 3: {
                clear
                header();
                string temp;
                cout.width(60);
                cout<<"Option : 3 } APPEND FLOOR \n\n";
                cout << "Enter the store name: ";
                cin >> temp;
                temp += ".txt";
                if(d.readFile(temp))
                {
                    d.addFloor();
                    cout <<"appended with floor details  Successfully !!" << endl;
                }
                cout << "\n\nPress any to continue.\n";
                cin >> y;
                break;
            }
            case 4: {
           
                clear
                header();

                cout.width(60);
                cout<<"Option : 4 } DISPLAY STORE DETAILS \n\n";
                d.displayFileContent();
                cout << "\n\nPress any to continue.\n";
                cin >> y;
                break;
            }
            case 5:
                clear
                header();
                cout.width(91); cout.fill('>'); cout<<"\n\n";
               cout.width(70);
               cout.fill(' ');
                cout<<"Option : 5 } EXITING FROM SHOPPING MALL SYSTEM \n\n";
                cout.width(30); cout.fill(' '); cout<<" ";
                cout.fill('<'); cout.width(18); cout<<"-> THANK YOU <-";
                cout.width(5); cout.fill('>'); cout<<" \n";
                cout << endl << endl ; 
                return 0;
            default:
                clear
                header();
                cout.width(60);
                cout << " ! Invalid choice !";
                cout << "\n\nPress any to continue.\n";
                cin >> y;
                
        }
    }

    return 0;
}