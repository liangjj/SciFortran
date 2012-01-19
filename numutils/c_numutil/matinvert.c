/************************************************************************/
/* MatInvert.c -							*/
/*  This program inverts a square matrix file.				*/
/* 									*/
/* Options:								*/
/*   (None.)								*/
/* 									*/
/* Example Usage:							*/
/*	matinvert  in_matrixfile.dat  inverted_out.dat  		*/
/* 								  	*/
/* File Types:								*/
/*      In:   Complex or Real Matrix					*/
/*      Out:  Matrix of same data-type as input matrix			*/
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

/********************************************************************
 * Invert Matrix (by Gauss Jordan technique)
 ********************************************************************/

void INVERT_CMATRIX( complex *R_in, complex *R_out, int size )
{
int ncol, nrow, count, i, j, L, ICOL, IROW;
complex    TEMP, BMAX, *R_inv;
floating   AMAX;

 ncol = 2*size; nrow = size;
 R_inv = (complex *)malloc( ncol * nrow * sizeof(complex) );

 /* Copy Matrix for Inversion */
 for (i=0; i!=size; i++)
  for (j=0; j!=size; j++)
   R_inv[i*ncol+j] = R_in[i*nrow+j];

 /*produce augmented identidy matrix*/
 for (i = 0; i!=nrow; i++)
  for (j = size; j!=ncol; j++)
   if (i==j-size) R_inv[i*ncol+j] = COMP(1.0,0.0); else R_inv[i*ncol+j] = COMP(0.0,0.0);

 for (i = 0; i!=nrow; i++)
  { /*2*/
   BMAX = R_inv[i*ncol];
   AMAX = CMAG( BMAX );   IROW = i;   ICOL = 0;  
   for (L = i; L!=nrow; L++)	/*FIND MAX VALUE*/
    for (j = 0; j!=nrow; j++)
     if (CMAG(R_inv[L*ncol+j]) > AMAX)
      {
       BMAX = R_inv[L*ncol+j];	AMAX = CMAG( BMAX );   
       IROW = L; ICOL = j;
      }

   if (IROW != i) 		/*EXCHANGE ROWS*/ /*ei. PIVOT*/
    for (j = 0; j!=ncol; j++)
     {
      TEMP = R_inv[i*ncol+j];
      R_inv[i*ncol+j] = R_inv[IROW*ncol+j];
      R_inv[IROW*ncol+j] = TEMP;
     }

   if (AMAX==0.0)
    printf("Covariance Matrix is not invertible because it has a zero diagonal element.\n");

   /*NORMALIZE ROW*/
   for (j = 0; j!=ncol; j++) R_inv[i*ncol+j] = CDIV( R_inv[i*ncol+j], BMAX ); 

   /*ELIMINATION*/
   for (L = 0; L!=nrow; L++)
    if (i != L)
     {
      TEMP = R_inv[L*ncol+ICOL];
      if ((TEMP.r!=0.0) || (TEMP.i!=0.0)) 
       for (j = 0; j!=ncol; j++)
	R_inv[L*ncol+j] = CSUB( R_inv[L*ncol+j], CMULT( R_inv[i*ncol+j], TEMP ) );
     }
  } /*2*/

   /*ORDER ROWS PROPERLY*/
   for (L = 0; L!=nrow; L++)
    for (j = 0; j!=nrow; j++)
     if ((R_inv[L*ncol+j].r>=0.9999) && (fabs(R_inv[L*ncol+j].i)<=0.0001))
      for (i = 0; i!=nrow; i++)
       R_out[j*nrow+i] = R_inv[L*ncol+i+nrow];

} /*INVERT_MATRIX*/


 

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
     {printf("ERROR matInvert: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname2)==0) {printf("ERROR matInvert: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR matInvert: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR matInvert: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR matInvert: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->dim2 < 2) {printf("ERROR matInvert: Input file is not a matrix.\n"); exit(1);}
 if (infile->dim2 != infile->dim1) {printf("ERROR matInvert: Non square matrix dimensions (%d, %d)\n", infile->dim1, infile->dim2); exit(1);}

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".inv");
    if (strcmp(fname1,fname2)==0) {printf("ERROR matInvert: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, infile->kind, infile->dim1, infile->dim2 );
 if (outfile->fpt==0) {printf("ERROR matInvert: Can't open output file '%s'.\n",fname2); exit(1);}

 CMat = (complex *)malloc( infile->dim1 * infile->dim2 * sizeof(complex) );
 if (CMat==0) {printf("ERROR matInvert: No memory.\n"); exit(0);}

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
       if (sscanf(word,"%d",&k)!=1) printf("ERROR matInvert: Reading index 1 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%d",&k)!=1) printf("ERROR matInvert: Reading index 2 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&v)!=1) printf("ERROR matInvert: Reading real '%s' on line %d.\n",word,i+1);
       CMat[ rn * infile->dim2 + cn ] = COMP( v, 0.0 );
      }
     else
      {
       if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR matInvert: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&(a.i))!=1) printf("ERROR matInvert: Reading imaginary '%s' on line %d.\n",word,i+1);
       CMat[ rn * infile->dim2 + cn ] = a;
      }

     cn = cn + 1;
     if (cn >= infile->dim2) { cn = 0;  rn = rn + 1; }
     i = i + 1;
    }
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);


 INVERT_CMATRIX( CMat, CMat, infile->dim1 );


 /* Write out the result matrix. */
 if (infile->kind=='R')
  {
    for (rn=0; rn < infile->dim1; rn++)
     for (cn=0; cn < infile->dim2; cn++)
      fprintf(outfile->fpt,"%d %d	%e\n", rn, cn, CMat[ rn * infile->dim2 + cn ] );
  }
 else
  {
    for (rn=0; rn < infile->dim1; rn++)
     for (cn=0; cn < infile->dim2; cn++)
      fprintf(outfile->fpt,"%e	%e\n", CMat[ rn * infile->dim2 + cn ].r, CMat[ rn * infile->dim2 + cn ].i );
  }

 fclose(outfile->fpt);
}
