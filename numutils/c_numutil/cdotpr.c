/************************************************************************/
/* Cdotpr.c -								*/
/*  This program computes the complex conjugate dot-product of two 	*/
/*  complex vector files.						*/
/* 									*/
/* Options:								*/
/*	(no options)							*/
/* 									*/
/* Example Usage:							*/
/*	cdotpr fileA  fileB  					  	*/
/*	    Dot Product = 345.7						*/
/* 								  	*/
/* File Types:								*/
/*      In:   Complex, dimensions must match.				*/
/*      Out:  (No out file. Result goes to screen (std.out).)		*/
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
 char fname1[999], fname2[999]="", line[500], word[100], trsh[100];
 int X, Y;
 double x,y, A, B, sum=0.0;
 complex a, b, c, csum;
 int i, j, k, m, arg;
 struct file_kind *infileA=0, *infileB=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     {printf("ERROR cdotpr: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
     {printf("ERROR cdotpr: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k<2) { printf("ERROR cdotpr: Missing input file on command line.\n"); exit(1); }
 if (infileA->fpt == 0) {printf("ERROR cdotpr: Can't open first input file '%s'.\n",fname1); exit(1);}
 if (infileB->fpt == 0) {printf("ERROR cdotpr: Can't open second input file '%s'.\n",fname2); exit(1);}
 if (infileA->kind != infileB->kind) {printf("ERROR cdotpr: Input files have mismatching types.\n"); exit(1);}
 if ((infileA->dim1 != infileB->dim1) || (infileA->dim2 != infileB->dim2))
  {printf("ERROR cdotpr: Input files have mismatching dimensions.\n"); exit(1);}

 /* Read the files. */
 i = 1; j = 1;  k = 0;  csum = COMP(0.0,0.0);
 while ( (!feof( infileA->fpt )) && (!feof( infileB->fpt )) )
  {
   do	/* Get next line from file A. */
    {
     Read_Line( infileA->fpt, line, 500 );  i++;
     Next_Word(line,trsh,word," 	,()");
    }
   while ((word[0]=='\0') && (!feof( infileA->fpt )) );

   if ((word[0]!='\0') && (!feof( infileA->fpt )))
    { /*A*/
     if (infileA->kind=='R')
      {
       if (sscanf(word,"%d",&k)!=1) printf("ERROR cdotpr: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
       Next_Word(line,trsh,word," 	,()");
       if (infileA->dim2>0)
	{
	 if (sscanf(word,"%d",&m)!=1) printf("ERROR cdotpr: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
	 Next_Word(line,trsh,word," 	,()");
	}
       if (sscanf(word,"%lf",&A)!=1) printf("ERROR cdotpr: Reading value '%s' on line %d of file '%s'.\n",word,i+1,fname1);
      }
     else
      { /* infileA->kind=='C' */
       if (sscanf(word,"%lf",&x)!=1) printf("ERROR cdotpr: Reading real '%s' on line %d of file '%s'.\n",word,i+1,fname1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR cdotpr: Reading imaginary '%s' on line %d of file '%s'.\n",word,i+1,fname1);
       a = COMP( x, y );
      }
    } /*A*/

   do	/* Get next line from file B. */
    {
     Read_Line( infileB->fpt, line, 500 );  j++;
     Next_Word(line,trsh,word," 	,()");
    }
   while ((word[0]=='\0') && (!feof( infileB->fpt )) );

   if ((word[0]!='\0') && (!feof( infileB->fpt )))
    { /*B*/
     if (infileB->kind=='R')
      {
       if (infileA->dim2>0) Next_Word(line,trsh,word," 	,()");
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&B)!=1) printf("ERROR cdotpr: Reading value '%s' on line %d of file '%s'.\n",word,j+1,fname2);
      }
     else
      { /* infileB->kind=='C' */
       if (sscanf(word,"%lf",&x)!=1) printf("ERROR cdotpr: Reading real '%s' on line %d of file '%s'.\n",word,j+1,fname2);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR cdotpr: Reading imaginary '%s' on line %d of file '%s'.\n",word,j+1,fname2);
       b = COMP( x, y );
      }
    } /*B*/

   /* Keep the sum. */
   if ( (!feof( infileA->fpt )) && (!feof( infileB->fpt )) )
    {
     if (infileA->kind=='R')
      {
	sum = sum + A * B;
      }
     else
     {
      csum = CMULT_ADD( a, CONJG(b), csum );
     }
    }

  }

 if (infileA->kind=='R')
  {
   if ((fabs(sum)>0.01) && (fabs(sum<1e5)))
    printf("\n Dot Product = %f\n\n", sum);	/* Print answer in nice format. */
   else
    printf("\n Dot Product = %e\n\n", sum);
  }
 else
  printf("\n Dot Product = (%e, %e)\n\n", csum.r, csum.i );

 fclose(infileA->fpt);
 fclose(infileB->fpt);
}
