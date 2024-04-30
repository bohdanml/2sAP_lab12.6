#include "pch.h"
#include "CppUnitTest.h"
#include "..\\2sAP_lab12.6\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)

		{
			Queue queue;
			queue.enqueue(30);
			queue.enqueue(70);
		
			Assert::IsTrue(queue.search(70));
		}
	};

}