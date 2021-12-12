/*
 * Class: CMSC140 CRN 20433_22867
 * Instructor: Grigoriy A. Grinberg
 * Project 5
 * Description:Write a program that simulates a magic square using 3 one dimensional parallel arrays of integer type.
 * Due Date: 12/06/21
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Full Name here: Kayla Tom
               */

#include<iostream>
using namespace std;

// Global constants
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);


//custom functions
void fillRow(int array[], int size, int row);
void showRow(int array[], int size);
bool singleRowRange(int array[], int size, int min, int max);


int main()
{
    
    //declare/intialize all necessary variables
    int array1[COLS], array2[COLS], array3[COLS];
    char choice;
    bool isAMagicSquare = false;
    bool repeat = false;
    const string PROGRAMMER_NAME = "Kayla Tom", DUE_DATE = "12/06/21";
    const int ASSIGNMENT_NUMBER = 5;
    
    
    //do-while loop that repeats progrm as long as repeat = true
    do{
    fillArray(array1, array2, array3, COLS); //call function to fill array
    showArray(array1, array2, array3, COLS); //call function to show array
    isAMagicSquare = isMagicSquare(array1, array2, array3, COLS); //call function to determine if square meets magic square requirements

        //if-else prints out proper response of whether or not it is a Lo Shu Magic Square
        if(isAMagicSquare == true){
            cout << "This is a Lo Shu Magic square.";
        }
        else{
            cout << "This is not a Lo Shu Magic square.";
        }
        
        cout<<"\n Do you want to try again? (Y or N)";
        cin >> choice;
        
        
        //if-else statement allows user to choose if they want the program to repeat
        if (choice == 'y' || choice =='Y')
        {
            repeat = true;
        }
        else{
            repeat = false;
        }
    }while(repeat);
    
    
    //programmer ending message
    cout << "\nThank you for testing my program!!"<< endl;
    cout << "PROGRAMMER: " << PROGRAMMER_NAME << endl;
    cout << "CMSC140 Common Project " << ASSIGNMENT_NUMBER << endl;
    cout << "Due Date: " << DUE_DATE << endl <<endl;
    
    return 0;
}
// Function definitions go here

//function isMagicSquare checks whether or not square meets all requirements
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    
    //declaring all necessary variables and calling each function
    bool isCheckingRange, isCheckingRowSum, isCheckingColSum, isCheckingDiagSum, isCheckingUnique;
    isCheckingRange = checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN , MAX);
    isCheckingRowSum = checkRowSum(arrayRow1, arrayRow2, arrayRow3,size);
    isCheckingColSum = checkColSum(arrayRow1, arrayRow2, arrayRow3, size);
    isCheckingDiagSum = checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);
    isCheckingUnique = checkUnique(arrayRow1, arrayRow2, arrayRow3, size);

    
    //if-else statement where if all the functions return true, statement returns true to main function. If false, returns false
    if(isCheckingRange == true && isCheckingRowSum == true && isCheckingColSum == true && isCheckingDiagSum == true && isCheckingUnique == true){
        return true;
    }
    else{
        return false;
    }
    
    
}

//custom function used to ask user for input and fill each row
void fillRow(int array[], int size, int row){
    for(int counter = 0; counter < size; counter++ ){
        cout << "Enter the number for row " << row << " and column " << counter << ":";
        cin >> array[counter];
    }
}

//function used to call fillRow which fills each "row"/array to complete the square
void fillArray(int arrayRowOne[], int arrayRowTwo[], int arrayRowThree[], int size){
    fillRow(arrayRowOne, size, 0);
    fillRow(arrayRowTwo, size, 1);
    fillRow(arrayRowThree, size, 2);
}



//function used to call showRow which displays each row in the square
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    showRow(arrayRow1, size);
    showRow(arrayRow2, size);
    showRow(arrayRow3, size);
}

//custom function which displays each row one-by-one
void showRow(int array[], int size){
    //for loop to go through and display each element in array
    for(int counter = 0; counter < size; counter++ ){
        cout << array[counter] << " ";
        
        //while loop to know when to move to next line down
        while(counter == 2){
            cout <<endl;
            break;
        }
        }
}


//custom function which checks the range of a single row
bool singleRowRange(int array[], int size, int min, int max){
    //set initial bool value to false
    bool value = false;
    
    //for loop that goes through each value in array to make sure it is not smaller than the minimum or greater than the max
    for(int counter = 0; counter < size; counter++){
       // if statement that changes bool value to true if it is not outside of range
        if(array[counter] > max || array[counter] < min){
            value = false;
        }
        else{
            value = true;
        }
    }
    return value;
}


bool checkRange(int arrayRowOne[], int arrayRowTwo[], int arrayRowThree[], int size, int min, int max){
    //initialize/declare bool values
    bool firstCheck, secondCheck, thirdCheck;
    bool valid = false;
    
    //call functions
    firstCheck = singleRowRange(arrayRowOne, size, min, max);
    secondCheck = singleRowRange(arrayRowTwo, size, min, max);
    thirdCheck= singleRowRange(arrayRowThree, size, min, max);
    
    //if all functions returned true, return true back to isMagicSquare function
    if( firstCheck == secondCheck && firstCheck == thirdCheck){
        valid = true;
    }
    else{
        valid =  false;
    }
    return valid;
}


// function checkRowSum which adds up the sum of each row and determines whether or not they are equal to one another
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    //declare sum variable for each array
    int sum1 = 0, sum2 = 0, sum3 = 0;
    //for loop for array one to add each element in the array
    for(int c = 0; c < size; c++ ){
        sum1+= arrayRow1[c];
       
    }
    
    //for loop for array two to add each element in the array
    for(int k = 0; k < size; k++ ){
        sum2+= arrayRow2[k];
       
    }
    //for loop for array three to add each element in the array
    for(int j = 0; j < size; j++ ){
        sum3+= arrayRow3[j];
      
    }
    
    //if-else statement. If statement is true, return true to isMagicSquare function
    if(sum1 == sum2 && sum2 == sum3 && sum1 == sum3){
        return true;
    }
    else{
        return false;
    }
    
  
}

//function checkColSum which checks the sums of each column and makes sure they are equal to one another
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    //declare array
    int sum[size];
    //for loop that adds the sum of each element in a column for each array
    for(int counter = 0; counter < size; counter++){
        sum[counter] = arrayRow1[counter] + arrayRow2[counter] + arrayRow3[counter];
    }
    
    //if all sums are equal to one another, return true to isMagicSquare function
    if(sum[size-1] == sum[size-2] && sum[size-1] == sum[size-3]){
        return true;
    }
    else{

        return false;
    }
}
//function checkDiagSum totals up the diagonal values and determines whether or not they are equal to one another
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    //declare variables
    int sum1, sum2;
    //add together diagonal values
    sum1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
    sum2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];
    //if equal to one another, return true to isMagicSquare function
    if( sum1 == sum2){
        return true;
    }
    else{
        return false;
    }
}

//function checkUnique makes sure that no number is repeated in the square
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    //declare necessary variables
    bool checkOne = true, checkTwo = true, checkThree = true, rowCheckOne = true, rowCheckTwo = true, rowCheckThree = true;
   
    //for loop to compare values of first array; returns true if no value is repeated in single array
    for(int counter = 1; counter <size; counter++){
        if(arrayRow1[0] != arrayRow1[counter]){
            rowCheckOne = true;
        }
        else{
            rowCheckOne = false;
            break;
                    }
    }
    //for loop to compare values of second array; returns true if no value is repeated in single array
    for(int counter = 1; counter <size; counter++){
        if(arrayRow2[0] != arrayRow2[counter]){
            rowCheckTwo = true;
        }
        else{
            rowCheckTwo = false;
            break;
                    }
    }
    //for loop to compare values of third array; returns true if no value is repeated in single array
    for(int counter = 1; counter <size; counter++){
        if(arrayRow3[0] != arrayRow3[counter]){
            rowCheckThree = true;
        }
        else{
            rowCheckThree = false;
            break;
                    }
    }
    
    //if the above functions all returned true, function moves to compare between two different arrays
    if(rowCheckOne == rowCheckTwo && rowCheckOne ==rowCheckThree){
        //for loop to compare elements in first and second array
        for(int counter = 0; counter < size; counter++){
       
            if(arrayRow1[counter] != arrayRow2[counter]){
                checkOne =  true;
            }
            else{
                checkOne =  false;
                break;
                
            }
        }
    
    //for loop to compare elements in first and third array
    for(int counter = 0; counter < size; counter++){
            if(arrayRow1[counter] != arrayRow3[counter]){
                checkTwo =  true;
            }
            else{
                checkTwo =  false;
                break;
            }
        }
        
    //for loop to compare elements in second and third array
    for(int counter = 0; counter < size; counter++){
            if(arrayRow2[counter] != arrayRow3[counter]){
                checkThree =  true;
            }
            else{
                checkThree =  false;
            }
        }
        
   
        // if all above functions are true, return true to isMagicSquare function
        if( checkOne == true && checkTwo == true && checkThree == true){
            return true;
        }
        else{
            return false;
    }
    }
    
    //part of bigger if-else function in that if not all checks were true when checking only within a single array, lines 294-338 don't execute and automatically return false to isMagicSquare
    else{
        return false;
    }
}





