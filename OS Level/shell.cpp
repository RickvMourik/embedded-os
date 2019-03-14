#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
#include <termios.h>
using namespace std;

#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);


void new_file(){
	string filename = "";
	cout << "Enter filename: ";
	cin >> filename;
	string path = "/home/hu/" + filename;
	creat(path.c_str(), S_IRWXO | S_IRWXU);
	string text = "";
	cout << "\nEnter text: ";
	cin.ignore();
	getline(cin, text);
	text += "\n";
	int fd  = open(path.c_str(), O_RDWR | O_EXCL);
	const void * input = text.c_str();
	write(fd, input, strlen(text.c_str()));
	close(fd);
}

void ls(){
	string path = "";
	cout << "Enter path: ";
	cin >> path;
	int pid = fork();
	if (pid == 0){
		execlp("ls", "ls", "-la", path.c_str(), NULL);
	}
	int waitnr = 2;
	wait(&waitnr);
}

void find(){
  int pid;
  int pip[2]; 
  int status;
  std::string str_search;

  std::cout << "Search: "; 
  std::getline(std::cin, str_search);
  const char * search = str_search.c_str();

  pipe(pip);
  pid = fork();

  if (pid == 0) {
    dup2(pip[1], 1);
    close(pip[0]);
    close(pip[1]);
    execlp("find", "find", ".", NULL);
  }
  else {
    wait(NULL);
  }
  pid = fork();
  if (pid == 0) {
    dup2(pip[0], 0);
    close(pip[0]);
    close(pip[1]);
    execlp("grep", "grep", search, NULL);
  }
  close(pip[0]);
  close(pip[1]);
  wait(NULL);
}




void python(){
  pid_t pid = fork();
  int status;
  if (pid == 0){
    execlp("python", "python", NULL);
  }else{
    wait(NULL);
  }
}
