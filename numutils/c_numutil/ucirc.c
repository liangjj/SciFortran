/************************************************************************/
/* Ucirc.c -								*/
/*  This program draws the unit-circle.					*/
/* 									*/
/* Options:								*/
/*	(no options)							*/
/* 									*/
/* Example Usage:							*/
/*	ucirc  ucirc.dat 	 				  	*/
/*	xgraph ucirc.dat						*/
/* 								  	*/
/* File Types:								*/
/*      In:   (None.)							*/
/*      Out:  (xy plot file.)						*/
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
 char fname1[999];
 int i, j, k, arg;
 struct file_kind *outfile=0;
 double phi, x, y;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     {printf("ERROR ucirc: Unknown command-line option %s\n", argv[arg]); exit(1);}
   } /*option*/
  else
   { /*file_name*/
    if (k==0)  
     { 
      strcpy(fname1,argv[arg]);
      k = k + 1;
     }
    else
     {printf("ERROR ucirc: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) 
  { printf(" ucirc: No output file on command line.  Defaulting to 'ucirc.dat'.\n");
    strcpy(fname1,"ucirc.dat");
  }
 
 printf("	(Writing output to %s)\n", fname1 );
 outfile = file_open_write( fname1, 'C', 0, 0 );
 if (outfile->fpt==0) {printf("ERROR ucirc: Can't open output file '%s'.\n", fname1); exit(1);}


 fprintf(outfile->fpt,"color = blue\n");
 phi = 0.0;
 while (phi<2.0 * 3.15)
  {
   fprintf(outfile->fpt,"%f	%f\n", cos(phi), sin(phi) );
   phi = phi + 0.02 * 3.14;
  }
 fprintf(outfile->fpt,"color = fuchsia\n");
 

 fclose(outfile->fpt);
}
