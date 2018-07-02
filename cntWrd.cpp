#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<vector>

std::vector<std::string> vectorWords;
long int nrOfFiles=0;

int loopAllFiles()
{
	DIR *d;
	char *char1,*char2;
	int ret;
	int arrSize=0;
	struct dirent *dir;
	d=opendir(".");
	if(d)
	{
		while((dir=reavectorWordsir(d))!=NULL)
		{
			char1=strtok(dir->d_name,".");
			char2=strtok(NULL,".");
			
			if(char2!=NULL)
			{
				ret=strcmp(char2,"txt");
				if(ret==0)
				{
					vectorWords.push_back(char1);
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
	unsigned long long c = vectorWords.size();
	for(int i=0;i<c;i++){

		int t=0;
		std::ifstream infile(vectorWords[i]+".txt");
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