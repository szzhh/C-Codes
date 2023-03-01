#include<iostream>
#include <stdlib.h>
#include <string.h>
#include "engine.h"     // 添加头文件
using namespace std;


int main(void)
{
	Engine *ep;

	// open engine
	if (!(ep = engOpen("\0")))
	{
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		return EXIT_FAILURE;
	}

	double xx[20] = { -0.8,-0.4,0.0,0.6,-0.8,-0.4,0.0,0.6,-0.8,-0.4,0.2,0.6,-0.8,-0.4,0.2,0.6,-0.8,-0.2,0.2,0.6 };
	double yy[20] = { -0.4,-0.4,0.8,-0.8,-0.2,-0.6,1.0,-0.6,0.0,-0.8,-0.8,-0.4,-0.2,-0.8,-0.6,-0.2,-0.4,-0.6,-0.4,0.0 };
	double zz[20] = { 0.477,0.825,0.600,0.000,0.566,0.693,0.000,0.529,0.600,0.477,0.566,0.693,0.566,0.566,0.775,0.775,0.447,0.775,0.894,0.800 };
	
	double x1[181], y1[181], z1[181][181];
	double tt = -0.8;
	for (int ii = 0; ii <= 180; ii++)
	{
		x1[ii] = tt;
		y1[ii] = tt;
		tt += 0.01;
	}
	for (int ii = 0; ii <= 180; ii++)
	{
		for (int jj = 0; jj <= 180; jj++)
		{
			z1[ii][jj] = x1[ii] * x1[ii] * y1[jj] + 0.62816;
		}
	}

	mxArray *X = NULL, *Y = NULL, *Z = NULL, *Z1 = NULL, *result = NULL;
	X = mxCreateDoubleMatrix(1, 20, mxREAL);
	Y = mxCreateDoubleMatrix(1, 20, mxREAL);
	Z = mxCreateDoubleMatrix(1, 20, mxREAL);
	Z1 = mxCreateDoubleMatrix(181, 181, mxREAL);
	memcpy((void *)mxGetPr(X), (void *)xx, sizeof(xx));
	memcpy((void *)mxGetPr(Y), (void *)yy, sizeof(yy));
	memcpy((void *)mxGetPr(Z), (void *)zz, sizeof(zz));
	memcpy((void *)mxGetPr(Z1), (void *)z1, sizeof(z1));
	engPutVariable(ep, "X", X);
	engPutVariable(ep, "Y", Y);
	engPutVariable(ep, "Z", Z);   
	engPutVariable(ep, "Z1", Z1);// put data to engine

	// execute matlab operations
	engEvalString(ep, "scatter3(X,Y,Z,'*');");
	engEvalString(ep, "hold on");
	engEvalString(ep, "X1=-0.8:0.01:1;");
	engEvalString(ep, "Y1=-0.8:0.01:1;");
	engEvalString(ep, "[X1,Y1]=meshgrid(X1,Y1);");
	engEvalString(ep, "mesh(X1,Y1,Z1);");
	engEvalString(ep, "hold off;");

	fgetc(stdin);

	// clean operation
	mxDestroyArray(X);
	mxDestroyArray(Y);
	mxDestroyArray(Z);
	mxDestroyArray(Z1);
	engEvalString(ep, "close;");

	
	engClose(ep);// 关闭引擎

	return 0;
}