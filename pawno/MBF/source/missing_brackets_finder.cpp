// this is just to start the perl scripts. The real source of the program is in the perl folder (don't delete it!)

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

int main()
{
	// Windows
	system("cd .\\perl\\ && perl GUI.pl");
	system("PAUSE");

	// Linux
	//system("cd ./perl/ && perl GUI.pl");

	std::cout << "Press a key to close the window.." << std::endl;
	char lClose;
	std::cin >> lClose;

	return 0;
}

