FIND_PATH=-I/home/tem/bit/linux/httpd/sql_connect -I/home/tem/bit/linux/httpd/sql_connect/mysql_lib/include -L/home/tem/bit/linux/httpd/sql_connect/mysql_lib/lib -lmysqlclient

.PHONY:all
all: debug_cgi math_cgi show_student_cgi register_cgi
debug_cgi:debug_cgi.c
	@gcc -o $@ $^
math_cgi:math_cgi.c
	@gcc -o $@ $^
show_student_cgi:show_student_cgi.cpp /home/tem/bit/linux/httpd/sql_connect/sql_connect.cpp 
	@g++ -o $@ $^ $(FIND_PATH) -g

register_cgi:register_cgi.cpp /home/tem/bit/linux/httpd/sql_connect/sql_connect.cpp 
	@g++ -o $@ $^ $(FIND_PATH)


.PHONY:output
output:
	@cp debug_cgi ../output/htdocs/cgi_bin 
	@cp math_cgi ../output/htdocs/cgi_bin 
	@cp show_student_cgi ../output/htdocs/cgi_bin

	@cp register_cgi ../output/htdocs/cgi_bin
	@cp ../cgi_bin/* ../htdocs/

.PHONY:clean
clean:
	@rm -rf  ../htdocs/debug_cgi  
	@rm -rf  ../htdocs/math_cgi 
	@rm -rf  ../htdocs/show_student_cgi 
	@rm -rf  ../htdocs/register_cgi
	@rm -rf debug_cgi math_cgi show_student_cgi register_cgi
