#ifndef __elxAdvancedKappaStatisticMetric_HXX__
#define __elxAdvancedKappaStatisticMetric_HXX__

#include "elxAdvancedKappaStatisticMetric.h"


namespace elastix
{
using namespace itk;

	/**
	 * ******************* Initialize ***********************
	 */

	template <class TElastix>
		void AdvancedKappaStatisticMetric<TElastix>
		::Initialize(void) throw (ExceptionObject)
	{
		TimerPointer timer = TimerType::New();
		timer->StartTimer();
		this->Superclass1::Initialize();
		timer->StopTimer();
		elxout << "Initialization of AdvancedKappaStatistic metric took: "
			<< static_cast<long>( timer->GetElapsedClockSec() * 1000 ) << " ms." << std::endl;

	} // end Initialize


  /**
	 * ***************** BeforeRegistration ***********************
	 */

	template <class TElastix>
		void AdvancedKappaStatisticMetric<TElastix>
		::BeforeRegistration(void)
	{
    /** Get and set taking the complement. */
    bool useComplement = true;
    this->GetConfiguration()->ReadParameter( useComplement,
      "UseComplement", this->GetComponentLabel(), 0, -1 );
    this->SetComplement( useComplement );

    /** Get and set the foreground value. */
    double foreground = 1.0;
    this->GetConfiguration()->ReadParameter( foreground,
      "ForegroundValue", this->GetComponentLabel(), 0, -1 );
    this->SetForegroundValue( foreground );

    /** Get and set the foreground value. */
    bool foregroundIsNonZero = false;
    this->GetConfiguration()->ReadParameter( foregroundIsNonZero,
      "ForegroundIsNonZero", this->GetComponentLabel(), 0, -1 );
    this->SetForegroundIsNonZero( foregroundIsNonZero );

  } // end BeforeRegistration()


  /**
	 * ***************** BeforeEachResolution ***********************
	 */

	template <class TElastix>
		void AdvancedKappaStatisticMetric<TElastix>
		::BeforeEachResolution(void)
	{
    /** Get the current resolution level. */
		unsigned int level = 
			( this->m_Registration->GetAsITKBaseType() )->GetCurrentLevel();
		
  } // end BeforeEachResolution


} // end namespace elastix


#endif // end #ifndef __elxAdvancedKappaStatisticMetric_HXX__

