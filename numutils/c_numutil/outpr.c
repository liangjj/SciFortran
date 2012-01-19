/************************************************************************/
/* Outpr.c -								*/
/*  This program multiplies to vectors to produce a matrix by outer	*/
/*  product multiply.  The input files can be real or complex, but 	*/
/*  types must match.							*/
/* 									*/
/* Options:								*/
/*	(no options)							*/
/* 									*/
/* Example Usage:							*/
/*	outpr  VecA  VecB  NewMatrixFile			  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real or Complex, dimensions and types must match.		*/
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
 double x,y, A, B, *MatB;
 complex a, b, c, *CMatB;
 int i, j, k, K, m, M, arg, q, row, col;
 struct file_kind *infileA=0, *infileB=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     {printf("ERROR outpr: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname3)==0) {printf("ERROR outpr: Can't over-write source.\n"); exit(1);}
       if (strcmp(fname2,fname3)==0) {printf("ERROR outpr: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR outpr: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k<2) { printf("ERROR outpr: Missing input file on command line.\n"); exit(1); }
 if (infileA->fpt == 0) {printf("ERROR outpr: Can't open first input file '%s'.\n",fname1); exit(1);}
 if (infileA->dim2>2) {printf("ERROR outpr: First file not vector, '%s'.\n",fname1); exit(1);}
 if (infileB->fpt == 0) {printf("ERROR outpr: Can't open second input file '%s'.\n",fname2); exit(1);}
 if (infileB->dim2>2) {printf("ERROR outpr: Second file not vector, '%s'.\n",fname2); exit(1);}
 if (infileA->kind != infileB->kind) {printf("ERROR outpr: Input files have mismatching data-types.\n"); exit(1);}

 /* Determine first file's dimension. */
 j = 0;
 do
  {
   do { Read_Line( infileA->fpt, line, 500 );  Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileA->fpt )) );
   if ((word[0]!='\0') && (!feof( infileA->fpt ))) j++;
  }
 while (!feof( infileA->fpt ));
 fclose(infileA->fpt);  free(infileA);
 infileA = file_open_read( fname1 );
 infileA->dim1 = j;  infileA->dim2 = 1;  

 /* Determine Second file's dimension. */
 j = 0;
 do
  {
   do { Read_Line( infileB->fpt, line, 500 );  Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileB->fpt )) );
   if ((word[0]!='\0') && (!feof( infileB->fpt ))) j++;
  }
 while (!feof( infileB->fpt ));
 fclose(infileB->fpt);  free(infileB);
 infileB = file_open_read( fname2 );
 infileB->dim1 = j;  infileB->dim2 = 1;  

 if (infileB->kind == 'R')
  {
   MatB = (floating *)malloc(infileB->dim1 * sizeof(floating));
   if (MatB==0) { printf("ERROR outpr: No memory. (R)\n"); exit(1); }
  }
 else
  {
   CMatB = (complex *)malloc(infileB->dim1 * sizeof(complex));
   if (CMatB==0) { printf("ERROR outpr: No memory. (C)\n"); exit(1); }
  }

 /* Read B into memory. */
 i = 0; j = 0;
 do { Read_Line( infileB->fpt, line, 500 );  Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileB->fpt )) );
 while (!feof( infileB->fpt ))
  {
   if (infileB->kind=='R')
    {
      Next_Word(line,trsh,word," 	,()");
      if (sscanf(word,"%lf",&B)!=1) printf("ERROR outpr: Reading value '%s' on line %d of file '%s'.\n",word,j+1,fname2);
      MatB[ i * infileB->dim2 + j ] = B;
    }
   else
    { /* infileB->kind=='C' */
      if (sscanf(word,"%lf",&x)!=1) printf("ERROR outpr: Reading real '%s' on line %d of file '%s'.\n",word,j+1,fname2);
      Next_Word(line,trsh,word," 	,()");
      if (sscanf(word,"%lf",&y)!=1) printf("ERROR outpr: Reading imaginary '%s' on line %d of file '%s'.\n",word,j+1,fname2);
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
	 {printf("ERROR outpr: Can't over-write source.\n"); exit(1);}
  }
 printf("	(Writing output to %s)\n", fname3 );
 outfile = file_open_write( fname3, infileA->kind, infileA->dim1, infileB->dim1 );
 if (outfile->fpt==0) {printf("ERROR outpr: Can't open output file '%s'.\n",fname3); exit(1);}


 /* --- Read A, while multiplying. --- */
 i = 1;  row = 0;
 do {Read_Line( infileA->fpt, line, 500 ); i++; Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileA->fpt )) );
 while ( !feof( infileA->fpt ) )
  { /*row*/

         if (infileA->kind=='R')
         {
          if (sscanf(word,"%d",&M)!=1) printf("ERROR outpr: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
 	  Next_Word(line,trsh,word," 	,()");
          if (sscanf(word,"%lf",&A)!=1) printf("ERROR outpr: Reading value '%s' on line %d of file '%s'.\n",word,i+1,fname1);
         }
        else
         { /* infileA->kind=='C' */
          if (sscanf(word,"%lf",&x)!=1) printf("ERROR outpr: Reading real '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          Next_Word(line,trsh,word," 	,()");
          if (sscanf(word,"%lf",&y)!=1) printf("ERROR outpr: Reading imaginary '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          a = COMP( x, y );
         }

     /* Write the product. */
     for (col=0; col<infileB->dim1; col++)
      if (infileA->kind=='R')
        fprintf(outfile->fpt,"%d %d	%e\n", row, col, A * MatB[ col ] );
      else
       {
	c = CMULT( a, CMatB[ col ] );
        fprintf(outfile->fpt,"%e	%e\n", c.r, c.i );
       }

    do {Read_Line( infileA->fpt, line, 500 ); i++; Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileA->fpt )) );
    row = row + 1;
  } /*row*/
 fclose(infileA->fpt);
 fclose(outfile->fpt);
}
