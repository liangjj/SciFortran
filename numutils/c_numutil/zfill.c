/************************************************************************/
/* Zfill.c -								*/
/* This program appends a real or complex vector with zeros. 		*/
/* 									*/
/* Options:								*/
/*   Use:								*/
/*	-l  length	- Length to make the new vector.		*/
/*   Or,								*/
/*	-nz number	- Number of zeros to add.			*/
/* 									*/
/* Example Usage:							*/
/*	zfill -l 512  oldfile  newfile  			  	*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real or Complex, Vector.					*/
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
 int X, Y, length=-1, nz=-1;
 double x,y;
 complex a, b;
 int i, j, k, arg;
 struct file_kind *infile=0, *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strcmp(argv[arg],"-l")==0)
      {
	arg = arg + 1;
        if (argc==arg) {printf("ERROR zfill: Missing length command-line argument.\n"); exit(1);}
	if (sscanf(argv[arg],"%d", &length)!=1) {printf("ERROR zfill: Bad integer length '%s'\n", argv[arg]); exit(1);}
      }
     else
     if (strcmp(argv[arg],"-nz")==0)
      {
	arg = arg + 1;
        if (argc==arg) {printf("ERROR zfill: Missing number-of-zeroes command-line argument.\n"); exit(1);}
	if (sscanf(argv[arg],"%d", &nz)!=1) {printf("ERROR zfill: Bad integer number-of-zeroes '%s'\n", argv[arg]); exit(1);}
      }
     else {printf("ERROR zfill: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname2)==0) {printf("ERROR zfill: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR zfill: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR zfill: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR zfill: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->dim2>1) {printf("ERROR zfill: Matrix file named, but must be vector only.\n"); exit(1);}
 if (length>0)
  printf("	(Extending length of vector to %d)\n", length);
 else
 if (nz>0)
  printf("	(Extending length of vector by %d)\n", nz);
 else
  {printf("ERROR zfill: No length option specified (-l or -nz).\n"); exit(1);}

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".zfilled");
    if (strcmp(fname1,fname2)==0) {printf("ERROR zfill: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, infile->kind, infile->dim1, infile->dim2 );
 if (outfile->fpt==0) {printf("ERROR zfill: Can't open output file '%s'.\n",fname2); exit(1);}

 i = 1;  k = 0;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     fprintf(outfile->fpt,"%s %s\n", word, line);
     k = k + 1;
    }
   i = i + 1;
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);

 if (length>0)
  if (k<length)
   {
    nz = length-k;
    printf("Appending %d zeros.\n", nz);  
   }
  else { printf("No zeros appended (vector was already %d-long).\n", k); nz = 0; }

 for (j=0; j<nz; j++)
  if (outfile->kind=='R')
   fprintf(outfile->fpt,"%d	0\n", k++);
  else
   fprintf(outfile->fpt,"0	0\n");

 fclose(outfile->fpt);
}
