/************************************************************************/
/* Commonlibs.c - Common support routines and structure definitions for	*/
/*  Numeric Utilities (Num-Utils).	  				*/
/*									*/
/*	  xgraphadmin@xgraph.org					*/
/*									*/
/* Copyright (C) 2002 CHein, MPerry, WMitchel, et.al.			*/
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

#include <stdio.h>
#include <math.h>

#ifndef COMMON_LIB
#define COMMON_LIB

#define floating double
#define Pi	3.1415926535897932384626433
typedef struct	
	{ floating 	r,
			i;
	} complex ;

complex COMP( a, b )
floating a,b;
{
complex c;
 c.r = a; c.i = b; 
 return c;
}

complex CONJG( a )
complex a;
{
 a.i = -a.i; 
 return a;
}

complex CMULT_ADD( a, b, c )
complex a, b, c;
{
complex sum;
 sum.r = a.r * b.r - a.i * b.i + c.r;
 sum.i = a.r * b.i + a.i * b.r + c.i;
 return sum;
}

complex CMULT( a, b )
complex a, b;
{
complex sum;
 sum.r = a.r * b.r - a.i * b.i;
 sum.i = a.r * b.i + a.i * b.r;
 return sum;
}

complex CSMULT( a, b )
complex a;
floating b;
{
complex sum;
 sum.r = a.r * b;
 sum.i = a.i * b;
 return sum;
}

floating CMAG( a )
complex a;
{
 return sqrt( a.r*a.r + a.i*a.i );
}

complex CSUB( a, b )
complex a, b;
{
complex sum;
 sum.r = a.r - b.r;
 sum.i = a.i - b.i;
 return sum;
}

complex CADD( a, b )
complex a, b;
{
complex sum;
 sum.r = a.r + b.r;
 sum.i = a.i + b.i;
 return sum;
}

/* Return the sign of a number. */
floating sgn( x ) floating x; { if (x<0.0) return -1.0; else return 1.0; }

/* Print a complex number. */
void cmplx( x )
complex x;
{ printf("(%f, %f)", x.r, x.i ); }

/* Print a phasor quantity. */
void phasor( x )
 complex x;
{
 floating    a,b;
 a = sqrt(x.r*x.r + x.i*x.i);
 if (fabs(x.r)>1e-28) b = atan( fabs(x.i/x.r) ) * 180.0/3.14159;
 else  if (abs(x.i)>0) b = x.i*90.0/fabs(x.i); else b = 0.0;
 if ((x.r<0.0) && (x.i>=0.0) ) b = 180.0 - b; else
 if ((x.r<0.0) && (x.i<0.0) ) b = 180.0 + b; else
 if ((x.r>0.0) && (x.i<0.0) ) b = 360.0 - b;
 printf("%f /_ %f", a, b);
}


complex CDIV( a, b )
complex a, b;
{
 complex c, sum;
 floating m, er1, er2;
 int i;
 m = b.r * b.r + b.i * b.i;
 if (m==0.0) { printf("ERROR:%c Divide by ZERO.\n", 7); return COMP(1.0e10, 0.0); }
 m = 1.0 / m;
 c.r = (b.r * a.r + b.i * a.i) * m;
 c.i = (b.r * a.i - b.i * a.r) * m;
 sum = c;
 return sum;
}



#define DMRFFT

void MRFFT_INIT( int  N, 	/* N: Number of points */
		 floating *SN, floating *CN )
{
 floating TPN;
 int I;

 TPN = 2.0 * Pi / (floating)N;
 for (I=0; I!=N; I++)
  { SN[I] = -sin(TPN * (floating)I);  CN[I] = cos(TPN * (floating)I); }
}


void MRFFT( complex *x, complex *Y, int N, int direction, floating *SN, floating *CN )
{ /*MRFFT*/
/****************************************************************
 * This subroutine accepts a complex vector of samples, and
 * computes the corresponding complex FFT, or inverse FFT.
 * This routine was derived from work done by Murlin S.
 * Corrington and CHein.  This algorithm is especially useful
 * for arbitrary transform lengths which are not a power of two.
 * The algorithm first chooses the most efficient radix sequence,
 * and then computes the transform accordingly.  Warnings can be
 * enabled for less desirable or relatively prime transform lengths.
 *
 * Inputs:	 x: input vector
 *		 N: Number of points
 *		 direction: (+1)=Forward DFT, (-1)=Inverse DFT
 * Output:	 Y: Output vector
 *
 *****************************************************************/

int 	I, itmp, sw, nsw, n_stages,
	Aradix, Bradix, NAB, NDIV, No,
	row, col, ct,  A, B, C, Bcount, Ccount, CSTP, ABN,
	stage, 	FF[2][40], base[40], cntr, level;

floating	TPN, ftmp, Real, Imag, *Xr[2], *Xi[2];

 /* Allocate some memory */
 for (I=0; I!=2; I++)
  {
   Xr[I] = (floating *)malloc( N * sizeof( floating ) );
   if (Xr[I]==0) printf("ERROR:%c Not Enough MEMORY Failure MRFFT Xr%d.\n", 7, I);
   Xi[I] = (floating *)malloc( N * sizeof( floating ) );
   if (Xi[I]==0) printf("ERROR:%c Not Enough MEMORY Failure MRFFT Xi%d.\n", 7, I);
  }

for (I=0; I!=N; I++)  {  Xr[0][I] = x[I].r;  Xi[0][I] = x[I].i;  }
if (direction<0)  for (I=0; I!=N; I++) SN[I] = -SN[I];
No = N;  n_stages = 0;
 do
  {
   I = (int)sqrt((floating)No);
   while ( (floating)No/(floating)I != (floating)(No/I) ) I = I - 1;
   No = No/I;   FF[0][n_stages] = I;	FF[1][n_stages] = No;
   n_stages = n_stages + 1;
  } while ((No>5) && (I != 1));
 if (I>9) printf("	Innefficient tranform length N (factor=%d).\n", I);

sw = 1; nsw = 0;  stage = 0;
while (stage!=n_stages)
{ /*640*/
 for (I=0; I!=N; I++) { Xr[sw][I] = 0.0;  Xi[sw][I] = 0.0; }
 Aradix = FF[0][stage];  Bradix = FF[1][stage];

 /* Multiply A-matrix */
 NAB = N / (Aradix * Bradix);  NDIV = N / Aradix;
 row = 0;  ct = 0;
 while (row<N)
 { /*1260*/
  CSTP = 0;	A = Aradix;	ABN = 0;
  while (A!=0)
  { /*1250*/
   Bcount = Bradix - 1;	 B = 0;	 col = ct;
   do
   { /*1200*/
    Ccount = Aradix; 	 C = B;  Real = 0.0;	Imag = 0.0;
    while (Ccount!=0)
     { /*1180*/
      if (C>=N) C = C - N;
      Real = Real + CN[C] * Xr[nsw][col] - SN[C] * Xi[nsw][col];
      Imag = Imag + CN[C] * Xi[nsw][col] + SN[C] * Xr[nsw][col];
      col = col + Bradix; C = C + CSTP; Ccount = Ccount - 1;
     } /*1180*/
    Xr[sw][row] = Real;   Xi[sw][row] = Imag;
    B = B + ABN;  row = row + 1; Bcount = Bcount - 1;
    if (Bcount!=-1) col = Bradix - Bcount - 1 + ct;
   } while (Bcount != -1); /*1200*/
   CSTP = CSTP + NDIV;
   A = A - 1; ABN = ABN + NAB;
  } /*1250*/
  ct = col - Bradix + 1;
 } /*1260*/
 itmp = sw;  sw = nsw;  nsw = itmp;  stage = stage + 1;
} /*640*/

for (I=0; I!=N; I++) { Xr[sw][I] = 0.0;  Xi[sw][I] = 0.0; }
 Aradix = FF[0][n_stages-1];  Bradix = FF[1][n_stages-1];
 /* Multiply B-matrix */
 NDIV = N / Bradix;  row = 0;  col = 0;
 while (row < N-1)
 { /*2115*/
  CSTP = 0;  Bcount = Bradix;
  while (Bcount!=0)
  { /*2210*/
   Ccount = Bradix;  C = 0;  Real = 0.0;  Imag = 0.0;
   while (Ccount!=0)
   { /*2170*/
    if (C>=N) C = C - N;
    Real = Real + CN[C] * Xr[nsw][col] - SN[C] * Xi[nsw][col];
    Imag = Imag + CN[C] * Xi[nsw][col] + SN[C] * Xr[nsw][col];
    Ccount = Ccount - 1;    C = C + CSTP;  col = col + 1;
   } /*2170*/
   Xr[sw][row] = Real;   Xi[sw][row] = Imag;
   CSTP = CSTP + NDIV;   Bcount = Bcount - 1;  row = row + 1;
   if (Bcount!=0) col = col - Bradix;
  } /*2210*/
 } /*2220*/

 cntr = 0;
 FF[1][n_stages] = 1;	FF[0][n_stages] = FF[1][n_stages-1];
 base[n_stages+1] = 0;	base[n_stages] = 0;
 level = n_stages;
 do
 {
  if (level==0)
   { 
    Y[cntr].r = Xr[sw][base[0]];  Y[cntr].i = Xi[sw][base[0]];
    cntr = cntr + 1;    base[level] = base[level] + FF[1][level];
   }
  else
   { level = level - 1;  base[level] = base[level+1]; }
  while ((level!=n_stages) && (base[level]>=FF[0][level] * FF[1][level] ))
   { level = level + 1;  base[level] = base[level] + FF[1][level]; }
 } while ( base[level] < FF[0][level] * FF[1][level] );

 if (direction>0)
  {
   ftmp = 1.0 / (floating)N;
   for (I=0; I!=N; I++)  { Y[I].r = ftmp * Y[I].r;   Y[I].i = ftmp * Y[I].i; }
  }

  /* Return Sine table to original if it was negated. */
  if (direction<0)  for (I=0; I!=N; I++) SN[I] = -SN[I];
  for (I=0; I!=2; I++) { free( Xr[I] );  free(Xi[I]); }
} /*MRFFT*/



/* FFT routine for perfect powers of twos only. */
int FFT_STATE=0, FFT_SIZE;

void fft_init( int N, floating *sintab1, floating *sintab2 )
{
 int k, mmax, m, step, i, j, sz;
 floating phi, sinphi, twid, pi2;
 
 sz = 1; m = 2;
 while (m<N) { sz = sz + 1; m = m << 1; }
 if (m!=N) 
  { if (N>2502) printf("	(Note: %d is not a perfect power of two.)\n	( FFT may not be as efficient.)\n", N);
    MRFFT_INIT( N, sintab1, sintab2 );
    FFT_STATE = 2;  FFT_SIZE = N;  return;
  }
 else FFT_STATE = 1;
 FFT_SIZE = N;

 pi2 = 0.5 * Pi;
 mmax = 1;  k = 0;
 while (mmax < N)
  { /*mmax*/
    step = mmax << 1;    phi = pi2 / (float)mmax;
    sinphi = sin(phi);   twid = sin(phi * 2.0);
    sintab1[k] = sinphi; sintab2[k] = twid;
    k = k + 1;  m = 0;
    while (m < mmax)
     { /*m*/
	i = m;
	while (i<N) { j = i + mmax;  i = i + step; }
	m = m + 1;
    } /*m*/
   mmax = step;
  } /*mmax*/
}




void fft( complex *data, int N, int direction, floating *sintab1, floating *sintab2 )
{
 int i, step, j, m, mmax, n;
 floating sinphi, phi, coef_i, coef_r, sci, scr, tmpr, tmpi, fdir, scale;
 int n2, k;
 complex ctmp;

 n2 = N >> 1;
 j = 0;   i = 0;   
 fdir = -(floating)direction;

 /* Perform decimation in time by bit reversing up front. */
 while (i<N)
  { /*i*/
    if (i<j) 
     { ctmp = data[j];  data[j] = data[i];  data[i] = ctmp; }
    m = n2;
    while ( (j>m-1) && (m>=2) ) 
     { j = j - m;  m = m >> 1; }
    j = j + m;  i = i + 1;
  } /*i*/

 mmax = 1;  k = 0;
 while (mmax < N)
  { /*mmax*/
    step = mmax << 1;
    sinphi = fdir * sintab1[k];
    sci = fdir * sintab2[k];
    scr = -2.0 * sinphi * sinphi;
    k = k + 1;    m = 0;
    coef_r = 1.0;    coef_i = 0.0;
    while (m < mmax)
     { /*m*/
	i = m;
	while (i<N)
	 { /*i*/
	   j = i + mmax;
	   tmpr = (coef_r * data[j].r) - (coef_i * data[j].i);
	   tmpi = (coef_r * data[j].i) + (coef_i * data[j].r);
	   data[j].r = data[i].r - tmpr;  data[j].i = data[i].i - tmpi;
	   data[i].r = data[i].r + tmpr;  data[i].i = data[i].i + tmpi;
	   i = i + step;
	 } /*i*/
	tmpr = coef_r;  m = m + 1;
	coef_r = coef_r + (coef_r * scr) - (coef_i * sci);
	coef_i = coef_i + (coef_i * scr) + (tmpr * sci);
    } /*m*/
   mmax = step;
  } /*mmax*/

 if (direction>0)
  {
   scale = 1.0 / (floating)N;
   for (i=0; i!=N; i++) 
    {
     data[i].r = scale * data[i].r;
     data[i].i = scale * data[i].i;
    }
  }
} 


void FFT( complex *x, complex *Y, int N, int direction, floating *SN, floating *CN )
{
 if ((FFT_STATE==0) || (N != FFT_SIZE))  fft_init( N, SN, CN );
 if (FFT_STATE==1) 
  {
   int i;
   for (i=0; i<N; i++) Y[i] = x[i];
   fft( Y, N, direction, SN, CN );
  }
 else
  MRFFT( x, Y, N, direction, SN, CN );
}



/*..............................................................*/
/* Remove leading and trailing white-space from a line of text. */
/*..............................................................*/
void remove_leading_trailing_space(char *line)
{
 int i;
 i = strlen(line)-1;
 while ((i>=0) && ((line[i]==' ') || (line[i]=='	') || (line[i]=='\n') || (line[i]==13)))
  i = i - 1;
 line[i+1] = '\0';
 while ((line[0]==' ') || (line[0]=='	'))
  { i=0; do { line[i] = line[i+1]; i = i + 1; } while (line[i]!='\0'); }
}


int is_number( char *word )
{
 if (word[0]=='\0') return 0; else
 if (isdigit(word[0])!=0) return 1; else
 if ((word[0]=='-') || (word[0]=='+'))
  { if (isdigit(word[1])!=0) return 1; else return 0; } else return 0;
}


/*.......................................................................
  .     NEXT_WORD - accepts a line of text, and returns with the        .
  . next word in that text in the third parameter, the original line    .
  . is shortened from the beginning so that the word is removed.        .
  . If the line encountered is empty, then the word returned will be    .
  . empty.                                                              .
  . NEXTWORD can parse on an arbitrary number of delimiters, and it 	.
  . returns everthing that was cut away in the second parameter.	.
  .......................................................................*/
void Next_Word( line, pre_trash, word, delim )
 char *line, *pre_trash, *word, *delim;
{
 int i=0, j=0, k=0, m=0, flag=1;

 /* Eat away preceding garbage */
 while ((line[i]!='\0') && (flag))
  {
   j = 0;
   while ((delim[j]!='\0') && (line[i]!=delim[j])) j = j + 1;
   if (line[i]==delim[j]) 
    { pre_trash[k] = line[i];  k = k + 1;  i = i + 1; }
   else  flag = 0;
  }

 while ((line[i]!='\0') && (!flag))
  {
   word[m] = line[i];
   m = m + 1;
   i = i + 1;
   if (line[i]!='\0')
    {
     j = 0;
     while ((delim[j]!='\0') && (line[i]!=delim[j])) j = j + 1;
     if (line[i]==delim[j]) flag = 1;
    }
  }

 /* Shorten line. */
 j = 0;
 while (line[i]!='\0')
  { line[j] = line[i];  j = j + 1;  i = i + 1; }

 /* Terminate the char-strings. */
 line[j] = '\0';
 pre_trash[k] = '\0';
 word[m] = '\0';
}



/*****************************************************/
/* Read_next line from file, filtering all comments. */
/*	Max = max line length.			     */
/* Usage:   Read_Line( &fileptr, word, max );        */
/*****************************************************/
void Read_Line( FILE *infile, char *word, int max )
{
 int i=0, line_crossed=0;
 char ch=' ', och=' ';

 do
  {
   i = 0;
   line_crossed = 0;
   ch = ' ';  och = ' ';
   while ((!feof(infile)) && ((ch!='\n') || (i==0)))
    {
     ch = getc(infile);
     if (!feof(infile))
      {
       if ((ch=='*') && (och=='/')) 
        { /* Eat comment. */
 	  i = i - 1; 
	  och = ch;
	  ch = getc(infile);  
	  while ((!feof(infile)) && (! ((ch=='/') && (och=='*'))) )
	   { och = ch; ch = getc(infile); if (ch=='\n') line_crossed = 1; }
	  if (line_crossed) ch = '\n'; else ch = ' ';
        }
       if (ch!='\n')
        { 
          word[i]=ch; i = i + 1;
          if (i==max) 
	   { word[i-1]='\0'; ch='\n'; printf("ERROR: Line too long '%s'.%c\n", word, 7); }
        }
      och = ch;
     }
    }
   if ((i>0) && (word[i-1]==13)) word[i-1] = '\0';
   word[i] = '\0';
   /* Check for leading '!'. */
   i = 0;
   while ((word[i]!='\0') && ((word[i]==' ') || (word[i]=='	'))) i++;
  }
 while ((!feof(infile)) && (word[i]=='!'));  
}



/* ----------------------------------------------------------------------- */

int delim_test( char ch, char *delim )
{
 int i=0;
 while ((delim[i]!='\0') && (ch!=delim[i])) i = i + 1;
 if (ch==delim[i]) return 1; else return 0;
}


void remove_leading_trailing( char *word, char *delim )
{
 int i=0, j;
 while ((word[i]!='\0') && (delim_test(word[i],delim)==1)) i = i + 1;
 j = 0;
 do { word[j++] = word[i++]; } while (word[i-1]!='\0');
 j = j - 2;
 while ((j>=0) && (delim_test(word[j],delim)==1)) j = j - 1;
 word[j+1] = '\0';
}


void filter_c_comments( char *line )
{
 int i=0, j=0;
 while ((line[i]!='\0') && (j==0))
  { if ((i>0) && (line[i-1]=='/') && (line[i]=='*')) j = 1; else i = i + 1; }
 if (j==1)
  {
   j = i + 1;   i = i - 1;
   while ((line[j]!='\0') && ((line[j]!='/') || (line[j-1]!='*'))) j = j + 1;
   if (line[j]!='\0') j = j + 1;
   do { line[i] = line[j]; i=i+1; j=j+1; } while (line[i-1]!='\0');
   remove_leading_trailing( line, " 	" );
  }
}



/****************************************************************/
/* XML_PARSE - This routine finds the next <xxx> tag, and grabs	*/
/*	it, and then grabs whatever follows, up to the next tag.*/
/*	It returns the tag and it's following contents.		*/
/*	It cleans any trailing white-space from the contents.	*/
/*  This routine is intended to be called iteratively, to parse	*/
/*  XML-formatted data.  Specifically, it pulls the contents	*/
/*  each tag.							*/
/****************************************************************/
void xml_parse( FILE *fileptr, char *tag, char *content, int *lnn )
{
 int i;  char ch;

 /* Get up to next tag. */
 do { ch = getc(fileptr);  if (ch==10) *lnn++; } while ((!feof(fileptr)) && (ch != '<'));

 /* Grab this tag. */
 i = 0;
 do 
  { tag[i] = getc(fileptr); i=i+1; 
    if ((i==3) && (tag[0]=='!') && (tag[1]=='-') && (tag[2]=='-'))
     { /*Filter_comment.*/
       i = 0;
       do { ch = getc(fileptr); if (ch=='-') i = i + 1; else if ((ch!='>') || (i==1)) i = 0; } 
       while ((!feof(fileptr)) && ((i<2) || (ch!='>')));
       do { ch = getc(fileptr);  if (ch==10) *lnn++; } while ((!feof(fileptr)) && (ch != '<'));
       i = 0;
     } /*Filter_comment.*/
  } while ((!feof(fileptr)) && (tag[i-1] != '>'));
 if (i==0) i = 1;
 tag[i-1] = '\0';

 /* Now grab contents until next tag. */
 i = 0;
 do { content[i] = getc(fileptr); if (content[i]==10) *lnn++; i=i+1; } while ((!feof(fileptr)) && (content[i-1] != '<'));
 ungetc( content[i-1], fileptr );
 if (i==0) i = 1;
 content[i-1] = '\0';

 /* Clean-up contents by removing trailing white-space. */
 /* 
 i = strlen(content)-1;
 while ((i>=0) && ((content[i]==' ') || (content[i]=='	') 
	|| (content[i]==10) || (content[i]==13)))   i = i - 1;
 content[i+1] = '\0'; 
 */
 remove_leading_trailing( tag, " 	" );
 remove_leading_trailing( content, " 	" );
}



void xml_get_next_tag( FILE *fileptr, char *tag, int *lnn )
/* Does only first half of xml_parse(), above. */
{
 int i;  char ch;

 /* Get up to next tag. */
 do { ch = getc(fileptr);  if (ch==10) *lnn++; } while ((!feof(fileptr)) && (ch != '<'));

 /* Grab this tag. */
 i = 0;
 do
  { tag[i] = getc(fileptr); i=i+1; 
    if ((i==3) && (tag[0]=='!') && (tag[1]=='-') && (tag[2]=='-'))
     { /*Filter_comment.*/
       i = 0;
       do { ch = getc(fileptr); if (ch=='-') i = i + 1; else if ((ch!='>') || (i==1)) i = 0; } 
       while ((!feof(fileptr)) && ((i<2) || (ch!='>')));
       do { ch = getc(fileptr);  if (ch==10) *lnn++; } while ((!feof(fileptr)) && (ch != '<'));
       i = 0;
     } /*Filter_comment.*/
  } while ((!feof(fileptr)) && (tag[i-1] != '>'));
 if (i==0) i = 1;
 tag[i-1] = '\0';
 remove_leading_trailing( tag, " 	" );
}



void xml_get_contents( FILE *fileptr, char *content, int *lnn )
/* Does only second half of xml_parse(), above. */
{
 int i;

 /* Now grab contents until next tag. */
 i = 0;
 do { content[i] = getc(fileptr); if (content[i]==10) *lnn++; i=i+1; } while ((!feof(fileptr)) && (content[i-1] != '<'));
 ungetc( content[i-1], fileptr );
 if (i==0) i = 1;
 content[i-1] = '\0';

 /* Clean-up contents by removing trailing white-space. */
 /*
 i = strlen(content)-1;
 while ((i>=0) && ((content[i]==' ') || (content[i]=='  ') 
        || (content[i]==10) || (content[i]==13)))   i = i - 1;
 content[i+1] = '\0'; 
 */
 remove_leading_trailing( content, " 	" );
}

/* ----------------------------------------------------------------------- */


struct file_kind
 {
  int dim1, dim2;
  char kind;	/* R/C */
  FILE *fpt;
 };


/****************************************************************/
/* File_Open_Read - Attempts to open named file for Reading.	*/
/*	Parameters:						*/
/*		fname - file name to open.			*/
/* After opeining file, it assess file's parameters.		*/
/* Returns file parameters.
/****************************************************************/
 struct file_kind *
file_open_read( char *fname )
{
 char tag[500], contents[1000], trash[500], word[500];
 struct file_kind *filep;
 int lncnt=0;

 filep = (struct file_kind *)malloc(sizeof(struct file_kind));
 filep->fpt = fopen(fname,"r");
 filep->kind = 'R';	/* Set bland defaults. */
 filep->dim1 = -1; filep->dim2 = 0; 
 if (filep->fpt!=0)
  {
   xml_parse( filep->fpt, tag, contents, &lncnt );
   Next_Word( contents, trash, word, " 	");

   if (strcasecmp(tag,"Type")!=0)
    { printf("\nWARNING: File Type Tag not found as first tag. Unknown file type '%s'.\n",fname);
      printf("Guesing type is Real Vector.\n");
      fclose(filep->fpt);
      filep->fpt = fopen(fname,"r");
    }
   else
    {
     if (strncasecmp(word,"Real",1)==0)  filep->kind = 'R';  else
     if (strncasecmp(word,"Complex",1)==0)  filep->kind = 'C';  else
      printf("\nWARNING: Unknown Data type '%s' in file %s.\nGuesing type is Real.\n", word, fname); 
     Next_Word( contents, trash, word, " 	[");
     if (strncasecmp(word,"Vector",1)==0)  { filep->dim1 = -1;   filep->dim2 = 0; } else
     if (strncasecmp(word,"Matrix",1)==0)
      {
       Next_Word( contents, trash, word, "[,]");
       if (sscanf(word,"%d",&(filep->dim1))!=1) { printf("ERROR: Bad Matrix First Dimension '%s'\n.", word); exit(0); }
       Next_Word( contents, trash, word, ",]");
       if (sscanf(word,"%d",&(filep->dim2))!=1) { printf("ERROR: Bad Matrix Second Dimension '%s'\n.", word); exit(0); }
      }
     else { printf("\nWARNING: Unknown Data structure '%s' in file %s.\nGuesing type is Vector.\n", word, fname); }
     while ((!feof(filep->fpt)) && (getc(filep->fpt)!=10));
    }
  }
 return filep;
}


/****************************************************************/
/* File_Open_Write - Attempts to open named file for writing.	*/
/*	Parameters:						*/
/*		fname = file name to open.			*/
/*		kind  = 'R' or 'C'				*/
/*		dim1  = first dimension, or -1 if unknown.	*/
/*		dim3  = second dimension			*/
/* After opening file, it sets the file's parameters.		*/
/* Returns file structure.					*/
/****************************************************************/
 struct file_kind *
file_open_write( char *fname, char kind, int dim1, int dim2 )
{
 struct file_kind *filep;

 filep = (struct file_kind *)malloc(sizeof(struct file_kind));
 filep->fpt = fopen(fname,"w");
 filep->kind = kind;
 filep->dim1 = dim1;
 filep->dim2 = dim2;
 if (filep->fpt!=0)
  {
   fprintf(filep->fpt,"!<Type> ");
   if (kind=='R') fprintf(filep->fpt,"Real, ");
   else		  fprintf(filep->fpt,"Complex ");
   if (dim2<2)  fprintf(filep->fpt,"Vector");
   else		fprintf(filep->fpt,"Matrix[%d,%d]", dim1, dim2 );
   fprintf(filep->fpt," </Type>\n");
  }
 return filep;
}

#endif
