/************************************************************************/
/* Convolve.c -								*/
/*  This program convolves to complex or real vectors.			*/
/*  (Defaults to frequency domain convolution for efficiency.)		*/
/* 									*/
/* Options:								*/
/*	-t	- Perform Time Domain Convolution. (slower)		*/
/*	-f	- Perform Frequency Domain Convolution.	(default)	*/
/* 									*/
/* Example Usage:							*/
/*	convolve infile1  infile2  outfile  			  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real or Complex Vectors (must match).			*/
/*      Out:  (Same type as input files.)				*/
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
 char fname1[999], fname2[999]="", fname3[999]="", line[500], word[100], trsh[100];
 complex a, *x, *y, *w, A, B;
 floating *SN, *CN;
 int i, j, k, n, m, N, arg, fdomain=1;
 struct file_kind *infileA=0, *infileB=0, *outfile=0;


 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (argv[arg][1] == 'f')  { fdomain = 1; }
     else
     if (argv[arg][1] == 't')  { fdomain = 0; }
     else {printf("ERROR convolve: Unknown command-line option %s\n", argv[arg]); exit(1);}
   } /*option*/
  else
   { /*file_name*/
    if (k==0)  
     { 
      strcpy(fname1,argv[arg]);
      infileA = file_open_read( fname1 );
      k = k + 1;
     }
    else
    if (k==1)  
     { 
      strcpy(fname2,argv[arg]);
      infileB = file_open_read( fname2 );
      k = k + 1;
     }
    else
    if (k==2)
     { strcpy(fname3,argv[arg]);  
       if (strcmp(fname1,fname3)==0) {printf("ERROR convolve: Can't over-write source.\n"); exit(1);}
       if (strcmp(fname2,fname3)==0) {printf("ERROR convolve: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR convolve: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k<2) { printf("ERROR convolve: Missing input file on command line.\n"); exit(1); }
 if (infileA->fpt == 0) {printf("ERROR convolve: Can't open first input file '%s'.\n",fname1); exit(1);}
 if (infileB->fpt == 0) {printf("ERROR convolve: Can't open second input file '%s'.\n",fname2); exit(1);}
 if (infileA->kind != infileB->kind) {printf("ERROR convolve: Input files have mismatching types.\n"); exit(1);}

 if (k<=2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname3,fname1);
    i = strlen(fname3)-1;  while ((i>=0) && (fname3[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname3);
    fname3[i] = '\0';
    strcat(fname3,".conv");
    if ((strcmp(fname1,fname3)==0) || (strcmp(fname2,fname3)==0))
	 {printf("ERROR convolve: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname3 );
 outfile = file_open_write( fname3, infileA->kind, infileA->dim1, infileA->dim2 );
 if (outfile->fpt==0) {printf("ERROR convolve: Can't open output file '%s'.\n",fname3); exit(1);}

 /* Read the files. */

 /* First determine dimension of input vector A. */
 n = 0;
 Read_Line( infileA->fpt, line, 500 );
 while (! feof( infileA->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0') n = n + 1;
   Read_Line( infileA->fpt, line, 500 );
  }
 fclose(infileA->fpt);

 /* Next determine dimension of input vector B. */
 m = 0;
 Read_Line( infileB->fpt, line, 500 );
 while (! feof( infileB->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0') m = m + 1;
   Read_Line( infileB->fpt, line, 500 );
  }
 fclose(infileB->fpt);


 N = m + n - 1;
 printf("	Convolving vectors of length %d x %d to produce %d point vector.\n", n, m, N); 

 SN = (floating *)malloc( N * sizeof(floating) );
 CN = (floating *)malloc( N * sizeof(floating) );
 x = (complex *)malloc( N * sizeof(complex) );
 y = (complex *)malloc( N * sizeof(complex) );
 w = (complex *)malloc( N * sizeof(complex) );


 /* Now read vector A. */
 infileA = file_open_read( fname1 );
 i = 1;  k = 0;
 Read_Line( infileA->fpt, line, 500 );
 while (! feof( infileA->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (infileA->kind=='R')
      {
        Next_Word(line,trsh,word," 	,()");
        if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR convolve: Reading real '%s' on line %d.\n",word,i+1);
	a.i = 0.0;
      }
     else
      {
       if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR convolve: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&(a.i))!=1) printf("ERROR convolve: Reading imaginary '%s' on line %d.\n",word,i+1);
      }
     x[k] = a;
     k = k + 1;
    }
   i = i + 1;
   Read_Line( infileA->fpt, line, 500 );
  }
 fclose(infileA->fpt);


 /* Now read vector B. */
 infileB = file_open_read( fname2 );
 i = 1;  k = 0;
 Read_Line( infileB->fpt, line, 500 );
 while (! feof( infileB->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (infileB->kind=='R')
      {
        Next_Word(line,trsh,word," 	,()");
        if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR convolve: Reading real '%s' on line %d.\n",word,i+1);
	a.i = 0.0;
      }
     else
      {
       if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR convolve: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&(a.i))!=1) printf("ERROR convolve: Reading imaginary '%s' on line %d.\n",word,i+1);
      }
     y[k] = a;
     k = k + 1;
    }
   i = i + 1;
   Read_Line( infileB->fpt, line, 500 );
  }
 fclose(infileB->fpt);


 if (fdomain)
  { /*fdomain*/

    /* Zero fill up to fft size and then transform. */
    for (i=n; i<N; i++)  { x[i].r = 0.0;  x[i].i = 0.0; }
    FFT( x, x, N, 1, SN, CN );

    /* Zero fill up to fft size and then transform. */
    for (i=m; i<N; i++)  { y[i].r = 0.0;  y[i].i = 0.0; }
    FFT( y, y, N, 1, SN, CN );

    for (i=0; i<N; i++)  w[i] = CMULT( x[i], y[i] );

    FFT( w, w, N, -1, SN, CN );

    /* Scale */
    for (i=0; i!=N; i++)  w[i] = CSMULT( w[i], (floating)N );

  } /*fdomain*/
 else
  { /*tdomain*/

    for (i=0; i!=N; i++)
     {
      w[i] = COMP( 0.0, 0.0 );
      for (j=0; j!=m; j++)
       {
        k = i-j;  
        if ((k>=0) && (k<n))
         w[i] = CMULT_ADD( x[k], y[j], w[i] );
       }
     }

  } /*tdomain*/

 if ((infileA->kind=='R') && (infileB->kind=='R'))
  for (k=0; k!=N; k++) 
   fprintf(outfile->fpt,"%d	%e\n", k, w[k].r ); 
 else
  for (k=0; k!=N; k++) 
   fprintf(outfile->fpt,"%e	%e\n", w[k].r, w[k].i); 

 fclose(outfile->fpt);
}
