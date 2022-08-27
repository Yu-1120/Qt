#include <stdio.h>
#include "./sqlite3.h"

//处理查询结果的回调函数 --- 一条结果调用一次
int sql_callback(void *arg, int col, char **str, char **name)
{
	int i;
	for (i = 0; i < col; i++)
	{
		printf("%s:%s ", name[i], str[i]);
	}
	printf("\n");

	return SQLITE_OK;
}

int main()
{
	//声明数据库的句柄
	//句柄是啥意思------
	/*
	句柄有多种意义：1、在程序设计中，指一种特殊的智能指针 ；
	2、在Windows编程中，是Windows用来标识被应用程序所建立或使用的对象的唯一整数，
	Windows使用各种各样的句柄标识诸如应用程序实例，窗口，控制，位图，GDI对象等等。
	****************************************************************************
	句柄(handle)，有两种解释

	第一种解释：句柄是一种特殊的智能指针 。当一个应用程序要引用其他系统(如数据库、操作系统)所管理的内存块或对象时，就要使用句柄。

	第二种解释：整个Windows编程的基础。

	句柄是Windows用来标识被应用程序所建立或使用的对象的唯一整数，WINDOWS使用各种各样的句柄标识诸如应用程序实例，窗口，控制，位图，GDI对象等等。

	一个句柄是指使用的一个唯一的整数值，即一个4字节(64位程序中为8字节)长的数值，来标识应用程序中的不同对象和同类中的不同的实例，诸如，一个窗口，按钮，图标，滚动条，输出设备，控件或者文件等。

	应用程序能够通过句柄访问相应的对象的信息，但是句柄不是指针，程序不能利用句柄来直接阅读文件中的信息。如果句柄不在I/O文件中，它是毫无用处的。 句柄是Windows用来标志应用程序中建立的或是使用的唯一整数，Windows大量使用了句柄来标识对象。


	*/
	sqlite3 *pDb = NULL;
	//打开数据库
	int res = sqlite3_open("./first.db", &pDb);
	if (res != SQLITE_OK)
	{
		printf("打开数据库失败!\n");
		return -1;
	}
	printf("打开数据库成功!\n");

	//执行SQL语句
	//建表
	// const char *sql = "create table if not exists stutbl(id int unique,name ntext,age int);";
	//插入数据
	/*
	const char *sql = "insert into stutbl values(1003,\'孙二娘\',28);";
	res = sqlite3_exec(pDb,sql,NULL,NULL,NULL);
	if(res!=SQLITE_OK){
		printf("执行sql语句失败!\n");
		return -1;
	}
	*/
	//    int sqlite3_exec(
	//   sqlite3 *pDb,                              /* 打开的数据库的句柄 */
	//   const char *sql,                           /* 要执行的SQL语句 */
	//   int (*callback)(void *arg,int col,char **str,char **name),
	//   /* 回调函数,处理SQL语句执行返回的结果(查询),一条结果调用一次
	//       arg - exec的第四个参数
	//       col - 本条结果的字段数
	//       str - 记录字段值的数组
	//       name - 记录字段名的数组
	//      回调函数必须返回SQLITE_OK */
	//   void *arg,                                 /* 传递给回调函数的第一个参数 */
	//   char **errmsg                              /* 错误信息 */
	// );
	// //成功返回SQLITE_OK,否则执行失败

	//查询数据----------------需要调回调函数
	const char *sql = "select * from stutbl;";
	res = sqlite3_exec(pDb, sql, sql_callback, NULL, NULL); // 8个参数其中4个封装成一个函数了
	if (res != SQLITE_OK)
	{
		printf("执行sql语句失败!\n");
		return -1;
	}

	//关闭数据库
	sqlite3_close(pDb);
	return 0;
}
