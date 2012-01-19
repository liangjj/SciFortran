/************************************************************************/
/* Transpose.c -							*/
/*  This program transposes a real matrix, or conjugate transposes a	*/
/*  complex matrix.							*/
/* 									*/
/* Options:								*/
/*	(no options)							*/
/* 									*/
/* Example Usage:							*/
/*	transpose  in_matrixfile.dat  out_transposed_matrixfile.dat  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Complex, Vector or Matrix					*/
/*      Out:  (Same type and dimension as input file.)			*/
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
 int X, Y, row, col;
 double x,y;
 floating *RMat;
 complex a, b, *CMat;
 int i, j, k, arg, scale_in=0;
 struct file_kind *infile=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     {printf("ERROR transpose: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname2)==0) {printf("ERROR transpose: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR transpose: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR transpose: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR transpose: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->dim2 < 2) {printf("ERROR transpose: Input file is not a matrix.\n"); exit(1);}

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".transpose");
    if (strcmp(fname1,fname2)==0) {printf("ERROR transpose: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, infile->kind, infile->dim1, infile->dim2 );
 if (outfile->fpt==0) {printf("ERROR transpose: Can't open output file '%s'.\n",fname2); exit(1);}

 if (infile->kind=='R')
  RMat = (floating *)malloc( infile->dim1 * infile->dim2 * sizeof(floating) );
 else
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
       if (sscanf(word,"%d",&k)!=1) printf("ERROR transpose: Reading index 1 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%d",&k)!=1) printf("ERROR transpose: Reading index 2 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR transpose: Reading real '%s' on line %d.\n",word,i+1);
       RMat[ row * infile->dim2 + col ] = y;
      }
     else
      {
       if (sscanf(word,"%lf",&x)!=1) printf("ERROR transpose: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR transpose: Reading imaginary '%s' on line %d.\n",word,i+1);
       a.r = x;  a.i = y;
       CMat[ row * infile->dim2 + col ] = a;
      }

     col = col + 1;
     if (col >= infile->dim2) { col = 0;  row = row + 1; }
     i = i + 1;
    }
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);

 for (col=0; col < infile->dim2; col++)
  for (row=0; row < infile->dim1; row++)
   if (infile->kind=='R')
     fprintf(outfile->fpt,"%d %d	%e\n", col, row, RMat[ row * infile->dim2 + col ] );
   else
    {
     a = CMat[ row * infile->dim2 + col ];
     if (row!=col) a = CONJG(a);
     fprintf(outfile->fpt,"%e	%e\n", a.r, a.i );
    }

 fclose(outfile->fpt);
}
