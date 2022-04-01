#pragma once

const int FILE_BUFFER_SIZE = 5000;
const int INPUT_BUFFER_SIZE = 50;
const int FILE_NAME_SIZE = 50;
const int FIELD_MAX_SIZE = 25;
const int COMMAND_SIZE = 20;
const int STUDENTS_MAX_SIZE = 100;
const int FIELDS_COUNT = 6;

const char OPEN_FILE_ERROR_MESSAGE[] = "Error opening the file";
const char SUCCESSFUL_OPERATION_MESSAGE[] = "Operation successfully executed!";
const char UNSUCCESSFUL_OPERATION_MESSAGE[] = "Operation didn't execute successfully!";
const char VALIDATION_ERROR_MESSAGE[] = "Error! Data not in correct format!";

const char EDIT_COMMAND[] = "edit";
const char SORT_COMMAND[] = "sort";
const char PRINT_COMMAND[] = "print";
const char SAVE_COMMAND[] = "save";

const char STUDENT_TAG[] = "student";
const char NAME_TAG[] = "name";
const char FN_TAG[] = "fn";
const char AGE_TAG[] = "age";
const char GENDER_TAG[] = "gender";
const char EMAIL_TAG[] = "email";
const char GRADE_TAG[] = "grade";

const char MALE[] = "Male";
const char FEMALE[] = "Female";

const int MIN_AGE = 15;
const int MAX_AGE = 65;
const int MIN_GRADE = 2;
const int MAX_GRADE = 6;