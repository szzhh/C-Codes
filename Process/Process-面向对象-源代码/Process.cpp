// Process.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Control.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	CControl control;

	control.welcome();  //页面加载3s左右，可以去掉
	control.run();
	return 0;
}

