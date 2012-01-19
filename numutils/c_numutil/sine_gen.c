/****************************************************************/
/* Sine_Gen - This utility produces a sinusoidal vector file.	*/
/*								*/
/* Command line options:					*/
/*	{file_name} - Output file name.				*/
/*	-n	- Number of samples to produce.			*/
/*	-freq	- Frequency, or number of cycles in the 	*/
/*		  produced vector.				*/
/*	-realvec - Produce an indexed real-vector file.		*/
/*								*/
/* Specify values on command line, or be prompted for them.	*/
/*								*/
/* By default, this utility produces a complex vector, one 	*/
/* real-imaginary pair per line.  By using the -realvec option,	*/
/* sine_gen produces an indexed real-vector file, having the	*/
/* integer count of the sample and a real sample on each line.	*/
/* (The realvec version is directly plotted with xgraph.	*/
/*  The default complex version requires the -a option in 	*/
/*  xgraph, for automatic x-axis increment, for plotting.)	*/
/*								*/
/* Example:							*/
/*	sine_gen -n 100 -freq 5  sinewave.dat			*/
/*	xgraph -a  sinewave.dat					*/
/* Or,								*/
/*	sin_gen -n 100 -freq 5 -realvec  sinewave.dat		*/
/*	xgraph sinewave.dat					*/
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
 int i, cvec=1, m=0, k, f_in=0;
 FILE *outf;
 double x, w=-1.0;
 char *fname=0;

 i = 1;
 while (i < argc)
 {
  if (strcmp(argv[i],"-realvec")==0) cvec = 0; else
  if (strcmp(argv[i],"-n")==0)
   {
    i = i + 1;
    if (i==argc) { printf("ERROR sine_gen: Missing number after '-n '\n"); exit(0); }
    if (sscanf(argv[i],"%d",&m)!=1)
     { printf("ERROR sine_gen: Sample count '-n %s' not integer.\n",argv[i]); exit(0); }
   }
  else
  if (strncmp(argv[i],"-freq",2)==0)
   {
    i = i + 1;  f_in = 1;
    if (i==argc) { printf("ERROR sine_gen: Missing frequency after '-freq '\n"); exit(0); }
    if (sscanf(argv[i],"%lf",&w)!=1)
     { printf("ERROR sine_gen: Frequency '-freq %s' not float.\n",argv[i]); exit(0); }
   }
  else
  fname = (char *)strdup(argv[i]);  
  i = i + 1;
 }

 printf("\n----------------------------------------------------------\n");
 printf("Sine_Gen - This utility produces a sinusoidal vector file.\n");
 printf("----------------------------------------------------------\n\n");

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
     { printf("ERROR sine_gen: Sample count not integer.\n"); exit(0); }
  }

 if (!f_in)
  {
   printf("What is the frequency (number of cycles in vector) ? ");
   if (scanf("%lf",&w)!=1)
     { printf("ERROR sine_gen: Sample count not integer.\n"); exit(0); }
  }

 outf = fopen(fname,"w");
 if (outf==0)
  { printf("ERROR sine_gen: Cannot open '%s' for writing.\n"); exit(0); }

 printf("Frequency   = %f\n",w);
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

 w = 2.0 * 3.141592654 * w / (double)m;

 k = 0;  x = 0.0;
 while (k<m)
  {
   x = (double)k * w;
   if (cvec)
    fprintf(outf,"%f	%f\n", cos(x), sin(x) );
   else
    fprintf(outf,"%d	%f\n", k, sin(x) );
   k++;
  }
 fclose(outf);
}
