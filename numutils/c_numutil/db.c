/************************************************************************/
/* DB.c -								*/
/*  This program converts a real vector file from 'linear' to 'dB'.	*/
/*  For example, consider the input file to be voltage magnitudes, then */
/*  the dB are computed by taking the log of the voltage squared.  	*/
/*  (DeciBells are considered a 'power-ratio'.)  I.E. 20 Log10(x).	*/
/* 									*/
/*  A check is made for negative or excessively small input values, and */
/*  these are truncated to -150 dB.					*/
/* 									*/
/* Options:								*/
/*	(no options)							*/
/* 									*/
/* Example Usage:							*/
/*	db  infile  outfile  					  	*/
/* 								  	*/
/* Common Usage:							*/
/*	fft  signals.dat  signals.fft					*/
/*	cmag signals.fft  spectrum.dat					*/
/*	db   spectrum.dat spectrum.db					*/
/*	xgraph spectrum.db						*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real							*/
/*      Out:  Real							*/
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
 
floating LOG10( x )
floating x;
{
 if (x>1.0e-15)  x = 20.0 * log10( x );
 else x = -150.0;
 return x;
}

main (argc, argv)
int argc;
char *argv[];
{
 char fname1[999], fname2[999]="", line[500], word[100], trsh[100];
 int X, Y;
 double x,y;
 complex a, b, scale_factor;
 int i, j, k, arg, scale_in=0;
 struct file_kind *infile=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     {printf("ERROR db: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname2)==0) {printf("ERROR db: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR db: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR db: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR db: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->kind!='R') {printf("ERROR db: Input file is not Real.\n"); exit(1);}

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".db");
    if (strcmp(fname1,fname2)==0) {printf("ERROR db: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, 'R', infile->dim1, infile->dim2 );
 if (outfile->fpt==0) {printf("ERROR db: Can't open output file '%s'.\n",fname2); exit(1);}

 i = 0;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (sscanf(word,"%d",&X)!=1) printf("ERROR db: Reading index '%s' on line %d.\n",word,i+1);
     Next_Word(line,trsh,word," 	,()");
     if (sscanf(word,"%lf",&y)!=1) printf("ERROR db: Reading value '%s' on line %d.\n",word,i+1);
     fprintf(outfile->fpt,"%d	%e\n", i, LOG10(y) );
     i = i + 1;
    }
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);
 fclose(outfile->fpt);
}
