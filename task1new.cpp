#include<iostream>
#include <bits/stl_vector.h>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
void psarray(string r,int m,int *ps);
void KMPsearch(string s,vector<string> Pagestring )
{
	
	vector<string>::iterator i;
	int f=0;
	int k;
	for(i=Pagestring.begin(),k=0;i<Pagestring.end();i++,k++)
	
	{   
		int m=s.length();
		int n=Pagestring[i].length();
		int ps[m];
		psarray(s,m,ps);
		int p=0;
        int q=0;
        while (p < n)
     {
        if (s[q] == Pagestring[i][p])
        {
            q++;
            p++;
        }
 
        if (q== m)
        {
            cout<<"page:"<<1<<','<<"line:"<<k<<endl;
            f=1;
            q = ps[q-1];
        }

        else if (p < n && s[q] != Pagestring[i][p])
        {
            
            if (q != 0)
                q = ps[q-1];
            else
                p = p+1;
        }
        
        
    }
   }
      if(f==0)
     cout<<"None"<<endl;
  
 }

void psarray(string r, int m, int *ps)
{
    
    int len = 0;
    ps[0] = 0;
    int i = 1;
    while (i < m)
    {
        if (r[i] == r[len])
        {
            len++;
            ps[i] = len;
            i++;
        }
        else 
       {
            if (len != 0)
                len = ps[len-1];
            else 
            {
                ps[i] = 0;
                i++;
            }
        }
    }
}
void occurence(string search,vector<string> datastring)
{
	
	cout<<"WORD:"<<search<<endl;
	KMPsearch(search,datastring);
	cout<<"occurences:"<<endl;
}

 


int main()
{   
    string line;
	ifstream infile("page_1.txt",ios::in );
	ifstream ifile("queries.txt",ios::in);
 	vector<string> queryfile;
    vector<string> Dataoffile;
    if(!ifile)
    cout<<"Error....query file not found"<<endl;
    while (std::getline(ifile, line))
    {
        queryfile.push_back(line);
    }
    vector<string>::iterator it;
    vector<string>::iterator t;
    if(!infile)
	cout<<"error..file not found"<<endl;
    
    while (std::getline(infile, line))
    {
        Dataoffile.push_back(line);
    }
    for( it=Dataoffile.begin();it<Dataoffile.end();it++)
    cout<<*it;
    for(t=queryfile.begin();t=queryfile.end();t++)
    {
    	occurence(*t,Dataoffile[]);
    	
	}
}

