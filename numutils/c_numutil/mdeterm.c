/************************************************************************/
/* Mdeterm.c -								*/
/*  This program copmutes the determinant of a matrix.			*/
/* 									*/
/* Options:								*/
/*   (None.)								*/
/* 									*/
/* Example Usage:							*/
/*	mdeterm  in_matrixfile.dat  					*/
/* 								  	*/
/* File Types:								*/
/*      In:   Complex or Real Matrix					*/
/*      Out:  (Reports determinant to screen.)				*/
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
/* GNU General Public License for more details. (gpl.txt)		*/
/* You should have received a copy of the GNU General Public License	*/
/* along with this program; if not, write to the Free Software		*/
/* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307.	*/
/************************************************************************/

#include "commonlibs.c"

#ifndef MAXFLOAT
 #include <values.h>
#endif


complex DET_CMATRIX( complex *R_in, int size )
{
int ncol, nrow, count, i, j, L, ICOL, IROW;
complex    TEMP, BMAX, *R_inv, Scale;
floating   AMAX;

 ncol = size; nrow = size;
 R_inv = (complex *)malloc( ncol * nrow * sizeof(complex) );

 /* Copy Matrix for Working */
 for (i=0; i!=size; i++)
  for (j=0; j!=size; j++)
   R_inv[i*ncol+j] = R_in[i*ncol+j];

 Scale = COMP(1.0,0.0);
 for (i = 0; i!=nrow; i++)
  { /*2*/
   BMAX = R_inv[i*ncol];
   AMAX = CMAG( BMAX );   IROW = i;   ICOL = 0;  
   for (L = i; L<nrow; L++)	/*FIND MAX VALUE*/
    for (j = i; j<nrow; j++)
     if (CMAG(R_inv[L*ncol+j]) > AMAX)
      {
       BMAX = R_inv[L*ncol+j];	AMAX = CMAG( BMAX );   
       IROW = L; ICOL = j;
      }

   if (IROW != i) 		/*EXCHANGE ROWS*/ /*ei. PIVOT*/
    {
     for (j = 0; j!=ncol; j++)
      {
       TEMP = R_inv[i*ncol+j];
       R_inv[i*ncol+j] = R_inv[IROW*ncol+j];
       R_inv[IROW*ncol+j] = TEMP;
      }
     Scale = CSMULT( Scale, -1.0 );
    }

   if (AMAX==0.0)  /* So, Determinant must be zero. */
    { Scale = COMP(0.0,0.0); return Scale; }

   /*NORMALIZE ROW*/
   for (j = 0; j!=ncol; j++) R_inv[i*ncol+j] = CDIV( R_inv[i*ncol+j], BMAX ); 
   Scale = CMULT(Scale, BMAX);

   /*ELIMINATION*/
   for (L = i+1; L<nrow; L++)
     {
      TEMP = R_inv[L*ncol+ICOL];
      if ((TEMP.r!=0.0) || (TEMP.i!=0.0)) 
       for (j = 0; j!=ncol; j++)
	R_inv[L*ncol+j] = CSUB( R_inv[L*ncol+j], CMULT( R_inv[i*ncol+j], TEMP ) );
     }
  } /*2*/

 /* Order the rows. */
 for (i=0; i<size-1; i++)
  {
   AMAX = MAXFLOAT;
   for (j=0; j<size; j++) 
    if (CMAG(CSUB(R_inv[j*ncol+i],COMP(1.0,0.0))) < AMAX)
     {
	IROW = j; 
	AMAX = CMAG(CSUB(R_inv[j*ncol+i],COMP(1.0,0.0)));
     }
   if (IROW != i)	/* Swap rows. */
    {
     for (j = 0; j!=ncol; j++)
      {
       TEMP = R_inv[i*ncol+j];
       R_inv[i*ncol+j] = R_inv[IROW*ncol+j];
       R_inv[IROW*ncol+j] = TEMP;
      }
     Scale = CSMULT( Scale, -1.0 );
    }
  }

  free(R_inv);
  return Scale;
} /*RowReduce_MATRIX*/



main (argc, argv)
int argc;
char *argv[];
{
 char fname1[999], line[500], word[100], trsh[100];
 int N, rn, cn, m;
 complex cprod, a, b, *CMat, csum;
 floating *Y, v;
 int i, j, k, arg;
 struct file_kind *infile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     {printf("ERROR mdeterm: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
     {printf("ERROR mdeterm: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR mdeterm: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR mdeterm: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->dim2 < 2) {printf("ERROR mdeterm: Input file is not a matrix.\n"); exit(1);}
 if (infile->dim2 != infile->dim1) {printf("ERROR mdeterm: Non square matrix dimensions (%d, %d)\n", infile->dim1, infile->dim2); exit(1);}

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
       if (sscanf(word,"%d",&k)!=1) printf("ERROR mdeterm: Reading index 1 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%d",&k)!=1) printf("ERROR mdeterm: Reading index 2 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&v)!=1) printf("ERROR mdeterm: Reading real '%s' on line %d.\n",word,i+1);
       CMat[ rn * infile->dim2 + cn ] = COMP(v,0.0);
      }
     else
      {
       if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR mdeterm: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&(a.i))!=1) printf("ERROR mdeterm: Reading imaginary '%s' on line %d.\n",word,i+1);
       CMat[ rn * infile->dim2 + cn ] = a;
      }

     cn = cn + 1;
     if (cn >= infile->dim2) { cn = 0;  rn = rn + 1; }
     i = i + 1;
    }
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);

 /* Calculate matrix determinant. */
 cprod = DET_CMATRIX( CMat, infile->dim1 );

 printf("\nDeterminant = ");
 if (infile->kind=='R') 
  printf("%e\n\n", cprod.r);
 else
  printf("(%e, %e)\n\n", cprod.r, cprod.i);

}
