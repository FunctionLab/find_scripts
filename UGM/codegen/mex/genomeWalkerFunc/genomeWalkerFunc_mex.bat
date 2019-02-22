@echo off
set MATLAB=D:\PROGRA~2\MATLAB\R2011a
set MATLAB_ARCH=win64
set MATLAB_BIN="D:\Program Files\MATLAB\R2011a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=E:\Code\Matlab Kits\UGM\codegen\mex\genomeWalkerFunc\
set LIB_NAME=genomeWalkerFunc_mex
set MEX_NAME=genomeWalkerFunc_mex
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for genomeWalkerFunc > genomeWalkerFunc_mex.mki
echo COMPILER=%COMPILER%>> genomeWalkerFunc_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> genomeWalkerFunc_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> genomeWalkerFunc_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> genomeWalkerFunc_mex.mki
echo LINKER=%LINKER%>> genomeWalkerFunc_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> genomeWalkerFunc_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> genomeWalkerFunc_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> genomeWalkerFunc_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> genomeWalkerFunc_mex.mki
echo BORLAND=%BORLAND%>> genomeWalkerFunc_mex.mki
echo OMPFLAGS= >> genomeWalkerFunc_mex.mki
echo EMC_COMPILER=msvc100>> genomeWalkerFunc_mex.mki
echo EMC_CONFIG=debug>> genomeWalkerFunc_mex.mki
"D:\Program Files\MATLAB\R2011a\bin\win64\gmake" -B -f genomeWalkerFunc_mex.mk
