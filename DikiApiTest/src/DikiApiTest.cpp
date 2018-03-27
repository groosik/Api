#include "DikiApi.h"
#include "gtest/gtest.h"

class DikiApiTest: public testing::Test
{
protected:
	std::vector<TransWithExamp> validResult;
	DikiApiTest();

};

DikiApiTest::DikiApiTest()
{
	validResult.resize(15);

	validResult[0]=
	{
		L"dog",
		L"pies",
		{
			{L"My dog has a very good sense of smell.", L"M�j pies ma bardzo dobry w�ch."},
			{L"I walk my dog every day.", L"Codziennie wyprowadzam mojego psa."},
			{L"I have a dog.", L"Mam psa."},
			{L"This dog is big.", L"Ten pies jest du�y."},
		}
	};

	validResult[1]=
	{
		L"dog",
		L"samiec (psa, lisa, wilka)",
		{
			{L"These dogs can be aggressive.", L"Te samce mog� by� agresywne."},
			{L"Is it a dog or a bitch?", L"To samiec czy suczka?"},
		}
	};

	validResult[2]=
	{
		L"dog",
		L"�ajdak, szuja",
		{
			{L"He's a dog, you can't trust him.", L"To �ajdak, nie mo�esz mu ufa�."},
			{L"He tried to lie to me, what a dog!", L"On pr�bowa� mnie ok�ama�, co za szuja!"},
		}
	};

	validResult[3]=
	{
		L"dog",
		L"lipa, szmelc, tandeta",
		{
			{L"This equipment is a dog!", L"Ten sprz�t to szmelc!"},
			{L"She sells dogs.", L"Ona sprzedaje tandet�."},
			{L"I won't give you even 10 dollars for this dog!", L"Nie dam ci nawet dziesi�ciu dolar�w za t� tandet�!"},
		}
	};

	validResult[4]=
	{
		L"dog",
		L"pokraka, maszkara (nieatrakcyjna kobieta)",
		{
			{L"Look at that woman. What a dog.", L"Popatrz na tamt� kobiet�. Jaka pokraka."},
			{L"I love my sister, but I must admit that she's a dog.", L"Kocham moj� siostr�, ale musz� przyzna�, �e jest maszkar�."},
			{L"I married this dog because she's rich.", L"Po�lubi�em t� pokrak�, bo jest bogata."},
		}
	};

	validResult[5]=
	{
		L"dog",
		L"kole�, ziomek",
		{
			{L"That's Peter, my best dog.", L"Poznaj Petera, mojego najlepszego ziomka."},
			{L"What's up, dog?", L"Co tam, ziomek?"},
		}
	};

	validResult[6]=
	{
		L"dog",
		L"pies na baby",
		{
			{L"Don't trust him, he's a real dog.", L"Nie ufaj mu, to prawdziwy pies na baby."},
			{L"Women should stay away from him, he's a dog.", L"Kobiety powinny trzyma� si� od niego z daleka, to pies na baby."},
		}
	};

	validResult[7]=
	{
		L"dog",
		L"dw�ja, pa�a (ocena)",
		{
			{L"I got a dog from that test.", L"Dosta�em pa�� z tego testu."},
			{L"I have to read this book or I'll get a dog.", L"Musz� przeczyta� t� ksi��k�, albo dostan� dw�j�."},
		}
	};

	validResult[8]=
	{
		L"dog",
		L"i�� blisko za kim�, nie odst�powa� (jak pies)",
		{
			{L"You have to dog him, I want to know where he lives!", L"Musisz i�� za nim blisko jak pies, chc� wiedzie�, gdzie on mieszka!"},
			{L"This girl dogs me but I don't like her!", L"Ta dziewczyna chodzi blisko za mn� jak pies, ale ja jej nie lubi�!"},
		}
	};

	validResult[9]=
	{
		L"dog",
		L"gn�bi� (gdy kogo� gn�bi jaki� problem lub pech), uprzykrza�",
		{
			{L"Don't let it dog you, I'll help you find a job.", L"Nie pozw�l, �eby ci� to gn�bi�o, pomog� ci znale�� prac�."},
			{L"This problem has been dogging me for a year now.", L"Ten problem gn�bi mnie ju� od roku."},
		}
	};

	validResult[10]=
	{
		L"dog",
		L"uprawia� seks na pieska",
		{
			{L"I dogged Jane yesterday!", L"Wczoraj uprawia�em z Jane seks na pieska!"},
			{L"Jane doesn't like to dog.", L"Jane nie lubi uprawia� seksu na pieska."},
		}
	};

	validResult[11]=
	{
		L"dog",
		L"nawali�, spieprzy�, schrzani�",
		{
			{L"Do not dog this, I won't give you another chance.", L"Nie spieprz tego, nie dam ci kolejnej szansy."},
			{L"If you dog again, I'll have to break up with you.", L"Je�li znowu nawalisz, b�d� musia� z tob� zerwa�."},
		}
	};

	validResult[12]=
	{
		L"dog",
		L"do�owa�, zamartwia�",
		{
			{L"You can't dog your mother, don't tell her about the accident.", L"Nie mo�esz do�owa� swojej matki, nie m�w jej o wypadku."},
			{L"I don't want to dog you, but I think we have a serious problem with our son.", L"Nie chc� ci� zamartwia�, ale my�l�, �e mamy powa�ny problem z naszym synem."},
		}
	};

	validResult[13]=
	{
		L"dog",
		L"�ledzi�, tropi�",
		{

		}
	};

	validResult[14]=
	{
		L"dog",
		L"olewa�, nie dawa� z siebie wszystkiego",
		{
			{L"He was accused of dogging it by his boss.", L"On zosta� oskar�ony o nie dawanie z siebie wszystkiego przez swojego szefa."},
		}
	};
}


TEST_F(DikiApiTest, getTranslation)
{
	DikiApi api;
	const std::wstring TO_TRANSLATE=L"dog";
	std::vector<TransWithExamp> translation=api.getTranslation(TO_TRANSLATE);

	ASSERT_EQ(translation.size(), validResult.size());

	for(int i=0; i<validResult.size(); ++i)
	{
		EXPECT_EQ(translation[i].translation, validResult[i].translation);
		EXPECT_EQ(translation[i].word, TO_TRANSLATE);
		ASSERT_EQ(translation[i].example.size(), validResult[i].example.size()) << i;
		
		for(int k=0; k<validResult[i].example.size(); ++k)
		{
			EXPECT_EQ(validResult[i].example[k].sentence, translation[i].example[k].sentence);
			EXPECT_EQ(validResult[i].example[k].translation, translation[i].example[k].translation);
		}

	}
}



