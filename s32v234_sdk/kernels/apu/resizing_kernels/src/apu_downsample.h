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
#ifndef _APU_DOWNSAMPLE_H
#define _APU_DOWNSAMPLE_H

#include "stringify_macros.h"

#define DOWNSAMPLE_K			apu_downsample
#define DOWNSAMPLE_KN			XSTR(DOWNSAMPLE_K)

#define DOWNSAMPLE_16u_K		apu_downsample_16u
#define DOWNSAMPLE_16u_KN		XSTR(DOWNSAMPLE_16u_K)

#define DOWNSAMPLE_GAUSS_K		apu_downsample_gauss
#define DOWNSAMPLE_GAUSS_KN		XSTR(DOWNSAMPLE_GAUSS_K)

#define DOWNSAMPLE_KN_IN		"INPUT_0"
#define DOWNSAMPLE_KN_OUT	"OUTPUT_0"

#ifdef APEX2_EMULATE

extKernelInfoDecl(DOWNSAMPLE_K);
void DOWNSAMPLE_K(kernel_io_desc lIn0, kernel_io_desc lOut0);

extKernelInfoDecl(DOWNSAMPLE_16u_K);
void DOWNSAMPLE_16u_K(kernel_io_desc lIn0, kernel_io_desc lOut0);

extKernelInfoDecl(DOWNSAMPLE_GAUSS_K);
void DOWNSAMPLE_GAUSS_K(kernel_io_desc lIn0, kernel_io_desc lOut0);

#endif


#endif