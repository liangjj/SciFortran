/************************************************************************/
/* Sub.c -								*/
/*  This program subtracts the elements of one real or complex vector 	*/
/*  or matrix file from another to produce a third file containg the 	*/
/*  differences.							*/
/* 									*/
/* Options:								*/
/*	(no options)							*/
/* 									*/
/* Example Usage:							*/
/*	sub  fileA  fileB  resultFile				  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real or Complex, dimensionality must match.		*/
/*      Out:  (Same type and dimension as input.)			*/
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
 double x,y, A, B;
 complex a, b, c;
 int i, j, k, m, arg;
 struct file_kind *infileA=0, *infileB=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     {printf("ERROR sub: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname3)==0) {printf("ERROR sub: Can't over-write source.\n"); exit(1);}
       if (strcmp(fname2,fname3)==0) {printf("ERROR sub: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR sub: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k<2) { printf("ERROR sub: Missing input file on command line.\n"); exit(1); }
 if (infileA->fpt == 0) {printf("ERROR sub: Can't open first input file '%s'.\n",fname1); exit(1);}
 if (infileB->fpt == 0) {printf("ERROR sub: Can't open second input file '%s'.\n",fname2); exit(1);}
 if (infileA->kind != infileB->kind) {printf("ERROR sub: Input files have mismatching types.\n"); exit(1);}
 if ((infileA->dim1 != infileB->dim1) || (infileA->dim2 != infileB->dim2))
  {printf("ERROR sub: Input files have mismatching dimensions.\n"); exit(1);}

 if (k<3)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname3,fname1);
    i = strlen(fname3)-1;  while ((i>=0) && (fname3[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname3);
    fname3[i] = '\0';
    strcat(fname3,".new");
    if ((strcmp(fname1,fname3)==0) || (strcmp(fname2,fname3)==0))
	 {printf("ERROR sub: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname3 );
 outfile = file_open_write( fname3, infileA->kind, infileA->dim1, infileA->dim2 );
 if (outfile->fpt==0) {printf("ERROR sub: Can't open output file '%s'.\n",fname3); exit(1);}

 /* Read the files. */
 i = 1; j = 1;  k = 0;
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
       if (sscanf(word,"%d",&k)!=1) printf("ERROR sub: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
       Next_Word(line,trsh,word," 	,()");
       if (infileA->dim2>0)
	{
	 if (sscanf(word,"%d",&m)!=1) printf("ERROR sub: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
	 Next_Word(line,trsh,word," 	,()");
	}
       if (sscanf(word,"%lf",&A)!=1) printf("ERROR sub: Reading value '%s' on line %d of file '%s'.\n",word,i+1,fname1);
      }
     else
      { /* infileA->kind=='C' */
       if (sscanf(word,"%lf",&x)!=1) printf("ERROR sub: Reading real '%s' on line %d of file '%s'.\n",word,i+1,fname1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR sub: Reading imaginary '%s' on line %d of file '%s'.\n",word,i+1,fname1);
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
       if (infileB->dim2>0) Next_Word(line,trsh,word," 	,()");
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&B)!=1) printf("ERROR sub: Reading value '%s' on line %d of file '%s'.\n",word,j+1,fname2);
      }
     else
      { /* infileB->kind=='C' */
       if (sscanf(word,"%lf",&x)!=1) printf("ERROR sub: Reading real '%s' on line %d of file '%s'.\n",word,j+1,fname2);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR sub: Reading imaginary '%s' on line %d of file '%s'.\n",word,j+1,fname2);
       b = COMP( x, y );
      }
    } /*B*/

   /* Write the sum. */
   if ( (!feof( infileA->fpt )) && (!feof( infileB->fpt )) )
    {
     if (infileA->kind=='R')
      {
       if (infileA->dim2<1)
        fprintf(outfile->fpt,"%d	%e\n", k, A + B );
       else
        fprintf(outfile->fpt,"%d	%d, %e\n", k, m, A + B );
      }
     else
     {
      c = CSUB( a, b );
      fprintf(outfile->fpt,"%e	%e\n", c.r, c.i );
     }
    }

  }
 fclose(infileA->fpt);
 fclose(infileB->fpt);
 fclose(outfile->fpt);
}
