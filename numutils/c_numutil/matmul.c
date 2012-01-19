/************************************************************************/
/* Matmul.c -								*/
/*  This program multiplies a matrix by a another matrix or vector to	*/
/*  produce a new matrix file.  The input files can be real or complex,	*/
/*  but must match.							*/
/* 									*/
/* Options:								*/
/*	(no options)							*/
/* 									*/
/* Example Usage:							*/
/*	matmul  matrixfileA  fileB  NewMatrixFile		  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real or Complex, dimensions must comply.			*/
/*      Out:  (Same type and dimension as first input.)			*/
/*									*/
/* From:  www.atl.lmco.com/proj/csim/xgraph/numutil                     */
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
 int X, Y;
 double x,y, A, B, sum, *MatA, *MatB;
 complex a, b, csum, *CMatA, *CMatB;
 int i, j, k, K, m, M, arg, q, row, col;
 struct file_kind *infileA=0, *infileB=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     {printf("ERROR matmul: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname3)==0) {printf("ERROR matmul: Can't over-write source.\n"); exit(1);}
       if (strcmp(fname2,fname3)==0) {printf("ERROR matmul: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR matmul: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k<2) { printf("ERROR matmul: Missing input file on command line.\n"); exit(1); }
 if (infileA->fpt == 0) {printf("ERROR matmul: Can't open first input file '%s'.\n",fname1); exit(1);}
 if (infileA->dim2<1) {printf("ERROR matmul: First file not matrix, '%s'.\n",fname1); exit(1);}
 if (infileB->fpt == 0) {printf("ERROR matmul: Can't open second input file '%s'.\n",fname2); exit(1);}
 if (infileA->kind != infileB->kind) {printf("ERROR matmul: Input files have mismatching data-types.\n"); exit(1);}

 if (infileB->dim2<2)	/* If second file is a vector, then determine it's dimension. */
  {
   j = 0;
   do
    {
     do { Read_Line( infileB->fpt, line, 500 );  Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileB->fpt )) );
     if ((word[0]!='\0') && (!feof( infileB->fpt ))) j++;
    }
   while (!feof( infileB->fpt ));
   fclose(infileB->fpt);  
   infileB = file_open_read( fname2 );
   infileB->dim1 = j;  infileB->dim2 = 1;  
  }
 if (infileA->dim2 != infileB->dim1)
  {printf("ERROR matmul: Input files have mismatching dimensions (%dx%d)*(%dx%d).\n",infileA->dim1,infileA->dim2,infileB->dim1,infileB->dim2); exit(1);}

 if (infileB->kind == 'R')
  {
   MatA = (floating *)malloc(infileA->dim2 * sizeof(floating));
   MatB = (floating *)malloc(infileB->dim1 * infileB->dim2 * sizeof(floating));
   if (MatB==0) { printf("ERROR matmul: No memory.\n"); exit(1); }
  }
 else
  {
   CMatA = (complex *)malloc(infileB->dim2 * sizeof(complex));
   CMatB = (complex *)malloc(infileB->dim1 * infileB->dim2 * sizeof(complex));
   if (CMatB==0) { printf("ERROR matmul: No memory.\n"); exit(1); }
  }

 /* Read B into memory. */
 i = 0; j = 0;
 do { Read_Line( infileB->fpt, line, 500 );  Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileB->fpt )) );
 while (!feof( infileB->fpt ))
  {
   if (infileB->kind=='R')
    {
      if (infileB->dim2>1) Next_Word(line,trsh,word," 	,()");
      Next_Word(line,trsh,word," 	,()");
      if (sscanf(word,"%lf",&B)!=1) printf("ERROR matmul: Reading value '%s' on line %d of file '%s'.\n",word,j+1,fname2);
      MatB[ i * infileB->dim2 + j ] = B;
    }
   else
    { /* infileB->kind=='C' */
      if (sscanf(word,"%lf",&x)!=1) printf("ERROR matmul: Reading real '%s' on line %d of file '%s'.\n",word,j+1,fname2);
      Next_Word(line,trsh,word," 	,()");
      if (sscanf(word,"%lf",&y)!=1) printf("ERROR matmul: Reading imaginary '%s' on line %d of file '%s'.\n",word,j+1,fname2);
      CMatB[ i * infileB->dim2 + j ] = COMP( x, y );
    }
   j = j + 1;
   if (j==infileB->dim2) { i = i + 1;  j = 0; }
   do { Read_Line( infileB->fpt, line, 500 );  Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileB->fpt )) );
  }
 fclose(infileB->fpt);


 /* Prepare to open the output file. */
 if (k<3)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname3,fname1);
    i = strlen(fname3)-1;  while ((i>=0) && (fname3[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname3);
    fname3[i] = '\0';
    strcat(fname3,".new");
    if ((strcmp(fname1,fname3)==0) || (strcmp(fname2,fname3)==0))
	 {printf("ERROR matmul: Can't over-write source.\n"); exit(1);}
  }
 printf("	(Writing output to %s)\n", fname3 );
 outfile = file_open_write( fname3, infileA->kind, infileA->dim1, infileB->dim2 );
 if (outfile->fpt==0) {printf("ERROR matmul: Can't open output file '%s'.\n",fname3); exit(1);}


 /* --- Read A, while multiplying. --- */
 i = 1;  row = 0;
 while ( row < infileA->dim1 )
  { /*row*/

   /* Read next row of A into memory. */
   for (j=0; j<infileA->dim2; j++)
    { /*j*/
     do {Read_Line( infileA->fpt, line, 500 ); i++; Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileA->fpt )) );
     if (!feof( infileA->fpt ))
      { /*A*/
        if (infileA->kind=='R')
         {
          if (sscanf(word,"%d",&M)!=1) printf("ERROR matmul: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          Next_Word(line,trsh,word," 	,()");
	  if (sscanf(word,"%d",&K)!=1) printf("ERROR matmul: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
	  Next_Word(line,trsh,word," 	,()");
          if (sscanf(word,"%lf",&A)!=1) printf("ERROR matmul: Reading value '%s' on line %d of file '%s'.\n",word,i+1,fname1);
	  MatA[j] = A;
         }
        else
         { /* infileA->kind=='C' */
          if (sscanf(word,"%lf",&x)!=1) printf("ERROR matmul: Reading real '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          Next_Word(line,trsh,word," 	,()");
          if (sscanf(word,"%lf",&y)!=1) printf("ERROR matmul: Reading imaginary '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          CMatA[j] = COMP( x, y );
         }
      } /*A*/
     else { printf("ERROR matmul: Premature end of file '%s'.\n",fname1); exit(1); }
    } /*j*/

   for (col=0; col < infileB->dim2; col++)
    { /*col*/
     sum = 0.0;  csum = COMP(0.0,0.0);
     for (j=0; j < infileB->dim1; j++)
      {
       if (infileA->kind=='R')
        sum = sum + MatA[j] * MatB[ j * infileB->dim2 + col ];
       else
        csum = CMULT_ADD( CMatA[j], CMatB[ j * infileB->dim2 + col ], csum );
      }

     /* Write the sum. */
     if (infileA->kind=='R')
      {
       if (infileB->dim2==1)
        fprintf(outfile->fpt,"%d	%e\n", row, sum );
       else
        fprintf(outfile->fpt,"%d %d	%e\n", row, col, sum );
      }
     else
      fprintf(outfile->fpt,"%e	%e\n", csum.r, csum.i );
    } /*col*/

    row = row + 1;
  } /*row*/
 fclose(infileA->fpt);
 fclose(outfile->fpt);
}
