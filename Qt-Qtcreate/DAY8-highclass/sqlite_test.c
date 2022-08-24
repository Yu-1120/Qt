#include <stdio.h>
#include "sqlite3.h"

//处理查询结果的回调函数 --- 一条结果调用一次
int sql_callback(void *arg,int col,char **str,char **name)
{
	int i;
	for(i=0;i<col;i++){
		printf("%s:%s ",name[i],str[i]);
	}
	printf("\n");
	
	return SQLITE_OK;
}

int main()
{
	//声明数据库的句柄
	sqlite3 *pDb = NULL;
	//打开数据库
	int res = sqlite3_open("./first.db",&pDb);
	if(res!=SQLITE_OK){
		printf("打开数据库失败!\n");
		return -1;
	}
	printf("打开数据库成功!\n");
	
	//执行SQL语句
	//建表
	//const char *sql = "create table if not exists stutbl(id int unique,name ntext,age int);";
	//插入数据
	/*
	const char *sql = "insert into stutbl values(1003,\'孙二娘\',28);";
	res = sqlite3_exec(pDb,sql,NULL,NULL,NULL);
	if(res!=SQLITE_OK){
		printf("执行sql语句失败!\n");
		return -1;
	}
	*/
	
	//查询数据
	const char *sql = "select * from stutbl;";
	res = sqlite3_exec(pDb,sql,sql_callback,NULL,NULL);
	if(res!=SQLITE_OK){
		printf("执行sql语句失败!\n");
		return -1;
	}

	
	//关闭数据库
	sqlite3_close(pDb);
	return 0;
}
