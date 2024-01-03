#include "pch.h"
#include "CppUnitTest.h"
#include "../idk/funkcje.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test1
{
	TEST_CLASS(test1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double arr[] = {7.0, 20.0, 13.0, 21.0, 5.0, 1.0, 9.0, 34.0, 0.0};
			double expected = 9.0;
			Assert::AreEqual(expected, mediana(arr, sizeof(arr) / sizeof(arr[0])));
		}

		TEST_METHOD(TestMethod2) 
		{
			double arr[] = { 7.0, 20.0, 13.0, 21.0, 5.0, 1.0, 9.0, 34.0, 0.0 };
			double expected = 10.0;
			Assert::AreNotEqual(expected, mediana(arr, sizeof(arr) / sizeof(arr[0])));
		}
	};
}
