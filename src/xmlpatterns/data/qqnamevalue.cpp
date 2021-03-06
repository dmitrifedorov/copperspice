/***********************************************************************
*
* Copyright (c) 2012-2016 Barbara Geller
* Copyright (c) 2012-2016 Ansel Sermersheim
* Copyright (c) 2012-2014 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software: you can redistribute it and/or 
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with CopperSpice.  If not, see 
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

#include "qanyuri_p.h"
#include "qbuiltintypes_p.h"
#include "qxpathhelper_p.h"

#include "qqnamevalue_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

QNameValue::QNameValue(const NamePool::Ptr &np, const QXmlName name) : m_qName(name)
   , m_namePool(np)
{
   Q_ASSERT(!name.isNull());
   Q_ASSERT(m_namePool);
}

QNameValue::Ptr QNameValue::fromValue(const NamePool::Ptr &np, const QXmlName name)
{
   Q_ASSERT(!name.isNull());
   return QNameValue::Ptr(new QNameValue(np, name));
}

QString QNameValue::stringValue() const
{
   return m_namePool->toLexical(m_qName);
}

ItemType::Ptr QNameValue::type() const
{
   return BuiltinTypes::xsQName;
}

QT_END_NAMESPACE
