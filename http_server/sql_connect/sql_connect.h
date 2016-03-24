#ifndef _SQL_CONNECT_
#define _SQL_CONNECT_

#include<iostream>
#include<stdlib.h>
#include<string>
#include"mysql.h"

class sql_connecter
{
public:
		sql_connecter(const std::string &_host,const std::string &_user,const std::string &_passwd,const std::string &_db);
		bool begin_connect();
		bool insert_sql(const std::string &data);
		bool select_sql(std::string[],std::string _out_str[][5],int &_out_row);
		bool select_mysql(std::string data1,std::string data2);
		bool close_connect();
		~sql_connecter();
		void show_info();
private:
		MYSQL_RES *res;
		MYSQL *mysql_base;
		std::string host;
		std::string user;
		std::string passwd;
		std::string db;
};

#endif
