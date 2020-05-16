/* GemRB - Infinity Engine Emulator
 * Copyright (C) 2003 The GemRB Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *
 */

#include "Tile.h"

namespace GemRB {

Tile::Tile(Animation* anim, Animation* sec)
{
	tileIndex = om = 0;
	this->anim[0] = anim;
	this->anim[1] = sec;
	for (size_t i = 0; i < 16; i++) {
		SearchMap[i] = {};
		HeightMap[i] = {};
		LightMap[i] = {};
		NLightMap[i] = {};
	}
}

Tile::~Tile(void)
{
	delete( anim[0] );
	delete( anim[1] );
}

}
