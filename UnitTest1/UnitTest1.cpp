#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.3.2/Lab_11.3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student stud;
			int a[3]{2,1,0};
			int b;
			IndexSort(stud, 3, "tmp.bin", "start.bin");
			ifstream f("tmp.bin");
			for (int i = 0; i < 3; i++)
			{
				f.seekg(i * (long)sizeof(int)); // встановили вказівник
				f.read((char*)&b, sizeof(int));
				Assert::AreEqual(a[i], b);
			}

		}
	};
}
