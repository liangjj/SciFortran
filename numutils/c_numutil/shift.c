/************************************************************************/
/* Shift.c -								*/
/*  This program shifts a real or complex vector or matrix file by a 	*/
/*  real or complex scalar, respectively.  In other words, it ADDs	*/
/*  an "offset" value to each term.					*/
/* 									*/
/* Options:								*/
/*	-s  Shift factor						*/
/*  If input file is real, than shift factor must be real.		*/
/*  If input file is complex, than shift factor must be complex.	*/
/* 	-x  For Real-Vectors only, shift the x-values (index) instead	*/
/*	    of the y-values, which otherwise is the assumed default.	*/
/* 									*/
/* Example Usage:							*/
/*   Shift a real file by real value 4.0.  Send results to new file.	*/
/*	shift  -s 4.0  oldfile  newfile  			  	*/
/* 								  	*/
/*   Shift complex file by (3.8, 2.4).   Send results to new file.	*/
/*	shift  -s 3.8 2.4  oldfile  newfile  			  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real or Complex, Vector or Matrix				*/
/*      Out:  (Same type as input.)					*/
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
 double x,y;
 complex a, b, shift_factor;
 int i, j, k, arg, shift_in=0, shiftx=0;
 struct file_kind *infile=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
      if (strcmp(argv[arg],"-s")==0)
       {
	arg = arg + 1;
        if (argc==arg) {printf("ERROR shift: Missing shift factor command-line argument.\n"); exit(1);}
	if (sscanf(argv[arg],"%lf", &x)!=1) {printf("ERROR shift: Bad real shift-factor '%s'\n", argv[arg]); exit(1);}
	shift_factor.r = x;   shift_factor.i = x;
	shift_in=1;

	if ((argc>arg+1) && (is_number(argv[arg+1])))
	 {
	  arg = arg + 1;
	  if (sscanf(argv[arg],"%lf", &y)!=1) {printf("ERROR shift: Bad imaginary shift-factor '%s'\n", argv[arg]); exit(1);}
	  shift_factor.i = y;
	  shift_in=2;
	 }
      }
     else
      if (strcmp(argv[arg],"-x")==0)
       {
	shiftx = 1;
       }
     else {printf("ERROR shift: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname2)==0) {printf("ERROR shift: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR shift: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR shift: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR shift: Can't open input file '%s'.\n",fname1); exit(1);}
 if (shift_in==0) {printf("ERROR shift: No shift factor on command-line.\n"); exit(1);}
 if ((infile->kind=='R') && (shift_in==2)) {printf("ERROR shift: Complex shift factor but Real file.\n"); exit(1);}
 if ((infile->kind=='C') && (shift_in==1)) {printf("WARNING: Real shift factor but Complex file.\n");}
 if (shift_in==1)
  printf("	(Shifting by %e)\n", shift_factor.r);
 else
  printf("	(Shifting by (%e, %e))\n", shift_factor.r, shift_factor.i );

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".shift");
    if (strcmp(fname1,fname2)==0) {printf("ERROR shift: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, infile->kind, infile->dim1, infile->dim2 );
 if (outfile->fpt==0) {printf("ERROR shift: Can't open output file '%s'.\n",fname2); exit(1);}

 i = 1;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {

     if (infile->kind=='R')
      {
       if (sscanf(word,"%d",&X)!=1) printf("ERROR shift: Reading index '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (infile->dim2>0)
	{
	 if (sscanf(word,"%d",&Y)!=1) printf("ERROR scale: Reading index '%s' on line %d.\n",word,i+1);
	 Next_Word(line,trsh,word," 	,()");
	}
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR shift: Reading value '%s' on line %d.\n",word,i+1);
       if (shiftx)
	X = X + shift_factor.r;
       else
	y = y + shift_factor.r;
       if (infile->dim2<1)
	fprintf(outfile->fpt,"%d	%e\n", X, y);
       else
	fprintf(outfile->fpt,"%d %d	%e\n", X, Y, y);
      }
     else
      { /* infile->kind=='C' */
       if (sscanf(word,"%lf",&x)!=1) printf("ERROR shift: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR shift: Reading imaginary '%s' on line %d.\n",word,i+1);
       a.r = x;  a.i = y;
       b = CADD( a, shift_factor );
       fprintf(outfile->fpt,"%e	%e\n", b.r, b.i );
      }

    }
   i = i + 1;
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);
 fclose(outfile->fpt);
}
