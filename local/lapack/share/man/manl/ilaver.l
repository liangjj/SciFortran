.TH  ILAVER 1 "April 2011" " LAPACK routine (version 3.3.1)                                  " " LAPACK routine (version 3.3.1)                                  " 
.SH NAME
LAPACK-3 - subroutine return the Lapack version
.SH SYNOPSIS
.TP 19
SUBROUTINE ILAVER(
VERS_MAJOR, VERS_MINOR, VERS_PATCH )
.SH PURPOSE
This subroutine return the Lapack version.
.SH ARGUMENTS
 return the lapack major version
 VERS_MINOR   (output) INTEGER
 return the lapack minor version from the major version
 VERS_PATCH   (output) INTEGER
 return the lapack patch version from the minor version
