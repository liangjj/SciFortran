/************************************************************************/
/* Phase.c -								*/
/*  This program converts a complex vector file into a real vector file	*/
/*  containing phase, in degrees, of each term.				*/
/* 									*/
/* Options:								*/
/*  -radians  - Report phase in radians instead of degrees.		*/
/* 									*/
/* Example Usage:							*/
/*	phase  complexfile  newfile  				  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Complex							*/
/*      Out:  Real							*/
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
 int X, Y, radflag=0;
 double x,y;
 complex a, b;
 int i, j, k, arg;
 struct file_kind *infile=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strncmp(argv[arg],"-radians",4)==0) radflag = 1;
     else {printf("ERROR phase: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname2)==0) {printf("ERROR phase: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR phase: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR phase: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR phase: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->kind!='C') {printf("ERROR phase: Input file is not Complex.\n"); exit(1);}

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".phase");
    if (strcmp(fname1,fname2)==0) {printf("ERROR phase: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, 'R', infile->dim1, infile->dim2 );
 if (outfile->fpt==0) {printf("ERROR phase: Can't open output file '%s'.\n",fname2); exit(1);}

 i = 0;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (sscanf(word,"%lf",&x)!=1) printf("ERROR phase: Reading real '%s' on line %d.\n",word,i+1);
     Next_Word(line,trsh,word," 	,()");
     if (sscanf(word,"%lf",&y)!=1) printf("ERROR phase: Reading imaginary '%s' on line %d.\n",word,i+1);

     if (fabs(x) < 1.0e-12)	/* Avoid divide by zero, or overly small value. */
      if (x>0.0) x = 1.0e-12; else x = -1.0e-12;

     y = atan(y/x);
     if (radflag==0) y = (180.0 / Pi) * y;	/* Convert to degrees. */

     fprintf(outfile->fpt,"%d	%e\n", i, y );
     i = i + 1;
    }
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);
 fclose(outfile->fpt);
}
