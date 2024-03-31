/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS

#define USE_SERIAL
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define EE_HANDS
//Master/slave delegation is made either by detecting voltage on VBUS connection or waiting for USB communication (SPLIT_USB_DETECT). Pro Micro boards can use VBUS detection out of the box and be used with or without SPLIT_USB_DETECT
//#define MASTER_RIGHT
//#define MASTER_RIGHT

/*
 you'll have to flash the EEPROM files for the correct hand to each controller. You can do this manually, or there are targets for avrdude and dfu to do this, while flashing the firmware:

    :avrdude-split-left
    :avrdude-split-right
    :dfu-split-left
    :dfu-split-right
    :dfu-util-split-left
    :dfu-util-split-right

Example:

make crkbd:default:avrdude-split-left
*/
//#define EE_HANDS
