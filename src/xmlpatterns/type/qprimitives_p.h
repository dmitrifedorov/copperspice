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

#ifndef QPrimitives_P_H
#define QPrimitives_P_H

#include <QtGlobal>
#include <QtCore/QHash>
#include <QtCore/QUrl>

QT_BEGIN_NAMESPACE

class QString;

namespace QPatternist {
typedef qreal xsDouble;
typedef xsDouble xsFloat;
typedef xsDouble xsDecimal;

/**
 * This is the native C++ scalar type holding the value space
 * for atomic values of type xs:integer. Taking this type, xsInteger,
 * as parameter, is the most efficient way to integrate with xs:integer.
 *
 * @ingroup Patternist_cppWXSTypes
 */
typedef qint64 xsInteger;

/**
 * This is the native C++ scalar type holding the value space
 * for atomic values of type xs:integer. Taking this type, xsInteger,
 * as parameter, is the most efficient way to integrate with xs:integer.
 *
 * @ingroup Patternist_cppWXSTypes
 */
typedef qint32 VariableSlotID;

typedef qint32  DayCountProperty;
typedef qint32  HourCountProperty;
typedef qint32  MinuteCountProperty;
typedef qint32  MonthCountProperty;
typedef qint32  SecondCountProperty;
typedef qint64  MSecondCountProperty;
typedef qint32  SecondProperty;
typedef qint32  YearProperty;
typedef qint8   DayProperty;
typedef qint8   HourProperty;
typedef qint8   MinuteProperty;
typedef qint8   MonthProperty;

/**
 * Milliseconds. 1 equals 0.001 SecondProperty.
 */
typedef qint16  MSecondProperty;

/**
 * The hour property of a zone offset. For example, -13 in the
 * zone offset "-13:08".
 */
typedef qint8   ZOHourProperty;

/**
 * The minute property of a zone offset. For example, -08 in the
 * zone offset "-13:08".
 */
typedef qint8   ZOMinuteProperty;

/**
 * The full zone offset in minutes.
 */
typedef qint32  ZOTotal;

typedef xsDouble PatternPriority;

/**
 * Signifies the import precedence of a template. For instance, the first
 * stylesheet module has 1, the first import 2, and so forth. Smaller means
 * higher import precedence. 0 is reserved for builtin templates.
 */
typedef int ImportPrecedence;

/**
 * @short Similar to Qt::escape(), but also escapes apostrophes and quotes,
 * such that the result is suitable as attribute content too.
 *
 * Since Qt::escape() is in QtGui, using it creates a dependency on that
 * library. This function does not.
 *
 * The implementation resides in qpatternistlocale.cpp.
 *
 * @see Qt::escape()
 */
QString escape(const QString &input);
}

QT_END_NAMESPACE

#endif
