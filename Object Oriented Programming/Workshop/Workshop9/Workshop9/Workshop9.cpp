#include "OOPCourse.h"

int main()
{
	OOPCourse p("Lecturer1", "Assistant1");

	p.addStudent("Stoycho Kyosev", 42069);
	p.addStudent("Yavor Alexandrov", 69420);
	p.addStudent("Angel Dimitriev", 00666);

	p.addGrade(42069, "K1", 5.33, "Assistant1");
	p.addGrade(42069, "HW1", 4, "Assistant1");
	p.addGrade(00666, "HW1", 6, "Lecturer1");
	p.addGrade(42069, "K1", 5, "Assistant1");

	double res = p.getAverageForCourse(); // 5.08

	p.editGrade(42069, "HW1", 2, "Lecturer1");
	double res44 = p.getAverageForCourse(); // 4.44

	double res5 = p.getAverageGradePerTask("HW1"); // 4;
	double res6 = p.getAverageGradePerTask("K1"); // 5.33;
	double res7 = p.getAverageGradePerTask("test"); // 0;

	bool res2 = p.removeStudent(42069);

	double res3 = p.getAverageGradePerTask("HW1"); // 6;

	double res4 = p.getAverageFromTeacher("Lecturer1"); //6

	OOPCourse test(p);
	test.addStudent("2222222", 22222);
	int a = 5;
}