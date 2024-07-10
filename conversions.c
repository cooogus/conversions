// the function of this program is to take user input whether it is a distance
// or temperature measurement, and convert it to the unit the user gives
// returning the original measurement and unit and the new measurement and unit
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * @param expected: the expected character from user input
 * @param received: the actual character received from userinput
 * @return: true if the expected character and received character are the same
 */
bool isValidUnit(const char expected, const char received)
{

    const char upper = toupper(received); // converting received character to uppercase

    switch (toupper(expected))
    { // checking to make sure the received character is one of the expected values
    case 'D':
        return upper == 'I' || upper == 'F' || upper == 'M' || upper == 'Y';
        break;
    case 'T':
        return upper == 'C' || upper == 'F' || upper == 'K';
    default:
        return false; // if not, return false
    }
}

/**
 *
 * @param numArgsNeeded: the number of format placeholders that needed to have
 * been read in the last scanf
 * @param numArgsRead: the actual number of placeholders that were read from
 * scanf, ie its return value
 * @param isLastElementOnLine: true if this is the last value that should be on
 * this line of input
 * @return: true if the input is correctly formatted and false otherwise
 */
bool isValidFormat(const int num_args_needed, const int num_args_read,
                   bool should_be_last_value_on_line)
{
    bool format_is_correct = num_args_read == num_args_needed;
    if (should_be_last_value_on_line)
    {
        char should_be_newline = '?';
        scanf("%c", &should_be_newline);
        format_is_correct = format_is_correct && should_be_newline == '\n';
    }
    return format_is_correct;
}

/**
 * Get a character  from the user but close the program if one is not entered
 * @param isLastElementOnLine : true if this is the last value that should be on
 * this line of input
 * @return a valid character
 */
char getValidChar(const bool isLastElementOnLine)
{
    const int numArgsNeeded = 1;
    int numArgsRead;
    char theCharacter;

    numArgsRead = scanf(" %c", &theCharacter);
    if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine))
    {
        return theCharacter;
    }
    else
    {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
}

/**
 * Get a double from the user but close the program if one is not entered
 * @param isLastElementOnLine : true if this is the last value that should be on
 * this line of input
 * @return a valid double
 */
double getValidDouble(const bool isLastElementOnLine)
{
    const int numArgsNeeded = 1;
    int numArgsRead;
    double num;

    numArgsRead = scanf("%lf", &num);
    if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine))
    {
        return num;
    }
    else
    {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
}

int stop() { exit(0); }

void wrapper() { stop(); }

/*
 * takes the temperature from the user and converts it to celsius
 * @param temp: the temperature the user gives
 * @param tempType: the temperature unit the user gives
 * @return newTemp: temp converted to celsius
 */
double tempConversion(double temp,
                      char tempType)
{
    double newTemp = 0.0;
    if (tempType == 'F')
    {
        newTemp = (temp - 32) * 5 / 9;
    }
    else if (tempType == 'C')
    {
        newTemp = temp;
    }
    else if (tempType == 'K')
    {
        newTemp = temp - 273.15;
    }
    return newTemp;
}

/*
 * converts the given user temperature in celsius to the given new unit the user requested
 * @param temp: the temperature the user gives
 * @param newTemp: the temp converted to celsius
 * @param tempType: the temperature unit the user gives
 * @param newTempType: the temperature unit the user wants temp to be converted to
 */
void conversionFromC(double temp, double newTemp, char tempType,
                     char newTempType)
{
    double finalTemp = 0.0;
    if (newTempType == 'F')
    {
        finalTemp = (newTemp * 9 / 5) + 32;
        printf("%.2lf%c is %.2lf%c", temp, tempType, finalTemp,
               newTempType);
    }
    else if (newTempType == 'C')
    {
        finalTemp = newTemp;
        printf("%.2lf%c is %.2lf%c", temp, tempType, finalTemp,
               newTempType);
    }
    else if (newTempType == 'K')
    {
        finalTemp = newTemp + 273.15;
        printf("%.2lf%c is %.2lf%c", temp, tempType, finalTemp,
               newTempType);
    }
}

/*
 * takes the distance from the user and converts it to inches
 * @param distance: the distance the user gives
 * @param distanceType: the distance unit the user gives
 * @return newDistance: distance converted to inches
 */
double distanceConverion(double distance, char distanceType)
{
    double newDistance = 0.0;
    if (distanceType == 'I')
    {
        newDistance = distance;
    }
    else if (distanceType == 'F')
    {
        newDistance = distance * 12;
    }
    else if (distanceType == 'Y')
    {
        newDistance = distance * 36;
    }
    else if (distanceType == 'M')
    {
        newDistance = distance * 63360;
    }
    return newDistance;
}

/*
 * converts the given user distance in inches to the given new unit the user requested
 * @param distance: the temperature the user gives
 * @param newDistance: the temp converted to celsius
 * @param distanceType: the temperature unit the user gives
 * @param newDistanceType: the temperature unit the user wants temp to be converted to
 */
void conversionFromI(double distance, double newDistance,
                     char distanceType, char newDistanceType)
{
    double finalDistance = 0.0;
    if (newDistanceType == 'I')
    {
        finalDistance = newDistance;
        printf("%.2lf%c is %.2lf%c", distance, distanceType, finalDistance,
               newDistanceType);
    }
    else if (newDistanceType == 'F')
    {
        finalDistance = newDistance / 12;
        printf("%.2lf%c is %.2lf%c", distance, distanceType, finalDistance,
               newDistanceType);
    }
    else if (newDistanceType == 'Y')
    {
        finalDistance = newDistance / 36;
        printf("%.2lf%c is %.2lf%c", distance, distanceType, finalDistance,
               newDistanceType);
    }
    else if (newDistanceType == 'M')
    {
        finalDistance = newDistance / 63360;
        printf("%.2lf%c is %.2lf%c", distance, distanceType, finalDistance,
               newDistanceType);
    }
}

int main()
{
    //getting user input 
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");

    char conversionType = toupper(getValidChar(true)); //converting user input to upper character 

    switch (conversionType)
    {
    case 'T': //if the user wants to change temp units 
        printf("Enter the temperature followed by its suffix (F, C, or K): ");
        double temp = getValidDouble(false); //making sure the number isn't the last thing on the line

        char tempType = toupper(getValidChar(true)); //making sure the unit is the last thing on the line
        if (!isValidUnit(conversionType, tempType)) //if not do this and exit program 
        {
            printf("%c is not a valid temperature type. Ending program.", tempType);
            exit(0);
        }

        printf("Enter the new unit type (F, C, or K): ");

        char newTempType = toupper(getValidChar(true)); //converting new unit type to upper character
        if (!isValidUnit(conversionType, newTempType)) //if format is not single valid character, exit 
        {
            printf("%c is not a valid temperature type. Ending program.", newTempType);
            exit(0);
        }

        //calling functions that do actual conversion calculations 
        double newTemp = tempConversion(temp, tempType);
        conversionFromC(temp, newTemp, tempType, newTempType);

        break;

    case 'D': //if the user wants to change distance units, repeating steps above but with distance units 
        printf("Enter the distance followed by its suffix (I,F,Y,M): ");
        double distance = getValidDouble(false); 

        char distanceType = toupper(getValidChar(true)); 
        if (!isValidUnit(conversionType, distanceType))
        {
            printf("%c is not a valid distance type. Ending program.", distanceType);
            exit(0);
        }

        printf("Enter the new unit type (I,F,Y,M): ");

        char newDistanceType = toupper(getValidChar(true));
        if (!isValidUnit(conversionType, newDistanceType))
        {
            printf("%c is not a valid distance type. Ending program.", newDistanceType);
            exit(0);
        }

        double newDistance = distanceConverion(distance, distanceType);
        conversionFromI(distance, newDistance, distanceType, newDistanceType);
        break;
    default: //if the original user input is invalid run this 
        printf("Unknown conversion type %c chosen. Ending program.",
               conversionType);
        exit(0);
    }

    return 0;
}
