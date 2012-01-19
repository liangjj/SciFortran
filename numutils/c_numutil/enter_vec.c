/************************************************************************/
/* enter_vec.c - 							*/
/* This program creates a new vector or matrix file, by asking a series */
/* of questions.  You enter numbers at your keyboard in response to the */
/* interactive prompts.							*/
/* 									*/
/* Example Usage:							*/
/*	entervec newfile  					  	*/
/* 								  	*/
/* File Types:								*/
/*      Out:  Real or complex Vector or Matrix.				*/
/*									*/
/* From:  www.xgraph.org/numutil.html			 		*/
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
 char fname2[999]="", line[500], word[100], vmtype[100], dkind[100], numkind;
 double x,y;
 int i, j, k, arg, vecnotmat, N, M, M1;
 struct file_kind *outfile=0;

 arg = 1;  k = 0;
 while (argc>arg)
 { /*arg*/

  if (argv[arg][0]=='-')
   { /*option*/
     {printf("ERROR entervec: Unknown command-line option %s\n", argv[arg]); exit(1);}
   } /*option*/
  else
   { /*file_name*/
    if (k==0)
     { strcpy(fname2,argv[arg]);  
       k = k + 1; 
     }
    else
     {printf("ERROR entervec: Too many file-names on command line.\n"); exit(1);}
   } /*file_name*/

  arg = arg + 1;
 } /*arg*/

 printf("\nEnter-Vec:\n");
 printf("Create a Vector or Matrix ?  (answer: v or m) ? ");
 scanf("%s",word);
 if (strncasecmp(word,"v",1)==0) vecnotmat = 1; else
 if (strncasecmp(word,"m",1)==0) vecnotmat = 0; else
  {printf("ERROR entervec: Bad answer to Vector/Matrix question.\n"); exit(0);}

 if (vecnotmat)
  {
   printf("Vector Length (n) ? ");
   if (scanf("%d",&N)!=1) { printf("ERROR entervec: Bad vector length integer.\n"); exit(0);}
   M = 0;  M1 = 1;  strcpy(vmtype,"vector");
  }
 else
  {
   printf("Matrix Dimensions (answer: #rows #columns) ? ");
   if (scanf("%d",&N)!=1) { printf("ERROR entervec: Bad matrix rows integer.\n"); exit(0);}
   if (scanf("%d",&M)!=1) { printf("ERROR entervec: Bad matrix cols integer.\n"); exit(0);}
   strcpy(vmtype,"matrix");  M1 = M;
  }

 printf("Real or Complex ? (answer: r or c) ? ");
 scanf("%s",word);
 if (strncasecmp(word,"r",1)==0) { numkind = 'R';  strcpy(dkind, "real"); } else
 if (strncasecmp(word,"c",1)==0) { numkind = 'C';  strcpy(dkind, "complex"); } else
  {printf("ERROR entervec: Bad answer to Real/Complex question.\n"); exit(0);}

 if (k<1)  /* No output file specified, so make default name by appending suffix. */
  { 
   if (vecnotmat)
    strcpy(fname2,"new.vec");
   else
    strcpy(fname2,"new.mat");
  }

 outfile = file_open_write( fname2, numkind, N, M );
 if (outfile->fpt==0) {printf("ERROR entervec: Can't open output file '%s'.\n",fname2); exit(1);}

 printf("\nI will now ask for the numbers to fill your %s.\n", vmtype);
 printf("This will be a %s %s, so for each entry, respond with a\n", dkind, vmtype);
 if (numkind=='R') printf(" real number. (ex. 3.14)\n"); 
 else printf(" real and imaginary number pair.\n  Answer: real# imaginary#.  (ex. 3.14 1.57)\n");

 for (i=0; i<N; i++)
  { /*i*/
   int err=0;

   for (j=0; j<M1; j++)
    { /*j*/
     do
      {
       if (err!=0) printf("\nTry again ...\n");
       if (M==0)
        printf(" Enter V[%d] ? ", i);
       else
        printf(" Enter M[%d,%d] ? ", i, j);
       if (scanf("%lf",&x)!=1)
        {printf("ERROR entervec: Bad real value.\n"); err++;}
       if (numkind=='C')
        if (scanf("%lf",&y)!=1)
         {printf("ERROR entervec: Bad imaginary value.\n"); err++;}
       }
      while ((err>0) && (err<3));	 /* Allow user to fix error. */
 
     if (numkind=='R')
      {
       if (M==0)
        fprintf(outfile->fpt,"%d	%g\n", i, x);
       else
        fprintf(outfile->fpt,"%d	%d	%g\n", i, j, x);
      }
     else
      fprintf(outfile->fpt,"%g	%g\n", x, y);
    } /*j*/
  } /*i*/
 printf("	(Writing output to %s)\n", fname2 );
 fclose(outfile->fpt);
}
