/*
             LUFA Library
     Copyright (C) Dean Camera, 2009.
              
  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com
*/

/*
  Copyright 2009  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this 
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in 
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting 
  documentation, and that the name of the author not be used in 
  advertising or publicity pertaining to distribution of the 
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for ConfigDescriptor.c.
 */

#ifndef _CONFIGDESCRIPTOR_H_
#define _CONFIGDESCRIPTOR_H_

	/* Includes: */
		#include <LUFA/Drivers/USB/USB.h>
		
		#include "MIDIHost.h"
		
	/* Macros: */
		/** Interface Class value for the MIDI Audio class */
		#define MIDI_STREAMING_CLASS           0x01
		
		/** Interface Class value for the MIDI Audio Streaming subclass */
		#define MIDI_STREAMING_SUBCLASS        0x03

		/** Interface Class value for the MIDI Audio Streaming protocol */
		#define MIDI_STREAMING_PROTOCOL        0x00

		/** Maximum size of a device configuration descriptor which can be processed by the host, in bytes */
		#define MAX_CONFIG_DESCRIPTOR_SIZE     512
	
	/* Enums: */
		/** Enum for the possible return codes of the ProcessConfigurationDescriptor() function. */
		enum MIDIHost_GetConfigDescriptorDataCodes_t
		{
			SuccessfulConfigRead            = 0, /**< Configuration Descriptor was processed successfully */
			ControlError                    = 1, /**< A control request to the device failed to complete successfully */
			DescriptorTooLarge              = 2, /**< The device's Configuration Descriptor is too large to process */
			InvalidConfigDataReturned       = 3, /**< The device returned an invalid Configuration Descriptor */
			NoCDCInterfaceFound             = 4, /**< A compatible CDC interface was not found in the device's Configuration Descriptor */
			NoEndpointFound                 = 5, /**< Compatible CDC endpoints were not found in the device's CDC interface */
		};

	/* Function Prototypes: */
		uint8_t ProcessConfigurationDescriptor(void);	
		
		uint8_t DComp_NextMIDIStreamingInterface(void* CurrentDescriptor);
		uint8_t DComp_NextMIDIStreamingDataEndpoint(void* CurrentDescriptor);
		
#endif
