#!/bin/bash
#
# $Id: hardwareReport.sh 421 2007-04-05 15:46:55Z dhill $
#
if [ $1 ] ; then
        MODULE=$1
else
        MODULE="pm1"
fi

if [ $2 ] ; then
        INSTALLDIR=$2
else
        INSTALLDIR="/usr/local/mariadb/columnstore"
fi

if [ $USER = "root" ]; then
	SUDO=" "
else
	SUDO="sudo"
fi

$SUDO rm -f /tmp/${MODULE}_softwareReport.txt

{
echo " "
echo "******************** Software Report for ${MODULE} ********************"
echo " "

echo " "
echo "-- Calpont Package Details --"
echo " "
echo "################# mcsadmin getcalpontsoftwareinfo #################"
echo " "
$INSTALLDIR/bin/mcsadmin getcalpontsoftwareinfo

echo " "
echo "-- Calpont Release Number file --"
echo " "
echo "################# cat $INSTALLDIR/releasenum #################"
echo " "
cat $INSTALLDIR/releasenum

echo " "
echo "-- Calpont Storage Configuration --"
echo " "
echo "################# mcsadmin getStorageConfig #################"
echo " "
$INSTALLDIR/bin/mcsadmin getStorageConfig

} > /tmp/${MODULE}_softwareReport.txt

exit 0