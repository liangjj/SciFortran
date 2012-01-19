/************************************************************************/
/* nums2vec.c - 							*/
/* This program converts a simple list of numbers, such as from Matlab	*/
/* to NumUtils Real Vector format, by adding the header line and an	*/
/* index column.							*/
/* 									*/
/* Options:								*/
/*   Use:								*/
/*	-c  - Make a complex vector instead of a real vector.		*/
/*	-i  - Expect index on each line of file.  ie. x y		*/
/*		(one x-y pair per line)					*/
/* 									*/
/* Example Usage:							*/
/*	nums2vec oldfile  newfile  				  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   (textual list of numbers)					*/
/*      Out:  Real or complex Vector.					*/
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
 int X, Y, csw=0;
 double x,y;
 complex a, b;
 int i, j, k, arg, indx=0;
 struct file_kind *outfile=0;
 FILE *infile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strcmp(argv[arg],"-c")==0)	csw = 1;	else
     if (strcmp(argv[arg],"-i")==0)	indx = 1;
     else {printf("ERROR nums2vec: Unknown command-line option %s\n", argv[arg]); exit(1);}
   } /*option*/
  else
   { /*file_name*/
    if (k==0)  
     { 
      strcpy(fname1,argv[arg]);
      infile = fopen( fname1, "r" );
      if (infile==0)
       {printf("ERROR nums2vec: Cannot open input file '%s'.\n",fname1); exit(1);}
      k = k + 1;
     }
    else
    if (k==1)
     { strcpy(fname2,argv[arg]);  
       if (strcmp(fname1,fname2)==0) {printf("ERROR nums2vec: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR nums2vec: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR nums2vec: No input file on command line.\n"); exit(1); }

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".vec");
    if (strcmp(fname1,fname2)==0) {printf("ERROR nums2vec: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 if (csw)
  outfile = file_open_write( fname2, 'C', 0, 0 );
 else
  outfile = file_open_write( fname2, 'R', 0, 0 );
 if (outfile->fpt==0) {printf("ERROR nums2vec: Can't open output file '%s'.\n",fname2); exit(1);}

 i = 0;
 fscanf(infile, "%lf", &x);
 while (! feof( infile ))
  {
   if (indx) fscanf(infile, "%lf", &x);
   if (csw)
    fprintf(outfile->fpt,"%g	0.0\n", x);
   else
    fprintf(outfile->fpt,"%d 	%g\n", i, x);
   i = i + 1;
   fscanf(infile, "%lf", &x);
  }
 fclose(infile);
 fclose(outfile->fpt);
 printf("Read %d points\n", i);
}
