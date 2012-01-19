/************************************************************************/
/* BarChart.c -								*/
/*  This program converts a real vector file into a bar-chart graph for */
/*  viewing with xgraph.						*/
/* 									*/
/* Options:								*/
/* 	-thickness <size>						*/
/* 	 (By default, barchart sets the bar thickness based on the 	*/
/*	  number of points in your file.  This option lets you override */
/*	 the automatic setting.  1.0 is thin, 10-is thicker, etc..)	*/
/*	-title <title>							*/
/*	-xtitle (x_axis_title>						*/
/*	-ytitle (y_axis_title>						*/
/* Note: Quotes are needed around multi-word titles.			*/
/* 									*/
/* Example Usage:							*/
/*	barchart  infile  graphfile				  	*/
/*	xgraph graphfile						*/
/* 								  	*/
/* File Types:								*/
/*      In:   Real							*/
/*      Out:  [graph-format]						*/
/*									*/
/* From:  www.xgraph.org/xgraph/numutil					*/
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
 double x,y, shift=0.0;
 float thickness=-1.0;
 int i, j, k, n, arg;
 char *title, *xtitle, *ytitle;
 struct file_kind *infile=0;
 FILE *outfile=0;

 title = (char *)strdup("Barchart");
 xtitle = (char *)strdup("");
 ytitle = (char *)strdup("");

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strcmp(argv[arg],"-title")==0)
      {
	arg++;
	if (argc==arg) {printf("ERROR: missing title after -title option.\n"); exit(0);}
	title = (char *)strdup(argv[arg]);
      }
     else
     if (strcmp(argv[arg],"-xtitle")==0)
      {
	arg++;
	if (argc==arg) {printf("ERROR: missing title after -xtitle option.\n"); exit(0);}
	xtitle = (char *)strdup(argv[arg]);
      }
     else
     if (strcmp(argv[arg],"-ytitle")==0)
      {
	arg++;
	if (argc==arg) {printf("ERROR: missing title after -ytitle option.\n"); exit(0);}
	ytitle = (char *)strdup(argv[arg]);
      }
     else
     if (strcmp(argv[arg],"-shift")==0)
      {
	arg++;
	if (argc==arg) {printf("ERROR: missing title after -shift option.\n"); exit(0);}
	if (sscanf(argv[arg],"%lf",&shift)!=1) { printf("ERROR: missing shift value (%s).\n",argv[arg]); exit(0);}
      }
     else
     {printf("ERROR barchart: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
       if (strcmp(fname1,fname2)==0) {printf("ERROR barchart: Can't over-write source.\n"); exit(1);}
       k = k + 1; 
     }
    else
     {printf("ERROR barchart: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR barchart: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR barchart: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->kind!='R') {printf("ERROR barchart: Input file is not Real.\n"); exit(1);}

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".barchart");
    if (strcmp(fname1,fname2)==0) {printf("ERROR barchart: Can't over-write source.\n"); exit(1);}
  }

 /* Open the output file. */
 printf("	(Writing output to %s)\n", fname2 );
 outfile = fopen( fname2, "w" );
 if (outfile==0) {printf("ERROR barchart: Can't open output file '%s'.\n",fname2); exit(1);}

 /* Write the graph titles. */
 fprintf(outfile,"title = %s\n", title);
 if (strlen(xtitle)>0) fprintf(outfile,"title_x = %s\n", xtitle);
 if (strlen(ytitle)>0) fprintf(outfile,"title_y = %s\n", ytitle);

 /* First count the number of values in the file to determine the width of bars to make. */
 if (thickness<0.0)
  {
   n = 0;
   Read_Line( infile->fpt, line, 500 );
   while (! feof( infile->fpt ))
    {
     Next_Word(line,trsh,word," 	,()");
     if (word[0]!='\0') n++;
     Read_Line( infile->fpt, line, 500 );
    }
   fclose(infile->fpt);
   infile = file_open_read( fname1 );
   thickness = 150.0 / (n + 1);
  }  

 fprintf(outfile,"thickness = %f\n", thickness);

 i = 0;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (sscanf(word,"%lf",&x)!=1) printf("ERROR barchart: Reading index '%s' on line %d.\n",word,i+1);
     Next_Word(line,trsh,word," 	,()");
     if (sscanf(word,"%lf",&y)!=1) printf("ERROR barchart: Reading real value '%s' on line %d.\n",word,i+1);
     fprintf(outfile,"%f	%g\n", x, shift );
     fprintf(outfile,"%f	%g\n", x, y + shift );
     fprintf(outfile,"next\n");
     i = i + 1;
    }
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);
 fprintf(outfile,"thickness = 1\n");
 fclose(outfile);
}
