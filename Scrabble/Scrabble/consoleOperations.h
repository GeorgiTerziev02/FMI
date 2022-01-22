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
#endif //SCRABBLE_CONSOLE_OPERATIONS_H
