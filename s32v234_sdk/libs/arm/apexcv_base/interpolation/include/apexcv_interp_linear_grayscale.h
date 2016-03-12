/******************************************************************************
 *  (C) Copyright CogniVue Corporation. 2014 All right reserved.
 * 
 *  Confidential Information
 *
 *  All parts of the CogniVue Program Source are protected by copyright law
 *  and all rights are reserved.
 *  This documentation may not, in whole or in part, be copied, photocopied,
 *  reproduced, translated, or reduced to any electronic medium or machine
 *  readable form without prior consent, in writing, from CogniVue.
 ******************************************************************************/
/*!*********************************************************************************
*  \file apexcv_interp_linear_grayscale.hpp
*  \brief Host-ACF interface for linear grayscale interpolation
***********************************************************************************/

#ifndef _APEXCV_INTERP_LINEAR_GRAYSCALE_HPP_
#define _APEXCV_INTERP_LINEAR_GRAYSCALE_HPP_

#include "all_interpol_graph_registrations.h"

/*!*********************************************************************************
*  \brief Host-ACF interface for linear grayscale interpolation.
*
*  This template class is an interface for creating, initializing, processing and releasing
*  the APU implementation of linear grayscale interpolation on the host.
***********************************************************************************/

class apexcv_interp_linear_grayscale
{
   public:
/*!*********************************************************************************
*  \brief Default constructor.
***********************************************************************************/
      apexcv_interp_linear_grayscale()  {};
   
/*!*********************************************************************************
*  \brief Destructor.
***********************************************************************************/   
      ~apexcv_interp_linear_grayscale() {};
   
/*!*********************************************************************************
*  \brief Initialize the process.
*
*  \return Error code for the initialization (zero on success).
*
*  We initialize the process on the host by initializing the ACF process
*
***********************************************************************************/                     
      int Initialize( DataDescriptor& lInput0,
                      DataDescriptor& lOutput0,
                      DataDescriptor& deltaX );
                       
/*!*********************************************************************************
*  \brief Release the process.
*
*  \return Error code for the release (zero on success).
***********************************************************************************/
      int Release();
   
/*!*********************************************************************************
*  \brief Execute the process.
*
*  \return Error code for the execution (zero on success).
*
***********************************************************************************/   
      int Process();

   private:
   
/*!*********************************************************************************
*  \brief Process declaration for linear grayscale interpolation
***********************************************************************************/
      INTERP_LINEAR_GRAYSCALE  mProcess;
};

#endif /* _APEXCV_INTERP_LINEAR_GRAYSCALE_HPP_ */