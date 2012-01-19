/************************************************************************/
/* Mat2image.c -							*/
/*  This program converts a matrix to an image file.			*/
/*  Image file is gray-scale intensity image of real matrix values or	*/
/*  magintude of complex matrix values.					*/
/* 									*/
/* Options:								*/
/*   -ascii - Produce ascii ppm image file.				*/
/*   -brightness - Normal=0.0, darker<0.0, brighter>0.0.		*/
/*   -contrast - Normal=1.0, duller<1.0, more contrast>1.0.		*/
/*   -color - Produce color (rainbow/temparature) image.		*/
/* 									*/
/* Example Usage:							*/
/*	mat2image  in_matrixfile.dat  out_image.ppm			*/
/* 								  	*/
/* File Types:								*/
/*      In:   Complex or Real Matrix					*/
/*      Out:  Binary ppm image file.					*/
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
/* GNU General Public License for more details. (gpl.txt)		*/
/* You should have received a copy of the GNU General Public License	*/
/* along with this program; if not, write to the Free Software		*/
/* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307.	*/
/************************************************************************/

#include "commonlibs.c"

/* Produce RGB for temparture scale. */
void color_function( float x, float basis, int *R, int *G, int *B )
{
 float r, b, g, q=1.0/0.45, color;

 x = x / basis;
 if (x < 0.45)
  { r = 0.0;   b = (0.45 - x) * q;   g = x * q; } else
 if (x < 0.9)
  { r = (x - 0.45) * q;   b = 0.0;   g = (0.9 - x) * q; }  else
  { if (x>1.0) x = 1.0;   r = 1.0;   b = (x - 0.9) / 0.1;   g = b; }

 *B = 255.0 * b;
 *G = 255.0 * g;
 *R = 255.0 * r;
}



void putpix( unsigned int m, int asc, int *k, FILE *outfile)
{
 unsigned char ch;
 char twrd[99];

 if (asc) 
  {
   sprintf(twrd, "%d", m);
   *k = *k + strlen(twrd) + 1;
   if (*k>70) {fprintf(outfile,"\n"); *k = 0;}
   fprintf(outfile,"%s ",twrd);
  }
 else
  {
   ch = m;
   fprintf(outfile,"%c", ch);
  }
}


main (argc, argv)
int argc;
char *argv[];
{
 char fname1[999], fname2[999], line[500], word[100], trsh[100];
 int N, rn, cn, m, asc=0;
 complex a, b;
 floating *Y, v, minv=9e9, maxv=-9e9;
 float *RMat, contrast=1.0, bias=0.0;
 int i, j, k, arg, COLOR=0;
 struct file_kind *infile=0;
 FILE *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strncmp(argv[arg],"-ascii",3)==0) asc = 1;
     else
     if (strncmp(argv[arg],"-color",3)==0) COLOR = 1;
     else
     if (strncmp(argv[arg],"-contr",5)==0) 
      {
	arg++;
	if (arg==argc) {printf("ERROR mat2image: Missing contrast value.\n"); exit(1);}
	if (sscanf(argv[arg],"%f",&contrast)!=1)
		{printf("ERROR mat2image: Bad contrast value '%s'.\n",argv[arg]); exit(1);}
      }
     else
     if (strncmp(argv[arg],"-brightness",6)==0) 
      {
	arg++;
	if (arg==argc) {printf("ERROR mat2image: Missing brightness value.\n"); exit(1);}
	if (sscanf(argv[arg],"%f",&bias)!=1)
		{printf("ERROR mat2image: Bad brightness value '%s'.\n",argv[arg]); exit(1);}
      }
     else
     {printf("ERROR mat2image: Unknown command-line option %s\n", argv[arg]); exit(1);}
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
     {printf("ERROR mat2image: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR mat2image: No input file on command line.\n"); exit(1); }
 if (infile->fpt == 0) {printf("ERROR mat2image: Can't open input file '%s'.\n",fname1); exit(1);}
 if (infile->dim2 < 2) {printf("ERROR mat2image: Input file is not a matrix.\n"); exit(1);}

 RMat = (float *)malloc( infile->dim1 * infile->dim2 * sizeof(float) );

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".ppm");
    if (strcmp(fname1,fname2)==0) {printf("ERROR mat2image: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = fopen( fname2, "w");
 if (outfile==0) {printf("ERROR mat2image: Can't open output file '%s'.\n",fname2); exit(1);}

 i = 0;		/* Read input into memory. */
 rn = 0;  cn = 0;
 Read_Line( infile->fpt, line, 500 );
 while (! feof( infile->fpt ))
  {
   Next_Word(line,trsh,word," 	,()");
   if (word[0]!='\0')
    {
     if (infile->kind=='R')
      {
       if (sscanf(word,"%d",&k)!=1) printf("ERROR mat2image: Reading index 1 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%d",&k)!=1) printf("ERROR mat2image: Reading index 2 '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&v)!=1) printf("ERROR mat2image: Reading real '%s' on line %d.\n",word,i+1);
       RMat[ rn * infile->dim2 + cn ] = v;
      }
     else
      {
       if (sscanf(word,"%lf",&(a.r))!=1) printf("ERROR mat2image: Reading real '%s' on line %d.\n",word,i+1);
       Next_Word(line,trsh,word," 	,()");
       if (sscanf(word,"%lf",&(a.i))!=1) printf("ERROR mat2image: Reading imaginary '%s' on line %d.\n",word,i+1);
       v = CMAG(a);
      }

     v = v * contrast + bias;
     RMat[ rn * infile->dim2 + cn ] = v;
     if (v < minv) minv = v;
     if (v > maxv) maxv = v;

     cn = cn + 1;
     if (cn >= infile->dim2) { cn = 0;  rn = rn + 1; }
     i = i + 1;
    }
   Read_Line( infile->fpt, line, 500 );
  }
 fclose(infile->fpt);

 printf("Max=%f, Min=%f\n", maxv, minv);

 /* Write out the image file. */
 if (COLOR)
  { if (asc) fprintf(outfile,"P3\n");  else  fprintf(outfile,"P6\n"); }
 else
  { if (asc) fprintf(outfile,"P2\n");  else  fprintf(outfile,"P5\n"); }
 fprintf(outfile,"# Creator: Num-Utils version 1.1\n");
 fprintf(outfile,"%d %d\n", infile->dim2, infile->dim1 );
 fprintf(outfile,"%d\n", 255);
 k = 0;
 for (rn=0; rn < infile->dim1; rn++)
  for (cn=0; cn < infile->dim2; cn++)
   {
    int n, r, g, b;
    unsigned int m;

    n = 255.0 * (RMat[ rn * infile->dim2 + cn ] - minv) / (maxv - minv);
    n = abs(n);
    if (COLOR==0)
     { 
      m = n;
      putpix( m, asc, &k, outfile);
     }
    else
     { /*color*/
       color_function( (float)n, 255.0, &r, &g, &b );
       m = r;
       putpix( m, asc, &k, outfile);
       m = g;
       putpix( m, asc, &k, outfile);
       m = b;
       putpix( m, asc, &k, outfile);
     } /*color*/
   }
 if (asc) fprintf(outfile,"\n");
 fclose(outfile);
}
