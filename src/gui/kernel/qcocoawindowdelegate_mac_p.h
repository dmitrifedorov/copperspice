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

#ifndef QCocoaWindowDelegate_MAC_P_H
#define QCocoaWindowDelegate_MAC_P_H

#include <qmacdefines_mac.h>
#import  <Cocoa/Cocoa.h>

QT_BEGIN_NAMESPACE
template <class Key, class T> class QHash;
QT_END_NAMESPACE

using QT_PREPEND_NAMESPACE(QHash);
QT_FORWARD_DECLARE_CLASS(QWidget)
QT_FORWARD_DECLARE_CLASS(QSize)
QT_FORWARD_DECLARE_CLASS(QWidgetData)

@interface QT_MANGLE_NAMESPACE(QCocoaWindowDelegate) : NSObject<NSWindowDelegate, NSDrawerDelegate>
{
   QHash<NSWindow *, QWidget *> *m_windowHash;
   QHash<NSDrawer *, QWidget *> *m_drawerHash;
}
+ (QT_MANGLE_NAMESPACE(QCocoaWindowDelegate) *)sharedDelegate;
- (void)becomeDelegateForWindow: (NSWindow *)window  widget: (QWidget *)widget;
- (void)resignDelegateForWindow: (NSWindow *)window;
- (void)becomeDelegateForDrawer: (NSDrawer *)drawer widget: (QWidget *)widget;
- (void)resignDelegateForDrawer: (NSDrawer *)drawer;
- (void)dumpMaximizedStateforWidget: (QWidget *)qwidget window: (NSWindow *)window;
- (void)syncSizeForWidget: (QWidget *)qwidget
                   toSize: (const QSize &)newSize
                 fromSize: (const QSize &)oldSize;
- (NSSize)closestAcceptableSizeForWidget: (QWidget *)qwidget
                                  window: (NSWindow *)window withNewSize: (NSSize)proposedSize;
- (QWidget *)qt_qwidgetForWindow: (NSWindow *)window;
- (void)syncContentViewFrame: (NSNotification *)notification;
@end

#endif