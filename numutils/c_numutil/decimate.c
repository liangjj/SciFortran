/************************************************************************/
/* Decimate.c -								*/
/*  This program decimates a real or complex vector by the decimation	*/
/*  amount, k.  It reads one input file (having n items) to produce an	*/
/*  output file containing n/k points.  I.E. It copies each kth sample  */
/*  to the output file.  This is useful for reducing the number of 	*/
/*  points in a vector, usually after low-pass filtering.  		*/
/*  This operation is also called "down-sampling", or "sub-sampling".	*/
/*  Default decimation amount is 2.  I.E. Every other sample (all even  */
/*  samples, starting with sample zero).				*/
/*  Writes the (i mod k) = 0 samples, from samples numbered 0 : n-1.	*/
/* 									*/
/* Options:								*/
/*	-k      = Decimation amount (default=2).			*/
/*	-offset = Offset value ((i mod k) = offset), default=0.		*/
/* 									*/
/* Example Usage:							*/
/*	Decimate  file_in  -k 4  File_out			  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real or Complex.						*/
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
 char fname1[999], fname2[999]="", line[500], word[100], trsh[100];
 int X, Y, decim=2;
 double x,y, A;
 complex a, b, c;
 int i, j, k, m, arg, oset=0;
 struct file_kind *infileA=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strcasecmp(argv[arg],"-k")==0)
      {
	arg++;
	if (arg==argc) { printf("ERROR Decimate: missing decimation amount after -k\n"); exit(0); }
	if (sscanf(argv[arg],"%d", &decim)!=1) 
	 { printf("ERROR Decimate: bad decimate integer %s\n",argv[arg]); exit(0); }
      }
     else
     if (strcasecmp(argv[arg],"-offset")==0)
      {
	arg++;
	if (arg==argc) { printf("ERROR Decimate: missing offset amount after -offset\n"); exit(0); }
	if (sscanf(argv[arg],"%d", &oset)!=1) 
	 { printf("ERROR Decimate: bad offset integer %s\n",argv[arg]); exit(0); }
      }
     else
     {printf("ERROR Decimate: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
     { strcpy(fname2,argv[arg]);  
       if (strcmp(fname1,fname2)==0) {printf("ERROR Decimate: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR Decimate: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k<1) { printf("ERROR Decimate: Missing input file on command line.\n"); exit(1); }
 if (infileA->fpt == 0) {printf("ERROR Decimate: Can't open input file '%s'.\n",fname1); exit(1);}

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".dec");
    if (strcmp(fname1,fname2)==0) 
	 {printf("ERROR Decimate: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, infileA->kind, infileA->dim1, infileA->dim2 );
 if (outfile->fpt==0) {printf("ERROR Decimate: Can't open output file '%s'.\n",fname2); exit(1);}

 /* Read the file. */
 i = 1; j = 0;  k = 0;
 while (!feof( infileA->fpt ))
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
       if (sscanf(word,"%d",&i)!=1) printf("ERROR Decimate: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
       Next_Word(line,trsh,word," 	,()");
       if (infileA->dim2>0)
	{
	 if (sscanf(word,"%d",&m)!=1) printf("ERROR Decimate: Reading index '%s' on line %d of file '%s'.\n",word,i+1,fname1);
	 Next_Word(line,trsh,word," 	,()");
	}
       if (sscanf(word,"%lf",&A)!=1) printf("ERROR Decimate: Reading value '%s' on line %d of file '%s'.\n",word,i+1,fname1);
      }
     else
      { /* infileA->kind=='C' */
       if (sscanf(word,"%lf",&x)!=1) printf("ERROR Decimate: Reading real '%s' on line %d of file '%s'.\n",word,i+1,fname1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR Decimate: Reading imaginary '%s' on line %d of file '%s'.\n",word,i+1,fname1);
       a = COMP( x, y );
      }
    } /*A*/

   if ((j % decim == oset) && (!feof( infileA->fpt )))  /* Write the value. */
    {
     if (infileA->kind=='R')
      {
       if (infileA->dim2<1)
        fprintf(outfile->fpt,"%d	%g\n", k, A );
       else
        fprintf(outfile->fpt,"%d	%d, %g\n", k, m, A );
       k++;
      }
     else
     {
      fprintf(outfile->fpt,"%g	%g\n", x, y );
     }
    }

   j++;
  }
 fclose(infileA->fpt);
 fclose(outfile->fpt);
}
