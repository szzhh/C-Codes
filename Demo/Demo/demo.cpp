#include<cstdlib>
#include<cstdio>
#include<string>
#include"engine.h"

const int BUFFER_SIZE = 1024;
char buffer[BUFFER_SIZE];
void test()
{
	Engine *ep;
	mxArray *x1 = NULL;
	mxArray *y1 = NULL;
	mxArray *z1 = NULL;
	if ((ep = engOpen("")) == NULL)
	{
		printf("Engine Fail\n");
	}
	engOutputBuffer(ep, buffer, BUFFER_SIZE);
	printf("Init Success\n");

	double x[20] = { -0.8,-0.4,0.0,0.6,-0.8,-0.4,0.0,0.6,-0.8,-0.4,0.2,0.6,-0.8,-0.4,0.2,0.6,-0.8,-0.2,0.2,0.6 };
	double y[20] = { -0.4,-0.4,0.8,-0.8,-0.2,-0.6,1.0,-0.6,0.0,-0.8,-0.8,-0.4,-0.2,-0.8,-0.6,-0.2,-0.4,-0.6,-0.4,0.0 };
	double z[20] = { 0.477,0.825,0.600,0.000,0.566,0.693,0.000,0.529,0.600,0.477,0.566,0.693,0.566,0.566,0.775,0.775,0.447,0.775,0.894,0.800 };
	x1 = mxCreateDoubleMatrix(1, 20, mxREAL);
	y1 = mxCreateDoubleMatrix(1, 20, mxREAL);
	z1 = mxCreateDoubleMatrix(1, 20, mxREAL);

	memcpy((char*)mxGetPr(x1), (void *)x, 20 * sizeof(double));
	memcpy((char*)mxGetPr(y1), (void *)y, 20 * sizeof(double));
	memcpy((char*)mxGetPr(z1), (void *)z, 20 * sizeof(double));

	engPutVariable(ep, "x", x1);
	engPutVariable(ep, "y", y1);
	engPutVariable(ep, "z", z1);
	engEvalString(ep, "scatter3(x,y,z,'*')");
	getchar();
	engClose(ep);
}

int main()
{
	test();
}