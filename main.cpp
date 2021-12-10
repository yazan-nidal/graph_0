#include"source.cpp"
//#include<iostream>
//using namespace std;

class nodeE
{    
private:
	int vertex1;
	int vertex2;
	int weight;
public:
nodeE(int v1=0,int v2=0,int w=0){ (*this).setEdge(v1,v2,w); }

void setEdge(int v1,int v2,int w)
{
	(*this).vertex1=v1;
	this->vertex2=v2;
	weight=w;
}

bool equalIndirected(const nodeE &obj)
{
	if((*this).weight != obj.weight)return false;
	if( ((*this).vertex1 == obj.vertex1)&&((*this).vertex2 == obj.vertex2) )return true;
	if( ((*this).vertex1 == obj.vertex2)&&((*this).vertex2 == obj.vertex1) )return true;
	return false;
}

void operator<<(int){ (*this).printEdge(); }

void printEdge()
{
	cout<<"vertex1 : "<<(*this).vertex1<<"\n";
	cout<<"vertex2 : "<<this->vertex2<<"\n";
	cout<<"weight : "<<weight<<"\n";
}

void getPair(){ cout<<"("<<this->vertex1<<" , "<<(*this).vertex2<<")";  }

~nodeE(){/* nothing to do */}

};

class nodeN
{
private:
	int vertex;
	int weight;
public:

nodeN(int v=0, int w=0)
{ setNodeN(v,w); }

void setNodeN(int v,int w)
{
	(*this).vertex=v;
	(*this).weight=w;
}

void operator<<(int){(*this).printNode();}

bool operator < (const nodeN &obj)
{ 
	if((*this).vertex == obj.vertex)return ((*this).weight < obj.weight);
	return ((*this).vertex < obj.vertex);
}

void printNode()
{
	cout<<"vertex : "<<(*this).vertex<<"\n";
	cout<<"weight : "<<weight<<"\n";
}

~nodeN(){/* nothing to do */}

};

int maxEdges(int num){return((num*(num-1))/2);}

void proce(int **&graph_matrix,nodeE *&as,sList <nodeN> *&bs,int numN,int numE)
{
	// intlaize
	graph_matrix=new int* [numN+1];
	for(int i=0;i<numN+1;i++)
	{
		*( graph_matrix+i)=new int[numN+1];
		**( graph_matrix+i)=i;
		*(*( graph_matrix)+i)=i;
		for(int j=1;j<=numN;j++){ *(*( graph_matrix+i)+j)=0; }
	}

	 as= new nodeE[numE+1];

	 bs= new sList<nodeN>[numN+1];

	 // /intlaize

	//proce
	int x,y,z;
	for(int i=1;i<=numE;i++)
	{
		do{cout<<"Please enter edge"<<i<<" and its weight in the order (vertex1, vertex1, weight): ";
		cin>>x; cin>>y; cin>>z;
		//x--; y-=1; z=z-1;
		if((x>numN) || (x<1) || (y>numN) || (y<1) || (x==y) || (graph_matrix[x][y]) || (graph_matrix[y][x]==1))
			{cout<<"Error : invalid input of edge !!!\n";}
		}
		while((x>numN) || (x<1) || (y>numN) || (y<1) || (x==y) || (graph_matrix[x][y]!=0));
		while(z<=0){cout<<"Error : weight  must be greater than 0 !!! \n"<<"Please enter weight for edge : "; cin>>z;}
		
		*(*( graph_matrix+x)+y)=z;
		*(*( graph_matrix+y)+x)=z;

		as[i].setEdge(x,y,z);

		//bs
		nodeN *p=new nodeN;
		(*p).setNodeN(y,z);
		bs[x].insert((*p));
		//bs
		p=new nodeN;
		(*p).setNodeN(x,z);
		bs[y].insert((*p));
	}

	 // /proce
}

void printMTX(int **&graph_matrix,	int numN,int numE)
{
	//print
	cout<<"\n print Matrix : \n\n";
	cout<<"	";
	for(int i=1;i<=numN;i++){cout<<*(*( graph_matrix)+i)<<"	";}cout<<endl<<endl;
	for(int i=1;i<=numN;i++)
	{cout<<*(*( graph_matrix+i))<<"	";
	for(int j=1;j<=numN;j++)
	{cout<<*(*( graph_matrix+i)+j)<<"	";}
	cout<<"\n";
	}
}

void printAS(nodeE *&as,int numE)
{
	cout<<"\n print Array of structures : \n\n";
	for(int i=1;i<=numE;i++){cout<<i<<"- \n"; *(as+i)<<1; cout<<"\n";}
}

void printALIST(sList <nodeN> *&bs,int numN)
{
	cout<<"/n Print array of lists  :\n\n";
	for(int i=1;i<=numN;i++)
	{ cout<<" List "<<i<<" : \n";
	bs[i].print();
	cout<<'\n';
	}
}

void intersection(nodeE *&asA,nodeE *&asB,int numE1,int numE2)
{
	if(asA==asB){cout<<"The same Graph \n"; return;}
	bool b=false;
	cout<<"intersection : ";
	for(int i=1;i<=numE1;i++)
	{
		for(int j=1;j<=numE2;j++)
		{
			if(asA[i].equalIndirected(asB[j])==1)
			{ if(!b){b=true; (*(asA+i)).getPair();} else{ cout<<","; (*(asA+i)).getPair(); } j=numE2+1; }
		}

	}
	if(!b){cout<<"no intersection \n";}
}

void subgraph(nodeE *&asA,nodeE *&asB,int numE1,int numE2)
{
	if(asA==asB){cout<<"The same Graph \n"; return;}
	if(numE1 > numE2){cout<<" NO \n"; return;}
		for(int i=1;i<=numE1;i++)
	{ bool b=false;
		for(int j=1;j<=numE2;j++)
		{
			if(asA[i].equalIndirected(asB[j])==1){b=true; j=numE2+1;}
		}

		if(!b){cout<<" NO \n"; return;}
	}

	cout<<" Yes \n";
}

void highest_degree(sList <nodeN> *bs,int numN)
{
	int h=0;
	for(int i=1;i<=numN;i++){ int l=bs[i].sizE(); if(l>=h)h=l; }
	if(h==0){cout<<"Empty Graph \n"; return;}
	bool b=false;
	for(int i=1;i<=numN;i++)
	{
		int l=bs[i].sizE(); 
		if(l==h)
		{ 
			if(!b){cout<<i; b=true;} else{cout<<","<<i;}
		}
	}
	cout<<" with the degree of "<<h<<"\n";
}

void lowest_degree(sList <nodeN> *bs,int numN)
{
	int h=maxEdges(numN);
	for(int i=1;i<=numN;i++){ int l=bs[i].sizE(); if(l<=h)if(l!=0)h=l; }
	if(h==maxEdges(numN)){cout<<"Empty Graph \n"; return;}
	bool b=false;
	for(int i=1;i<=numN;i++)
	{
		int l=bs[i].sizE(); 
		if(l==h)
		{ 
			if(!b){cout<<i; b=true;} else{cout<<","<<i;}
		}
	}
	cout<<" with the degree of "<<h<<"\n";
}

void main()
{
	// graph A
	//parametaer graph A
	int **graph_matrixA;
	nodeE *asA;
	sList <nodeN> *bsA;

	//intlaize
	int t1,t2;
	do{cout<<"Please enter the number of nodes in graph A: "; cin>>t1;
	if(t1<=1){cout<<"Error : input Number of Node !!! \n";}}
	while(t1<=1);

	do{cout<<"Please enter the number of edges in Graph A: ";cin>>t2; if(t2>maxEdges(t1) || t2<=0){cout<<"Error : input number of edges !!!\n";}}
	while(t2>maxEdges(t1) || t2<=0);
	
	//nodes and edges graph A
    const int numN1=t1;
	const int numE1=t2;
	//proce graph A
	proce(graph_matrixA,asA,bsA,numN1,numE1);
	cout<<"\n";
	//graph B
	//parametaer graph B
	int **graph_matrixB;
	nodeE *asB;
	sList <nodeN> *bsB;

	//intlaize
	int c1,c2;
	do{cout<<"Please enter the number of nodes in graph B: "; cin>>c1;
	if(c1<=1){cout<<"Error : input Number of Node !!! \n";}}
	while(c1<=1);

	do{cout<<"Please enter the number of edges in Graph B: ";cin>>c2; if(c2>maxEdges(c1) || c2<=0){cout<<"Error : input number of edges !!!\n";}}
	while(c2>maxEdges(c1) || c2<=0);
	
	//nodes and edges graph B
    const int numN2=c1;
	const int numE2=c2;
	//proce graph B
	proce(graph_matrixB,asB,bsB,numN2,numE2);
	
	cout<<"\n";

	int select=0;
	do{
	cout<<"Please select one of the following: \n\n";
	cout<<" 1- Output graph A from the array of lists \n"; 
	cout<<" 2- Output graph A from the matrix \n";
	cout<<" 3- Output graph A from the array of structures \n";
	cout<<" 4- Output graph B from the array of lists \n"; 
	cout<<" 5- Output graph B from the matrix \n";
	cout<<" 6- Output graph B from the array of structures \n";
	cout<<" 7- Output the intersection between both graphs \n";
	cout<<" 8- Is graph (A) a subgraph of graph (B)? \n";
	cout<<" 9- Is graph (B) a subgraph of graph (A)? \n";
	cout<<" 10- Display the vertex (vertices) with the highest degree from graph A. \n";
	cout<<" 11- Display the vertex (vertices) with the lowest degree from graph A. \n";
	cout<<" 12- Display the vertex (vertices) with the highest degree from graph B. \n";
	cout<<" 13- Display the vertex (vertices) with the lowest degree from graph B. \n";
	cout<<" 14- Exit program \n";

	cout<<"\n select : "; cin>>select;

	switch(select)
	{
	case 1:{printALIST(bsA,numN1); cout<<"\n\****************************************************\n"; break; }
	case 2:{printMTX(graph_matrixA,numN1,numE1); cout<<"\n\****************************************************\n"; break; }
	case 3:{printAS(asA,numE1); cout<<"\n\****************************************************\n"; break; }
	case 4:{printALIST(bsB,numN2); cout<<"\n\****************************************************\n"; break; }
	case 5:{printMTX(graph_matrixB,numN2,numE2); cout<<"\n\****************************************************\n"; break; }
	case 6:{printAS(asB,numE2); cout<<"\n\****************************************************\n"; break; }
	case 7:{intersection(asA,asB,numE1,numE2); cout<<"\n\****************************************************\n"; break; }
	case 8:{cout<<"answer : ";subgraph(asA,asB,numE1,numE2); cout<<"\n\****************************************************\n"; break; }
	case 9:{cout<<"answer : ";subgraph(asB,asA,numE2,numE1); cout<<"\n\****************************************************\n"; break; }
	case 10:{highest_degree(bsA,numN1); cout<<"\n\****************************************************\n"; break; }
	case 11:{lowest_degree(bsA,numN1); cout<<"\n\****************************************************\n"; break; }
	case 12:{highest_degree(bsB,numN2); cout<<"\n\****************************************************\n"; break; }
	case 13:{lowest_degree(bsB,numN2); cout<<"\n\****************************************************\n"; break; }
	case 14:{break;}

	default :
		{
			cout<<"Error : invalid select !!! \n";
		}
	}

	}
	while(select != 14);

	cout<<"\n\n-------------End of Programe-------------\n";

}