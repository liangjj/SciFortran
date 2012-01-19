/************************************************************************/
/* MatXvec -								*/
/*  This program extracts a row or column from a matrix row into a 	*/
/*  vector.								*/
/* 									*/
/* Options:								*/
/*	-row x	- Row to extract.					*/
/*	-col x	- column to extract.					*/
/*  Note: Rows and columns assumed to range 1 to n.			*/
/*	  One (1) is the first row or column.				*/
/*	  The last row or column is n, where n is the number of rows	*/
/*	  or columns, respectively.					*/ 
/* 									*/
/* Example Usage:							*/
/*	matXvec  in_matrixfile.dat  -row 3 out_vector.dat  		*/
/* 								  	*/
/* File Types:								*/
/*      In:   Complex or Real Matrix					*/
/*      Out:  Vector of same data-type as input matrix			*/
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
 int Row=-1, Col=-1, N, rn, cn;
 complex *x;
 complex a, b, *CMat;
 floating *Y, *RMat, v;
 int i, j, k, arg;
 struct file_kind *infile=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strncmp(argv[arg],"-row",2)==0)
      {
	arg = arg + 1;
	if (argc==arg) { printf("ERROR matXvec: Missing row number on command line.\n"); exit(1); }
	if (sscanf(argv[arg],"%d",&Row)!=1) { printf("ERROR matXvec: Bad row number (%s).\n", argv[arg]); exit(1); }
      }
     else
     if (strncmp(argv[arg],"-col",2)==0)
      {
	arg = arg + 1;
	if (argc==arg) { printf("ERROR matXvec: Missing column number on command line.\n"); exit(1); }
	if (sscanf(argv[arg],"%d",&Col)!=1) { printf("ERROR matXvec: Bad column  number (%s).\n", argv[arg]); exit(1); }
      }
     else
     {printf("ERROR matXvec: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname2)==0) {printf("ERROR matXvec: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR matXvec: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR matXvec: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR matXvec: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->dim2 < 2) {printf("ERROR matXvec: Input file is not a matrix.\n"); exit(1);}
 if ((Row<1) && (Col<1)) {printf("ERROR matXvec: No valid row or column specified.\n"); exit(1);}
 if ((Row>0) && (Col>0)) {printf("ERROR matXvec: Both row and column specified.\n"); exit(1);}
 if (Row > infile->dim1) {printf("ERROR matXvec: Row (%d) too large for matrix dimension (%d)\n", Row, infile->dim1); exit(1);}
 if (Col > infile->dim2) {printf("ERROR matXvec: Column (%d) too large for matrix dimension (%d)\n", Col, infile->dim2); exit(1);}

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".vec");
    if (strcmp(fname1,fname2)==0) {printf("ERROR matXvec: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, infile->kind, 0, 0 );
 if (outfile->fpt==0) {printf("ERROR matXvec: Can't open output file '%s'.\n",fname2); exit(1);}

 if (infile->kind=='R')
  RMat = (floating *)malloc( infile->dim1 * infile->dim2 * sizeof(floating) );
 else
  CMat = (complex *)malloc( infile->dim1 * infile->dim2 * sizeof(complex) );

 i = 0;		/* Read input into memory. */
 rn = 0;  cn = 0;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (infile->kind=='R')
      {
       if (sscanf(word,"%d",&k)!=1) printf("ERROR matXvec: Reading index 1 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%d",&k)!=1) printf("ERROR matXvec: Reading index 2 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&v)!=1) printf("ERROR matXvec: Reading real '%s' on line %d.\n",word,i+1);
       RMat[ rn * infile->dim2 + cn ] = v;
      }
     else
      {
       if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR matXvec: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&(a.i))!=1) printf("ERROR matXvec: Reading imaginary '%s' on line %d.\n",word,i+1);
       CMat[ rn * infile->dim2 + cn ] = a;
      }

     cn = cn + 1;
     if (cn >= infile->dim2) { cn = 0;  rn = rn + 1; }
     i = i + 1;
    }
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);

 /* Write out the row or column. */
 if (infile->kind=='R')
  {
   if (Row>0) 
    for (cn=0; cn < infile->dim2; cn++)
     fprintf(outfile->fpt,"%d	%e\n", cn, RMat[ (Row-1) * infile->dim2 + cn ] );
   else
    for (rn=0; rn < infile->dim1; rn++)
     fprintf(outfile->fpt,"%d	%e\n", rn, RMat[ rn * infile->dim2 + Col-1 ] );
  }
 else
  {
   if (Row>0) 
    for (cn=0; cn < infile->dim2; cn++)
     fprintf(outfile->fpt,"%e	%e\n", CMat[ (Row-1) * infile->dim2 + cn ].r, CMat[ (Row-1) * infile->dim2 + cn ].i );
   else
    for (rn=0; rn < infile->dim1; rn++)
     fprintf(outfile->fpt,"%e	%e\n", CMat[ rn * infile->dim2 + Col-1 ].r, CMat[ rn * infile->dim2 + Col-1 ].i );
  }

 fclose(outfile->fpt);
}
