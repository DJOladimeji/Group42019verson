#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
#include "../Group4groupProject/Doctor.h"; 
#include "../Group4groupProject/Patient.h";
#include "../Group4groupProject/Source.h";
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorityHMSUnitTest
{
	TEST_CLASS(File)
	{
	public:

		TEST_METHOD(writingToDoctorPatientFile)
		{
			DOCTOR doc;    
			strncpy_s(doc.firstname, MAXCHARACTER, "Gurjit", MAXCHARACTER);          
			strncpy_s(doc.lastname, MAXCHARACTER, "Singh", MAXCHARACTER);
			strncpy_s(doc.department, MAXCHARACTER, "Surgery", MAXCHARACTER);
			doc.index = 0;

			char expected[MAXCHARACTER] = "Doctor: Gurjit Singh - Departement: Surgery";

			char c[MAXCHARACTER];

			creatingDoctor(doc);

			FILE* fp;
			fopen_s(&fp, "GurjitSingh.txt", "r");
			fgets(c, MAXCHARACTER, fp);

			fclose(fp);

			Assert::AreEqual(expected, c);
		}
	};

	/*TEST_CLASS(ProiorityHMSunitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};*/
}
