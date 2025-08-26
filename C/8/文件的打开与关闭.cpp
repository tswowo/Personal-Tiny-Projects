#include<stdio.h>
int main()
{
	//stdio.h中定义了别名为FILE的结构体指针变量类型
	//以及相关文件读写操作函数
	FILE *p;//可以指向一个打开文件的文件信息区，通过文件信息区的信息可以 访问该文件
	p=fopen("test_open.txt","w");//"w"只写，指定文件不存在时，建立新文件 
	
	fputs("Hello World\n",p);//fputs从文件开头向文件写数据 
	fputs("Hello Shopping",p);
	
	fclose(p);//关闭文件以确保文件安全
	//如果没有关闭文件，程序执行完毕后，文件也会自动关闭 
	p=NULL;
	return 0;	
}
