/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SC_SOURCE_FILTER_INC_HTMLIMP_HXX
#define INCLUDED_SC_SOURCE_FILTER_INC_HTMLIMP_HXX

#include "eeimport.hxx"
#include "htmlpars.hxx"

class ScHTMLImport : public ScEEImport
{
private:
    static void         InsertRangeName( ScDocument* pDoc, const OUString& rName, const ScRange& rRange );

public:
    ScHTMLImport( ScDocument* pDoc, const OUString& rBaseURL, const ScRange& rRange, bool bCalcWidthHeight );
    virtual ~ScHTMLImport() override;
    const ScHTMLParser* GetParser() const { return static_cast<ScHTMLParser*>(mpParser); }

    virtual void        WriteToDocument( bool bSizeColsRows = false, double nOutputFactor = 1.0,
                                         SvNumberFormatter* pFormatter = nullptr, bool bConvertDate = true ) override;

    static OUString     GetHTMLRangeNameList( ScDocument* pDoc, const OUString& rOrigName );
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
