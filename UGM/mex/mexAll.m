
mex  -outdir minFunc_2009 minFunc_2009/lbfgsC.c
mex  -outdir minFunc_2009 minFunc_2009/mcholC.c

mex  -outdir KPM KPM/max_mult.c

mex  -Imex -outdir compiled mex/UGM_makeEdgeVEC.c
mex  -Imex -outdir compiled mex/UGM_Decode_ExactC.c
mex  -Imex -outdir compiled mex/UGM_Infer_ExactC.c
mex  -Imex -outdir compiled mex/UGM_Infer_ChainC.c
mex  -Imex -outdir compiled mex/UGM_makeClampedPotentialsC.c
mex  -Imex -outdir compiled mex/UGM_Decode_ICMC.c
mex  -Imex -outdir compiled mex/UGM_Decode_GraphCutC.c
mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC.c
mex  -Imex -outdir compiled mex/UGM_Infer_MFC.c
mex  -Imex -outdir compiled mex/UGM_Infer_LBPC.c
mex  -Imex -outdir compiled mex/UGM_Decode_LBPC.c
mex  -Imex -outdir compiled mex/UGM_Infer_TRBPC.c
mex  -Imex -outdir compiled mex/UGM_Decode_TRBPC.c
mex  -Imex -outdir compiled mex/UGM_CRF_makePotentialsC.c
mex  -Imex -outdir compiled mex/UGM_CRF_makePotentialsC_FC.c

mex  -Imex -outdir compiled mex/UGM_CRF_PseudoNLLC.c
mex  -Imex -outdir compiled mex/UGM_LogConfigurationPotentialC.c
mex  -Imex -outdir compiled mex/UGM_Decode_AlphaExpansionC.c
mex  -Imex -outdir compiled mex/UGM_Decode_AlphaExpansionBetaShrinkC.c
mex  -Imex -outdir compiled mex/UGM_CRF_NLLC.c
mex  -Imex -outdir compiled mex/UGM_CRF_NLLC_FC.c

mex  -Imex -outdir compiled mex/UGM_CRF_PseudoNLLC_FC.c
mex  -Imex -outdir compiled mex/UGM_CRF_makePotentialsC_FC2.c
mex  -Imex -outdir compiled mex/UGM_CRF_NLLC_FC2.c
mex  -Imex -outdir compiled mex/UGM_CRF_PseudoNLLC_FC2.c
mex  -Imex -outdir compiled mex/UGM_LogConfigurationPotentialC_Hidden.c

mex  -Imex -outdir compiled mex/UGM_CRF_NLLC_FC_Hidden.c

mex  -Imex -outdir compiled mex/UGM_Infer_ConditionalC.c
mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC_Clamp.c
mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC_Clamp.c
mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC_Clamp_Single.c
mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC_Clamp_Single_Batch.c

mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC.c
mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC_Single.c
mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC_Single_Batch.c
mex  CFLAGS="\$CFLAGS -fopenmp" LDFLAGS="\$LDFLAGS -fopenmp" -Imex -outdir compiled mex/UGM_Sample_GibbsC_Single_Batch_OpenMP.c
 mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC_Single_Batch_OpenMP.c COMPFLAGS="/openmp $COMPFLAGS"
 mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC_Clamp_Single_Batch_OpenMP.c COMPFLAGS="/openmp $COMPFLAGS"
 mex  -Imex -outdir compiled mex/UGM_CRF_makePotentialsC_FC_Batch_OpenMP.c COMPFLAGS="/openmp $COMPFLAGS"

mex  -Imex -outdir compiled mex/UGM_CRF_NLLC_FC_Hidden_Sample.c
mex  -Imex -outdir compiled mex/UGM_CRF_NLLC_FC_Hidden_Sample_Batch.c

mex  -Imex -outdir compiled mex/UGM_CRF_makePotentialsC_FC_Batch.c

mex  -Imex -outdir compiled mex/UGM_LogConfigurationPotentialC_Hidden_Batch_OpenMP.c COMPFLAGS="/openmp $COMPFLAGS"

mex  CXXFLAGS="\$CXXFLAGS -fopenmp  -O3" LDFLAGS="\$LDFLAGS -fopenmp  -O3 " -Imex -I/home/jzthree/include -L/home/jzthree/lib -ltrng4 -outdir compiled mex/UGM_Sample_GibbsC_Single_Batch_OpenMP_edgePot.cpp
mex  CXXFLAGS="\$CXXFLAGS -fopenmp  -O3" LDFLAGS="\$LDFLAGS -fopenmp  -O3 " -Imex -I/home/jzthree/include -L/home/jzthree/lib -ltrng4 -outdir compiled mex/UGM_Sample_GibbsC_Clamp_Single_Batch_OpenMP_edgePot.cpp

 mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC_Single_Batch_OpenMP_edgePot.c COMPFLAGS="/openmp $COMPFLAGS"
 mex  -Imex -outdir compiled mex/UGM_Sample_GibbsC_Clamp_Single_Batch_OpenMP_edgePot.c COMPFLAGS="/openmp $COMPFLAGS"

