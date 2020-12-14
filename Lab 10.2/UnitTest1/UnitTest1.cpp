#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 10.2/Lab 10.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[1001];
			str[0] = 'd';
			str[1] = 'i';
			str[2] = 'm';
			str[3] = 'a';
			str[4] = ' ';
			str[5] = ' ';
			str[6] = ' ';
			int k = Count(str);
			Assert::AreEqual(k, 3);
		}
	};
}
