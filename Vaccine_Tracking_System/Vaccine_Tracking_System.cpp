#include <iostream>
#include <string>
using namespace std;

struct Citizen {
    string name;
    int ID;
    string password;
    string gender;
    int age;
    string government;
    string country;
    bool vaccinated;
    int numbers_of_vaccinated;
};

class Node {
public:
    Citizen data;
    Node* next;

    Node(const Citizen& citizen) {
        data = citizen;
        next = NULL;
    }
};

class WaitingList {
public:
    Node* front;
    Node* rear;

    WaitingList() {
        this->front = NULL;
        this->rear = NULL;
    }

    bool IsEmpty() {
        return front == NULL;
    }

    void AddToWaitingList(const Citizen& citizen) {
        Node* newNode = new Node(citizen);
        if (IsEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void RemoveFromWaitingList() {
        if (IsEmpty()) {
            cout << "The WaitingList is Empty......." << endl;
        }
        else if (front == rear) {
            Node* delptr = front;
            front = rear = NULL;
            delete delptr;
        }
        else {
            Node* delptr = front;
            front = front->next;
            delete delptr;
        }
        cout << "The Citizen Vaccined...\n";
    }

    void Display() {
        if (IsEmpty()) {
            cout << "The WaitingList is Empty......." << endl;
        }
        else {
            Node* temp = front;
            int i = 1;
            while (temp != NULL) {
                cout << "---------------------------------------" << endl;
                cout << "Citizen Info No." << i << " Is : " << endl;
                cout << "Name Is : " << temp->data.name << endl;
                cout << "National ID Is : " << temp->data.ID << endl;
                cout << "Password Is : " << temp->data.password << endl;
                cout << "Gender Is : " << temp->data.gender << endl;
                cout << "Age Is : " << temp->data.age << endl;
                cout << "Government Is : " << temp->data.government << endl;
                cout << "Country Is : " << temp->data.country << endl;
                cout << "VaccinatedState Is : " << temp->data.vaccinated << endl;
                cout << "---------------------------------------" << endl;
                temp = temp->next;
                i++;
            }
            cout << endl;
        }
    }
};

class Citizens {
private:
    Node* head;

public:
    Citizens() {
        head = NULL;
    }

    bool isEmpty() {
        return (head == NULL);
    }

    void add(const Citizen& citizen) {
        Node* newNode = new Node(citizen);
        if (isEmpty()) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    bool isFound(const int& ID, const string& password) {
        bool found = false;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data.ID == ID && temp->data.password == password) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }

    void displayCitizen(const int& ID, const string& password) {
        Node* temp = head;
        while (temp != NULL) {
            if (isFound(ID, password)) {
                cout << "---------------------------------------" << endl;
                cout << "Your Personal Info Is : " << endl;
                cout << "Your Name Is : " << temp->data.name << endl;
                cout << "Your National ID Is : " << temp->data.ID << endl;
                cout << "Your Password Is : " << temp->data.password << endl;
                cout << "Your Gender Is : " << temp->data.gender << endl;
                cout << "Your Age Is : " << temp->data.age << endl;
                cout << "Your Government Is : " << temp->data.government << endl;
                cout << "Your Country Is : " << temp->data.country << endl;
                cout << "Your VaccinatedState Is : " << temp->data.vaccinated << endl;
                cout << "Your Taken Number Of doses Is : " << temp->data.numbers_of_vaccinated << endl;
                cout << "---------------------------------------" << endl;
                break;
            }
            temp = temp->next;
        }

        if (!isFound(ID, password)) {
            cout << "This citizen Not Found.......\n";
        }
    }

    void DeleteCitizen(const int& ID, const string& password) {
        Node* delptr = head;
        Node* prv = NULL;
        while (delptr != NULL && !isFound(ID, password)) {
            prv = delptr;
            delptr = delptr->next;
        }

        if (delptr == NULL) {
            cout << "This citizen Not Found.......\n";
            return;
        }

        if (prv == NULL) {
            head = head->next;
            delete delptr;
        }
        else {
            prv->next = delptr->next;
            delete delptr;
        }
    }

    void displayAll() {
        if (isEmpty()) {
            cout << "There Is Not Records To Display......." << endl;
        }
        else {
            Node* temp = head;
            int i = 1;
            while (temp != NULL) {
                cout << "---------------------------------------" << endl;
                cout << "Citizen Info No." << i << " Is : " << endl;
                cout << "Name Is : " << temp->data.name << endl;
                cout << "National ID Is : " << temp->data.ID << endl;
                cout << "Gender Is : " << temp->data.gender << endl;
                cout << "Age Is : " << temp->data.age << endl;
                cout << "Government Is : " << temp->data.government << endl;
                cout << "Country Is : " << temp->data.country << endl;
                cout << "VaccinatedState Is : " << temp->data.vaccinated << endl;
                cout << "Taken Number Of doses Is : " << temp->data.numbers_of_vaccinated << endl;
                cout << "---------------------------------------" << endl;
                temp = temp->next;
                i++;
            }
            cout << endl;
        }
    }

    bool IsFound(const int& ID) {
        bool found = false;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data.ID == ID) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }

    void displayCitizen(const int& ID) {
        Node* temp = head;
        int i = 1;
        while (temp != NULL) {
            if (IsFound(ID)) {
                cout << "---------------------------------------" << endl;
                cout << "Citizen Info With ID '" << ID << "' Is: " << endl;
                cout << "Name Is : " << temp->data.name << endl;
                cout << "National ID Is : " << temp->data.ID << endl;
                cout << "Gender Is : " << temp->data.gender << endl;
                cout << "Age Is : " << temp->data.age << endl;
                cout << "Government Is : " << temp->data.government << endl;
                cout << "Country Is : " << temp->data.country << endl;
                cout << "VaccinatedState Is : " << temp->data.vaccinated << endl;
                cout << "Taken Number Of doses Is : " << temp->data.numbers_of_vaccinated << endl;
                cout << "---------------------------------------" << endl;
                break;
            }
            temp = temp->next;
            i++;
        }

        if (!IsFound(ID)) {
            cout << "This citizen Not Found.......\n";
        }
    }

    void DeleteCitizen(const int& ID) {
        Node* delptr = head;
        Node* prv = NULL;
        while (delptr != NULL && !IsFound(ID)) {
            prv = delptr;
            delptr = delptr->next;
        }

        if (delptr == NULL) {
            cout << "This citizen Not Found.......\n";
            return;
        }

        if (prv == NULL) {
            head = head->next;
            delete delptr;
        }
        else {
            prv->next = delptr->next;
            delete delptr;
        }

        cout << "Citizen with ID " << ID << " deleted successfully.\n";
    }

    void DeleteAllCitizen() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "All Citizens Are Deleted......\n";
    }

    void printBasicStatistics() {
        int totalPopulation = 0;
        int appliedForVaccination = 0;
        int unvaccinated = 0;
        int receivedAtLeastOneDose = 0;
        int fullyVaccinated = 0;

        Node* temp = head;
        while (temp != NULL) {
            totalPopulation++;
            if (temp->data.vaccinated) {
                appliedForVaccination++;
                if (temp->data.numbers_of_vaccinated > 0) {
                    receivedAtLeastOneDose++;
                    if (temp->data.numbers_of_vaccinated == 2) {
                        fullyVaccinated++;
                    }
                }
            }
            else {
                unvaccinated++;
            }
            temp = temp->next;
        }

        cout << "Basic Statistics:" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Percentage of those who applied for vaccination: " << ((double)appliedForVaccination / totalPopulation) * 100 << "%" << endl;
        cout << "Percentage of the unvaccinated: " << ((double)unvaccinated / totalPopulation) * 100 << "%" << endl;
        cout << "Percentage of those who received at least one dose: " << ((double)receivedAtLeastOneDose / totalPopulation) * 100 << "%" << endl;
        cout << "Percentage of those who got fully vaccinated: " << ((double)fullyVaccinated / totalPopulation) * 100 << "%" << endl;
        cout << "---------------------------------------" << endl;
    }

};

class Admin {
public:
    const string Name = "1";
    const string Password = "1";

    bool login(string name, string password) {
        bool valid = false;
        if (name == Name && password == Password) {
            valid = true;
        }
        else {
            valid = false;
        }
        return valid;
    }
};

void MainShowMenu(WaitingList& waitingList, Citizens& citizens) {
    cout << "<====Welcome To Egyptian Vaccine Tracking System====>" << endl;
    cout << "1) Admin View " << endl;
    cout << "2) Citizen View " << endl;
    cout << "0) Exit " << endl;
    cout << "Please Choose What View Do You Want: ";
    int Mainchoice;
    cin >> Mainchoice;
    Admin admin;
    while (Mainchoice != 0) {
        switch (Mainchoice) {
        case 1: {
            string name, password;
            cout << "Enter Admin Name: ";
            cin >> name;
            cout << "Enter Admin Password: ";
            cin >> password;
            if (admin.login(name, password)) {
                int Adminchoice;
                do {
                    cout << "<====Admin View====>" << endl;
                    cout << "1) Display All Records " << endl;
                    cout << "2) Display Any Record " << endl;
                    cout << "3) Delete All Records " << endl;
                    cout << "4) Delete Any Record " << endl;
                    cout << "5) Show Basic Statistics " << endl;
                    cout << "6) Manage The WaitingList " << endl;
                    cout << "0) Back To Main Menu " << endl;
                    cout << "Please Choose What View Do You Want: ";
                    cin >> Adminchoice;
                    switch (Adminchoice) {
                    case 1:
                        citizens.displayAll();
                        break;
                    case 2: {
                        int ID;
                        cout << "To Display Specific Record You Must Enter ID :  " << endl;
                        cin >> ID;
                        citizens.displayCitizen(ID);
                        break;
                    }
                    case 3:
                        citizens.DeleteAllCitizen();
                        break;
                    case 4: {
                        int ID;
                        cout << "To Delete Specific Record You Must Enter ID :  " << endl;
                        cin >> ID;
                        citizens.DeleteCitizen(ID);
                    }
                          break;
                    case 5: {
                        citizens.printBasicStatistics();
                    }
                          break;
                    case 6: {
                        int Waitingchoice;
                        do {
                            cout << "<====WaitingList View====>" << endl;
                            cout << "1) Display The WaitingList  " << endl;
                            cout << "2) Vaccine Citizen " << endl;
                            cout << "0) Back To Admin menu " << endl;
                            cout << "Please Choose What View Do You Want: ";
                            cin >> Waitingchoice;
                            switch (Waitingchoice) {
                            case 1:
                                waitingList.Display();
                                break;
                            case 2:
                                waitingList.RemoveFromWaitingList();
                                break;
                            case 0:
                                break;
                            default:
                                cout << "You Entered An Invalid Choice." << endl;
                            }
                        } while (Waitingchoice != 0);
                    }
                          break;
                    }
                } while (Adminchoice != 0);
            }
            else {
                cout << "Invalid Admin Credentials. Please try again." << endl;
            }
            break;
        }

        case 2: {
            int Citizenchoice;
            do {
                cout << "<====Citizen View====>" << endl;
                cout << "1) Log In " << endl;
                cout << "2) Sign Up " << endl;
                cout << "0) Back To Main Menu " << endl;
                cout << "Please Choose What View Do You Want: ";
                cin >> Citizenchoice;
                switch (Citizenchoice) {
                case 1: {
                    string citizenPassword;
                    int citizenID;
                    cout << "Enter Your ID: ";
                    cin >> citizenID;
                    cout << "Enter Your Password: ";
                    cin >> citizenPassword;
                    if (citizens.isFound(citizenID, citizenPassword)) {
                        int Loginchoice;
                        do {
                            cout << "<====Citizen View====>" << endl;
                            cout << "1) Display Your Record  " << endl;
                            cout << "2) Update Your Record  " << endl;
                            cout << "3) Delete Your Record  " << endl;
                            cout << "0) Back To Citizen Menu " << endl;
                            cout << "Please Choose What View Do You Want: ";
                            cin >> Loginchoice;
                            switch (Loginchoice) {
                            case 1:
                                citizens.displayCitizen(citizenID, citizenPassword);
                                break;
                            case 2: {
                                citizens.DeleteCitizen(citizenID, citizenPassword);
                                cout << "Enter updated Info : \n\n";
                                Citizen newCitizen;
                                cout << "Enter Name: ";
                                cin >> newCitizen.name;
                                cout << "Enter National  ID: ";
                                cin >> newCitizen.ID;
                                while (citizens.IsFound(newCitizen.ID)) {
                                    cout << "A citizen with this National ID already exists. Please enter a unique National  ID.\n";
                                    cout << "Enter National  ID: ";
                                    cin >> newCitizen.ID;
                                }
                                cout << "Enter Password: ";
                                cin >> newCitizen.password;
                                cout << "Enter Gender (Enter M for Male, F for Female) : ";
                                cin >> newCitizen.gender;
                                cout << "Enter Age: ";
                                cin >> newCitizen.age;
                                cout << "Enter Government: ";
                                cin >> newCitizen.government;
                                cout << "Enter Country: ";
                                cin >> newCitizen.country;
                                cout << "Are you vaccinated? (Enter 1 for Yes, 0 for No): ";
                                cin >> newCitizen.vaccinated;
                                if (newCitizen.vaccinated == 1) {
                                    cout << "How many number of vaccinations? (Enter 1 or 2): ";
                                    cin >> newCitizen.numbers_of_vaccinated;
                                }
                                else {
                                    newCitizen.numbers_of_vaccinated = 0;
                                    waitingList.AddToWaitingList(newCitizen);
                                }
                                citizens.add(newCitizen);
                                cout << " Successful update!" << endl;
                                Loginchoice = 0;
                                break;
                            }
                            case 3:
                                citizens.DeleteCitizen(citizenID, citizenPassword);
                                cout << "Citizen with ID " << citizenID << " deleted successfully.\n";
                                break;
                            case 0:
                                break;
                            default:
                                cout << "You Entered An Invalid Choice." << endl;
                            }
                        } while (Loginchoice != 0);
                    }
                    else {
                        cout << "Citizen Not Found or Invalid Credentials." << endl;
                    }
                    break;
                }
                case 2: {
                    Citizen newCitizen;
                    cout << "Enter Name: ";
                    cin >> newCitizen.name;
                    cout << "Enter National  ID: ";
                    cin >> newCitizen.ID;
                    while (citizens.IsFound(newCitizen.ID)) {
                        cout << "A citizen with this National ID already exists. Please enter a unique National  ID.\n";
                        cout << "Enter National  ID: ";
                        cin >> newCitizen.ID;
                    }
                    cout << "Enter Password: ";
                    cin >> newCitizen.password;
                    cout << "Enter Gender (Enter M for Male, F for Female) : ";
                    cin >> newCitizen.gender;
                    cout << "Enter Age: ";
                    cin >> newCitizen.age;
                    cout << "Enter Government: ";
                    cin >> newCitizen.government;
                    cout << "Enter Country: ";
                    cin >> newCitizen.country;
                    cout << "Are you vaccinated? (Enter 1 for Yes, 0 for No): ";
                    cin >> newCitizen.vaccinated;
                    if (newCitizen.vaccinated == 1) {
                        cout << "How many number of vaccinations? (Enter 1 or 2): ";
                        cin >> newCitizen.numbers_of_vaccinated;
                    }
                    else {
                        newCitizen.numbers_of_vaccinated = 0;
                        waitingList.AddToWaitingList(newCitizen);
                    }
                    citizens.add(newCitizen);
                    cout << "Sign Up Successful!" << endl;
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "You Entered An Invalid Choice." << endl;
                }
            } while (Citizenchoice != 0);
            break;
        }
        default:
            cout << "You Entered An Invalid Choice." << endl;
            break;
        }
        cout << "<====Welcome To Egyptian Vaccine Tracking System====>" << endl;
        cout << "1) Admin View " << endl;
        cout << "2) Citizen View " << endl;
        cout << "0) Exit " << endl;
        cout << "Please Choose What View Do You Want: ";
        cin >> Mainchoice;
    }
    cout << "Exiting..." << endl;
}

int main() {
    Citizens citizens;
    WaitingList waitingList;

    // Adding 10 test citizens
    for (int i = 1; i <= 10; ++i) {
        Citizen newCitizen;
        newCitizen.name = "Citizen" + to_string(i);
        newCitizen.ID = i;
        newCitizen.password = "password" + to_string(i);
        newCitizen.gender = (i % 2 == 0) ? "M" : "F"; // Alternate between M and F
        newCitizen.age = 20 + i; // Ages 21 to 30
        newCitizen.government = "Government" + to_string(i);
        newCitizen.country = "Country" + to_string(i);
        newCitizen.vaccinated = (i % 3 == 0); // Every third citizen is vaccinated
        newCitizen.numbers_of_vaccinated = (newCitizen.vaccinated) ? ((i % 2 == 0) ? 2 : 1) : 0; // If vaccinated, 50% chance of 1 or 2 doses

        if (!newCitizen.vaccinated) {
            waitingList.AddToWaitingList(newCitizen);
        }

        citizens.add(newCitizen);
    }
    MainShowMenu(waitingList, citizens);
    return 0;
}

