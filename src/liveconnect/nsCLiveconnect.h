/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */

/*
 * This file is part of the Java-vendor-neutral implementation of LiveConnect
 *
 * It contains class definition implementing the public interface.
 *
 */
/*
 * This file is part of the Java-vendor-neutral implementation of LiveConnect
 *
 * It contains the class definition to implement nsILiveconnect XP-COM interface.
 *
 */


#ifndef nsCLiveconnect_h___
#define nsCLiveconnect_h___

#include "nsILiveconnect.h"
#include "nsAgg.h"


/**
 * nsCLiveconnect implements nsILiveconnect interface for navigator.
 * This is used by a JVM to implement netscape.javascript.JSObject functionality.
 */
class nsCLiveconnect :public nsILiveconnect {
public:
    ////////////////////////////////////////////////////////////////////////////
    // from nsISupports and AggregatedQueryInterface:

    NS_DECL_AGGREGATED

    ////////////////////////////////////////////////////////////////////////////
    // from nsILiveconnect:

    /**
     * get member of a Native JSObject for a given name.
     *
     * @param obj        - A Native JS Object.
     * @param name       - Name of a member.
     * @param pjobj      - return parameter as a java object representing 
     *                     the member. If it is a basic data type it is converted to
     *                     a corresponding java type. If it is a NJSObject, then it is
     *                     wrapped up as java wrapper netscape.javascript.JSObject.
     */
    NS_IMETHOD	
    GetMember(JNIEnv *jEnv, jsobject obj, const char *name, jobject *pjobj);

    /**
     * get member of a Native JSObject for a given index.
     *
     * @param obj        - A Native JS Object.
     * @param index      - Index of a member.
     * @param pjobj      - return parameter as a java object representing 
     *                     the member. 
     */
    NS_IMETHOD	
    GetSlot(JNIEnv *jEnv, jsobject obj, int index, jobject *pjobj);

    /**
     * set member of a Native JSObject for a given name.
     *
     * @param obj        - A Native JS Object.
     * @param name       - Name of a member.
     * @param jobj       - Value to set. If this is a basic data type, it is converted
     *                     using standard JNI calls but if it is a wrapper to a JSObject
     *                     then a internal mapping is consulted to convert to a NJSObject.
     */
    NS_IMETHOD	
    SetMember(JNIEnv *jEnv, jsobject obj, const char *name, jobject jobj);

    /**
     * set member of a Native JSObject for a given index.
     *
     * @param obj        - A Native JS Object.
     * @param index      - Index of a member.
     * @param jobj       - Value to set. If this is a basic data type, it is converted
     *                     using standard JNI calls but if it is a wrapper to a JSObject
     *                     then a internal mapping is consulted to convert to a NJSObject.
     */
    NS_IMETHOD	
    SetSlot(JNIEnv *jEnv, jsobject obj, int slot, jobject jobj);

    /**
     * remove member of a Native JSObject for a given name.
     *
     * @param obj        - A Native JS Object.
     * @param name       - Name of a member.
     */
    NS_IMETHOD	
    RemoveMember(JNIEnv *jEnv, jsobject obj, const char *name);

    /**
     * call a method of Native JSObject. 
     *
     * @param obj        - A Native JS Object.
     * @param name       - Name of a method.
     * @param jobjArr    - Array of jobjects representing parameters of method being caled.
     * @param pjobj      - return value.
     */
    NS_IMETHOD	
    Call(JNIEnv *jEnv, jsobject obj, const char *name, jobjectArray jobjArr, jobject *pjobj);

    /**
     * Evaluate a script with a Native JS Object representing scope.
     *
     * @param obj                - A Native JS Object.
     * @param pNSIPrincipaArray  - Array of principals to be used to compare privileges.
     * @param numPrincipals      - Number of principals being passed.
     * @param script             - Script to be executed.
     * @param pjobj              - return value.
     */
    NS_IMETHOD	
    //Eval(JNIEnv *jEnv, jsobject obj, nsIPrincipal **pNSIPrincipaArray, PRInt32 numPrincipals, const char *script, jobject *pjobj);
    Eval(JNIEnv *jEnv, jsobject obj, const char *script, jobject *pjobj);

    /**
     * Get the window object for a plugin instance.
     *
     * @param pJavaObject        - Either a jobject or a pointer to a plugin instance 
     *                             representing the java object.
     * @param pjobj              - return value. This is a native js object 
     *                             representing the window object of a frame 
     *                             in which a applet/bean resides.
     */
    NS_IMETHOD	
    GetWindow(JNIEnv *jEnv, void *pJavaObject, jsobject *pobj);

    /**
     * Get the window object for a plugin instance.
     *
     * @param jEnv       - JNIEnv on which the call is being made.
     * @param obj        - A Native JS Object.
     */
    NS_IMETHOD	
    FinalizeJSObject(JNIEnv *jEnv, jsobject obj);

   
    ////////////////////////////////////////////////////////////////////////////
    // from nsCLiveconnect:

    nsCLiveconnect(nsISupports *aOuter);
    virtual ~nsCLiveconnect(void);

protected:
};

#endif /* // nsCLiveconnect_h___ */
