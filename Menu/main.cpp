#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;
int main()
{
int choice;
bool gameOn = true;
while (gameOn != false){

cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout << "@***************************************************************************@\n";
cout << "@***************************************************************************@\n";
cout << "@***@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@***@\n";
cout << "@***@*******************************************************************@***@\n";
cout << "@***@*******************************************************************@***@\n";
cout << "@***@***@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@***@***@\n";
cout << "@***@***@                       ++++++++++++++                      @***@***@\n";
cout << "@***@***@                    << SPANZURATOAREA >>                   @***@***@\n";
cout << "@***@***@                       ++++++++++++++                      @***@***@\n";
cout << "@***@***@                                                           @***@***@\n";
cout << "@***@***@                                                           @***@***@\n";
cout << "@***@***@                    1 - Start the game.                    @***@***@\n";
cout << "@***@***@                                                           @***@***@\n";
cout << "@***@***@                        2 - Story.                         @***@***@\n";
cout << "@***@***@                                                           @***@***@\n";
cout << "@***@***@                        3 - Help.                          @***@***@\n";
cout << "@***@***@                                                           @***@***@\n";
cout << "@***@***@                        4 - Exit.                          @***@***@\n";
cout << "@***@***@                                                           @***@***@\n";
cout << "@***@***@                                                           @***@***@\n";
cout << "@***@***@                                                           @***@***@\n";
cout << "@***@***@                     Enter your choice:                    @***@***@\n";
cout << "@***@***@                                                           @***@***@\n";
cout << "@***@***@                                                           @***@***@\n";
cout << "@***@***@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@***@***@\n";
cout << "@***@*******************************************************************@***@\n";
cout << "@***@*******************************************************************@***@\n";
cout << "@***@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@***@\n";
cout << "@***************************************************************************@\n";
cout << "@***************************************************************************@\n";
cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";



choice=_getch();
choice=choice-'0';



switch (choice)
{
case 1:
    {system ("CLS");
     cout << "Game starts!\n";
     system ("PAUSE");
     system("CLS");
     }
// rest of code here

break;
case 2:
{   system("CLS");
    cout << "Story so far....\n";
    system ("PAUSE");
    system("CLS");}
// rest of code here
break;
case 3:
{   system("CLS");
    cout << "Ahahah, you really think I will help you?\n";
    system ("PAUSE");
    system("CLS");}
// rest of code here
break;
case 4:
{   system("CLS");
    cout << "End of Program. Goodbye. :( \n";
    system ("PAUSE");
    system("CLS");}

gameOn = false;
break;
default:
    {system("CLS");
     cout << "Not a Valid Choice. \n";
     cout << "Choose again.\n";
     cin >> choice;
     system("PAUSE");
     system("CLS");}
break;
}

}
return 0;
}
