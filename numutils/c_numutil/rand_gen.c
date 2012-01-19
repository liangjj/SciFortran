/****************************************************************/
/* Rand_Gen - This utility produces a random vector file.	*/
/*								*/
/* Command line options:					*/
/*	{file_name} - Output file name.				*/
/*	-n	- Number of samples to produce.			*/
/*	-seed	- Random Seed to use.				*/
/*	-realvec - Produce an indexed real-vector file.		*/
/*								*/
/* Specify values on command line, or be prompted for them.	*/
/*								*/
/* By default, this utility produces a complex vector, one 	*/
/* real-imaginary pair per line.  By using the -realvec option,	*/
/* rand_gen produces an indexed real-vector file, having the	*/
/* integer count of the sample and a real sample on each line.	*/
/* (The realvec version is directly plotted with xgraph.	*/
/*  The default complex version requires the -a option in 	*/
/*  xgraph, for automatic x-axis increment, for plotting.)	*/
/*								*/
/* Example:							*/
/*	rand_gen -n 100 -seed 405690  noise.dat			*/
/*	xgraph -a  noise.dat					*/
/* Or,								*/
/*	sin_gen -n 100 -seed 405690 -realvec  noise.dat		*/
/*	xgraph noise.dat					*/
/*								*/
/* File Types:							*/
/*      In:   (none)						*/
/*      Out:  Complex (default), or Real (option)		*/
/*								*/
/* From:  www.atl.lmco.com/proj/csim/xgraph/numutil 		*/
/*	  chein@atl.lmco.com					*/
/*								*/
/* Copyright (C) 2002 CHein					*/
/* This program is free software; you can redistribute it	*/
/* and/or  modify it under the terms of the GNU General		*/
/* Public License as published by the Free Software		*/
/* Foundation, Version 2 of the GPL.  This program is		*/
/* distributed in the hope that it will be useful, but		*/
/* WITHOUT ANY WARRANTY; without even the implied warranty	*/
/* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	*/
/* See the GNU General Public License for more details.		*/
/* You should have received a copy of the GNU General		*/
/* Public License along with this program; if not, write to	*/
/* the  Free Software Foundation, Inc., 59 Temple Place,	*/
/* Suite 330,  Boston, MA 02111-1307. 				*/
/****************************************************************/

#include <stdio.h>
#include <strings.h>
#include <math.h>


main (argc, argv)
int argc;
char *argv[];
{
 int i, cvec=1, m=0, k, seed=-1;
 FILE *outf;
 double RCONST = (double)1.0 / (double)2147483647.0; /* set up the rand normalizing constant */
 char *fname=0;

 i = 1;
 while (i < argc)
 {
  if (strcmp(argv[i],"-realvec")==0) cvec = 0; else
  if (strcmp(argv[i],"-n")==0)
   {
    i = i + 1;
    if (i==argc) { printf("ERROR rand_gen: Missing number after '-n '\n"); exit(0); }
    if (sscanf(argv[i],"%d",&m)!=1)
     { printf("ERROR rand_gen: Sample count '-n %s' not integer.\n",argv[i]); exit(0); }
   }
  else
  if (strcmp(argv[i],"-seed")==0)
   {
    i = i + 1;  
    if (i==argc) { printf("ERROR rand_gen: Missing frequency after '-freq '\n"); exit(0); }
    if (sscanf(argv[i],"%d",&seed)!=1)
     { printf("ERROR rand_gen: Frequency '-freq %s' not float.\n",argv[i]); exit(0); }
   }
  else
  fname = (char *)strdup(argv[i]);  
  i = i + 1;
 }

 printf("\n------------------------------------------------------\n");
 printf("Rand_Gen - This utility produces a random vector file.\n");
 printf("------------------------------------------------------\n\n");

 if (fname==0)
  {
   printf("What is the output file name ? ");
   fname = (char *)malloc(1000 * sizeof(char *));
   scanf("%s",fname);
  }

 if (m<1)
  {
   printf("What is the number of samples to produce ? ");
   if (scanf("%d",&m)!=1)
     { printf("ERROR rand_gen: Sample count not integer.\n"); exit(0); }
  }

 /* initialize the random generator seed: */
 srandom( seed );  

 outf = fopen(fname,"w");
 if (outf==0)
  { printf("ERROR rand_gen: Cannot open '%s' for writing.\n"); exit(0); }

 printf("Seed = %d\n",seed);
 printf("Nsamples    = %d\n",m);
 if (cvec)
  {
   printf("Producing complex data. (Plot as 'xgraph -a %s')\n", fname);
   fprintf(outf,"! <Type> Complex Vector </Type>\n", m);
  }
 else
  {
   printf("Producing indexed real data. (Plot as 'xgraph %s')\n", fname);
   fprintf(outf,"! <Type> Real Vector </Type>\n", m);
  }
 printf("Output file = %s\n\n", fname); 

 k = 0;
 while (k<m)
  {
   if (cvec)
    fprintf(outf,"%f	%f\n", (double)random() * RCONST, (double)random() * RCONST );
   else
    fprintf(outf,"%d	%f\n", k, (double)random() * RCONST );
   k++;
  }
 fclose(outf);
}
