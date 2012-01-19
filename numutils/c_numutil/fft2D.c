/************************************************************************/
/* fft2D -								*/
/*  This program performs the 2D FFT on a complex matrix.		*/
/* 									*/
/* Options:								*/
/*	-f	- Forward FFT						*/
/*	-r	- Reverse or Inverse FFT				*/
/*	-i	- Reverse or Inverse FFT				*/
/*	-d 1	- Forward FFT						*/
/*	-d -1	- Reverse FFT						*/
/* 									*/
/* Example Usage:							*/
/*	fft2D  in_matrixfile.dat  out_transformed_matrixfile.dat  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Complex or Real Matrix					*/
/*      Out:  Complex Matrix						*/
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
 char fname1[999], fname2[999]="", line[500], word[100], trsh[100];
 int row, col, sign=1, N;
 floating v, *SN, *CN;
 complex *x, *Y;
 complex a, b, *CMat;
 int i, j, k, arg, scale_in=0;
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
     {printf("ERROR fft2D: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname2)==0) {printf("ERROR fft2D: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR fft2D: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR fft2D: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR fft2D: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->dim2 < 2) {printf("ERROR fft2D: Input file is not a matrix.\n"); exit(1);}

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".fft2D");
    if (strcmp(fname1,fname2)==0) {printf("ERROR fft2D: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, infile->kind, infile->dim1, infile->dim2 );
 if (outfile->fpt==0) {printf("ERROR fft2D: Can't open output file '%s'.\n",fname2); exit(1);}

 CMat = (complex *)malloc( infile->dim1 * infile->dim2 * sizeof(complex) );

 i = 0;		/* Read input into memory. */
 row = 0;  col = 0;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (infile->kind=='R')
      {
       if (sscanf(word,"%d",&k)!=1) printf("ERROR fft2D: Reading index 1 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%d",&k)!=1) printf("ERROR fft2D: Reading index 2 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&v)!=1) printf("ERROR fft2D: Reading real '%s' on line %d.\n",word,i+1);
       CMat[ row * infile->dim2 + col ] = COMP( v, 0.0 );
      }
     else
      {
       if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR fft2D: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&(a.i))!=1) printf("ERROR fft2D: Reading imaginary '%s' on line %d.\n",word,i+1);
       CMat[ row * infile->dim2 + col ] = a;
      }

     col = col + 1;
     if (col >= infile->dim2) { col = 0;  row = row + 1; }
     i = i + 1;
    }
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);

 /* Allocate the working arrays. */
 if (infile->dim1 > infile->dim2)  N = infile->dim1;  else  N = infile->dim2;
 SN = (floating *)malloc( N * sizeof(floating) );
 CN = (floating *)malloc( N * sizeof(floating) );
 x = (complex *)malloc( N * sizeof(complex) );
 Y = (complex *)malloc( N * sizeof(complex) );

 /* Transform the columns. */
 for (col=0; col < infile->dim2; col++)
  {
   for (row=0; row < infile->dim1; row++)
     x[row] = CMat[ row * infile->dim2 + col ];
   FFT( x, Y, infile->dim1, sign, SN, CN );
   for (row=0; row < infile->dim1; row++)
     CMat[ row * infile->dim2 + col ] = Y[row];
  }

 /* Transform the rows. */
 for (row=0; row < infile->dim1; row++)
  FFT( &(CMat[ row * infile->dim2 ]), &(CMat[ row * infile->dim2 ]), infile->dim2, sign, SN, CN );

 for (row=0; row < infile->dim1; row++)
  for (col=0; col < infile->dim2; col++)
    {
     a = CMat[ row * infile->dim2 + col ];
     fprintf(outfile->fpt,"%e	%e\n", a.r, a.i );
    }

 fclose(outfile->fpt);
}
