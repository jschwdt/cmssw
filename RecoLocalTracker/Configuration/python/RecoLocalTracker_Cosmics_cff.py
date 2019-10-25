import FWCore.ParameterSet.Config as cms

from RecoLocalTracker.SiStripRecHitConverter.SiStripRecHitConverter_cfi import *
from RecoLocalTracker.SiStripRecHitConverter.SiStripRecHitMatcher_cfi import *
from RecoLocalTracker.SiStripRecHitConverter.StripCPEfromTrackAngle_cfi import *
from RecoLocalTracker.SiStripZeroSuppression.SiStripZeroSuppression_cfi import *
from RecoLocalTracker.SiStripClusterizer.SiStripClusterizer_cfi import *
from RecoLocalTracker.SiPixelClusterizer.SiPixelClusterizer_cfi import *
from RecoLocalTracker.SiPixelRecHits.SiPixelRecHits_cfi import *
from RecoLocalTracker.SiPixelRecHits.PixelCPEESProducers_cff import *
pixeltrackerlocalrecoTask = cms.Task(siPixelClusters,siPixelRecHits)
pixeltrackerlocalreco = cms.Sequence(pixeltrackerlocalrecoTask)
striptrackerlocalrecoTask = cms.Task(siStripZeroSuppression,siStripClusters,siStripMatchedRecHits)
striptrackerlocalreco = cms.Sequence(striptrackerlocalrecoTask)
trackerlocalrecoTask = cms.Task(pixeltrackerlocalrecoTask,striptrackerlocalrecoTask)
trackerlocalreco = cms.Sequence(trackerlocalrecoTask)
