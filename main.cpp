#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pet {
public:
    string name;
    string type;
    int age;
    string breed;

    Pet(string n, string t, int a, string b) : name(n), type(t), age(a), breed(b) {}

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Breed: " << breed << endl;
    }
};

class PetAdoptionSystem {
private:
    vector<Pet> pets;

public:
    PetAdoptionSystem() {
        pets.push_back(Pet("Bella", "Dog", 3, "Labrador"));
        pets.push_back(Pet("Max", "Cat", 2, "Persian"));
        pets.push_back(Pet("Buddy", "Dog", 1, "Bulldog"));
        pets.push_back(Pet("Luna", "Cat", 4, "Siamese"));
    }

    void displayAvailablePets() {
        cout << "Available Pets for Adoption:" << endl;
        for (size_t i = 0; i < pets.size(); ++i) {
            cout << i + 1 << ". " << pets[i].name << " (" << pets[i].type << ")" << endl;
        }
    }

    void showPetDetails(int index) {
        if (index < 1 || index > pets.size()) {
            cout << "Invalid selection. Please try again." << endl;
        } else {
            pets[index - 1].displayInfo();
        }
    }

    void adoptPet(int index) {
        if (index < 1 || index > pets.size()) {
            cout << "Invalid selection. Please try again." << endl;
        } else {
            cout << "Congratulations! You have successfully adopted " << pets[index - 1].name << "." << endl;
            pets.erase(pets.begin() + index - 1);
        }
    }
};

void showMenu() {
    cout << "Pet Adoption System" << endl;
    cout << "1. View Available Pets" << endl;
    cout << "2. View Pet Details" << endl;
    cout << "3. Adopt a Pet" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    PetAdoptionSystem system;
    int choice, petIndex;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            system.displayAvailablePets();
            break;
        case 2:
            cout << "Enter the number of the pet to view details: ";
            cin >> petIndex;
            system.showPetDetails(petIndex);
            break;
        case 3:
            cout << "Enter the number of the pet you want to adopt: ";
            cin >> petIndex;
            system.adoptPet(petIndex);
            break;
        case 4:
            cout << "Thank you for using the Pet Adoption System. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
