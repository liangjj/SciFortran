/************************************************************************/
/* Multpbp.c -								*/
/*  This program multiplies a vector by another vector, point-by-point.	*/
/*  The input files can be real or complex, but must match.		*/
/* 									*/
/* Options:								*/
/*	(no options)							*/
/* 									*/
/* Example Usage:							*/
/*	multpbp  fileA  fileB  File.new				  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real or Complex, dimensions must match.			*/
/*      Out:  (Same type and dimension as input files.)			*/
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
 int i, j, k, K, m, M, arg;
 struct file_kind *infileA=0, *infileB=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     {printf("ERROR multpbp: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname3)==0) {printf("ERROR multpbp: Can't over-write source.\n"); exit(1);}
       if (strcmp(fname2,fname3)==0) {printf("ERROR multpbp: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR multpbp: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k<2) { printf("ERROR multpbp: Missing input file on command line.\n"); exit(1); }
 if (infileA->fpt == 0) {printf("ERROR multpbp: Can't open first input file '%s'.\n",fname1); exit(1);}
 if (infileB->fpt == 0) {printf("ERROR multpbp: Can't open second input file '%s'.\n",fname2); exit(1);}
 if (infileA->kind != infileB->kind) {printf("ERROR multpbp: Input files have mismatching data-types.\n"); exit(1);}
 if ((infileA->dim1 != infileB->dim1) || (infileA->dim2 != infileB->dim2)) {printf("ERROR multpbp: Input files have mismatching dimensions.\n"); exit(1);}

 /* Prepare to open the output file. */
 if (k<3)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname3,fname1);
    i = strlen(fname3)-1;  while ((i>=0) && (fname3[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname3);
    fname3[i] = '\0';
    strcat(fname3,".new");
    if ((strcmp(fname1,fname3)==0) || (strcmp(fname2,fname3)==0))
	 {printf("ERROR multpbp: Can't over-write source.\n"); exit(1);}
  }
 printf("	(Writing output to %s)\n", fname3 );
 outfile = file_open_write( fname3, infileA->kind, infileA->dim1, infileA->dim2 );
 if (outfile->fpt==0) {printf("ERROR multpbp: Can't open output file '%s'.\n",fname3); exit(1);}


 /* --- Read A and B, while multiplying. --- */
 i = 1;  
 do {Read_Line( infileA->fpt, line, 500 ); i++; Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileA->fpt )) );
 while ( !feof( infileA->fpt ) )
  { 
     if (!feof( infileA->fpt ))
      { /*A*/
        if (infileA->kind=='R')
         {
          if (sscanf(word,"%d",&M)!=1) printf("ERROR multpbp: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          Next_Word(line,trsh,word," 	,()");
	  if (infileA->dim2>1)
	   {
	    if (sscanf(word,"%d",&K)!=1) printf("ERROR multpbp: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
	    Next_Word(line,trsh,word," 	,()");
	   }
          if (sscanf(word,"%lf",&A)!=1) printf("ERROR multpbp: Reading value '%s' on line %d of file '%s'.\n",word,i+1,fname1);
         }
        else
         { /* infileA->kind=='C' */
          if (sscanf(word,"%lf",&x)!=1) printf("ERROR multpbp: Reading real '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          Next_Word(line,trsh,word," 	,()");
          if (sscanf(word,"%lf",&y)!=1) printf("ERROR multpbp: Reading imaginary '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          a = COMP( x, y );
         }
      } /*A*/
     else { printf("ERROR multpbp: Premature end of file '%s'.\n",fname1); exit(1); }

     do {Read_Line( infileB->fpt, line, 500 ); i++; Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileB->fpt )) );
     if (!feof( infileB->fpt ))
      { /*A*/
        if (infileA->kind=='R')
         {
          if (sscanf(word,"%d",&X)!=1) printf("ERROR multpbp: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          Next_Word(line,trsh,word," 	,()");
	  if (infileB->dim2>1)
	   {
	    if (sscanf(word,"%d",&Y)!=1) printf("ERROR multpbp: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
	    Next_Word(line,trsh,word," 	,()");
	   }
          if (sscanf(word,"%lf",&B)!=1) printf("ERROR multpbp: Reading value '%s' on line %d of file '%s'.\n",word,i+1,fname1);
         }
        else
         { /* infileA->kind=='C' */
          if (sscanf(word,"%lf",&x)!=1) printf("ERROR multpbp: Reading real '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          Next_Word(line,trsh,word," 	,()");
          if (sscanf(word,"%lf",&y)!=1) printf("ERROR multpbp: Reading imaginary '%s' on line %d of file '%s'.\n",word,i+1,fname1);
          b = COMP( x, y );
         }
      } /*A*/
     else { printf("ERROR multpbp: Premature end of file '%s'.\n",fname1); exit(1); }

     /* Write product. */
     if (infileA->kind=='R')
      {
       if (infileB->dim2<2)
        fprintf(outfile->fpt,"%d	%e\n", M, A * B );
       else
        fprintf(outfile->fpt,"%d %d	%e\n", M, K, A * B );
      }
     else
      {
       c = CMULT( a, b );
       fprintf(outfile->fpt,"%e	%e\n", c.r, c.i );
      }

   do {Read_Line( infileA->fpt, line, 500 ); i++; Next_Word(line,trsh,word," 	,()"); } while ((word[0]=='\0') && (!feof( infileA->fpt )) );
  } 
 fclose(infileA->fpt);
 fclose(outfile->fpt);
}
