#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;
using std::isdigit;
struct Room {
    string type;
    string number;
    bool isVacant;
    string name;
    int age;
    int hoursOfStay;
    string status;
};
bool hasNumber(const string& str){
    for (char const &c : str) {
        if (std::isdigit(c)) 
            return true;
    }
    return false;
}

int main() {
    int num1;
    string fullName;
    int age;

    Room rooms[15];
    rooms[0] = {"Regular", "RM1", false};
    rooms[1] = {"Regular", "RM2", true};
    rooms[2] = {"Regular", "RM3", true};
    rooms[3] = {"Regular", "RM4", false};
    rooms[4] = {"Regular", "RM5", true};
    rooms[5] = {"Regular", "RM6", true};
    rooms[6] = {"Regular", "RM7", true};
    rooms[7] = {"Regular", "RM8", false};
    rooms[8] = {"Regular", "RM9", true};
    rooms[9] = {"Regular", "RM10", true};
    rooms[10] = {"Deluxe", "RM1", true};
    rooms[11] = {"Deluxe", "RM2", false};
    rooms[12] = {"Deluxe", "RM3", true};
    rooms[13] = {"VIP", "RM1", true};
    rooms[14] = {"VIP", "RM2", false};

    while (true) {
     num1 =0;
    
       while (num1 < 1 || num1 > 4){
        cout << "\t********* WELCOME TO PUPPETEERS HOTEL ツ ********\n";
        cout << "\n1. Room Availability and Pricing\n";
        cout << "2. Book a Room\n";
        cout << "3. Search Room Details\n";
        cout << "4. Exit\n";
        cout << "\n\nEnter your Choice here >> ";
        cin >> num1;

		if (num1 < 1 || num1 > 4){
           cout << "\nInvalid choice.Please Enter a Valid option.";
           cout << "\nEnter your Choice here >> ";
           cin >> num1;
           }
           }
        switch (num1) {
            case 1: {
                cout << "\t** Room Availability and Pricing **\n";
                cout << setw(10) << left << "Room Type" << setw(15) << "Rate(6HRS)" << setw(15) << "Rate(12HRS)" << setw(15) << "Rate(24HRS)" << '\n';
                cout << "_______________________________________________________\n";
                cout << setw(10) << left << "Regular" << setw(15) << "php 1200" << setw(15) << "php 2200" << setw(15) << "php 4200" << '\n';
                cout << setw(10) << left << "Deluxe" << setw(15) << "php 2200" << setw(15) << "php 3200" << setw(15) << "php 5200" << '\n';
                cout << setw(10) << left << "VIP" << setw(15) << "php 4200" << setw(15) << "php 5200" << setw(15) << "php 7200" << '\n';
                cout << "_______________________________________________________\n";
                cout << '\n';

                cout << setw(10) << left << "Room Type" << setw(15) << "Status" << setw(20) << "Room Number" << '\n';
                cout << "_______________________________________________________\n";

                for (int i = 0; i < 15; i++) {
                    cout << setw(10) << left << rooms[i].type << setw(15) << (rooms[i].isVacant ? "Vacant" : "Not Vacant") << setw(20) << rooms[i].number << '\n';
                    if (rooms[i].number == "RM5" || rooms[i].number == "RM10") {
                        cout << "_______________________________________________________\n";
                    }
                }

                cout << "\n>> Prices above are VAT-exclusive. 12% VAT will be added to the total transaction amount.";
                cout << "\n>> 20% Discount shall be applied to senior citizens aged 60 and above.";
                cout << "\n>> Ages 17 and below are not allowed to book/check-in a room alone in this hotel.";
                cout << "\n>> Hours of check-in are fixed (6/12/24) and cannot be altered once booked.";
                break;
            }

            case 2: {
                int roomTypeChoice;
                string roomType;
                string roomNumber;
                double roomRate = 0.0;
                bool isDiscountApplied = false;
                double vat = 0.12;
                double amountBeforeTax = 0.0;
                double vatableAmount = 0.0;
                double totalAmountDue = 0.0;
                double amountTendered = 0.0;
                double change = 0.0;
                bool isMinor = false;
                bool isSeniorCitizen = false;
                bool hasDisability = false;
                double discount = 0.0;
                
                while (true)  {
                cout << "\n \t\t*********** CHECK-IN *********** \n\n";
                cout << "\nSELECT A ROOM TYPE: ";
                cout << "[1] Regular\t[2] Deluxe\t[3] VIP";
                cout << "\nEnter your choice here >> "; 
                cin >> roomTypeChoice;

                if (roomTypeChoice < 1 || roomTypeChoice > 3) {
                    cout << "Invalid room type choice. Please try again.\n";
                    continue;
                    }
                    break;
                }

                if (roomTypeChoice == 1) {
                    roomType = "Regular";
                    while (true) {
                        cout << "SELECT A ROOM NUMBER:\t[1] Regular RM1 [2]Regular RM2 [3]Regular RM3 [4]Regular RM4 [5]Regular RM5 \n\t\t\t[6]Regular RM6 [7]Regular RM7 [8]Regular RM8 [9]Regular RM9 [10]Regular RM10";
                        cout <<"\nEnter your choice here >>";
                        cin >> roomNumber;
                        if (stoi(roomNumber) < 1 || stoi(roomNumber) > 10) {
                            cout << "Invalid room number. Please try again.\n";
                            continue;
                        }
                        if (!rooms[stoi(roomNumber) - 1].isVacant) {
                            cout << "The selected room is not vacant.\n";
                            cout << "Please try again!\n";
                            continue;
                        }
                        break;
                    }
                } else if (roomTypeChoice == 2) {
                    roomType = "Deluxe";
                    while (true) {
                        cout << "SELECT A ROOM NUMBER: [1] Deluxe RM1 [2] Deluxe RM2 [3] Deluxe RM3";
                        cout <<"\nEnter your choice here >>";
                        cin >> roomNumber;
                        if (stoi(roomNumber) < 1 || stoi(roomNumber) > 3) {
                            cout << "Invalid room number. Please try again.\n";
                            continue;
                        }
                        if (!rooms[stoi(roomNumber) + 9].isVacant) {
                            cout << "The selected room is not vacant.\n";
                            cout << "Please try again!\n";
                            continue;
                        }
                        break;
                    }
                } else if (roomTypeChoice == 3) {
                    roomType = "VIP";
                    while (true) {
                        cout << "SELECT A ROOM NUMBER :[1] VIP RM1 [2] VIP RM2 ";
                        cout <<"\nEnter your choice here >>";
                        cin >> roomNumber;
                        if (stoi(roomNumber) < 1 || stoi(roomNumber) > 2) {
                            cout << "Invalid room number. Please try again.\n";
                            continue;
                        }
                        if (!rooms[stoi(roomNumber) + 12].isVacant) {
                            cout << "The selected room is not vacant.\n";
                            cout << "Please try again!\n";
                            continue;
                        }
                        break;
                    }
                }

                string selectedRoom = roomType + " " + roomNumber;

                int hoursChoice;
                while (true) {
                cout << "SELECT NUMBER OF HOURS OF STAY: ";
                cout << "[1] 6 hours\t[2] 12 hours\t[3] 24 hours\t";
                cout << "\nEnter your choice here >>";
                cin >> hoursChoice;

                if (hoursChoice < 1 || hoursChoice > 3) {
                    cout << "Invalid hours of stay choice. Please try again.\n";
                    continue;
                    }
                    break;
                }
                
                if (hoursChoice == 1) {
                    if (roomType == "Regular")
                        roomRate = 1200;
                    else if (roomType == "Deluxe")
                        roomRate = 2200;
                    else if (roomType == "VIP")
                        roomRate = 4200;
                } else if (hoursChoice == 2) {
                    if (roomType == "Regular")
                        roomRate = 2200;
                    else if (roomType == "Deluxe")
                        roomRate = 3200;
                    else if (roomType == "VIP")
                        roomRate = 5200;
                } else if (hoursChoice == 3) {
                    if (roomType == "Regular")
                        roomRate = 4200;
                    else if (roomType == "Deluxe")
                        roomRate = 5200;
                    else if (roomType == "VIP")
                        roomRate = 7200;
                }

              cin.ignore();
           cout << "ENTER YOUR FULL NAME: ";
			getline(cin, fullName);
			while(hasNumber(fullName)) {
   		 cout << "Name should not contain numbers. Please try again.\n";
           cout << "ENTER YOUR FULL NAME: ";
  		  getline(cin, fullName);
			}
			while (true) {
			    cout << "ENTER YOUR AGE: ";
  		  while (!(cin >> age)) {
      			  cout << "Invalid input. Please enter a age number not a letters.\n";
                    cout << "ENTER YOUR AGE: ";
    			    cin.clear();
    			    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			    }

				    if (age <= 17) {
    			    cout << "Minors are not allowed to reserve a room. Please try again.\n";
   			     continue;
				    }
 				   break;
				}


            
		isSeniorCitizen = age >= 60;

            
            bool isWithChildBelow3 = false;
            char response;
            cout << "Are you with a child below 3 years old? [Y/N]: ";
            cin >> response;
            if (response == 'Y' || response == 'y') {
                isWithChildBelow3 = true;
            } else if (response != 'N' && response != 'n') {
                cout << "Invalid input. Please enter 'Y' or 'N'.\n";
            }

            if (age >= 60 || isWithChildBelow3) {
                discount = 0.2;
                isDiscountApplied = true;
            }

                int discountChoice;
                cout << "PERSON WITH DISABILITY? [1] Yes [2] No ";
                cout << "\nEnter your choice here: ";
                cin >> discountChoice;

                if (discountChoice == 1) {
                    hasDisability = true;
                    discount = 0.2;
                    isDiscountApplied = true;
                }

               amountBeforeTax = roomRate ;
				double totalDiscountedRate = 0.0;
				if (isSeniorCitizen || hasDisability || isWithChildBelow3) {
   			 totalDiscountedRate = roomRate * discount;
				}
				amountBeforeTax -= totalDiscountedRate; 
				vatableAmount = amountBeforeTax * vat;
				totalAmountDue = amountBeforeTax + vatableAmount;
                

					cout << "\nTOTAL AMOUNT DUE: PHP " << totalAmountDue;

			while (true) {
    				cout << "\nPlease enter your payment amount: PHP ";
  			  cin >> amountTendered;

    			if(cin.fail()) {
       		 cout << "Invalid input. Please enter a number.\n";
      		  cin.clear();
     		   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   			 } else if(amountTendered < totalAmountDue) {
        		cout << "Booking is unsuccessful. Your payment must cover the total amount due. Please try again.\n";
  			  } else {
    		    break;
  			  }
				}

                	
                change = amountTendered - totalAmountDue;
				
                cout << "\n\t\t********** TRANSACTION SUMMARY **********";

                cout << "\nFULL NAME: " << fullName;
                cout << "\t        AGE: " << age;
                cout << "\nROOM TYPE: " << roomType;
                cout << "\t\tROOM NUMBER: " << "RM" + roomNumber;
                cout << "\nROOM RATE: PHP " << roomRate;
                cout << "\t\tNUMBER OF HOURS OF STAY: ";
                if (hoursChoice == 1) {
                    cout << "6 hours";
                } else if (hoursChoice == 2) {
                    cout << "12 hours";
                } else if (hoursChoice == 3) {
                    cout << "24 hours";
                }

               cout << "\nDISCOUNT APPLIED: " << (isDiscountApplied ? "Yes" : "No");
                cout << "\t\tTOTAL DISCOUNTED RATE: PHP " << totalDiscountedRate;
                cout << "\nAMOUNT BEFORE TAX: PHP " << amountBeforeTax;
                cout << "\tVAT (12%): PHP " << vatableAmount;
                cout << "\n\nTOTAL AMOUNT DUE: PHP " << totalAmountDue;
                cout << "\tSENIOR CITIZEN: " << (isSeniorCitizen ? "Yes" : "No");
                cout << "\nAMOUNT TENDERED: PHP " << amountTendered;
                cout << "\tCHANGE: PHP " << change;

    if (roomType == "Regular")
        rooms[stoi(roomNumber) - 1].isVacant = false;
    else if (roomType == "Deluxe")
        rooms[stoi(roomNumber) + 9].isVacant = false;
    else if (roomType == "VIP")
        rooms[stoi(roomNumber) + 12].isVacant = false;

    // Update room details
    if (roomType == "Regular") {
        rooms[stoi(roomNumber) - 1].name = fullName;
        rooms[stoi(roomNumber) - 1].age = age;
        rooms[stoi(roomNumber) - 1].hoursOfStay = hoursChoice;
        rooms[stoi(roomNumber) - 1].status = "Paid";
    }
    else if (roomType == "Deluxe") {
        rooms[stoi(roomNumber) + 9].name = fullName;
        rooms[stoi(roomNumber) + 9].age = age;
        rooms[stoi(roomNumber) + 9].hoursOfStay = hoursChoice;
        rooms[stoi(roomNumber) + 9].status = "Paid";
    }
    else if (roomType == "VIP") {
        rooms[stoi(roomNumber) + 12].name = fullName;
        rooms[stoi(roomNumber) + 12].age = age;
        rooms[stoi(roomNumber) + 12].hoursOfStay = hoursChoice;
        rooms[stoi(roomNumber) + 12].status = "Paid";
    }

    break;
}

    case 3: {
    while (true) {
        cout << "\t** SEARCH ROOM DETAILS **\n";
        cout << "SELECT A ROOM TYPE: [1] Regular  [2] Deluxe  [3] VIP\n";
        int roomTypeChoice;
        cout << "Enter your choice here >> ";
        cin >> roomTypeChoice;

        string roomType;
        int roomNumber;
        if (roomTypeChoice == 1) {
            roomType = "Regular";
            cout << "SELECT A ROOM NUMBER: \t[1] Regular RM1 [2]Regular RM2 [3]Regular RM3 [4]Regular RM4 [5]Regular RM5 \n\t\t\t[6]Regular RM6 [7]Regular RM7 [8]Regular RM8 [9]Regular RM9 [10]Regular RM10";
            cout << "\nEnter your choice here >> ";
            cin >> roomNumber;
            if (roomNumber < 1 || roomNumber > 10) {
                cout << "Invalid room number. Please try again.\n";
                cout << "\nEnter your choice here >> ";
            cin >> roomNumber;
                continue;
            }
        } else if (roomTypeChoice == 2) {
            roomType = "Deluxe";
            cout << "SELECT A ROOM NUMBER: [1] Deluxe RM1 [2] Deluxe RM2 [3] Deluxe RM3\n";
            cout << "\nEnter your choice here >> ";
            cin >> roomNumber;
            if (roomNumber < 1 || roomNumber > 3) {
                cout << "Invalid room number. Please try again.\n";
               cout << "\nEnter your choice here >> ";
            cin >> roomNumber;
                continue;
            }
        } else if (roomTypeChoice == 3) {
            roomType = "VIP";
            cout << "SELECT A ROOM NUMBER: [1] VIP RM1 [2] VIP RM2\n";
            cout << "\nEnter your choice here >> ";
            cin >> roomNumber;
            if (roomNumber < 1 || roomNumber > 2) {
                cout << "Invalid room number. Please try again.\n";
               cout << "\nEnter your choice here >> ";
            cin >> roomNumber;
                continue;
            }
        } else {
            cout << "Invalid room type choice. Please try again.\n";
            continue;
        }

        bool customerFound = false;
        
        for (int i = 0; i < 15; i++) {
            if (rooms[i].type == roomType && rooms[i].number == ("RM" + to_string(roomNumber))) {
                if (!rooms[i].isVacant) {
                    customerFound = true;
                    cout << "DETAILS FOUND FOR THE SELECTED ROOM:\n";
                    cout << "ROOM TYPE: " << roomType << "\n";
                    cout << "ROOM NUMBER: " << roomNumber << "RM" << "\n";
                    cout << "NAME: " << rooms[i].name << "\n";
                    cout << "AGE: " << rooms[i].age << "\n";
                    cout << "NUMBER OF HOURS OF STAY: ";
                    if (rooms[i].hoursOfStay == 1) {
                        cout << "6 hours";
                    } else if (rooms[i].hoursOfStay == 2) {
                        cout << "12 hours";
                    } else if (rooms[i].hoursOfStay == 3) {
                        cout << "24 hours";
                    }
                    cout << "\nSTATUS: " << rooms[i].status << "\n";
                    break;
                }
            }
        }

        if (!customerFound) {
            cout << "No customer found for the selected room.\n";
        }

        cout << "\nDo you want to search another room? [1] Yes [2] No\n";
        int searchAnotherRoomChoice;
        cout << "Enter your choice here >> ";
        cin >> searchAnotherRoomChoice;

        if (searchAnotherRoomChoice == 2) {
            break; 
        }
    }

    break;
}
    case 4:
                // Exit the program
                cout << "\t******* THIS IS PUPPETEERS HOTEL ********";
                cout << "\n\t     ________________________";
                cout << "\n\t    |   ** THANK YOU ツ **   |";
                cout << "\n\t    |       ** AND **        |"; 
                cout << "\n\t    |   ** COME AGAIN!! ツ** |";
                cout << "\n\t    |________________________|";
                cout << "\n\n\t******* THIS IS PUPPETEERS HOTEL ********";
                return 0;

            default:
                cout << "\nInvalid choice. Please enter a valid option.";
                break;
        }

        
   			
              int yesorno;
do {
  do {
    cout << "\n\nDo you want to go back to the MAIN MENU? \t [1] Yes [2] No";
    cout << "\nEnter your choice here >>";
    cin >> yesorno;
    if(yesorno < 1 || yesorno > 2){
      cout << "\nInvalid choice. Please enter 1 for Yes and 2 for No.\n";
    }
  } while(yesorno < 1 || yesorno > 2);

  if (yesorno == 2) {
    continue;
  } else if (yesorno == 1) {
    
    break;
  }

} while(true);



}

    return 0;
}


   
   
    