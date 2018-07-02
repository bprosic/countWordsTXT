#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<vector>

std::vector<std::string> listWords;
long int nrOfFiles=0;

int loopAllFiles()
{
	DIR *d;
	char *ch1,*ch2;
	int ret;
	int arrSize=0;
	struct dirent *dir;
	d=opendir(".");
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			ch1=strtok(dir->d_name,".");
			ch2=strtok(NULL,".");
			if(ch2!=NULL)
			{
				ret=strcmp(ch2,"txt");
				if (ret==0) {
					listWords.push_back(ch1);
					nrOfFiles++;
				}
			}
		}
		closedir(d);
	}	
	return 0;
}

int main()
{
	unsigned long long w_count=0;
	loopAllFiles();
	unsigned long long c = listWords.size();
	for (int i=0;i<c;i++) {
		int t=0;
		std::ifstream infile(listWords[i]+".txt");
		std::istream_iterator<std::string> in{ infile },end;
		t=std::distance(in,end);
		w_count+=t;
	}
	std::cout<<"\n";
	std::cout<<"nr of files: "<<nrOfFiles<<"\n";
	std::cout<<"nr of words: "<<w_count;
	std::cout<<"\n";
	return 0;
}