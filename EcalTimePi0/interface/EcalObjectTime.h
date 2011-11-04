#include "CalibCalorimetry/EcalTiming/interface/EcalTimeTreeContent.h"

// Consts
const float sigmaNoiseEB          = 1.06;  // ADC ; using total single-sample noise
const float sigmaNoiseEE          = 2.10;  // ADC ; using total single-sample noise
const float timingResParamNEB     = 28.51;   // ns ; plots approved http://indico.cern.ch/conferenceDisplay.py?confId=92739
const float timingResParamConstEB = 0.1;     // ns ; 
const float timingResParamNEE     = 31.84;   // ns ; Fig. 2 from CFT-09-006
const float timingResParamConstEE = 0.4;     // ns ; rough, probably conservative estimate
float minAmpliOverSigma_   = 30;    // dimensionless
float maxChi2NDF_ = 20;  //TODO: gf configurable


// container to hold time-relaed observables for clusters or objects
struct ClusterTime {
  bool  isvalid;
  int   numCry;
  int   seed;
  int   second;
  float seedtime;
  float secondtime;
  float time;
  float timeErr;
  float otherstime;
  float otherstimeErr;
  float chi2;
} ;

ClusterTime timeAndUncertSingleCluster (int bClusterIndex, EcalTimeTreeContent treeVars_);
ClusterTime timeAndUncertyPhoton       (int bClusterIndex, EcalTimeTreeContent treeVars_);
ClusterTime timeAndUncertyJet          (int bClusterIndex, EcalTimeTreeContent treeVars_);