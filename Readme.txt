This is the code accompanying the manuscript "Accurate genome-wide predictions of spatio-temporal gene expression during embryonic development".

To compile, use the following command in the matlab console:
cd ./UGM
mexAll

To finish training, evaluation, and prediction with 5 fold cross-validation, use  
run_crf_auto(1,8,0);  
run_crf_auto(2,8,0);  
run_crf_auto(3,8,0);  
run_crf_auto(4,8,0);  
run_crf_auto(5,8,0); 
in matlab console, which can be done in parallel too.

The code train an ontology-aware CRF model based on SVM predictions ('consensus.may2014_modexpscaled2_srxtg500.insitu.cvdata.xdata.mat') and developmental ontology ('dag_02122016.mat'), predict on holdout data (evaluation), and predict on genes without prior annotation (prediction; SVM predictions from 'consensus.may2014_modexpscaled2_srxtg500.insitu.cvdata.xdata.pred.mat'). The training algorithm initializes the model with pseodolikelihood based estimation of model parameters and fine tunes with MCMC in the second stage. The SVM predictions are performed using SVMperfer tool from libsleipnir https://bitbucket.org/libsleipnir/sleipnir/src/sleipnir/.

This implementation is heavily based upon Mark Schmidt's UGM code https://www.cs.ubc.ca/~schmidtm/Software/ with minor modifications for efficiency from me.
