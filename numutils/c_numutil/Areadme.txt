Numerical Utilities - Num-Utils     (Version 1.1)
-------------------------------

The Numerical Utilities perform common mathematical operations on 
files containing lists of numbers.  Files may represent vectors or
matrices. The files may be plotted by various tools, such as 
XGRAPH, and the utilities provide means to manipulate data to be
plotted.

The utilities are useful for anyone studying Digital Signal
Processing (DSP), linear algebra, statistics, or numerical
analysis in general, as well any field dealing  with numerical
data.  The utilities form a simple and inexpensive alternative to-,
or can  be used to complement-, more extensive environments such
as Octave, Matlab, or programming  libraries such as LAPACK by
leveraging the familiar capabilities of the operating system's
command-line and/or script files.  Num-Util enables file-names to 
be treated as variable-names.  

For full documentation and latest versions, see:
	www.xgraph.org/numutil.html
===============================================================

List of Utilities:
------------------

 Scaling / Shifting 
 ------------------
  scale.c	- Scales a real or complex vector file by a scalar.
  shift.c	- Adds a scalar to a real or complex vector file.
  normalize.c	- Normalize a vector.  Makes sum (or max) of terms equal 1.0.

 Generating Functions
 --------------------
  sine_gen.c	- Generates sinusoidal vectors.
  rand_gen.c	- Generates random vectors, noise.

 Conversions
 -----------
  abs.c		- Computes absolute value (or complex magnitude).
  cmag.c	- Converts a complex vector file into real (magnitude) vector.
  db.c		- Converts a real vector file from linear to dB.
  phasor.c	- Converts a complex vector file into magnitude and phase.
  real2cmplx.c	- Converts a real vector to a complex vector.
  extract_real.c      - Extracts real part of complex vector to real vector.
  extract_imaginary.c - Extracts imaginary part of complex vector to real vector.
  barchart      - Converts real vector to bar-chart graph.
  mat2image.c	- Convert matrix to an image file.
  image2matrix.c- Convert an image file to a matrix file.
  num2vec       - Converts simple number list to NumUtils Vector format.
  vec2nums      - Converts real or complex vector files to simple number list files.


 Operations / Transforms
 -----------------------
  add.c		- Adds two real or complex vectors or matrices.
  sub.c		- Subtracts one vector or matrix from another.
  conjg.c	- Conjugates a complex vector.
  dotpr.c	- Computes the dot-product (inner-product) of two vectors.
  cdotpr.c	- Complex-conjugate dot-product of two complex vectors.

  matmul.c	- Matrix-matrix or Matrix-vector multiply, real or complex.  
  multpbp.c	- Multiplies real or complex vector by vector (point by point).
  outpr.c	- Outer-product multiply. Multiplies two vectors, produces matrix.

  zfill.c	- zero-fills a vector to arbitrary length.
  convolve.c	- Convolves two complex or real vectors. (FIR filter)
  correlate.c	- Computes the correlation of two complex or real vectors.
  fft.c   	- Computes FFT on a complex or real vector (of any length).
  window.c	- Computes windowing functions, hamming, hanning, bartlet, blackman.
  transpose.c	- Transposes real matrix, or conjugate-transposes complex matrices.
  ucirc.c	- Produces Unit Circle points for Z-plane plots.
  fft2D.c	- Computes the 2D-FFT on a complex or real matrix.
  eigen.c	- Computes Eigen vectors and values.
  svd.c		- Computes Singular Value Decomposition.
  z_trans.c	- Z-transform, finds roots of arbitrary polynomials.
  matinvert.c	- Invert a real or complex matrix.
  matXvec.c	- Extract matrix row or column to a vector.
  mdeterm.c	- Compute the matrix determinant, real or complex.
    augmatvec.c	- Augment matrix by vector.  Adds row or column to matrix.
  join2xy.c	- Joins 2 Real Vectors into one Vector, becoming x and y.
		  Useful for plotting one file against another.            
  differentiate - Differentiates a real vector.
  integrate     - Intregrates a real vector.


 Statistics
 ----------
  statistics.c	- Computes mean, variance, min, max, and
			optionally the median, of a real vector.
  histgram.c	- Plots histogram of real vector files.

TBD:  convolve2d, more examples, etc..  Any volunteers? 
============================================================

Background
----------

Num-Util is consistent with the convention of other file
utilities, such as "copy",  "diff", "cat", "sort", "zip", "grep",
"awk", "xv", "xgraph", "latex", etc..  All data files are ASCII
text files, (not binary) which are readable, printable, and
convenient to produce, edit, or read with other programs.  Being
file-based utilities, data is not limited by memory (RAM size).  

Because each Num-Util tool is an independent utility, they can be
called from programs without risk of library or symbol conflicts.
They can also be called directly from the command-line,
-interactively-, without need of writing a program.   Although
many of the functions are trivial, the collection has value by
virtue of it's consistency and completeness.  

Num-Util presently supports four formats for data files: 
	(1) Real Vector, (2) Complex Vector,
	(3) Real Matrix, (4) Complex Matrix.
A simple XML-like convention in the data-file's first line
indicates the file's type, and enables the tools to operate
consistently on either kind of data-file. The header also specifies
the file's dimension(s), as either vector or 2D matrix. See below
for format specification.  The utilities include extensive
checking.

The Num-Utilities are provided in source-code form, and are easily
compiled on any platform with a C compiler.  The utilities are
simple and self-contained. No additional tools or libraries are
needed.  A simple Build.com script is provided to automatically
compile the utilities, or to show the suggested compilation
commands.  Most of the Num-Util are under 100 lines of
code. (grep ";" xx.c | wc)

The Num-Utils have been in use by some small groups of
researchers for the decade.  We noticed that others were often
re-inventing common functions on projects without knowledge of
the Num-Utils and realized they may be beneficial to share
with others.  Therefore, we hope these utilities and conventions
will be helpful, and that contributors might combine efforts by
adding additional functions and utilities consistent with the
initial set, as well as to help in improving and enhancing them,
or that it serves as the basis or template for other endeavors.
Num-Util are released under GPL, included in gpl.txt.
So that everyone may share in combined efforts, we request that
improvements/comments be directed back to xgraphadmin@xgraph.org for
centralized re-distribution with credit.

For full documentation, FAQ's, and latest versions, see:
	www.xgraph.org/numutil.html
See also related/supporting tools:
	www.xgraph.org
	www.trilon.com/xv/xv.html	

============================================================

To Build and Install:
---------------------
 1. Source Build.com
    This makes executables in ./bin.
 2. Place numutils/bin in your path.  (Use absolute location.)
    For example, assuming you unpacked into /home/bart/numutils, 
    and you are in csh or tcsh: 
              set  path  =  ( /home/bart/numutils/bin  $path )
    For bash shell users, it would be:
              export PATH=.:/home/bart/numutils/bin:$PATH 

Test by trying some examples.  Some example data files and 
run-scripts are provided in the "examples" directory. 
 Try:     source   script_fft.com
 Try:     source   script_convolve.com
 Try:     source   script_image.com
 Try:     source   script_color_image.com

============================================================

Data File Formats
-----------------
The first line indicates the file type.  It must start with 
an exclamation mark, followed by dimensional and typing
information of the form:
	! <Type> ? </Type>

Where "?" is one of:
	- Real Vector
	- Real Matrix[,]
	- Complex Vector
	- Complex Matrix[,]

Specifically:

 - Real Vector - Data stored as:  (index) (value)
	Example:
		!<Type> Real Vector </Type>
		! indx  value
		  0	45.6
		  1	23.2	
		  2	10.9

 - Real Matrix[rows,cols] - Data stored as:  (row) (col) (value)
	The column is the more rapidly changing index.
	Example:
		!<Type> Real Matrix[2,2] </Type>
		! r c   value
		  1 1	52.1	! M[1,1]
		  1 2	34.5	! M[1,2]
		  2 1	29.4	! M[2,1]
		  2 2	91.8	! M[2,2]

 - Complex Vector - Data stored as:  (real) (imaginary)
	Example:
		!<Type> Complex Vector </Type>
		! real  imag
		  0.89	0.34
		  0.56	0.77
		  0.43	0.18

 - Complex Matrix[rows,cols] - Data stored as:  (real) (imag)
	Example:
		!<Type> Complex Matrix[2,2] </Type>
		! real  imag
		  0.89   0.34	! M[1,1]
		  0.56   0.77	! M[1,2]
		  0.43   0.18	! M[2,1]
		  0.67	 0.25	! M[2,2]


With this scheme, other formats could be defined, such as integer
vectors, or higher dimensional matrices, but no such formats are
presently used.

Optional comment fields can be added by starting with "!".
Everything after the "!"  until end of line is considered a
comment.

Comment fields can also be added by using the C-style comment
designators, "/*" and "*/".   These may span multiple lines.

===============================================================

For full documentation, FAQ's, and latest versions, see:
	www.xgraph.org/numutil.html
