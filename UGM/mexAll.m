
mex -compatibleArrayDims -outdir minFunc_2009 minFunc_2009/lbfgsC.c
mex -compatibleArrayDims -outdir minFunc_2009 minFunc_2009/mcholC.c

mex -compatibleArrayDims -outdir KPM KPM/max_mult.c

mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_makeEdgeVEC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Decode_ExactC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Infer_ExactC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Infer_ChainC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_makeClampedPotentialsC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Decode_ICMC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Decode_GraphCutC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Sample_GibbsC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Infer_MFC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Infer_LBPC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Decode_LBPC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Infer_TRBPC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Decode_TRBPC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_CRF_makePotentialsC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_CRF_makePotentialsC_FC.c

mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_CRF_PseudoNLLC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_LogConfigurationPotentialC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Decode_AlphaExpansionC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Decode_AlphaExpansionBetaShrinkC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_CRF_NLLC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_CRF_NLLC_FC.c

mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_CRF_PseudoNLLC_FC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_CRF_makePotentialsC_FC2.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_CRF_NLLC_FC2.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_CRF_PseudoNLLC_FC2.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_LogConfigurationPotentialC_Hidden.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_CRF_NLLC_FC_Hidden.c

mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Infer_ConditionalC.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Sample_GibbsC_Clamp.c

mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Sample_GibbsC_Single_Batch_edgePot.c
mex -compatibleArrayDims -Imex -outdir compiled mex/UGM_Sample_GibbsC_Clamp_Single_Batch_edgePot.c



