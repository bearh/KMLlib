/* KMLlib.c
- Contains functions for creating KML files
- which can be read by google earth

Requirements:
A sane unix box(FreeBSD,OpenBSD,OSX, probably some linux distros and the other BSD's) for the use of the strl functions to avoid getting owned as easily ;p

Functions:
init_file();
close_file();
add_element(char *tag);
add_data(char *data);

*/
#include <stdio.h>
#include <string.h>
//#include "kmllib.h"

char line[100];

/*
	- init_file()
	-- Returns a pointer to the indention level (0) and the starting string.
*/
char init_file(){
	extern char line[100];
	char START_STRING[100] = ""
		"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
		"<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n";
	strlcpy(line,START_STRING,sizeof(line));
	return 1;
}

char close_file(){
	extern char line[100];
	char END_STRING[100] = ""
		"</kml>";
	strlcpy(line,END_STRING,sizeof(line));
	return 1;
}
/*
A test function, move to different file.
*/

int main(){
	extern char line[100];
	char file_build[1000];
	init_file();
	strlcat(file_build,line,sizeof(file_build));
	close_file();
	strlcat(file_build,line,sizeof(file_build));
	printf("%s\n",file_build);
}





















