/* Copyright 2024 ClownFish (@clownfish-og)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

//disable options to reduce firmware size
#define NO_ACTION_ONESHOT
#define LAYER_STATE_8BIT

#ifdef RGB_MATRIX_ENABLE

#ifdef RGB_MATRIX_DEFAULT_MODE
#undef RGB_MATRIX_DEFAULT_MODE
#endif  //RGB_MATRIX_DEFAULT_MODE

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_ALPHAS_MODS

#endif  // RGB_MATRIX_ENABLE
