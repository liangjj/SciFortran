/************************************************************************/
/* Fft.c -								*/
/*  This program reads in a complex list of data smaples, and computes 	*/
/*  the corresponding complex DFT, and prints this out to a file.  	*/
/* 									*/
/* Options:								*/
/*	-f	- Forward FFT						*/
/*	-r	- Reverse or Inverse FFT				*/
/*	-i	- Reverse or Inverse FFT				*/
/*	-d 1	- Forward FFT						*/
/*	-d -1	- Reverse FFT						*/
/* 									*/
/* Example Usage:							*/
/*	fft  infile.dat  outfile.fft				  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Complex or Real						*/
/*      Out:  Complex 							*/
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
 int i, j, k, arg;
 int t, sign=1, N;
 floating *SN, *CN;
 complex *x, *Y;
 char fname1[999], fname2[999]="", line[500], word[100], trsh[100];
 complex a, b;
 struct file_kind *infile=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (argv[arg][1] == 'f')  { sign = 1; }  else
     if (argv[arg][1] == 'r')  { sign = -1; } else
     if (argv[arg][1] == 'i')  { sign = -1; } else
     if (argv[arg][1] == 'd') 
      {
        arg = arg + 1;
        if (argc==arg) {printf("ERROR fft: Insufficient command-line arguments for 'd' option.\n"); exit(1);}
        if (sscanf(argv[arg],"%d", &sign)!=1) {printf("ERROR fft: Bad direction sign %s\n", argv[arg]); exit(1); }
      }
     else
      {printf("ERROR fft: Unknown command-line option %s\n", argv[arg]); exit(1);}
   } /*option*/
  else
   { /*file_name*/
    if (k==0)  
     { 
      strcpy(fname1,argv[arg]);
      infile = file_open_read( fname1 );
      k = k + 1;
     }
    else
    if (k==1)
     { strcpy(fname2,argv[arg]);  
       if (strcmp(fname1,fname2)==0) {printf("ERROR fft: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR fft: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR fft: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR fft: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->dim2 > 1) {printf("ERROR fft: Input file is not Vector but Matrix.\n"); exit(1);}

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".fft");
    if (strcmp(fname1,fname2)==0) {printf("ERROR fft: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, 'C', infile->dim1, 0 );
 if (outfile->fpt==0) {printf("ERROR fft: Can't open output file '%s'.\n",fname2); exit(1);}

 /* First determine dimension of input vector. */
 N = 0;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0') N = N + 1;
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);
 printf("Performing %d-point transform.\n\n", N);
 
 SN = (floating *)malloc( N * sizeof(floating) );
 CN = (floating *)malloc( N * sizeof(floating) );
 x = (complex *)malloc( N * sizeof(complex) );
 Y = (complex *)malloc( N * sizeof(complex) );

 infile = file_open_read( fname1 );
 i = 1;  k = 0;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (infile->kind=='R')
      {
        Next_Word(line,trsh,word," 	,()");
        if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR fft: Reading real '%s' on line %d.\n",word,i+1);
	a.i = 0.0;
      }
     else
      {
       if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR fft: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&(a.i))!=1) printf("ERROR fft: Reading imaginary '%s' on line %d.\n",word,i+1);
      }
     x[k] = a;
     k = k + 1;
    }
   i = i + 1;
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);

 FFT( x, Y, N, sign, SN, CN );

 for (k=0; k<N; k++)
   fprintf(outfile->fpt,"%e	%e\n", Y[k].r, Y[k].i);

 fclose(outfile->fpt);
}
