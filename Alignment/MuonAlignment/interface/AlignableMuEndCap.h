#ifndef Alignment_MuonAlignment_AlignableMuEndCap_H
#define Alignment_MuonAlignment_AlignableMuEndCap_H

#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Alignment/CommonAlignment/interface/Alignable.h"
#include "Alignment/CommonAlignment/interface/AlignableComposite.h"
#include "Alignment/CommonAlignment/interface/AlignableSurface.h"

#include "Alignment/MuonAlignment/interface/AlignableCSCStation.h"

#include "DataFormats/TrackingRecHit/interface/AlignmentPositionError.h"
#include "Geometry/Vector/interface/Basic3DVector.h"

#include <vector>

class GeomDet;

/// Concrete class for muon CSC EndCap alignable.
///
/// Misalignment can be de-/reactivated (forwarded to components).
///

class AlignableMuEndCap : public AlignableComposite 
{

 public:

  AlignableMuEndCap( const std::vector<AlignableCSCStation*> cscStations );

  ~AlignableMuEndCap();
  
  virtual std::vector<Alignable*> components() const 
  {

        std::vector<Alignable*> result;
        result.insert( result.end(), theCSCStations.begin(), theCSCStations.end() );
        return result;

  }
  
  typedef GlobalPoint           PositionType;
  typedef TkRotation<float>     RotationType;

  // gets the global position as the average over all positions of the layers
  PositionType computePosition() ;
  // get the global orientation
  RotationType computeOrientation() ; //see explanation for "theOrientation"
  // get the Surface
  AlignableSurface computeSurface() ;

  AlignableCSCStation &station(int i);  
  
  virtual void twist(float);

  /// Printout muon End Cap information (not recursive)
  friend std::ostream& operator << ( std::ostream&, const AlignableMuEndCap& );

  /// Recursive printout of the muon End Cap structure
  void dump( void );



private:

  std::vector<AlignableCSCStation*> theCSCStations;


};

#endif




