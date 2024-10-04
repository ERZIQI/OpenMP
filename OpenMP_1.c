#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <math.h>


#define NBMAX 8
#define SIZETAB 20000


int tabVal1[NBMAX];
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
	double start, end, tExeSeq,  tExePar, times[4];
	ncores = omp_get_num_procs();
	printf("%d coeurs disponibles\n",ncores);

    //initialisations
	for(i=0;i<NBMAX; i++){
            tabVal1[i] = i+1;
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
	end=omp_get_wtime();

	//utilisation des resultats
	for(i=0;i<8;i++){
     printf ("t%d: %d ",i,tabVal1[i]);
	}
    printf ("\n");

	tExeSeq=(end-start);
	printf ("temps d'execution seq : %g \n",tExeSeq);

	// ****************************** parallele *****************************


	//initialisations
	for(i=0;i<NBMAX; i++){
            tabVal1[i] = i+1;
            for(j=0;j<SIZETAB; j++){
                tab1[i][j] = j-i;
                tab2[i][j] = i-j;
            }
	}

	/*start1=omp_get_wtime();
	tabVal1[0] =  searchLast (tab1[3], tab2[3],tabVal1[3]);
	end1=omp_get_wtime();*/


	start=omp_get_wtime();
	#pragma omp parallel for num_threads(2)
	for(i=0;i<2;i++){
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
       tabVal1[i] =  searchLast (tab1[i], tab2[i],tabVal1[i]);
	}

	times[0] = omp_get_wtime() - start;

	#pragma omp parallel for num_threads(4)
	for(i=0;i<4;i++){
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

	times[1] = omp_get_wtime() - times[0];

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

	times[2] = omp_get_wtime() - times[1];

	#pragma omp parallel for num_threads(8)
	for(i=0;i<8;i++){
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
	times[3] = omp_get_wtime() - times[2];
	end=omp_get_wtime();

	tExePar=(end-start);

	//utilisation des resultats
	for(i=0;i<8;i++){
     printf ("t%d: %d ",i,tabVal1[i]);
	}
    printf ("\n");

	
	printf ("temps d'execution Parallele  : %g \n",tExePar);

	double tot = 0;
	double Acc;
	double cout_total[] = {2,4,2,8};
	double cout_total_;

	for(i=0;i<4;i++){
		tot	+= times[i];
		cout_total_	+= times[i]*cout_total[i];
	}


	long double cout_final =  tot/cout_total_;
	Acc =  tExeSeq/tExePar;

	printf ("Acceleration 		= 		 %g \n",Acc);
	printf ("cout reel		 	= 		 %g \n",cout_final);

	//tExe1=(end1-start1);
	//printf ("temps d'execution de searchLast() : %g \n",tExe1);

    return 0;
}
