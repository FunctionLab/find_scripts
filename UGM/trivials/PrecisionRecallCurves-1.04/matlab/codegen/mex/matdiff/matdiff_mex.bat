@echo off
set MATLAB=D:\PROGRA~2\MATLAB\R2011a
set MATLAB_ARCH=win64
set MATLAB_BIN="D:\Program Files\MATLAB\R2011a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=E:\Code\Matlab Kits\trivials\PrecisionRecallCurves-1.04\matlab\codegen\mex\matdiff\
set LIB_NAME=matdiff_mex
set MEX_NAME=matdiff_mex
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for matdiff > matdiff_mex.mki
echo COMPILER=%COMPILER%>> matdiff_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> matdiff_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> matdiff_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> matdiff_mex.mki
echo LINKER=%LINKER%>> matdiff_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> matdiff_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> matdiff_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> matdiff_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> matdiff_mex.mki
echo BORLAND=%BORLAND%>> matdiff_mex.mki
echo OMPFLAGS= >> matdiff_mex.mki
echo EMC_COMPILER=msvc100>> matdiff_mex.mki
echo EMC_CONFIG=debug>> matdiff_mex.mki
"D:\Program Files\MATLAB\R2011a\bin\win64\gmake" -B -f matdiff_mex.mk
