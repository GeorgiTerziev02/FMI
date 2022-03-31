#include <iostream>
#include "Interval.h"

//class Interval {
//private:
//	int a;
//	int b;
//public:
//	Interval()
//	{
//		this->a = 0;
//		this->b = 0;
//	}
//
//	Interval(const int& a, const int& b) {
// 		if (a > b)
//		{
//			this->a = 0;
//			this->b = 0;
//		}
//		else {
//			this->a = a;
//			this->b = b;
//		}
//	}
//
//	int getInterval() const {
//		return this->b - this->a;
//	}
//
//	bool isInInterval(const int& number) const {
//		return this->a <= number && number <= this->b;
//	}
//
//	int getPrimeNumbersCount() const {
//		int counter = 0;
//		for (int i = this->a; i <= this->b; i++)
//		{
//			if (i == 1)
//			{
//				counter++;
//				continue;
//			}
//
//			bool isPrime = true;
//			for (int j = 2; j < sqrt(a); j++)
//			{
//				if (i % j == 0)
//				{
//					isPrime = false;
//					break;
//				}
//			}
//
//			if (isPrime)
//			{
//				counter++;
//			}
//		}
//
//		return counter;
//	}
//
//	int getPalindromesCount() const {
//		int counter = 0;
//
//		for (int i = this->a; i <= this->b; i++)
//		{
//			int temp = i;
//			int reversed = 0;
//
//			while (temp != 0)
//			{
//				reversed = reversed * 10 + temp % 10;
//				temp /= 10;
//			}
//
//			if (i == reversed)
//			{
//				counter++;
//			}
//		}
//
//		return counter;
//	}
//
//	int getUniqueNumbersCount() const {
//		int counter = 0;
//
//		for (int i = this->a; i <= this->b; i++)
//		{
//			int temp = i;
//			bool isUnique = true;
//			while (temp != 0)
//			{
//				int innerTemp = temp;
//				while (innerTemp != 0)
//				{
//					innerTemp /= 10;
//					if (innerTemp % 10 == temp % 10)
//					{
//						isUnique = false;
//						break;
//					}
//				}
//
//				if (!isUnique)
//				{
//					break;
//				}
//				temp /= 10;
//			}
//
//			if (isUnique)
//			{
//				counter++;
//			}
//		}
//
//		return counter;
//	}
//
//	bool areEndsDegreeOfTwo() const {
//		int tempA = this->a;
//		int tempB = this->b;
//
//		bool result = true;
//		while (tempA != 0)
//		{
//			if (tempA % 2 != 0)
//			{
//				result = false;
//				break;
//			}
//			tempA /= 2;
//		}
//
//		if (!result)
//		{
//			return result;
//		}
//
//		while (tempB != 0)
//		{
//			if (tempB % 2 != 0)
//			{
//				result = false;
//				break;
//			}
//			tempB /= 2;
//		}
//
//		return result;
//	}
//
//	Interval*const getCommonInterval(const Interval& secondInterval) const {
//		return new Interval(max(this->a, secondInterval.a), min(this->b, secondInterval.b));
//	}
//
//	bool isSubinterval(const Interval& secondInterval) const {
//		return this->a <= secondInterval.a && secondInterval.b <= this->b;
//	}
//};
//
//int min(const int& a, const int& b) {
//	return a < b ? a : b;
//}
//
//int max(const int& a, const int& b) {
//	return a > b ? a : b;
//}

int main()
{
    Interval t1(3, 10); // [3, 10]
    Interval t2(4, 14); // [4, 14]
    Interval t3; // [0, 0]

    Interval* result = t1.getCommonInterval(t2); // [4, 10]

    std::cout << (*result).getA() << " " << (*result).getB() << std::endl;

    std::cout << t2.isSuperinterval(*result) << std::endl; //true

    std::cout << (*result).getPrimeNumbersCount() << std::endl; // 2 (only 5 and 7)

    Interval t4(2, 8);
    std::cout << t1.areEndsDegreeOfTwo() << std::endl;
    std::cout << t2.areEndsDegreeOfTwo() << std::endl;
    std::cout << t3.areEndsDegreeOfTwo() << std::endl;
    std::cout << t4.areEndsDegreeOfTwo() << std::endl;

    delete result;
}