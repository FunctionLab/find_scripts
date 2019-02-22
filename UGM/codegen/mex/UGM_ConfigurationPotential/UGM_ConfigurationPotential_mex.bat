@echo off
set MATLAB=D:\PROGRA~2\MATLAB\R2011a
set MATLAB_ARCH=win64
set MATLAB_BIN="D:\Program Files\MATLAB\R2011a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=E:\Code\Matlab Kits\UGM\codegen\mex\UGM_ConfigurationPotential\
set LIB_NAME=UGM_ConfigurationPotential_mex
set MEX_NAME=UGM_ConfigurationPotential_mex
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for UGM_ConfigurationPotential > UGM_ConfigurationPotential_mex.mki
echo COMPILER=%COMPILER%>> UGM_ConfigurationPotential_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> UGM_ConfigurationPotential_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> UGM_ConfigurationPotential_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> UGM_ConfigurationPotential_mex.mki
echo LINKER=%LINKER%>> UGM_ConfigurationPotential_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> UGM_ConfigurationPotential_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> UGM_ConfigurationPotential_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> UGM_ConfigurationPotential_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> UGM_ConfigurationPotential_mex.mki
echo BORLAND=%BORLAND%>> UGM_ConfigurationPotential_mex.mki
echo OMPFLAGS= >> UGM_ConfigurationPotential_mex.mki
echo EMC_COMPILER=msvc100>> UGM_ConfigurationPotential_mex.mki
echo EMC_CONFIG=debug>> UGM_ConfigurationPotential_mex.mki
"D:\Program Files\MATLAB\R2011a\bin\win64\gmake" -B -f UGM_ConfigurationPotential_mex.mk
