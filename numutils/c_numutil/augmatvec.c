/************************************************************************/
/* Mataugv -								*/
/*  This program augments a matrix by a vector.  In other words, it 	*/
/*  adds a row or column to a matrix from a vector file.	 	*/
/*  The dimensions of the matrix length or height must match the vector */
/*  length.								*/
/*  									*/
/*  If first input file is a vector, then a new matrix is made.		*/
/*  The -r, -c, option indicates the shape, either 2 rows and N columns	*/
/*  or N ros and 2 columns respectively.				*/
/* 									*/
/* Options:								*/
/*	-r	- Add row to matrix, last row.				*/
/*	-c	- Add column to matrix, last column.			*/
/*	-row x	- Add xth row to matrix.				*/
/*	-col x	- Add xth column to matrix.				*/
/*  Note: Rows and columns assumed to range 1 to n.			*/
/*	  One (1) is the first row or column.				*/
/*	  The last row or column is n, where n is the number of rows	*/
/*	  or columns, respectively.					*/ 
/* 									*/
/* Example Usage:							*/
/*	mataugv  mat.dat vec.dat -row 3 out_mat.dat 	 		*/
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
 char fname1[999], fname2[999]="", fname3[999]="", line[500], word[100], trsh[100];
 int Row=-1, Col=-1;	/* Row/Column number for insertion options. (-1 or >0) */
 int N;			/* Length of added vector. */
 int rn, cn;		/* Dimensions of final matix. */
 int R=0, C=0;		/* Flags for auto-augment options, last row/column. (0/1) */
 int jj, kk, M;
 complex *x;
 complex a, b, *CMat, *CVec;
 floating *Y, *RMat, *RVec, v;
 int i, j, k, arg, h;
 struct file_kind *infile1=0, *infile2=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strcmp(argv[arg],"-r")==0) R = 1;
     else
     if (strcmp(argv[arg],"-c")==0) C = 1;
     else
     if (strcmp(argv[arg],"-row")==0)
      {
	arg = arg + 1;
	if (argc==arg) { printf("ERROR mataugv: Missing row number on command line.\n"); exit(1); }
	if (sscanf(argv[arg],"%d",&Row)!=1) { printf("ERROR mataugv: Bad row number (%s).\n", argv[arg]); exit(1); }
      }
     else
     if (strcmp(argv[arg],"-col")==0)
      {
	arg = arg + 1;
	if (argc==arg) { printf("ERROR mataugv: Missing column number on command line.\n"); exit(1); }
	if (sscanf(argv[arg],"%d",&Col)!=1) { printf("ERROR mataugv: Bad column  number (%s).\n", argv[arg]); exit(1); }
      }
     else
     {printf("ERROR mataugv: Unknown command-line option %s\n", argv[arg]); exit(1);}
   } /*option*/
  else
   { /*file_name*/
    if (k==0)  
     { 
      strcpy(fname1,argv[arg]);
      infile1 = file_open_read( fname1 );
      k = k + 1;
     }
    else
    if (k==1)
     { strcpy(fname2,argv[arg]);  
       infile2 = file_open_read( fname2 );
       k = k + 1; 
     }
    else
    if (k==2)
     { strcpy(fname3,argv[arg]);  
       k = k + 1; 
     }
    else
     {printf("ERROR mataugv: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR mataugv: No input files on command line.\n"); exit(1); }
 if (infile1->fpt == 0) {printf("ERROR mataugv: Can't open input file 1 '%s'.\n",fname1); exit(1);}
 if (infile2->fpt == 0) {printf("ERROR mataugv: Can't open second input file '%s'.\n",fname2); exit(1);}
 if (infile2->dim2 > 1) {printf("ERROR mataugv: Input file 2 '%s' is not a vector.\n",fname1); exit(1);}
 if (infile1->kind != infile2->kind) {printf("ERROR mataugv: Input file '%s' type differs from file '%s'.\n",fname1,fname2); exit(1);}

 if (k<3)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname3,fname1);
    i = strlen(fname3)-1;  while ((i>=0) && (fname3[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname3);
    fname3[i] = '\0';
    strcat(fname3,".mat");
    if ((strcmp(fname1,fname3)==0) || (strcmp(fname2,fname3)==0)) {printf("ERROR mataugv: Can't over-write source.\n"); exit(1);}
  }

 if (infile1->dim2 < 2)	/* If 1st file is vector, Determine vector dimension, N. */
  { /*Convert vector to matrix.*/
   N = 0;
   Read_Line( infile1->fpt, line, 500 );
   while (! feof( infile1->fpt ))
    {
     Next_Word(line,trsh,word," 	,()");
     if (word[0]!='\0') N++;
     Read_Line( infile1->fpt, line, 500 );
    }
   fclose(infile1->fpt);
   infile1 = file_open_read( fname1 );
   if (R) { Row = 2;  rn = 2;  cn = N;  M = N; }
   if (C) { Col = 2;  rn = N;  cn = 2;  M = 1; }
  }
 else
  { /*Regular matrix.*/
   M = infile1->dim2;
   if (R) Row = infile1->dim1 + 1;
   if (C) Col = infile1->dim2 + 1;

   if (Row > infile1->dim1 + 1) {printf("ERROR mataugv: Row (%d) too large for matrix dimension (%d)\n", Row, infile1->dim1); exit(1);}
   if (Col > infile1->dim2 + 1) {printf("ERROR mataugv: Column (%d) too large for matrix dimension (%d)\n", Col, infile1->dim2); exit(1);}

   if (Row>0) rn = infile1->dim1 + 1; else { rn = infile1->dim1;  N = rn; }
   if (Col>0) cn = infile1->dim2 + 1; else { cn = infile1->dim2;  N = cn; }
  }

 if ((Row<0) && (Col<0)) {printf("ERROR mataugv: No valid row or column specified.\n"); exit(1);}
 if ((Row>0) && (Col>0)) {printf("ERROR mataugv: Both row and column specified.\n"); exit(1);}

 if (infile1->kind=='R')
  {
   RMat = (floating *)malloc( rn * cn * sizeof(floating) );
   RVec = (floating *)malloc( N * sizeof(floating) );
  }
 else
  {
   CMat = (complex *)malloc( rn * cn * sizeof(complex) );
   CVec = (complex *)malloc( N * sizeof(complex) );
  }

 printf("	(Writing output to '%s' (%d x %d).)\n", fname3, rn, cn );
 outfile = file_open_write( fname3, infile1->kind, rn, cn );
 if (outfile->fpt==0) {printf("ERROR mataugv: Can't open output file '%s'.\n",fname3); exit(1);}

 i = 0;		/* Read input into memory. */
 j = 0;  k = 0;
 if (j == Row-1) j = j + 1;
 if (k == Col-1) k = k + 1;
 if (infile1->dim2>0)
  { if (k >= infile1->dim2) { k = 0;  j = j + 1; } }
 Read_Line( infile1->fpt, line, 500 );
 while (! feof( infile1->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (infile1->kind=='R')
      {
       if (sscanf(word,"%d",&h)!=1) printf("ERROR mataugv: Reading index 1 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (infile1->dim2>0)
	{
         if (sscanf(word,"%d",&h)!=1) printf("ERROR mataugv: Reading index 2 '%s' on line %d.\n",word,i+1);
         Next_Word(line,trsh,word," 	,()");
	}
       if (sscanf(word,"%lf",&v)!=1) printf("ERROR mataugv: Reading real '%s' on line %d.\n",word,i+1);
       RMat[ j * cn + k ] = v;
      }
     else
      {
       if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR mataugv: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&(a.i))!=1) printf("ERROR mataugv: Reading imaginary '%s' on line %d.\n",word,i+1);
       CMat[ j * cn + k ] = a;
      }

     k = k + 1;
     if (infile1->dim2>0)
      { if (k >= infile1->dim2) { k = 0;  j = j + 1; } }
     else
      { if (k >= M) { k = 0;  j = j + 1; } }
    }
   i = i + 1;
   Read_Line( infile1->fpt, line, 500 );
  }
 fclose(infile1->fpt);

 k = 0; i = 1;
 Read_Line( infile2->fpt, line, 500 );
 while ((! feof( infile2->fpt )) && (k < N))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (infile1->kind=='R')
      {
       if (sscanf(word,"%d",&k)!=1) printf("ERROR mataugv: Reading index 1 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&v)!=1) printf("ERROR mataugv: Reading real '%s' on line %d.\n",word,i+1);
       RVec[ k ] = v;
      }
     else
      {
       if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR mataugv: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&(a.i))!=1) printf("ERROR mataugv: Reading imaginary '%s' on line %d.\n",word,i+1);
       CVec[ k ] = a;
      }

     k = k + 1;
    }
   i = i + 1;
   Read_Line( infile2->fpt, line, 500 );
  }
 fclose(infile2->fpt);

 if (k<N) printf("ERROR mataugv: Insufficient vector entries, %d vs. %d\n", k, N); 

 /* Write out the row or column. */
 jj = 0;
 if (infile1->kind=='R')
  {
    for (j=0; j < outfile->dim1; j++)
     {
      kk = 0;
      for (k=0; k < outfile->dim2; k++)
       {
	if (j == Row-1)
	 fprintf(outfile->fpt,"%d %d	%e\n", j, k, RVec[k] ); else
	if (k == Col-1)
	 fprintf(outfile->fpt,"%d %d	%e\n", j, k, RVec[j] ); 
	else
	 {
	  fprintf(outfile->fpt,"%d %d	%e\n", j, k, RMat[ jj * cn + kk ] );
	  kk++;
	  if (kk>=M) { kk = 0;  jj++; }
	 }
       }
     }
  }
 else
  {
    for (j=0; j < outfile->dim1; j++)
     {
      for (k=0; k < outfile->dim2; k++)
       {
	kk = 0;
	if (j == Row-1)
         fprintf(outfile->fpt,"%e	%e\n", CVec[k].r, CVec[k].i ); else
	if (k == Col-1)
         fprintf(outfile->fpt,"%e	%e\n", CVec[j].r, CVec[j].i ); 
	else
	 {
          fprintf(outfile->fpt,"%e	%e\n", CMat[ jj * cn + kk ].r, CMat[ jj * cn + kk ].i );
	  kk++;
	  if (kk>=M) { kk = 0;  jj++; }
	 }
       }
     }
  }

 fclose(outfile->fpt);
}
