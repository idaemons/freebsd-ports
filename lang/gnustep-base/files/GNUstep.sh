#!/bin/sh

PREFIX=%%PREFIX%%
IFFILE=${PREFIX}/etc/gdomap_if
PIDFILE="/var/run/gdomap.pid"
GNUSTEP_SYSTEM_ROOT="${PREFIX}/GNUstep/System"

case "$1" in
start)
	if [ -e ${GNUSTEP_SYSTEM_ROOT}/Makefiles/GNUstep.sh ]; then
		. ${GNUSTEP_SYSTEM_ROOT}/Makefiles/GNUstep.sh
		rm -f ${PIDFILE}
		opentool gdomap -a ${IFFILE} -I ${PIDFILE}
		opentool gdnc
		echo -n ' GNUstep'
	fi
	;;
stop)
	[ -r ${PIDFILE} ] && kill $(cat ${PIDFILE}) && echo -n ' GNUstep'
	killall gdnc
	rm -f ${PIDFILE}
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
