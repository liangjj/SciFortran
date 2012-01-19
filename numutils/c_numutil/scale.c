/************************************************************************/
/* Scale.c -								*/
/*  This program scales a real or complex vector or matrix file by a 	*/
/*  real or complex scalar, respectively.				*/
/* 									*/
/* Options:								*/
/*	-s  Scale factor						*/
/*  If input file is real, than scale factor must be real.		*/
/*  If input file is complex, than scale factor must be complex.	*/
/* 	-x  For Real-Vectors only, scale the x-values (index) instead	*/
/*	    of the y-values, which otherwise is the assumed default.	*/
/* 									*/
/* Example Usage:							*/
/*   Scale a real file by real value 4.0.  Send results to new file.	*/
/*	scale  -s 4.0  oldfile  newfile  			  	*/
/* 								  	*/
/*   Scale complex file by (3.8, 2.4).   Send results to new file.	*/
/*	scale  -s 3.8 2.4  oldfile  newfile  			  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real or Complex, Vector or Matrix.			*/
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
 complex a, b, scale_factor;
 int i, j, k, arg, scale_in=0, scalex=0;
 struct file_kind *infile=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
      if (strcmp(argv[arg],"-s")==0)
       {
	arg = arg + 1;
        if (argc==arg) {printf("ERROR scale: Missing scale factor command-line argument.\n"); exit(1);}
	if (sscanf(argv[arg],"%lf", &x)!=1) {printf("ERROR scale: Bad real scale-factor '%s'\n", argv[arg]); exit(1);}
	scale_factor.r = x;   scale_factor.i = 0.0;
	scale_in=1;

	if ((argc>arg+1) && (is_number(argv[arg+1])))
	 {
	  arg = arg + 1;
	  if (sscanf(argv[arg],"%lf", &y)!=1) {printf("ERROR scale: Bad imaginary scale-factor '%s'\n", argv[arg]); exit(1);}
	  scale_factor.i = y;
	  scale_in=2;
	 }
      }
     else
      if (strcmp(argv[arg],"-x")==0)
       {
	scalex = 1;
       }
     else {printf("ERROR scale: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname2)==0) {printf("ERROR scale: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR scale: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR scale: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR scale: Can't open input file '%s'.\n",fname1); exit(1);}
 if (scale_in==0) {printf("ERROR scale: No scale factor on command-line.\n"); exit(1);}
 if ((infile->kind=='R') && (scale_in==2)) {printf("ERROR scale: Complex scale factor but Real file.\n"); exit(1);}
 if ((infile->kind=='C') && (scale_in==1)) {printf("WARNING: Real scale factor but Complex file.\n");}
 if (scale_in==1)
  printf("	(Scaling by %e)\n", scale_factor.r);
 else
  printf("	(Scaling by (%e, %e))\n", scale_factor.r, scale_factor.i );

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".scaled");
    if (strcmp(fname1,fname2)==0) {printf("ERROR scale: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, infile->kind, infile->dim1, infile->dim2 );
 if (outfile->fpt==0) {printf("ERROR scale: Can't open output file '%s'.\n",fname2); exit(1);}

 i = 1;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {

     if (infile->kind=='R')
      {
       if (sscanf(word,"%lf",&x)!=1) printf("ERROR scale: Reading index '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (infile->dim2>0)
	{
	 if (sscanf(word,"%d",&Y)!=1) printf("ERROR scale: Reading index '%s' on line %d.\n",word,i+1);
	 Next_Word(line,trsh,word," 	,()");
	}
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR scale: Reading value '%s' on line %d.\n",word,i+1);
       if (scalex)
 	x = x * scale_factor.r;
       else
        y = y * scale_factor.r;
       if (infile->dim2<1)
	fprintf(outfile->fpt,"%g	%g\n", x, y);
       else
	fprintf(outfile->fpt,"%d %d	%g\n", X, Y, y);
      }
     else
      { /* infile->kind=='C' */
       if (sscanf(word,"%lf",&x)!=1) printf("ERROR scale: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&y)!=1) printf("ERROR scale: Reading imaginary '%s' on line %d.\n",word,i+1);
       a.r = x;  a.i = y;
       b = CMULT( a, scale_factor );
       fprintf(outfile->fpt,"%g	%g\n", b.r, b.i );
      }

    }
   i = i + 1;
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);
 fclose(outfile->fpt);
}
