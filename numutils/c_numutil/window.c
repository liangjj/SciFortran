/************************************************************************/
/* Window.c -								*/
/*  This program produces windowing functions, also called amplitude 	*/
/*  shadings or tapers.	 Used to minimize the effects of 		*/
/*  discontinuities at the ends of sample records.			*/
/*  Defaults to Hamming window, but produces other windows by options.	*/
/* 									*/
/* Options:								*/
/*	-n  x		- Number of points. (Default = 128)		*/
/*	-bartlet 	- Produce bartlet or basic trianglur window.	*/
/*	-triangular	- Produce basic trianglur window.		*/
/*	-hanning	- Produce cosine squared window.		*/
/*	-hamming	- Produce Hamming window (default).		*/
/*				Also called "raised-cosine".		*/
/* 	-blackman	- Produce Blackman window.			*/
/* 									*/
/* Example Usage:							*/
/*	window  window.dat 	 				  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   (None.)							*/
/*      Out:  (Real vector file.)					*/
/*									*/
/* From:  www.atl.lmco.com/proj/csim/xgraph/numutil			*/
/*	  chein@atl.lmco.com						*/
/*									*/
/* Copyright (C) 2002 CHein						*/
/* This program is free software; you can redistribute it and/or modify	*/
/* it under the terms of the GNU General Public License as published by	*/
/* the Free Software Foundation, Version 2 of the GPL.			*/
/* This program is distributed in the hope that it will be useful,	*/
/* but WITHOUT ANY WARRANTY; without even the implied warranty of	*/
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the	*/
/* GNU General Public License for more details.				*/
/* You should have received a copy of the GNU General Public License	*/
/* along with this program; if not, write to the Free Software		*/
/* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307.	*/
/************************************************************************/

#include "commonlibs.c"
 

main (argc, argv)
int argc;
char *argv[];
{
 char fname1[999];
 int i, j, k, arg;
 struct file_kind *outfile=0;
 double x, y;
 int N=128, windowtype=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strcmp(argv[arg],"-n")==0)
      {
	arg = arg + 1;
 	if (arg==argc) { printf("ERROR window: Missing number of points after -n.\n"); exit(1); }
	if (sscanf(argv[arg],"%d",&N)!=1) { printf("ERROR window: Bad integer number of points after -n = '%s'.\n",argv[arg]); exit(1); }
      }
     else
     if (strcmp(argv[arg],"-bartlet")==0) windowtype = 1;
     else
     if (strcmp(argv[arg],"-triangular")==0) windowtype = 1;
     else
     if (strcmp(argv[arg],"-hanning")==0) windowtype = 2;
     else
     if (strcmp(argv[arg],"-hamming")==0) windowtype = 0;
     else
     if (strcmp(argv[arg],"-blackman")==0) windowtype = 3;
     else
     {printf("ERROR window: Unknown command-line option %s\n", argv[arg]); exit(1);}
   } /*option*/
  else
   { /*file_name*/
    if (k==0)  
     { 
      strcpy(fname1,argv[arg]);
      k = k + 1;
     }
    else
     {printf("ERROR window: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) 
  { strcpy(fname1,"window.dat");
    printf(" window: No output file on command line.  Defaulting to '%s'.\n", fname1);
  }
 
 printf("	(Writing output to %s)\n", fname1 );
 outfile = file_open_write( fname1, 'R', 0, 0 );
 if (outfile->fpt==0) {printf("ERROR window: Can't open output file '%s'.\n", fname1); exit(1);}


 x = 0.0;
 for (i=0; i<N; i++)
  {
   switch (windowtype)
    {
     case 0:    y = 0.54 - 0.46 * cos( 2.0 * Pi * (double)i / (double)(N - 1) );		/* Hamming */
		break;
     case 1: 	y = 1.0 - 2.0 * fabs( 0.5 * (double)N - (double)i - 0.5 ) / (double)N;		/* Triangular */
		break;
     case 2:    y = 0.5 * (1.0 - cos( 2.0 * Pi * (double)i / (double)(N - 1) ) );		/* Hanning / Cosine squared */
		break;
     case 3:    y = 0.42 - 0.5 * cos( 2.0 * Pi * (double)i / (double)(N - 1) ) + 0.08 * cos( 4.0 * Pi * (double)i / (double)(N - 1) );
		break;										/* Blackman */
    }

   fprintf(outfile->fpt,"%d	%f\n", i, y);
   x = x + 1.0;
  }
 

 fclose(outfile->fpt);
}
