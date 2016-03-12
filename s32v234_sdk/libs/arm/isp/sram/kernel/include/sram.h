/*****************************************************************************
*
* Freescale Confidential Proprietary
*
* Copyright (c) 2014 Freescale Semiconductor;
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
/**
* \file     sram.h
* \brief    declarations for SRAM manager driver
* \author   Tomas Babinec
* \version  0.1
* \date     22.4.2014
* \note
****************************************************************************/

#ifndef SRAM_H
#define SRAM_H

#ifdef __cplusplus 
extern "C" { 
#endif

#include "isp_hw.h"

#if !defined(__STANDALONE__)
#include <linux/ioctl.h>
#endif // #if !defined(__STANDALONE__) && defined(__KERNEL__)

#define SRAM_DRV_SUCCESS 0
#define SRAM_DRV_FAILURE -1

// name of the device file
#define SRAM_DEVICE_NAME "sram"

// magic number for SRAM driver
#define SRAM_IOC_MAGIC 's'

// uncomment to enable DEBUG printing
#define SRAM_DEBUG

#if !defined(__STANDALONE__)
#include "sram_ioctl.h"
#endif // #if !defined(__STANDALONE__) && defined(__KERNEL__)
  
#ifdef __cplusplus 
} // extern "C" 
#endif

#endif