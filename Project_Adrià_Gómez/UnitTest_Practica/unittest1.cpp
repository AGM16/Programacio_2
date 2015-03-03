#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project_Adrià_Gómez/Point2D.h"
#include "../Project_Adrià_Gómez/Point2D.cpp"
#include "../Project_Adrià_Gómez/StringClass.h"
#include "../Project_Adrià_Gómez/StringClass.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Practica
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		//----------------------------------------------------------------


		//POINT2D CLASS


		//----------------------------------------------------------------

		TEST_METHOD(TestPoint2DPlus)
		{
			Point2D Point1, P1, P2;

			P1.f_px = 4.0f;
			P1.f_py = 5.0f;

			P2.f_px = 4.0f;
			P2.f_py = 8.0f;

			Point1 = P1 + P2;

			Assert::AreEqual((float)Point1.f_px, 8.0f);
			Assert::AreEqual((float)Point1.f_py, 13.0f);


		}


		TEST_METHOD(TestPoint2DORest)
		{

			Point2D Point1, P1, P2;

			P1.f_px = 4.0f;
			P1.f_py = 5.0f;

			P2.f_px = 4.0f;
			P2.f_py = 8.0f;

			Point1 = P1 - P2;

			Assert::AreEqual((float)Point1.f_px, 0.0f);
			Assert::AreEqual((float)Point1.f_py, -3.0f);
		}


		TEST_METHOD(TestPoint2DPlusEqual)
		{
			Point2D Point1, P1, P2;

			P1.f_px = 4.0f;
			P1.f_py = 5.0f;

			P2.f_px = 4.0f;
			P2.f_py = 8.0f;

			Point1 = P1 += P2;

			Assert::AreEqual((float)Point1.f_px, 8.0f);
			Assert::AreEqual((float)Point1.f_py, 13.0f);

		}


		TEST_METHOD(TestPoint2DResEqual)
		{
			Point2D Point3, P1, P2;

			P1.f_px = 5.0f;
			P1.f_py = 5.0f;

			P2.f_px = 4.0f;
			P2.f_py = 8.0f;

			Point3 = P1 -= P2;

			Assert::AreEqual((float)Point3.f_px, 1.0f);
			Assert::AreEqual((float)Point3.f_py, -3.0f);

		}


		TEST_METHOD(TestPoint2DEqualEqual)
		{
			Point2D  P1, P2;

			P1.f_px = 5.0f;
			P1.f_py = 5.0f;

			P2.f_px = 5.0f;
			P2.f_py = 5.0f;

			Assert::IsTrue(P1 == P2);
		}


		TEST_METHOD(TestPoint2DNotEqual)
		{
		
			Point2D  P1, P2;

			P1.f_px = 1.0f;
			P1.f_py = 2.0f;

			P2.f_px = 3.0f;
			P2.f_py = 4.0f;

			Assert::IsTrue(P1 != P2);

		}


		TEST_METHOD(TestPoint2DIsZero)
		{

			Point2D  P1, P2;

			P1.f_px = 0.0f;
			P1.f_py = 0.0f;

			P2.f_px = 1.0f;
			P2.f_py = 2.0f;

			P1.IsZero();
			P2.IsZero();

			Assert::IsTrue(P1.IsZero());
			Assert::IsFalse(P2.IsZero());

		}


		TEST_METHOD(TestPoint2DSetZero)
		{
			Point2D  P1;

			P1.f_px = 8.0f;
			P1.f_py = 7.0f;

			P1.SetZero();

			Assert::AreEqual(P1.f_px, 0.0f);
			Assert::AreEqual(P1.f_py, 0.0f);

		}


		TEST_METHOD(TestPoint2DDistanceTo)
		{
			Point2D  P1, P2;

			P1.f_px = 3.0f;
			P1.f_py = 1.0f;
			P2.f_px = 2.0f;
			P2.f_py = 1.0f;

			Assert::AreEqual(P1.DistanceTo(P2), 1.0f);

		}


        //----------------------------------------------------------------


		//STRINGCLASS CLASS

		

		//----------------------------------------------------------------

		TEST_METHOD(TestStringClassConstructor0)
		{
			
			StringClass Word1;
			Assert::AreEqual(Word1.Length(), 0);
			Assert::AreEqual(Word1.Getc_Word(), "\0");
		}

		TEST_METHOD(TestStringClassConstructor_Copy_Const_Char)
		{
			
			StringClass Word1("sentence");
			Assert::AreEqual(Word1.c_word, "sentence");
			
		}

		TEST_METHOD(TestStringClassConstructor_Copy_String_Class_Char)
		{

			StringClass Word2("Program");
			StringClass &Word1 = Word2;
			Assert::AreEqual(Word1.c_word, "Program");

		}


		//------------------------------------------------------
		//Operators
		//-------------------------------------------------------

		TEST_METHOD(TestStringClassAssignation_Equal_Const_String_C)
		{
		
		StringClass Word1; 

		Word1 = "hello";
		
		Assert::AreEqual(Word1.c_word, "hello");

		}

		TEST_METHOD(TestStringClassAssignation_Equal_String_Class_C)
		{

			StringClass Word1("hello"), Word2("hola");

			Word1 = Word2;

			Assert::AreEqual(Word1.c_word, "hola");

		}
		
		
		TEST_METHOD(TestStringClassEqual_Equal_String_C)
		{
			
			StringClass Word1("word");
			Assert::IsTrue(Word1 == "word");
		}

		TEST_METHOD(TestStringClassEqual_Equal_String_Class_C)
		{
			
			StringClass Word1("word2015"), Word2("word2015");
			Assert::IsTrue(Word1 == Word2);
		}

		TEST_METHOD(TestStringClassNot_Equal_String_C)
		{
			
			StringClass Word1("word2015");
			Assert::IsTrue(Word1 != "word1234567");
		}

		TEST_METHOD(TestStringClassNot_Equal_String_Class_C)
		{
			
			StringClass Word1("word2015"), Word2("sentence132456");
			Assert::IsTrue(Word1 != Word2);
		}



		//------------------------------------------------------
		//Methods
		//-------------------------------------------------------

		TEST_METHOD(TestStringClass_Getc_Word)
		{
			
			StringClass Word1("word2000");

			Assert::AreEqual(Word1.Getc_Word(), "word2000");
		}


		TEST_METHOD(TestStringClass_Capicity)
		{
			
			StringClass Word1("word2015");

			Assert::AreEqual(Word1.Capacity(), 4);
		}
		
		
		TEST_METHOD(TestStringClass_Length)
		{
			
			StringClass Word1("word2015");

			Assert::AreEqual(Word1.Length(), 8);
		}


		TEST_METHOD(TestStringClass_Clear)
		{
			
			StringClass Word1("word2015");

			Word1.Clear();
			
			Assert::AreEqual(Word1.Length(), 0);
		}


	};
}