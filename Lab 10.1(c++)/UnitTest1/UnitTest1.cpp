#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 10.1(c++)/Lab 10.1(c++).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			char str1[1000];
			str1[0] = '+';
			str1[1] = 'b';
			str1[2] = '-';
			str1[3] = ' ';
			str1[4] = '=';
			str1[5] = 'f';
			int k = Count(str1);
			Assert::AreEqual(k, 3);
		}
	};
}
