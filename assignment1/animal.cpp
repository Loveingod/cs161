/*********************************************************************
** Author:  Marc Clinedinst
** Date:  9 January 2015
** Description:  This is my first assignment for CS161.  This program
demonstrates simple console input and put put, using the cout and
cin objects from the iostream library.  Specifically, this program
prompts the end user to enter their favorite animal; after the end
user enters his or her favorite animal, the console displays
back the user's response.  The program then terminates.
*********************************************************************/

#include <iostream>
#include <string>

/*********************************************************************
** Description:  This is the main function of the program.  As described
in the project description above, the function below asks the user to
enter their favorite animal into the console; the console then 
outputs the user's response as part of a sentence.
** Parameters:  There are no parameters passed to the main function.
** Pre-Conditions:  The main function is where a C++ program begins
execution.  Assuming everything is set up correctly, the program will
begin execution after the function header.
** Post-Conditions:  Assuming that everything was successful, the
main function will return the number 0.
*********************************************************************/
int main()
{
    std::string faveAnimal;
    std::cout << "Please enter your favorite animal" << std::endl;
    std::cin >> faveAnimal;
    std::cout << "Your favorite animal is the " << faveAnimal;
    std::cout << "." << std::endl;    
    
    return 0;
}