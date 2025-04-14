#include "Closet_Monster.h"
#include "Under_Bed_Monster.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main() {
    // Create a vector of Darkness Monster unique pointers
    vector<unique_ptr<Darkness_Monster>> monsters;
    srand(time(NULL));
    const int NUM_MONSTERS = 10;
    int num_eyes_staring = 0;

    // Loops through vector and creates 10 darkness monsters that are either specifically closet or under bed monsters
    for (int i = 0; i < NUM_MONSTERS; ++i) {
        if (rand() % 2) {
            monsters.push_back(make_unique<Closet_Monster>());
            num_eyes_staring += monsters[i]->get_number_of_eyes();
        } else {
            monsters.push_back(make_unique<Under_Bed_Monster>());
            num_eyes_staring += monsters[i]->get_number_of_eyes();
        }
    }

    string input;
    cout << "While sitting in your room, you get an uneasy feeling." << endl;
    cout << "There are " << num_eyes_staring << " monster eyes staring at you from the darkness..." << endl;
    int remaining_eyes = num_eyes_staring;
    // Repeatedly gives the user the option to poke the eyes or run away.
    while (remaining_eyes > 0) {
        cout << "\nUser, what will you do?: " << endl;
        cout << "a. Poke the monsters' eyes" << endl;
        cout << "b. Run away" << endl;
        cin >> input;
        // Input validation
        while (input.size() != 1 || (tolower(input[0]) != 'a' && tolower(input[0]) != 'b')) {
            cout << "Invalid input. Try again (must enter \"a\" or \"b\"): " << endl;
            cin >> input;
        }
        // If they choose to poke the eyes, calls the poke_eye and scare method on each monster. If they choose to run away, the program ends.
        if (tolower(input[0]) == 'a') {
            remaining_eyes = 0;
            for (int i = 0; i < monsters.size(); ++i) {
                cout << "You poke one of the monster's eyes!" << endl;
                monsters[i]->poke_eye();
                remaining_eyes += monsters[i]->get_number_of_eyes();
                cout << monsters[i]->scare() << endl;
            }
            cout << "\nThere are now " << remaining_eyes << " monster eyes staring at you from the darkness..." << endl;
        } else {
            cout << "\nYou make a run for it!" << endl;
            break;
        }
    }
    return 0;
}
