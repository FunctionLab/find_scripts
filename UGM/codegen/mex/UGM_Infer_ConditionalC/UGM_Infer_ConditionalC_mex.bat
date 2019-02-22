@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2013a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2013a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=UGM_Infer_ConditionalC_mex
set MEX_NAME=UGM_Infer_ConditionalC_mex
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for UGM_Infer_ConditionalC > UGM_Infer_ConditionalC_mex.mki
echo COMPILER=%COMPILER%>> UGM_Infer_ConditionalC_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> UGM_Infer_ConditionalC_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> UGM_Infer_ConditionalC_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> UGM_Infer_ConditionalC_mex.mki
echo LINKER=%LINKER%>> UGM_Infer_ConditionalC_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> UGM_Infer_ConditionalC_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> UGM_Infer_ConditionalC_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> UGM_Infer_ConditionalC_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> UGM_Infer_ConditionalC_mex.mki
echo BORLAND=%BORLAND%>> UGM_Infer_ConditionalC_mex.mki
echo OMPFLAGS= >> UGM_Infer_ConditionalC_mex.mki
echo OMPLINKFLAGS= >> UGM_Infer_ConditionalC_mex.mki
echo EMC_COMPILER=msvcsdk>> UGM_Infer_ConditionalC_mex.mki
echo EMC_CONFIG=optim>> UGM_Infer_ConditionalC_mex.mki
"C:\Program Files\MATLAB\R2013a\bin\win64\gmake" -B -f UGM_Infer_ConditionalC_mex.mk
