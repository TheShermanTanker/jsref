/* -*- Mode: Java; tab-width: 8; c-basic-offset: 4 -*-
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

package netscape.javascript;

/**
 * JSException is an exception which is thrown when JavaScript code
 * returns an error.
 */

public
class JSException extends RuntimeException {
    String filename;
    int lineno;
    String source;
    int tokenIndex;
    Object wrappedException;

    /**
     * Constructs a JSException without a detail message.
     * A detail message is a String that describes this particular exception.
     *
     * @deprecated Not for public use in future versions.
     */
    public JSException() {
	super();
        filename = "unknown";
        lineno = 0;
        source = "";
        tokenIndex = 0;
    }

    /**
     * Constructs a JSException with a detail message.
     * A detail message is a String that describes this particular exception.
     * @param s the detail message
     *
     * @deprecated Not for public use in future versions.
     */
    public JSException(String s) {
	super(s);
        filename = "unknown";
        lineno = 0;
        source = "";
        tokenIndex = 0;
    }

    /**
     * Constructs a JSException with a wrapped JavaScript exception object.
     * This constructor needs to be public so that Java users can throw 
     * exceptions to JS cleanly.
     */
    private JSException(Object wrappedException) {
	super();
	this.wrappedException = wrappedException;
    }
    
    /**
     * Constructs a JSException with a detail message and all the
     * other info that usually comes with a JavaScript error.
     * @param s the detail message
     *
     * @deprecated Not for public use in future versions.
     */
    public JSException(String s, String filename, int lineno,
                       String source, int tokenIndex) {
	super(s);
        this.filename = filename;
        this.lineno = lineno;
        this.source = source;
        this.tokenIndex = tokenIndex;
    }

    /**
     * Instance method getWrappedException.
     */
    public Object getWrappedException() {
	return wrappedException;
    }

}

