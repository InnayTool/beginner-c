

/*
	Generelle Gestalltung von C-Code:
	#################################
	
	C ist eine prozedurale Programmiersprache, d. h. der Code Besteht aus Funktionen bzw. Prozeduren,
	die voneinander aufgerufen werden (s. Funktion 'main').
	Diese Funktionen beinhalten immer einen Funktionskopf (Rückgabetyp, Name, Aufrufargumente)
	und die geschweiften Klammern in denen der Code steht.
	Mit dem Schlüsselwort 'return' kann außerdem ein Wert zurückgegeben werden.
	Die Funktion ist nach dessen Aufruf dann beendet.

	


*/

#include "simpleClib.h"



int quit(int argc, char* argv[])
{
	return 0;
}

int help(int argc, char* argv[])
{
	size_t i;
	conwrite("help(");
	for(i = 1; i < argc; ++i)
	{
		if(i > 1)
			conwrite(", ");
		conwrite(argv[i]);
	}
	conwrite(");");
	return 1;
}

int info(int argc, char* argv[])
{
	conwriteline("info");
	return 1;
}

int zuio(int argc, char* argv[])
{
	conwrite("zuio");
	return 1;
}

int add(int argc, char* argv[])
{
	float f1, f2;
	f1 = strreadfloat(argv[1]);
	f2 = strreadfloat(argv[2]);
	conwritefloat(floating, 1, 6, f1 + f2);
}
int main(int argc, char* argv[])
{

	commandset cmds;

	conwrite("BeginnersC cmd by Yannick Bungers\n2013\n");
	commandcreateset(&cmds, 3);
	commandadd(&cmds, "help", help);
	commandadd(&cmds, "info", info);
	commandadd(&cmds, "quit", quit);
	commandadd(&cmds, "zuio", zuio);
	commandadd(&cmds, "main", main);
	commandadd(&cmds, "add", add);
	commandmainloop(&cmds, "\n>>> ");
	return 1;
}

/*
	Die 'main' funktion ist der Einstiegspunkt des Programms.
	Ihr wird mit 'argc' die Anzahl der Aufargumente und mit 'argv' die Pointer zu diesen übergeben.
	Sie kann wie jede andere Funktion einen Wert zurückgeben. Die wird dann vom Betriebssystem ausgewertet.	
*/
