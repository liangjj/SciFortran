/************************************************************************/
/* Image2matix.c -							*/
/*  This program converts an image file to a NumUtils matrix file.	*/
/*  By default, the image's intensity values become the matrix values.	*/
/*  The output values span 0.0 to 1.0.  Maximum intensity (brightest)   */
/*  equals 1.0.  Mimumum intensity (darkest) equals 0.			*/
/*  Options enable selecting conversion for either red, blue, or green  */
/*  (rgb) component colors to matrix values.				*/
/* 									*/
/* Options:								*/
/*  -red - Select the red-component of the image to matrix.		*/
/*  -blue - Select the blue-component of the image to matrix.		*/
/*  -green - Select the green-component of the image to matrix.		*/
/* 									*/
/* Example Usage:							*/
/*	image2matrix  in_imagefile.ppm  out_matrix.dat			*/
/* 								  	*/
/* File Types:								*/
/*      In:   PPM image file.						*/
/*      Out:  Real Matrix file.						*/
/*									*/
/* From:  www.atl.lmco.com/proj/csim/xgraph/numutil			*/
/*	  chein@atl.lmco.com						*/
/*									*/
/* Copyright (C) 2002 Mike Perry					*/
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

/*......................................................*/
/* Data structures to hold images.          		*/
/*......................................................*/
struct rs_image_rec
 { int r, g, b; };

struct rs_image
 {
  int cols, rows, maxval;
  struct rs_image_rec *image;
 } *Image;



struct rs_image *Read_ppm_image( char *fname )
{
 FILE *infile;
 char ch, ft;
 int row, col, ncols, nrows, r, g, b;
 struct rs_image *image;
 int maxval;

 infile = fopen(fname,"r");
 if (infile==0) { printf("ERROR image2matrix: Cannot open image file %s\n",fname); exit(0);}

 if (getc(infile)!='P') {printf("ERROR image2matrix: Input file '%s' is not in PPM format.\n",fname);  exit(0);}
 ft = getc(infile);
 if ((ft=='2') || (ft=='3') || (ft=='5') || (ft=='6'))
  {
    while( (ch = getc(infile)) && isspace(ch) ); /* chew whitespace */
    while( ch == '#' ) 
     {
      while( getc(infile) != '\n' );  /* eat comment line. */
      ch = getc(infile);
     }
    ungetc( ch, infile );
    fscanf( infile, "%d", &ncols ); /* number of cols */

    while( (ch = getc(infile)) && isspace(ch) ); /* chew whitespace */
    while( ch == '#' )
     {
      while( getc(infile) != '\n' );  /* eat comment line. */
      ch = getc(infile);
     }
    ungetc( ch, infile );
    fscanf( infile, "%d", &nrows ); /* number of rows */

    while( (ch = getc(infile)) && isspace(ch) ); /* chew whitespace */
    while( ch == '#' )
     {
      while( getc(infile) != '\n' );  /* eat comment line. */
      ch = getc(infile);
     }
    ungetc( ch, infile );
    fscanf( infile, "%d", &maxval ); /* maximum value of a value */

    while (getc(infile)!='\n');
#if (0)
    while( (ch = getc(infile)) && isspace(ch) ); /* chew whitespace */
    while( ch == '#' )
     {
      while( getc(infile) != '\n' );  /* eat comment line. */
      ch = getc(infile);
     }
    ungetc( ch, infile );
#endif

    /* get data */
    image = (struct rs_image *)malloc( sizeof(struct rs_image) );
    image->image = (struct rs_image_rec *)malloc( (nrows * ncols) * sizeof(struct rs_image_rec) );
    image->cols = ncols;   image->rows = nrows;  image->maxval = maxval;
    /* image->rendered_image = 0;
       image->rendered_cols = 0;  image->rendered_rows = 0; */

    if ( ft == '2' ) 
     { /* ascii b&w */
      for (row=0; row!=nrows; row++)
        for (col=0; col!=ncols; col++)
	{
	 fscanf(infile,"%d",&r);    
	 image->image[row*ncols+col].r = r;
	 image->image[row*ncols+col].b = r;
	 image->image[row*ncols+col].g = r;
	}
     }
    else
    if( ft == '3' ) 
     { /* ascii color */
      for (row=0; row!=nrows; row++)
        for (col=0; col!=ncols; col++)
	{
	 fscanf(infile,"%d",&r);    fscanf(infile,"%d",&g);	fscanf(infile,"%d",&b);
	 image->image[row*ncols+col].r = r;
	 image->image[row*ncols+col].b = b;
	 image->image[row*ncols+col].g = g;
	}
     }
    else
    if( ft == '5' ) 
     { /* binary */
      for (row=0; row!=nrows; row++)
        for (col=0; col!=ncols; col++)
	{
	 unsigned char rc, gc, bc;

	 fread( &rc, 1, 1, infile );  r = rc;
	 image->image[row*ncols+col].r = r;
	 image->image[row*ncols+col].b = r;
	 image->image[row*ncols+col].g = r;
	}
     }
    else
    if( ft == '6' ) 
     { /* binary */
      for (row=0; row!=nrows; row++)
        for (col=0; col!=ncols; col++)
	{
	 unsigned char rc, gc, bc;

	 fread( &rc, 1, 1, infile );  r = rc;
	 fread( &gc, 1, 1, infile );  g = gc;
	 fread( &bc, 1, 1, infile );  b = bc;
	 image->image[row*ncols+col].r = r;
	 image->image[row*ncols+col].b = b;
	 image->image[row*ncols+col].g = g;
	}
     }
   return image;
  }
 else {printf("ERROR image2matrix: Not prepared to handle file type %c.\n",ft); exit(0);}
}




main (argc, argv)
int argc;
char *argv[];
{
 char fname1[999], fname2[999], line[500], word[100], trsh[100];
 int N, rn, cn, m, asc=0;
 complex a, b;
 floating *Y, v, minv=9e9, maxv=-9e9;
 float *RMat, contrast=1.0, bias=0.0, value;
 int i, j, k, arg, COLOR=0;
 struct rs_image_rec imel;
 struct file_kind *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     if (strncmp(argv[arg],"-red",2)==0) COLOR = 1;
     else
     if (strncmp(argv[arg],"-blue",2)==0) COLOR = 2;
     else
     if (strncmp(argv[arg],"-green",2)==0) COLOR = 3;
     else
     {printf("ERROR image2matrix: Unknown command-line option %s\n", argv[arg]); exit(1);}
   } /*option*/
  else
   { /*file_name*/
    if (k==0)  
     { 
      strcpy(fname1,argv[arg]);
      Image = Read_ppm_image( fname1 );
      k = k + 1;
     }
    else
    if (k==1)  
     { 
      strcpy(fname2,argv[arg]);
      k = k + 1;
     }
    else
     {printf("ERROR image2matrix: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 if (k==0) { printf("ERROR image2matrix: No input file on command line.\n"); exit(1); }

 RMat = (float *)malloc( Image->rows * Image->cols * sizeof(float) );

 if (k<2)  /* No output file specified, so make default name by appending suffix. */
  { 
    strcpy(fname2,fname1);
    i = strlen(fname2)-1;  while ((i>=0) && (fname2[i]!='.')) i = i-1;
    if (i<0) i = strlen(fname2);
    fname2[i] = '\0';
    strcat(fname2,".dat");
    if (strcmp(fname1,fname2)==0) {printf("ERROR image2matrix: Can't over-write source.\n"); exit(1);}
  }

 printf("	(Writing output to %s)\n", fname2 );
 outfile = file_open_write( fname2, 'R', Image->rows, Image->cols );
 if (outfile->fpt==0) {printf("ERROR image2matrix: Can't open output file '%s'.\n",fname2); exit(1);}

 /* Write image-matirx to file. */
 for (i=0; i<Image->rows; i++)
  for (j=0; j<Image->cols; j++)
   {
    imel = Image->image[ i * Image->cols + j ];
    switch (COLOR)
     {
      case 0:  value = (float)(imel.r + imel.g + imel.b) / (3.0 * (float)(Image->maxval)); break;
      case 1:  value = (float)imel.r / (float)(Image->maxval); break;
      case 2:  value = (float)imel.b / (float)(Image->maxval); break;
      case 3:  value = (float)imel.g / (float)(Image->maxval); break;
     }
    fprintf(outfile->fpt,"%d %d %g\n", i, j, value );
   }

 fclose(outfile->fpt);
}
