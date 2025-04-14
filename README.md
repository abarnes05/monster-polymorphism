# monster-polymorphism

## Summary of Program
This program was written in C++ and it's purpose is to demonstrate my knowledge of polymorphism and writing a testing suite. 
The program consists of 3 superclasses of monsters, with each superclass having 2 subclasses or monster sub-types. 
Each monster superclass has a pure virtual scare method which is overridden by their subclasses.
All three superclasses have a test suite which tests their methods as well as their subclasses methods.
Water Monster and Darkness Monster have main programs which have the user encounter the different monsters and asks for the users input.

### Water Monsters
* `Water_Monster` (superclass)
* `Lake_Monster` (subclass)
* `Sea_Monster` (subclass)
* `Water_Monster_Main`
* `Water_Monster_Testing`

All of these files were given to me as starter code.
You can run the test suite with the Water_Monster_Testing executable and the main program using the Water_Monster executable.

### Darkness Monsters
* `Darkness_Monster` (superclass)
* `Closet_Monster` (subclass)
* `Under_Bed_Monster` (subclass)
* `Darkness_Monster_Main`
* `Darkness_Monster_Testing`

Darkness_Monster, Closet_Monster, Under_Bed_Monster, and the test suite were given to me as starter code, except they weren't completely written. 
I implemented the poke_eye() method for Darkness Monster and the scare() method for Closet and Under Bed Monster.
I also wrote the test cases for the poke_eye() method for Darkness Monster and the scare() methods for the subclasses.
Lastly, I wrote the main program.
You can run the test suite with the Darkness_Monster_Testing executable and the main program using the Darkness_Monster executable.

### Sky Monsters
* `Sky_Monster` (superclass)
* `Cloud_Monster` (subclass)
* `Comet_Monster` (subclass)
* `Sky_Monster_Testing`

The subclasses and the test suite were given to me as starter code.
I wrote the Sky_Monster superclass completely.
You can run the test suite with the Sky_Monster_Testing executable.

## All starter code was given to me by my professor, Lisa Dion (The University of Vermont)
