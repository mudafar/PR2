

#include <std_lib_facilities.h>


int strsz(const char* str)
{
  int sz = 0;

	while (*str)
	{
		++str;
		sz++;
	}
	str -= sz;        //regresar a la posicion original

	return sz;
}



char* strdupp(const char* str)
{
	int sz = strsz(str);


	char* aux = new char[sz];

	for (int i = 0; i <= sz; i++)
	{
		*aux = *str;
		++str;
		++aux;
	}
	aux -= (sz+1);          

	return aux;
}


char* findx(const char* s, const char* x)
{
	int szs = strsz(s);			//tamaño de s
	int szx = strsz(x);			//tamaño de x
	int cont;

	if (szx > szs)
		return 0;

	for (s; *s != 0; s++)		//que no llegue al final \0 
	{
		if (*s == *x)
		{
			cont = 0;

			for (x; *x != 0 ; x++)
			{
				if (*s == *x)
				{
					++cont;
					++s;
				}
			}
			if (cont == szx)
			{
				s -= cont;
				szs = strsz(s);

				char* fino = new char[szs];
				while (*s != 0)
				{
					*fino = *s;
					++s;
					++fino;
				}
				*fino = '\0';
				fino -= szs;
				return fino;

			}
			x -= szx;
		}
	}




	return 0;
}




int main()
{

	char* str = "Hola como\0";
	char* aux;
	char* fino = "la c\0";

	aux = strdupp(str);

	cout<<aux<<endl;


	cout<<"\n------------------------------------------------------------------------------\n";

	char* aux2 = findx(str,fino);

	cout<<aux2<<endl;



	keep_window_open();
}
