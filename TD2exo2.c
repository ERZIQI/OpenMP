#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>
#include <math.h>


#define NBMAX 8
#define SIZETAB 20000


int tabVal1[NBMAX],tabVal2[NBMAX];
int tab1[NBMAX][SIZETAB],tab2[NBMAX][SIZETAB];

int searchLast (int tab1[SIZETAB],int tab2[SIZETAB],int elem)
{
	int i,j;
	int pos=-1;

	for(i=0;i<SIZETAB; i++){
	   for(j=0;j<SIZETAB; j++){
			if( tab1[i] == tab2[j] && tab1[i] == elem)
					pos = i;}}

   return(pos);
}

int main (void){
	int ncores;
	int i,j;
	double start, end, tExeSeq, tExePar ;
	ncores = omp_get_num_procs();
	printf("%d coeurs disponibles\n",ncores);

    //initialisations
	for(i=0;i<NBMAX; i++){
            tabVal1[i] = i+1;
            tabVal2[i] = i+1;
            for(j=0;j<SIZETAB; j++){
                tab1[i][j] = j-i;
                tab2[i][j] = i-j;
            }
	}


	start=omp_get_wtime();


	for(i=0;i<2;i++){
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	}

	for(i=0;i<4;i++){
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	}

	for(i=0;i<2;i++){
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	}

	for(i=0;i<8;i++){
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	}
	end=omp_get_wtime();

	//utilisation des resultats
	for(i=0;i<8;i++){
     printf ("t%d: %d ",i,tabVal1[i]);
	}
    printf ("\n");
    for(i=0;i<8;i++){
     printf ("t%d: %d ",i,tabVal2[i]);
	}
	printf ("\n");

	tExeSeq=(end-start);
	printf ("temps d'execution seq : %g \n",tExeSeq);


//***************** region parallele ********************************\\ 


	start=omp_get_wtime();
	omp_set_nested(1);

	#pragma omp parallel sections
	{

	#pragma omp section
    {
	
	#pragma omp parallel for num_threads(2)

	for(i=0;i<2;i++){
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	}

	#pragma omp parallel for num_threads(2)

	for(i=0;i<2;i++){
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	   tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	}

	}

	#pragma omp section
	{

	#pragma omp parallel for num_threads(4)

	for(i=0;i<4;i++){
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	}

	#pragma omp parallel for num_threads(6)

	for(i=0;i<8;i++){
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
       tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	   tabVal2[i] =  searchLast (tab1[i], tab2[i],tabVal2[i]);
	}

	}

	}
	end=omp_get_wtime();


	//utilisation des resultats
	for(i=0;i<8;i++){
     printf ("t%d: %d ",i,tabVal1[i]);
	}
    printf ("\n");
    for(i=0;i<8;i++){
     printf ("t%d: %d ",i,tabVal2[i]);
	}
	printf ("\n");

	tExePar=(end-start);
	printf ("temps d'execution par : %g \n",tExePar);

	double Acc;
	Acc =  tExeSeq/tExePar;

	printf ("Acceleration 		= 		 %g \n",Acc);

    return 0;
}