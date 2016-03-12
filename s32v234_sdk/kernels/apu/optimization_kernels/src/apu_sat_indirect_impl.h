/*****************************************************************************
*
* Freescale Confidential Proprietary
*
* Copyright (c) 2013 Freescale Semiconductor;
* All Rights Reserved
*
*****************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************/
/*!
* \file apu_sat_indirect_impl.h
* \brief Summed area table implementation for APEX
* \addtogroup sat
* @{
****************************************************************************/

#ifndef _APU_SAT_IMPL_H_
#define _APU_SAT_IMPL_H_

#ifdef APEX2_EMULATE 
#include "apu_lib.hpp" // if using the APU emulation library
using namespace APEX2;
#endif

/*****************************************************************************
* prototypes
*****************************************************************************/

/****************************************************************************/

/* !
  Computes summed area table (integral image) of the 32bit input. Output has 64 bit.
   
   out(i,j) = sum(in(k,l)) where k,l := (0,0) to (i,j) inclusive
   outSqr(i,j) = sum(in(k,l)^2) where k,l := (0,0) to (i,j) inclusive

\brief Summed area table: input unsigned 32bit, output unsigned 64bit 

\param apDestHigh	- [Output] 32bit high word of the integral image of the squared input
\param apDestLow	- [Output] 32bit low word of the integral image of the squared input
\param apPrevRowHigh- [Output] 32bit the last integral row of the squared input in the tile.
\param apcSrc		- [Input]  32bit source block pointer 
\param bw			- [Input]  Source block width (in bytes) including padding
\param bh			- [Input] Source block height (in bytes) including padding
\param inStrideW	- [Input]  Source block width (in elements not bytes) including padding
\param outStrideW	- [Input]  Destination block width (in elements not bytes) including padding
\param aFirstTile	- [Input]Boolean. True, if the first tile is computed.

void sat_in32u_out64u(vec32u* apDestHigh, vec32u* apDestLow,
	vec32u* apPrevRowHigh, vec32u* apPrevRowLow, const vec32u* apcSrc,
	int16s bw, int16s bh, int16s inStrideW, int16s outStrideW, int08u aFirstTile);
*/


/*! OBSOLETE 
  Computes summed area table (integral image) of the 32bit input. Output has 64 bit. Chunks are selected by an offset vector
   
   out(i,j) = sum(in(k,l)) where k,l := (0,0) to (i,j) inclusive
   outSqr(i,j) = sum(in(k,l)^2) where k,l := (0,0) to (i,j) inclusive

\brief Summed area table: input signed 32bit, output signed 64bit

\param apDestHigh	- [Output] 32bit high word of the integral image of the squared input
\param apDestLow	- [Output] 32bit low word of the integral image of the squared input
\param apPrevRowHigh- [Output] 32bit the last integral row of the squared input in the tile.
\param apcSrc		- [Input]  32bit source block pointer
\param bw			- [Input]  Source block width (in bytes) including padding
\param bh			- [Input]  Source block height (in bytes) including padding
\param inStrideW	- [Input]  Source block width (in elements not bytes) including padding
\param outStrideW	- [Input]  Destination block width (in elements not bytes) including padding
\param aFirstTile	- [Input]  Boolean. True, if the first tile is computed.
*/
void sat_indirect_in32s_out64s(vec32s* apDestHigh, vec32u* apDestLow,
	vec32s* apPrevRowHigh, vec32u* apPrevRowLow, const vec32s* apcSrc,
	int16s bw, int16s bh, int16s inStrideW, int16s outStrideW, int08u aFirstTile);



#endif // _APU_SAT_IMPL_H_

/*! @} */
