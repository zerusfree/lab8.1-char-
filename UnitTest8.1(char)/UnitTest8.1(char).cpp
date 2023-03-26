#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char t[20] = "AGAOOGO";
			char* j = Change(t, "AGA", "OGO");
			Assert::AreEqual(j, "**O**");
		}
	};
}
