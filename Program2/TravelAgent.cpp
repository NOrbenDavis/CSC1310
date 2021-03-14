/**********************************************************************
	Title:        TravelAgent.cpp
	Author:       Nicholas Davis
	Date Created: 3/4/2021
	Purpose:      Main fct for program 2
***********************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include <limits>
#include <time.h>
#include "Destination.h"
#include "LinkedList.h"


using namespace std;

void printASCII();
float stringToFloat(string);

int main()
{
    LinkedList<Destination*> travelList; 
    Destination *destinationPtr;
    Destination *printPtr;
    cout << endl << "Hello! My name is Gavin O Clerigh and I am your professional travel agent, tour director, and guide!" << endl;
    printASCII();
    ifstream file;
    file.open("placeFile.txt");
    if(file.is_open())
    {
        srand(time(NULL));
        string readName;
        string readDesc;
        string tempRead;
        float readCost;
        int readDanger;

        //Take inputs from file
        while(!file.eof())
        {
            getline(file, readName, '#');
            if(file.eof())
            {
                file.close();
                break;
            }
            getline(file, readDesc, '#');
            getline(file, tempRead, '#');
            readCost = stringToFloat(tempRead);
            getline(file, tempRead, '#');
            readDanger = stoi(tempRead);
            destinationPtr = new Destination(readName,readDesc,readCost,readDanger);

            travelList.insertNode(destinationPtr);
        }

        //Print out travel List
        cout << endl << " Below are all possible travel destinations that I can hook you up with: " << endl;
        for (int i = 0; i < travelList.getLength(); i++)
        {
            printPtr = travelList.getNodeValue(i);
            cout << "****Destination #" << i+1 << "****" << endl;
            cout << *printPtr << endl;
        }
        cout << endl << "*********************************************************" << endl;
        string nameInput;
        int salaryInput;
        char yorn;
        char yorn2;

        cout << "Please answer the following four questions and I will determine the place you should travel." << endl;
        cout << endl << "\t 1. What is your name?\t";
        getline(cin, nameInput);


        cout << endl << "\t 2. How much money do you make per year?\t";
        cin >> salaryInput;
        //If wonky
        while (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Oops! You entered something wonky. Please enter a integer:  ";
            cin >> salaryInput;
        }

        cout << endl << "\t 3. Do you like the taste of fruity pebbles cereal? (y or n)\t";
        cin >> yorn;
        //If wonky
        while (!cin || (yorn != 'y' && yorn != 'n'))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Oops! You entered something wonky. Please enter a character:  ";
            cin >> yorn;
        }
        


        cout << endl << "\t 4. Is planet Earth flat? (y or n)\t";
        cin >> yorn2;
        //If wonky
        while (!cin || (yorn2 != 'y' && yorn2 != 'n'))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Oops! You entered something wonky. Please enter a character:  ";
            cin >> yorn2;
        }


        //Print what got given
        cout << endl << nameInput << ", based on your salary ($" << salaryInput << ") and the fact that you ";
        if(yorn == 'y')
        {
            cout << "like Fruit Pebbles cereal and you ";
        }
        else
        {
            cout << "do not like Fruity Pebbles cereal and you ";
        }
        if(yorn2 == 'y')
        {
            cout << "do think the Earth is flat, ";
        }
        else
        {
            cout << "do not think the Earth is flat, ";
        }   

        cout << "you are going to travel to the following Destination!" << endl << endl;

        //Generate Random Num to point too
        int randomNum;
        randomNum = rand() % 7 + 1;

        printPtr = travelList.getNodeValue(randomNum);
        cout << *printPtr << endl;
    }
    else
    {
        cout << endl << "Failed to open the file." << endl;
    }
    cout << endl << endl << "HAVE FUN!" << endl;
    return 0;
}


void printASCII()
{


    cout << ",..,,..,....,,,..,...,..,..,,..,,..,.,....,,.,,.....,.....,,,,.,,.,...,,,...,,..\n";
    cout << "......,.,.....,......,.,.,.,.....,..,.,,..,.,....,.,.....,,.......,,.,,...,,,...\n";
    cout << "..,,.,.....,,..,.,.,...,,.,...,.,.,....,..,.,,...,.,.,......,,.,.,....,,.,.....,\n";
    cout << "....,.,,..,,.,..,,.,.,.....,,....,,.......,..,,...,.......,.,,,.........,.,.,.,.\n";
    cout << ",,,.,.,,....,,.,,,,,.,...,,.,..,,.,.,.,,...,,..,,.,,.....,,,,..,,...,..,,...,...\n";
    cout << ".....,....,,,..,.,....,.,.,../&&% #%&&.(%****&%&%&#,........,..,,,...,..,.......\n";
    cout << "...,.,,,.,,.,,,,..,.,,..(&%%%&&. . ................&&&&*.,.,,.,.,.,.,...,.,.....\n";
    cout << ",,.....,...,.,,..,,.,&%&&&%.......... ...............#%&%%%.....,..............,\n";
    cout << "......,,.........,,&%&&&%.... ...... . . ...... ..........&&&&,,,..,..,,.....,..\n";
    cout << ".,,,..,.....,..,%%&&&%..... ....#############.. ........ ...%%%%....,.,...,....,\n";
    cout << "......,.,......%&&&&% ... .....#############..* .......... ...&&&...,,..,.,..,..\n";
    cout << ",...,.,,....,*&&%&%&%.........###############..# ..... . ..&%%&&&&%,...,,....,..\n";
    cout << ",....,,....,&%&%%&&&&.&. ... #     ########   .   ........&&&&&&%&%&...,,....,..\n";
    cout << ",,........./%%&%%&&%&&..  ..####### #.##### ##./#/ . ..%&&&&%&&%&%%&#.,.,,.,.,..\n";
    cout << ".,.........%&%&%%%%%%&&&& . .### **##/(((####  #### .* ## %%%&&&%%%%&,.......,,.\n";
    cout << ",,..,,,....%&%&%%&&%&& ### ######((((/((((((((((#####. ### &&&%%%&&&%...,..,....\n";
    cout << "..,...,,...%%%&%%&%%&& ##  ####((((((( (( (((((((#### # #*%%&&%%%%&&&,.,,.....,,\n";
    cout << "........,..&%&&%&%&%%&% ### ######################### (* %&&&&%%%&%&%.....,.....\n";
    cout << ".,...,..,..&&&&%&&%%&&%%%(( #######         ######## &(#%&&&&%%&&&&%&.,..,.....,\n";
    cout << ".,..,.,.....%%&%&%&&%%%&&&&&& #################### &%&%%&&&%&&%&&%%%............\n";
    cout << "....,.,......%%%%&%&&&%%%%&%%&&/ ############### %%%&&&&%&&&&&&%%&&%,.,.,.,...,.\n";
    cout << ".........,...,&%%%&%%&%&&%%%&%&&%   #########. /&%%%&&%&&&&%%&&%&%&.....,..,....\n";
    cout << ",,.............%&&&%&%&&&%&%%%%%% #*    *###### &%%&%&%&%&&&%%%&&,..,..,......,,\n";
    cout << ",........,.....,.%&%%&%%&&&%&&#   %/       ,%%% .  %&&&%%%&%&&&/..,...,..,,....,\n";
    cout << ".,,,..,,..,.....,..&%&%&&&&& ,,,  %%%%%%%%%%&%%  ,., %%%&&&&%/,,,,,......,.,....\n";
    cout << ",.......,..,...,,....%&,,, ,... %%&%%%%%%%&%%%%%% ,,, .,,*&,....,....,..,.,..,..\n";
    cout << ".,....,.,....,..,,,,.,,,, ,,,,,. %%%%%%%%%%%%%%% ,,,., ,,,..,,.........,....,.,,\n";
    cout << ",....,.....,.,,.,,,,,,,. ,.,.,,, %%%%%%%%%%%%%&% ,,,,,,, ,,,,,,.. ..,,.,.,,.....\n";
    cout << ".,,,..,...,,,.,,,,.,,,,.,,.  ,,, %%%&&%%%%&%%%& ,,.,,  ,,,,,.,,.,,,, ...,.,.....\n";
    cout << "..,......(..,,(,,,,(#*(,,,.,. ,, %%%%%%%&%%%%%% .  ..,...,,,.,,,,,,,............\n";
    cout << ".,... ###( / , #. #(,  #,,,,, ,.%%%%%%%%&%&%%%%.,..,,,,,,,.,,,.,.,,.,, .......,.\n";
    cout << "........,.....,,.,...,,.,....,,.%&%%%%%%%%%%%% ,,.,,..,..,,,.,,,,,,..,,..,..,...\n" << endl;

}

float stringToFloat(string str)
{
    float number;
    char convertStr[1000];
    strcpy (convertStr,str.c_str());
    number = atof(convertStr);
    return number;
}