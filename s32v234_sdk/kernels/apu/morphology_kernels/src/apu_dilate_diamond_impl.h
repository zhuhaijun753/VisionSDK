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
* \file apu_dilate_diamond_impl.h
* \brief Image diamond dilation implementation for APEX
* \addtogroup dilation
* @{
****************************************************************************/

#ifndef _APU_dilate_diamond_IMPL_H_
#define _APU_dilate_diamond_IMPL_H_

#ifdef APEX2_EMULATE 
#include "apu_lib.hpp" // if using the APU emulation library
using namespace APEX2;
#endif

/****************************************************************************/
/*!
   Dilates the image using 5x5 diamond structure element.
   \brief 5x5 diamond dilation.
 
   \param dst  - [Output] pointer to the destination buffer
   \param src  - [Input]  pointer to the source buffer
   \param dstr - [Input]  line stride of the destination data
   \param sstr - [Input]  line stride of the source data
   \param bw   - [Input]  width of one data block
   \param bh   - [Input]  height of one data block
*****************************************************************************/
void dilate_diamond(vec08u* dst, vec08u* src, int dstr, int sstr, int bw, int bh);

#endif // _APU_dilate_diamond_IMPL_H_ 

/*! @} */
