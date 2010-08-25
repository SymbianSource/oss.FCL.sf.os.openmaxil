// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef  	__OSTOMXILFRAMEWORKTRACE_H
#define 	__OSTOMXILFRAMEWORKTRACE_H

/**
Enable this macro to compile in the OMX-IL peformance trace points that trace out all the performance
use-cases.
*/

#ifdef SYMBIAN_PERF_TRACE_OMX_IL

/*
 * ComponentId Default
 * must be defined before <opensystemtrace_types.h>
 * Include this header file from exe specific header file that defines EXECUTABLE_DEFAULT_COMPONENTID
 */

#include <opensystemtrace_types.h>
#include <e32des8.h>

#define MAKESTRING(str) (#str)
#define BLANK_STR (& (_L8("") ) )


const TUint ADDITIONAL_INFO_SIZE = 100;

const TClassificationAll  EPerFormanceTraceClassification = ESystemCharacteristicMetrics;
const static TComponentId KTracePerformanceTraceUID= 0x100039e4;

/**
This defines trace attributes to be used by trace points within OMX-IL.
*/
namespace Ost_OMXIL_Performance
    {

    // Enumerates all the OMX commands that are traced for performance,
    enum  OMX_PERFORMANCE_USECASES
        {
        E_Init = 0,
        E_DeInit,
        E_GetHandle,
        E_GetParam,
        E_SetParam,
        E_SendCommand,
        E_SetupTunnel,
        E_GetConfig,
        E_SetConfig,
        E_FreeHandle,
        E_Event,
        E_GetContentPipe,
        E_GetComponentsOfRole,
        E_GetRolesOfComponent,
        E_ComponentNameEnum,
        E_AllocateBuffer,
        E_EmptyThisBuffer,
        E_ComponentTunnelRequest,
        E_FillThisBuffer,
        E_FreeBuffer,
        E_UseBuffer,
        E_GetComponentVersion,
        E_GetExtensionIndex,
        E_ComponentDeInit,
        E_SetCallbacks,
        E_EmptyBufferDone,
        E_FillBufferDone
        };
    
	/* This defines the format of the performance trace packets
	*	%d	:TTraceID
	*	%s	:OMX_PERFORMANCE_USE_CASES (this is still a C style string at the moment)
	*	%d  :ErrorCode
	*   %S	:Additional information [Optional]
	*/
	_LIT8(K_OMX_PerformanceTraceFormat,"%u;%s;%u;%S");


   /* This defines the format of the performance trace packets (minimum) usually used for OMX-IL API start
    *   %d  :TTraceID
    *   %s  :OMX_PERFORMANCE_USE_CASES (this is still a C style string at the moment)
    */
    _LIT8(K_OMX_PerformanceTraceFormatMin,"%u;%s;");

    /* This defines the format of the performance trace packets to mark use case start and  End
    *	%d	:TTraceID
	*	%S	:OMX_PERFORMANCE_USE_CASES
	*/
	_LIT8(K_OMX_UseCasePerformanceTraceFormat, "%u;%S");

    
	//****************** Additional information trace packet format ****************
    /* This defines the format of the performance trace packets
    *   %s  :role
    *   %u  :number of components
    */
    _LIT8(K_RoleInfo,"%s;%u");
	
    /* This defines format of the additional information section of the EMeasurementEnd:E_GetHandle
    *  get handle packet
	*	%u	:Component Handle
	*	%s	:component Name

	*/
    _LIT8(K_HandleInfo, "%u;%s");

    /* This defines format of the additional information section of the EMeasurementEnd:E_SendCommand
      *  get handle packet
      *   %u  :Component Handle
      *   %d  :Command
      *   %d  :aParam1
      */
    _LIT8(K_OMXSendCommandInfo, "%u;%u;%u");


	/* This defines format of the additional information section of the EMeasurementEnd:E_GetHandle
	*  get handle packet
	*	%u	: component
	*	%d	: OmxIndex Type
	*
	*   NOTE:  This shares additional info packet format as EMeasurementEnd:SetParameter
	*          This shares additional info packet format as EMeasurementEnd:GetConfig
	*          This shares additional info  packet format as EMeasurementEnd:SetConfig
	*/
    _LIT8(K_GetParameterInfo, "%u;%u");


    /* This defines format of the additional information section of the EMeasurementEnd:E_Event
      *  get handle packet
      *   %u  :Component Handle
      *   %u  :Event
      *   %u  :aParam1
       *  %u  :aParam2 
      */
	_LIT8(K_OMXEventNotificationInfo, "%u;%u;%u;%u");



	/* This defines format of the additional information section of the EMeasurementEnd:K_TunnelSetupInfo
	  *  get handle packet
	  *   %u  :Source Component Handle
	  *   %u  :source port
	  *   %u  :Sink Component Handle
	  *   %u  :sink port
	  */
	_LIT8(K_TunnelSetupInfo, "%u;%u;%u;%u");
	

	/* This defines format of the additional information section of the EMeasurementEnd:E_FreeHandle
	  *  get handle packet
	  *   %u  :Component Handle
	  */
	_LIT8(K_HandleOnlyInfo, "%u");
	

    enum TTraceId
        {
        /**
        This format is used in all performance trace packets generated by OMX-IL

        SymTraceFormatString "%d;%s;%s"
        */
        EMeasurementStart = KInitialClientFormat,

        /**
        This format is used in performance trace packets generated by OMX-IL
        SymTraceFormatString "%d;%s;%s"
        */
        EMeasurementEnd,

        /**
        This format is used in performance trace packets generated by OMX-IL to mark
        Where the higher level test. started from.

        SymTraceFormatString "%d;%s"
        */
        EUseCaseStart,

        /**
        This format is used in performance trace packets generated by OMX-IL to mark
        Where the higher level test ends.


        SymTraceFormatString "%d;%s"
        */
        EUseCaseEnd,


        /**
        Provided to allow the following compile time assert.
        */
        ETraceIdHighWaterMark,
        };
    __ASSERT_COMPILE(ETraceIdHighWaterMark <= KMaxTraceId + 1);

    } // end of namespace OstComponentOSTDemo


// Normal PC and ContextId Defaults
// Note these are the same as the ones provided by OST
#define EXECUTABLE_DEFAULT_HAS_THREAD_IDENTIFICATION EAddThreadIdentification
#define EXECUTABLE_DEFAULT_HAS_PC ENoPc
#include <opensystemtrace.h>


#endif 		//SYMBIAN_PERF_TRACE_OMX_IL
#endif 		//OSTOMXILFRAMEWORKTRACE_H