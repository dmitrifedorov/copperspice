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


#include "qremovaliterator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

RemovalIterator::RemovalIterator(const Item::Iterator::Ptr &target,
                                 const xsInteger pos) : m_target(target),
   m_removalPos(pos),
   m_position(0)
{
   Q_ASSERT(target);
   Q_ASSERT(pos >= 1);
}

Item RemovalIterator::next()
{
   if (m_position == -1) {
      return Item();
   }

   m_current = m_target->next();

   if (!m_current) {
      m_position = -1;
      m_current.reset();
      return Item();
   }

   ++m_position;

   if (m_position == m_removalPos) {
      next(); /* Recurse, return the next item. */
      --m_position; /* Don't count the one we removed. */
      return m_current;
   }

   return m_current;
}

xsInteger RemovalIterator::count()
{
   const xsInteger itc = m_target->count();

   if (itc < m_removalPos) {
      return itc;
   } else {
      return itc - 1;
   }
}

Item RemovalIterator::current() const
{
   return m_current;
}

xsInteger RemovalIterator::position() const
{
   return m_position;
}

Item::Iterator::Ptr RemovalIterator::copy() const
{
   return Item::Iterator::Ptr(new RemovalIterator(m_target->copy(), m_removalPos));
}

QT_END_NAMESPACE
