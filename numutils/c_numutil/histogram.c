/************************************************************************/
/* Histogram.c -							*/
/* This program plots the histogram of a real vector.			*/
/* 									*/
/* Options:								*/
/*	-nbins x   - Number of bins to divide histogram of values into.	*/
/* 									*/
/* Example Usage:							*/
/*	histogram vectorfile  histo.dat				  	*/
/*	xgraph histo.dat						*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real Vector.						*/
/*      Out:  histgram.dat (plot-file)					*/
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
 

/* ------------------------ MAIN ------------------------------ */
main (argc, argv)
int argc;
char *argv[];
{
 char fname1[999], fname2[999]="", line[500], word[100], trsh[100];
 int X, Y, N=0;
 double x,y, sum=0.0, sum2=0.0, min=9e99, max=-9e99;
 int i, j, k, m, arg, *bins, nbins=10, color_wheel=2;
 struct file_kind *infile=0;
 FILE *outfile;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strcmp(argv[arg],"-nbins")==0)
      {
	arg++;
	if ((arg==argc) || (sscanf(argv[arg],"%d",&nbins)!=1))
	 {printf("ERROR histogram: Missing or bad integer after -nbins\n"); exit(1);}
      }
     else
     {printf("ERROR histogram: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
     { 
      strcpy(fname2,argv[arg]);
      k = k + 1;
     }
    else
     {printf("ERROR histogram: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR histogram: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR histogram: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->kind=='C') {printf("ERROR histogram: Complex file named, but must be Real only.\n"); exit(1);}

 /* First count the number of values and determine ranges. */

 i = 1;  
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (infile->dim2>0) Next_Word(line,trsh,word," 	,()");
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (sscanf(word,"%lf", &x)!=1) {printf("ERROR histogram: Bad real value '%s' on line %d of file %s\n", word, i, fname1); exit(1);}
     if (x<min) min = x;
     if (x>max) max = x;
     N = N + 1;
    }
   i = i + 1;
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);

 /* Initialize the "buckets". */
 bins = (int *)malloc( (nbins+1) * sizeof(int) );
 for (i=0; i<=nbins; i++) bins[i] = 0;

 /* Now "bin" the data. */
 infile = file_open_read( fname1 );
 i = 1;  
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (infile->dim2>0) Next_Word(line,trsh,word," 	,()");
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (sscanf(word,"%lf", &x)!=1) {printf("ERROR histogram: Bad real value '%s' on line %d of file %s\n", word, i, fname1); exit(1);}
     m = (float)nbins * (x - min) / (max-min);
     bins[m]++;     
    }
   i = i + 1;
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".histo");
    if (strcmp(fname1,fname2)==0) {printf("ERROR histogram: Can't over-write source.\n"); exit(1);}
  }

 printf("       (Writing output to %s)\n", fname2 );
 outfile = fopen(fname2,"w");
 if (outfile==0) {printf("ERROR histogram: Can't open output file '%s'.\n",fname2); exit(1);}
 fprintf(outfile,"title = Histogram\n");
 fprintf(outfile,"title_x = Values\n");
 fprintf(outfile,"title_y = Number\n");
 fprintf(outfile,"thickness = %f\n", 1.0 + 100.0 / (float)nbins );

 for (k=0; k<=nbins; k++)
  if (bins[k] > 0)
   {
        fprintf(outfile,"color=%d\n",color_wheel++);
        if (color_wheel>15) color_wheel = 2;    /* Rotate color-wheel. */

        fprintf(outfile,"%f     0\n", ((float)k+0.5)*(max-min)/(float)nbins + min );
        fprintf(outfile,"%f     %d\n", ((float)k+0.5)*(max-min)/(float)nbins + min, bins[k]  );
        fprintf(outfile,"next\n");

   }
 fclose(outfile);

 printf("\nTo plot histogram:\n              xgraph %s\n", fname2);

}
