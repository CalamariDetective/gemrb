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
 * $Header: /data/gemrb/cvs2svn/gemrb/gemrb/gemrb/plugins/Core/EffectQueue.h,v 1.12 2005/08/01 20:52:14 avenger_teambg Exp $
 *
 */

#ifndef EFFECTQUEUE_H
#define EFFECTQUEUE_H


#include <vector>
#include "Effect.h"

class Actor;

#define MAX_EFFECTS 512

bool Init_EffectQueue();

class GEM_EXPORT EffectQueue {
	std::vector< Effect* >  effects;
	Actor* Owner;
public:
	EffectQueue();
	virtual ~EffectQueue();

	void SetOwner(Actor* act) { Owner = act; }
	Actor* GetOwner() { return Owner; }

	// Returns true is successful. fx is just a reference, AddEffect()
	// will malloc its own copy
	bool AddEffect(Effect* fx);
	bool RemoveEffect(Effect* fx);

	void AddAllEffects(Actor* target);
	void ApplyAllEffects(Actor* target);
	void ApplyEffect(Actor* target, Effect* fx, bool first_apply);
	void PrepareDuration(Effect* fx);
	void RemoveAllEffects(ieDword opcode);
	void RemoveLevelEffects(ieDword level, bool dispellable);

	//locating opcodes
	Effect *HasOpcodeWithParam(ieDword opcode, ieDword param2);
	Effect *HasOpcodeWithParamPair(ieDword opcode, ieDword param1, ieDword param2);
	Effect *HasOpcodeMatchingCreature(ieDword opcode, Actor *actor);
	Effect *HasOpcodeWithResource(ieDword opcode, ieResRef resource);
	void dump();
};

typedef int (* EffectFunction)(Actor*, Actor*, Effect*);


struct EffectLink {
	const char* Name;
	EffectFunction Function;
};


#endif  // ! EFFECTQUEUE_H
