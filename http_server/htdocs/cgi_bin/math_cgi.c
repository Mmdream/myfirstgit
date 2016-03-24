#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
void math_add(char *const data_string)
{
	if(!data_string)
	{
		return;
	}
	char *data1 = NULL;
	char *data2 = NULL;
	char *start = data_string;
	while(*start != '\0')
	{
		if(*start == '=' && data1 == NULL)
		{
			data1 = start+1;
			start++;
			continue;
		}
		if(*start == '&')
		{
			*start = '\0';
		}
		if(*start == '=' && data1 != NULL)
		{
			data2 = start+1;
			break;
		}
		start++;
	}
	int int_data1 = atoi(data1);
	int int_data2 = atoi(data2);
	int add_res = int_data1 + int_data2;
	printf("<p>the add result is: %d</p>\n", add_res);
}
*/

void math_mul(char *const data_string)
{
	if(!data_string)
	{
		return;
	}
	char *data1 = NULL;
	char *data2 = NULL;
	char *start = data_string;
	while(*start != '\0')
	{
		if(*start == '=' && data1 == NULL)
		{
			data1 = start+1;
			start++;
			continue;
		}
		if(*start == '&')
		{
			*start = '\0';
		}
		if(*start == '=' && data1 != NULL)
		{
			data2 = start+1;
			break;
		}
		start++;
	}
	int int_data1 = atoi(data1);
	int int_data2 = atoi(data2);
	int mul_res = int_data1 * int_data2;
	printf("<p>the mul result is: %d</p>\n", mul_res);
}

int main()
{
	int content_length = -1;
	char method[1024];
	char query_string[1024];
	char post_data1[4096];
	//char post_data2[4096];

	memset(method, '\0', sizeof(method));
	memset(query_string, '\0', sizeof(query_string));
	memset(post_data1, '\0', sizeof(post_data1));
	//memset(post_data2,'\0',sizeof(post_data2));

	printf("<html>\n");
	printf("<head>MATH YUNSUAN</head>\n");
	printf("<body>\n");
	strcpy(method, getenv("REQUEST_METHOD"));
	if( strcasecmp("GET", method) == 0 )
	{
		strcpy(query_string, getenv("QUERY_STRING"));
		//math_add(query_string);
		math_mul(query_string);
	}
	else if( strcasecmp("POST", method) == 0 )
	{
		content_length = atoi(getenv("CONTENT_LENGTH"));
		int i = 0; 
		for(; i < content_length; i++ ){
			read(0, &post_data1[i], 1);
		}
		post_data1[i] = '\0';
		math_mul(post_data1);
/*
		int j = i+1;
		for(;j<content_length;j++)
		{
			read(0,&post_data2[j],1);
		}
		post_data2[j] = '\0';
		math_mul(post_data);
*/
	}
	else
	{
		//DO NOTHING
		return 1;
	}

	printf("</body>\n");
	printf("</html>\n");
}
