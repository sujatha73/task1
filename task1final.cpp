#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
void psarray(string r,int m,int *ps);
int global=1;
void KMPsearch(string s,vector<string> Pagestring )
{
	global++;
	vector<string>::iterator i;
	int f=0;
	int k;
	for(i=Pagestring.begin(),k=0;i<Pagestring.end();i++,k++)
	
	{   
        int m=s.length();
		int n=(*i).length();
		int ps[m];
		psarray(s,m,ps);
		int p=0;
		int q=0;
		while(p<n)
		{
			if(s[q]==(*i)[p])
			{
				q++;
				p++;
				
			}
			if(q==m)
			{
				cout<<"page;"<<global<<','<<"line:"<<k<<endl;
				f=1;
				q=ps[q-1];
			}
			else if((p<n)&&(s[q]!=(*i)[p]))
			{
				if(q!=0)
				q=ps[q-1];
				else
				p=p+1;
				
			}
		}
	}
	if(f==0)
	cout<<"None"<<endl;
}
void psarray(string r,int m,int *ps)
{
	int len=0;
	ps[0]=0;
	int i=1;
	while(i<m)
	{
		if(r[i]==r[len])
		{
			len++;
			ps[i]=len;
			i++;
			
		}
		else
		{
			if(len!=0)
			len=ps[len-1];
			else
			{
				ps[i]=0;
				i++;
			}
		}
		
	}
}

void occurence(string search,vector<string> datastring)
{
	KMPsearch(search,datastring);	
}
int main()
{   
    string line;
    string page="page_";
	ifstream ifile("queries.txt",ios::in);
 	vector<string> queryfile;
    vector<string> Dataoffile;
    vector<string>::iterator t;
    if(!ifile)
    cout<<"Error....query file not found"<<endl;
    while (std::getline(ifile, line))
    {
        queryfile.push_back(line);
    }
    for(t=queryfile.begin();t!=queryfile.end();t++)
    {
    	cout<<"WORD:"<<*t<<endl;
    	cout<<"Occurences:"<<endl;
     for(int l=1;l<10;l++)
     {
	ifstream infile("page_"+to_string(1)+".txt",ios::in);
    if(!infile)
	cout<<"error..file not found"<<endl;
    
    while (std::getline(infile, line))
    {
        Dataoffile.push_back(line);
    }
   	occurence(*t,Dataoffile);
	infile.close();
	Dataoffile.clear();
     }
    }

}
