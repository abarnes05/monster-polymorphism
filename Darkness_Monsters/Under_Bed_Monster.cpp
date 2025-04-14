#include "Under_Bed_Monster.h"
using namespace std;

Under_Bed_Monster::Under_Bed_Monster() : Darkness_Monster() {
}

Under_Bed_Monster::Under_Bed_Monster(int noe) : Darkness_Monster(noe) {
}

string Under_Bed_Monster::scare() {
    if (rand() % 2) {
        return "*Grabs you*";
    }
    return "*" + to_string(number_of_eyes) + " eye(s) watching you*";
}
