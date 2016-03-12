##############################################################################
#
# Freescale Confidential Proprietary
#
# Copyright (c) 2014 Freescale Semiconductor;
# All Rights Reserved
#
##############################################################################
#
# THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
# THE POSSIBILITY OF SUCH DAMAGE.
#
##############################################################################
#
#  CONTENT
#    S32V hello world
#
#  AUTHOR
#    Stefan Schwarz
#
#  DATE
#    2015-07-09
#
#  LANGUAGE
#    make
#
##############################################################################

SDK_ROOT :=	../../../../s32v234_sdk

##############################################################################
ARM_APP = hello
##############################################################################

ARM_APP_SRCS =                                                               \
        main.cpp                                                             \

ARM_INCS =                                                                   \
        -I$(SDK_ROOT)/libs/arm/utils/oal/user/include                        \
        -I.

DEFS +=		                                                             \

ARM_APP_LIBS =	                                                             \
	$(SDK_ROOT)/libs/arm/utils/oal/user/$(ODIR)/liboal.a		     \
	$(SDK_ROOT)/libs/arm/apex/apex/user/$(ODIR)/libapex2drv.a            \


	
EXP_ITEMS +=	\
	