#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int harf[5][10] = { 0 };
	int rastgeleSayi;
	bool sayiVar = false;
	srand(time(0));

	// harf matrisinin elemanlarini tek tek gezip iclerine sayi atamak icin donguye giriliyor.
	cout << "  Rastgele ve Tekrarsiz Matris" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// her cift j icin buyuk sayi, her tek j icin kucuk sayi uretiliyor ve char tipine donusturulup harf seklinde gosteriliyor.
			if (j % 2 == 0)
			{
				while (1)
				{
					// 65 - 90 arasýnda rastgele sayi üretiyor.
					rastgeleSayi = 65 + rand() % 26;

					// rastgele uretilen sayinin harf matrisinde var olup olmadigini kontrol ediyor.
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (harf[i][j] == rastgeleSayi)
								sayiVar = true;
						}
					}

					// eger harf matrisinin icinde uretilen yeni sayiya rastlanmadiysa donguyu kýrýp cikiyor. 
					if (sayiVar == false)
						break;
					else
						sayiVar = false;
				}

				harf[i][j] = rastgeleSayi;
				cout << "  " << char(harf[i][j]);
			}
			else {
				while (1)
				{
					// 97 - 122 arasý rastgele sayi uretiyor. 
					rastgeleSayi = 97 + rand() % 26;

					// rastgele uretilen sayinin harf matrisinde var olup olmadigini kontrol ediyor.
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (harf[i][j] == rastgeleSayi)
								sayiVar = true;
						}
					}

					// eger harf matrisinin icinde uretilen yeni sayiya rastlanmadiysa donguyu kýrýp cikiyor. 
					if (sayiVar == false)
						break;
					else
						sayiVar = false;
				}

				harf[i][j] = rastgeleSayi;
				cout << "  " << char(harf[i][j]);
			}
		}
		cout << endl << endl;
	}

	// bu kýsýmda matrisi siralamak icin kabarcik siralama algoritmasini kullandim. 
	int gecici;
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (harf[i][j] > harf[x][y])
					{
						gecici = harf[x][y];
						harf[x][y] = harf[i][j];
						harf[i][j] = gecici;
					}
				}
			}
		}
	}

	cout << "        Sirali Matris" << endl;

	// siralanmis sayilardan olusan matrisin elemanarini tek tek char tipine donusturup ekrana bastiriyorum.
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "  " << char(harf[i][j]);
		}
		cout << endl << endl;
	}

	cout << endl;

	system("pause");
}


