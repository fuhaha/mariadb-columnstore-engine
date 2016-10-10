/* Copyright (C) 2014 InfiniDB, Inc.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; version 2 of
   the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA. */

/******************************************************************************************
* Author: Zhixuan Zhu
******************************************************************************************/
/**
 * @file
 */
#ifndef SNMP_MANAGER_H
#define SNMP_MANAGER_H

#include <string>
#include <map>
#include "alarm.h"

#if defined(_MSC_VER) && defined(xxxSNMPMANAGER_DLLEXPORT)
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

namespace snmpmanager {

/** @brief type define
 *
 */
typedef std::multimap<int, Alarm> AlarmList;


/** @brief constant define
 *
 */

/** @brief SNMPManager class interface
 *
 */
class SNMPManager
{
public:
	/** @brief default ctor
	 *
	 */
	EXPORT SNMPManager();

	/** @brief dtor
	 *
	 */
	EXPORT virtual ~SNMPManager();
	
	/** @brief send an alarm
	 *
	 * @param componentID the component, hardware or software ID
	 * @param alarmID the alarm ID
	 * @param state set or clear
	 * @param repModuleName reported Module Name (used by non-realtime process)
	 * @param repProcessName reporting Process Name (used by non-realtime process)
	 */
	EXPORT void sendAlarmReport (const char* componentID, 
						 const int alarmID, 
						 const int state,
						 std::string repModuleName = "",
						 std::string repProcessName = "");


	/** @brief return active alarm list
	 *
	 * @param AlarmList the alarm map reference to store alarms
	 */
	EXPORT void getActiveAlarm (AlarmList& ) const;
	
	/** @brief return alarm list
	 *
	 * @param date date of alarms, "today" or date in YYYYMMDD
	 * @param AlarmList the alarm map reference to store alarms
	 */
	EXPORT void getAlarm (std::string date, AlarmList& ) const;
	
	/** @brief get NMS address for trapd
	 *
	 * @param addr the reference to store addr
	 */

private:
	/** @brief copy ctor. keep private for now
	 *
	 */
	SNMPManager(const SNMPManager& rhs);
	
	/** @brief assign op. keep private for now
	 *
	 */
	SNMPManager& operator=(const SNMPManager& rhs);
	
	/**
	 * this is to avoid running create_trap_session more than once.
	 */
	static bool initFlag;	
	
	std::string parentOAMModuleName;

};

}

#undef EXPORT

#endif
