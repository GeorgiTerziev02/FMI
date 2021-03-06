#pragma once
#include "Kindle.h"

int signUpUser(Kindle& kindle);

int logInUser(const Kindle& kindle);

void viewBooks(const Kindle& kindle);

void readBook(Kindle& kindle, User* user);

void readBookPage(Kindle& kindle, const User* user);

void commentBook(Kindle& kindle, User* user);

void readBookComments(Kindle& kindle, const User* user);

void rateBook(Kindle& kindle, const User* user);

void viewBookRates(Kindle& kindle, const User* user);

void editBook(Kindle& kindle, const User* user);

void editBookRating(Kindle& kindle, const User* user);

void addPage(Kindle& kindle, const User* user);