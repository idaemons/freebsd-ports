#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	cd ${PREFIX}; [ -x fsgs/fsgs -a -f fsgs/fsgs.cfg ] && fsgs/fsgs > /dev/null & && echo -n ' fsgs'
	;;
stop)
	killall fsgs && echo -n ' fsgs'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
