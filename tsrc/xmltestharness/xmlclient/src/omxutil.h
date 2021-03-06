/*
* Copyright (c) 2008 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
*
*/


#ifndef OMXUTIL_H_
#define OMXUTIL_H_

#include <e32cmn.h>
#include <openmax/il/khronos/v1_x/OMX_Core.h>

class OMXUtil
	{
public:
	static void ErrorDes(OMX_ERRORTYPE aError, TBuf<64>& aErrorDes);
	};

#endif /*OMXUTIL_H_*/
