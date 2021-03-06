#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "sql_connect.h"

const std::string _remote_ip = "192.168.146.128";
const std::string _remote_user = "tem";
const std::string _remote_passwd = "123456";
const std::string _remote_db   = "mysqlhttp";

void regis_ter(char *const data_string)
{
	if(!data_string)
	{
		return;
	}
	
	char name[64];
	char price[64];
	char sales_volume[64];
	char producer[64];
	char *start_string = data_string;
	//printf("data_string is :%s\n",data_string);
	char post_data[1024];

	memset(post_data,'\0',sizeof(post_data));
	int i = 0;
	while(start_string[i] != '\0')
	{
		if(start_string[i] == '=' || start_string[i] == '&')
		{
			start_string[i] = ' ';
		}
		i++;	
	}

	bzero(name,sizeof(name));
	bzero(price,sizeof(price));
	bzero(sales_volume,sizeof(sales_volume));
	bzero(producer,sizeof(producer));
	sscanf(start_string,"%*s %s %*s %s %*s %s %*s %s",name,price,sales_volume,producer);
	
	//printf("%s\n",name);
	//printf("%s\n",price);
	//printf("%s\n",sales_volume);
	//printf("%s\n",producer);


    sql_connecter conn(_remote_ip, _remote_user,_remote_passwd, _remote_db);
    conn.begin_connect();
	
	strcat(post_data,"\'");
	strcat(post_data,name);
	strcat(post_data,"\'");
	strcat(post_data,",");

	strcat(post_data,price);
	strcat(post_data,",");
	strcat(post_data,sales_volume);
	strcat(post_data,",");
	strcat(post_data,"\'");
	strcat(post_data,producer);
	strcat(post_data,"\'");

	//printf("%s",post_data);

	conn.insert_sql(post_data);
	std::cout<<"Register Success!<br/>"<<std::endl;
}


int main()
{

	int content_length = -1;
	char method[1024];
	char query_string[1024];
	char post_data[4096];

	memset(method, '\0', sizeof(method));
	memset(query_string, '\0', sizeof(query_string));
	memset(post_data, '\0', sizeof(post_data));

	std::cout<<"<html>"<<std::endl;
	std::cout<<"<head>Register The Car's Information Result</head><br/>"<<std::endl;
	std::cout<<"<body>"<<std::endl;

	strcpy(method, getenv("REQUEST_METHOD"));
	if( strcasecmp("GET", method) == 0 )
	{
		strcpy(query_string, getenv("QUERY_STRING"));	
		regis_ter(query_string);
	}
	else if( strcasecmp("POST", method) == 0 )
	{
		content_length = atoi(getenv("CONTENT_LENGTH"));
		int i = 0; 
		for(; i < content_length; i++ )
		{
			read(0, &post_data[i], 1);
		}
		post_data[i] = '\0';
		regis_ter(post_data);
	}
	

	std::string _sql_data[1024][5];
	std::string header[5];
	int curr_row = -1;

	sql_connecter conn(_remote_ip,_remote_user,_remote_passwd,_remote_db);
	conn.begin_connect();
	conn.select_sql(header,_sql_data,curr_row);
	std::cout<<"<table border=\"1\">"<<std::endl;
	std::cout<<"<tr>"<<std::endl;

	for(int i = 0;i < 5;i++)
	{
		std::cout<<"<th>"<<header[i]<<"</th>"<<std::endl;

	}

	std::cout<<"</tr>"<<std::endl;

	for(int i = 0;i < curr_row; i++)
	{
		std::cout<<"<tr>"<<std::endl;
		for(int j =0;j < 5;j++)
		{
			std::cout<<"<td>"<<_sql_data[i][j]<<"</td>"<<std::endl;
		}
		std::cout<<"</tr>"<<std::endl;
	}
	std::cout<<"</table>"<<std::endl;
	std::cout<<"</body>"<<std::endl;
	std::cout<<"</html>"<<std::endl;
return 0;
}
