/* GemRB - Infinity Engine Emulator
 * Copyright (C) 2003 The GemRB Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header: /data/gemrb/cvs2svn/gemrb/gemrb/gemrb/plugins/Core/ActorMgr.h,v 1.4 2005/06/11 20:18:00 avenger_teambg Exp $
 *
 */

#ifndef ACTORMGR_H
#define ACTORMGR_H

#include "Plugin.h"
#include "Actor.h"
#include "DataStream.h"

#ifdef WIN32

#ifdef GEM_BUILD_DLL
#define GEM_EXPORT __declspec(dllexport)
#else
#define GEM_EXPORT __declspec(dllimport)
#endif

#else
#define GEM_EXPORT
#endif

class GEM_EXPORT ActorMgr : public Plugin {
public:
	ActorMgr(void);
	virtual ~ActorMgr(void);
	virtual bool Open(DataStream* stream, bool autoFree = true) = 0;
	virtual Actor* GetActor() = 0;

	//returns saved size, updates internal offsets before save
	virtual int GetStoredFileSize(Actor *ac) = 0;
	//saves file
	virtual int PutActor(DataStream *stream, Actor *actor) = 0;
};

#endif
