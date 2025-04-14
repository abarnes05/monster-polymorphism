#include "Closet_Monster.h"
#include "Under_Bed_Monster.h"
#include <ctime>
#include <iostream>
using namespace std;

bool test_Darkness_Monster();
bool test_Closet_Monster();
bool test_Under_Bed_Monster();

int main() {
    srand(time(NULL));
    if (test_Darkness_Monster()) {
        cout << "Passed all Darkness Monster test cases" << endl;
    }
    if (test_Closet_Monster()) {
        cout << "Passed all Closet Monster test cases" << endl;
    }
    if (test_Under_Bed_Monster()) {
        cout << "Passed all Under Bed Monster test cases" << endl;
    }
    return 0;
}

bool test_Darkness_Monster() {
    bool passed = true;
    // Darkness Monster is abstract so we can only access it through the child classes
    Closet_Monster cm;
    if (cm.get_number_of_eyes() < 2 || cm.get_number_of_eyes() > Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    Closet_Monster cm2(1);
    if (cm2.get_number_of_eyes() != Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED 1 test case" << endl;
    }
    cm2.set_number_of_eyes(50);
    if (cm2.get_number_of_eyes() != 50) {
        passed = false;
        cout << "FAILED 50 test case" << endl;
    }
    cm2.set_number_of_eyes(101);
    if (cm2.get_number_of_eyes() != Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED 101 test case" << endl;
    }
    cm2.set_number_of_eyes(-7);
    if (cm2.get_number_of_eyes() != Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED negative test case" << endl;
    }
    // Test poke_eye method
    cm2.set_number_of_eyes(2);
    bool pokeEyeResult2 = cm2.poke_eye();
    if (cm2.get_number_of_eyes() != 1) {
        passed = false;
        cout << "FAILED poke eye test case, noe=2: Did not decrement number_of_eyes" << endl;
    }
    if (pokeEyeResult2 != true) {
        passed = false;
        cout << "FAILED poke eye test case, noe=2: Did not return true" << endl;
    }
    cm2.poke_eye();
    bool pokeEyeResult0 = cm2.poke_eye();
    if (cm2.get_number_of_eyes() < 5 || cm2.get_number_of_eyes() > Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED poke eye test case, noe=0: Did not set number_of_eyes between 5 and MAX_NUMBER_EYES" << endl;
    }
    if (pokeEyeResult0 != false) {
        passed = false;
        cout << "FAILED poke eye test case, noe=0: Did not return false" << endl;
    }
    return passed;
}

bool test_Closet_Monster() {
    bool passed = true;
    Closet_Monster cm(4);
    if (cm.is_open()) {
        passed = false;
        cout << "FAILED non-default constructor test case" << endl;
    }
    cm.open_door();
    if (!cm.is_open()) {
        passed = false;
        cout << "FAILED open door test case" << endl;
    }
    Closet_Monster cm2;
    if (cm2.is_open()) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    // Test scare method
    if (cm2.scare() != "*Knocks on door*") {
        passed = false;
        cout << "FAILED default constructor (closed door) scare test case" << endl;
    }
    cm2.open_door();
    if (cm2.scare() != "*Slams door*") {
        passed = false;
        cout << "FAILED open door scare test case" << endl;
    }
    if (cm2.is_open()) {
        passed = false;
        cout << "FAILED closed door after scare test case" << endl;
    }
    return passed;
}

bool test_Under_Bed_Monster() {
    bool passed = true;
    Under_Bed_Monster ubm(78);
    if (ubm.get_number_of_eyes() != 78) {
        passed = false;
        cout << "FAILED non-default constructor test case" << endl;
    }
    Under_Bed_Monster ubm2;
    if (ubm2.get_number_of_eyes() < 2 || ubm2.get_number_of_eyes() > Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    // Test scare method
    string message;
    for (int i = 0; i < Darkness_Monster::MAX_NUMBER_EYES; ++i) {
        message = ubm2.scare();
        if (message == "*Grabs you*") {
            ubm2.poke_eye();
        } else {
            // message is [number_of_eyes] watching you. Check that the number_of_eyes is correct
            if (stoi(message.substr(1, message.find_first_of(' '))) != ubm2.get_number_of_eyes()) {
                passed = false;
                // Note: no cout statement because this is in a loop and we don't want to crowd the console output
            }
        }
    }
    return passed;
}
