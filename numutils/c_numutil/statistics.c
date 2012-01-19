/************************************************************************/
/* Statistics.c -							*/
/* This program Computes mean, variance, min, max, and optionally the 	*/
/* median, of a real vector.						*/
/* 									*/
/* Options:								*/
/*	-median  - Find the median (requires sufficient memory).	*/
/* 									*/
/* Example Usage:							*/
/*	statistics  vectorfile  				  	*/
/*  Or,									*/
/*	statistics  -median  vectorfile  			  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real Vector.						*/
/*      Out:  (None. Reports result to std.out (screen).)		*/
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
 
struct sort_list
 {
   floating value;
   struct sort_list *nxt;
 } *vlist=0;


/* Add item to sorted list for median calculation. */
void addvlist(floating x)
{
 struct sort_list *tmppt, *prv=0, *ptr;

 ptr = vlist;	/* Find (sorted) insertion point in list of values. */
 while ((ptr!=0) && (ptr->value < x)) { prv = ptr;  ptr = ptr->nxt; }

 tmppt = (struct sort_list *)malloc(sizeof(struct sort_list));
 if (tmppt==0) { printf("ERROR statistics: Insuffient memory for median computation.\n"); exit(1); }
 tmppt->value = x;	/* Make new item. */

 /* Insert new item in list. */
 if (prv==0)
  { tmppt->nxt = vlist;  vlist = tmppt; }
 else
  { tmppt->nxt = ptr;  prv->nxt = tmppt; }
}


/* ------------------------ MAIN ------------------------------ */
main (argc, argv)
int argc;
char *argv[];
{
 char fname1[999], fname2[999]="", line[500], word[100], trsh[100];
 int X, Y, N=0;
 double x,y, sum=0.0, sum2=0.0, min=9e99, max=-9e99, mean, variance;
 int i, j, k, arg, medianflag=0;
 struct file_kind *infile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strcmp(argv[arg],"-median")==0)
      {
	medianflag = 1;
      }
     else {printf("ERROR statistics: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
     {printf("ERROR statistics: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR statistics: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR statistics: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->kind=='C') {printf("ERROR statistics: Complex file named, but must be Real only.\n"); exit(1);}
 if (infile->dim2>1) {printf("ERROR statistics: Matrix file named, but must be vector only.\n"); exit(1);}

 i = 1;  k = 0;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (sscanf(word,"%lf", &x)!=1) {printf("ERROR statistics: Bad real value '%s' on line %d of file %s\n", word, i, fname1); exit(1);}
     sum = sum + x;
     sum2 = sum2 + x*x;
     if (x<min) min = x;
     if (x>max) max = x;
     N = N + 1;
     if (medianflag) addvlist(x);
    }
   i = i + 1;
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);

 printf("\nStatistics of File: %s\n", fname1);
 mean = sum / (double)N;
 printf("\nMean =	 %f	(%e)\n", mean, mean );
 variance = (sum2 / (double)N) - mean * mean;
 printf("Variance = %f	(%e)\n", variance, variance );
 printf("Minimum = %f	(%e)\n", min, min);
 printf("Maximum = %f	(%e)\n", max, max);
 if (medianflag)
  {
   i = 0;
   while (i<N/2) { vlist = vlist->nxt;  i++; }
   printf("Median = %f	(%e)\n", vlist->value, vlist->value );
  }
}
