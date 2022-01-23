/**
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @idnumber 3MI0600090
* @compiler VC
*
* <Header file with functions manipulating the console ui>
*
*/

#pragma once

#ifndef SCRABBLE_CONSOLE_OPERATIONS_H
// Visualize a separator line in the console 
void printSeparatorLine();
// clear console
void clearConsole();
// Remove all error flags and characters from the input buffer
void clearInputBuffer();
// Visualize Main Menu in the console
void displayMainMenu();
// Visualize Settings in the console
void displaySettings(const int& lettersCount, const int& roundsCount, const int& shufflesAvailable);
// Visualize all available letters in the console
void displayAvailableLetters(const int* const letters);
// Clear console and visualize main menu
void returnToMainMenu();
#endif //SCRABBLE_CONSOLE_OPERATIONS_H
