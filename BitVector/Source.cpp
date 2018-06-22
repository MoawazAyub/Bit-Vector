# include<iostream>
# include<math.h>


using namespace std;

class Bitvector
{
	unsigned char * bits;
	int n;             // no of bits

public:

	Bitvector(int s = 256)
	{
		bits = new unsigned char[static_cast<int>(ceil(s / 8))];
		n = s;

	}

	void set()
	{
		for (int i = 0; i < static_cast<int>(ceil(n / 8)); i++)
		{
			bits[i] = 255;

		}

	}

	void set2()
	{
		for (int i = 0; i < static_cast<int>(ceil(n / 8)); i++)
		{
			bits[i] = 0;

		}

	}

	void set(int bitnum, bool val)
	{
		int bytenum = bitnum / 8;
		int bitoffset = bitnum % 8;

		if (val == true)
		{
			unsigned char mask = (128 >> bitoffset);
			bits[bytenum] = bits[bytenum] | mask;

		}

		else
		{
			unsigned char mask = ~(128 >> bitoffset);
			bits[bytenum] = bits[bytenum] & mask;

		}

	}

	bool getbit(int bitnum)
	{
		int bytenum = bitnum / 8;
		int bitoffset = bitnum % 8;

		unsigned char mask = (128 >> bitoffset);

		mask = mask & bits[bytenum];

		if (mask != 0)
		{
			return true;

		}

		else
		{
			return false;

		}

	}



};


void main()
{
	Bitvector b1(728000);

	b1.set();
	b1.set(8000, false);

	cout << b1.getbit(8000);

}