//
// Created by Alexia Barnes on 2/20/25.
//
#ifndef SKY_MONSTER_H
#define SKY_MONSTER_H

#include <string>

class Sky_Monster {
public:
    /**
     * Requires: nothing
     * Modifies: number_of_wings
     * Effects: sets number_of_wings to a random even int in range 2-100
     */
    Sky_Monster();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: does nothing
     */
    virtual ~Sky_Monster() = default;

    /**
    * Requires: nothing
    * Modifies: number_of_wings
    * Effects: calls set_number_of_wings with now
    */
    explicit Sky_Monster(int now);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns number_of_wings
     */
    virtual int get_number_of_wings() const;

    /**
     * Requires: nothing
     * Modifies: number_of_wings
     * Effects: sets number_of_wings to now if now is an even int in range 2-100.
     *          otherwise sets number_of_wings to 100.
     */
    void set_number_of_wings(int now);

    /**
     * Requires: nothing
     * Modifies: number_of_wings
     * Effects: if number_of_wings is at least 2, increments number_of_wings by two and returns true.
     *          if number_of_wings is already at MAX_NUMBER_WINGS returns false.
     */
    virtual bool growth_spurt();

    // pure virtual method to return a scary string
    virtual std::string scare() = 0;

    static const int MAX_NUMBER_WINGS = 100;
protected:
    int number_of_wings;
};

#endif //SKY_MONSTER_H
