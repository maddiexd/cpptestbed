#include <iostream>
#include <string>
using namespace std;



class pet {
    public:
        pet(string hName) {
            food = 7;
            water = 5;
            happiness = 7;
            name = hName;
            died = false;
            cout << "Hello! My name is " << name << "! I am your new pet." << endl;
            showStats();
        }
        void feed(int amount) {
            int original = food;
            food = min(10, food+amount);
            cout << "Nom Nom Nom!" << endl << name << " has gained " << food - original << " food points!" << endl;
            activity();
        }
        void drink(int amount) {
            int original = water;
            water = min(10, water+amount);
            cout << "Glug Glug Glug!" << endl << name << " has gained " << water - original << " water points!" << endl;
            activity();
        }
        void play(int amount) {
            int original = happiness;
            happiness = min(10, happiness+amount);
            cout << "Yay!" << endl << name << " has gained " << happiness - original << " happiness points!" << endl;
            activity();
        }
        void showStats() {
            if (!(died)) {
            cout << name << " has " << food << " food points, " << water << " water points and " << happiness << " happiness points!" << endl;
            if (food <= 3) {
                cout << name << " is hungry!" << endl;
            }
            if (water <= 3) {
                cout << name << " is thirsty!" << endl;
            }
            if (happiness <= 3) {
                cout << name << " is sad." << endl;
            }
        } else {
            cout << name << " is dead.";
            }
        }
        bool getDied() {
            return died;
        }
    private:
        int food;
        int water;
        int happiness;
        string name;
        bool died;

        void activity() {
            food = max(0, food-2);
            water = max(0, water-3);
            happiness = max(0, happiness-1);
            if ((food <= 0 || water <= 0) || ((food <= 3 || water <= 2) && happiness == 0)) {
                died = true;
            }


        }
};
int main() {
    string petName;
    cout << "What do you want to call your pet? \n>>> ";
    cin >> petName;
    pet MyPet(petName);
    int choice;
    do {
        cout << "What do you want to do with your pet?\n1. Feed\n2. Drink\n3. Play\n4. Show stats\n>>> ";
        cin >> choice;
        switch (choice) {
            case 1:
                MyPet.feed(6);
                MyPet.showStats();
                break;
            case 2:
                MyPet.drink(6);
                MyPet.showStats();
                break;
            case 3:
                MyPet.play(4);
                MyPet.showStats();
                break;
            case 4:
                MyPet.showStats();
                break;
            default:
                cout << "Sorry, incorrect input.";
                break;
        } 
    } while (!(MyPet.getDied()));

    return 0;
}