/**------------------------------------------
    Program 4, Part 2: User Interface for Contacts

    Course: CS 141, Fall 2022.
    System: Linux x86_64 and G++
    Author: Ayush Patel, Classes provied by :George Maratos and David Hayes
 ---------------------------------------------**/


#include <iostream>
#include <vector>
#include "Contact.h"
#include "ContactList.h"
using namespace std;

//this function is for the menu in general
void themenu() {
    cout << endl;
    cout << endl;
    cout << "********************************************" << endl;
    cout << "Main Menu" << endl;
    cout << endl;
    cout << "Enter the letter for the desired menu option: " << endl;
    cout << "    C - Get count" << endl;
    cout << "    L - Load contacts from file" << endl;
    cout << "    S - Search contacts" << endl;
    cout << "    P - Print contacts" << endl;
    cout << "    X - Exit" << endl;
    cout << endl;
    cout << endl;
}


//user a do while loop, went through all of the general menu options with if and else if statements using toupper to accept any user input case, user the -> this method to access functions from the Contact class, used stoi to convert the strings into integers for phone numbers and the number options that the user wanted to access to edit the contacts in their phone, user the reference method to access the data from the ContactList object, mutiple if and else if statements within each general option
int main() {
  //general contactlist object
  ContactList optionL;
  vector<int> numberofcontactsfound;
  char userInput;
  do { 
    themenu();
    cin >> userInput;
    if (toupper(userInput) == 'C') {
      
      cout << "There are " << optionL.getCount() << " contacts" << endl;
    }
    else if (toupper(userInput) == 'L') {
      // ContactList optionL;
      cout << "Enter a filename" << endl;
      string filename;
      cin >> filename;
      cout << optionL.loadContactsFromFile(filename) << endl;
    }
    else if (toupper(userInput) == 'S') {
      ContactList* contacts = &optionL;
      cout << "Enter a search term" << endl;
      string searchitem;
      cin >> searchitem;
      cout << endl;
      cout << endl;
      optionL.findContactsByName(searchitem);
      numberofcontactsfound = optionL.findContactsByName(searchitem);
      if (optionL.findContactsByName(searchitem).size() == 1) {
        cout << "Found " << optionL.findContactsByName(searchitem).size() << " result" << endl;
      }
      else {
      cout << "Found " << optionL.findContactsByName(searchitem).size() << " results" << endl;
      }
      for (int i = 0; i < numberofcontactsfound.size(); i++) {
        optionL.getContact(i);
        Contact* options = contacts->getContact(numberofcontactsfound.at(i));
        cout << i+1 << ". ";
        cout << options->getName();
        cout << endl;
      }
      string newinput;
      vector<int> gnew = optionL.findContactsByName(searchitem);
      cout << "Enter an option: " << endl;
      cout << "   P - Print contacts" << endl;
      cout << "   or a Contact number to view/edit" << endl;
      cout << "   R - Return to main menu" << endl;
      cin >> newinput;
      if (newinput == "R") {
        
      }
      else if (newinput == "P") {
        optionL.printContacts(numberofcontactsfound);
        }
      else if (newinput != "R" && newinput != "P") {
        optionL.getContact(stoi(newinput));
        Contact* options = contacts->getContact(numberofcontactsfound.at(stoi(newinput)-1));
        cout << options->getAsString();
      
      cout << "Enter an option for contact: " << endl;
      cout << "   A - Edit address " << endl;
      cout << "   B - Edit date of birth " << endl;
      cout << "   E - Edit email address " << endl;
      cout << "   N - Edit name " << endl;
      cout << "   P - Edit phone numbers " << endl;
      cout << "   R - Return to main menu " << endl;
      cout << "   D - Delete " << endl;
      char editinput;
      cin >> editinput;
      if (toupper(editinput) == 'D') {
        optionL.getContact(stoi(newinput));
        Contact* options = contacts->getContact(numberofcontactsfound.at(stoi(newinput)-1));
        cout << "Are you sure you want to delete contact " << options->getName() << "?" << endl;
        cout << "Enter 'Y' to confirm." << endl;
        char yorn; 
        cin >> yorn;
        if (toupper(yorn) == 'Y') {
          optionL.getContact(stoi(newinput));
          Contact* options = contacts->getContact(numberofcontactsfound.at(stoi(newinput)-1));
          cout << optionL.deleteContact(numberofcontactsfound.at(stoi(newinput)-1)) << endl;
        }
        
      }
      else if (toupper(editinput) == 'E') {
        optionL.getContact(stoi(newinput));
        Contact* options = contacts->getContact(numberofcontactsfound.at(stoi(newinput)-1));
        cout << "Current email: " << endl;
        cout << options->getEmail() << endl;
        cout << "Enter new email or C to cancel: " << endl;
        string newemail;
        cin >> newemail;
        if (newemail == "C") {
          
        }
        else {
          cout << endl;
          cout << "Email updated: " << endl;
          cout << newemail << endl;
          options->setEmail(newemail);
        }
      }
      else if (toupper(editinput) == 'P') {
        optionL.getContact(stoi(newinput));
        Contact* options = contacts->getContact(numberofcontactsfound.at(stoi(newinput)-1));
        if (options->getPhoneNumbers().size()==1) {
          cout << "Found " << options->getPhoneNumbers().size() << " phone number " << endl;
        }
        else {
          cout << "Found " << options->getPhoneNumbers().size() << " phone numbers " << endl;
        }
        for (int i = 0; i < options->getPhoneNumbers().size(); i++) {
          cout << i + 1 << ". " << options->getPhoneNumbers().at(i) << endl;;
        }
        cout << "Enter an option: " << endl;
        cout << "   A - Add a phone number " << endl;
        cout << "   R - Return to main menu " << endl;
        cout << "   or list number to delete " << endl;
        string optionhere;
        cin >> optionhere;
        if (optionhere == "R") {
          
        }
        else if (optionhere == "A") {
          cout << "Enter the letter for the phone number type: " << endl;
          cout << "C(ell), W(ork) or H(ome) " << endl;
          char thephonet;
          cin >> thephonet; 
          optionL.getContact(stoi(newinput));
          Contact* options = contacts->getContact(numberofcontactsfound.at(stoi(newinput)-1));
          cout << "Enter the phone number: " << endl;
          string newphone;
          cin >> newphone;
          cout << options->addPhone(thephonet, newphone) << endl;
        }
        else {
          optionL.getContact(stoi(newinput));
          Contact* options = contacts->getContact(numberofcontactsfound.at(stoi(newinput)-1));
          cout << "Are you sure you want to delete phone: " << options->getPhoneNumbers().at(stoi(optionhere)-1) << "?" << endl;
          cout << "Enter 'Y' to confirm. " << endl;
          char y;
          cin >> y;
          if (toupper(y) == 'Y') {
            cout << options->deletePhone(stoi(optionhere)-1) << endl;
          }
          
        }
      }
      
    }
    }
    else if (userInput == 'P') {
      optionL.printContacts(numberofcontactsfound);
    }
  }
  while (toupper(userInput) != 'X' && !cin.eof());
     
}