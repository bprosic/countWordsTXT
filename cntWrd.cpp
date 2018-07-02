#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<vector>

std::vector<std::string> dd;
long int nrOfFiles=0;

int loopAllFiles()
{
	DIR *d;
	char *p1,*p2;
	int ret;
	int arrSize=0;
	struct dirent *dir;
	d=opendir(".");
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			p1=strtok(dir->d_name,".");
			p2=strtok(NULL,".");
			
			if(p2!=NULL)
			{
				ret=strcmp(p2,"txt");
				if(ret==0)
				{
					dd.push_back(p1);
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
	unsigned long long c = dd.size();
	for(int i=0;i<c;i++){

		int t=0;
		std::ifstream infile(dd[i]+".txt");
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