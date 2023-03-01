#include <iostream>
#include <string>
//#include <cctype>
using std::cout;
using std::endl;
using std::cin;
using std::string;
int main(void){
	string str1="hi,test,hello";
	string str2="hi,test";
	//字符串比较
	if(str1.compare(str2)>0)
		printf("str1>str2\n");
	else if(str1.compare(str2)<0)
		printf("str1<str2\n");
	else
		printf("str1==str2\n");
	
	//str1的子串（从索引3开始，包含4个字符）与str2进行比较
	if(str1.compare(3,4,str2)==0)
		printf("str1的指定子串等于str2\n");
	else
		printf("str1的指定子串不等于str2\n");
	
	//str1指定子串与str2的指定子串进行比较
	if(str1.compare(3,4,str2,3,4)==0)
		printf("str1的指定子串等于str2的指定子串\n");
	else
		printf("str1的指定子串不等于str2的指定子串\n");
	
	//str1指定子串与字符串的前n个字符进行比较
	if(str1.compare(0,2,"hi,hello",2)==0)
		printf("str1的指定子串等于指定字符串的前2个字符组成的子串\n");
	else
		printf("str1的指定子串不等于指定字符串的前2个字符组成的子串\n");
	return 0;
}
