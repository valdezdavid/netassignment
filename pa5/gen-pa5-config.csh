#!/bin/tcsh -f
#
# Put this file in the same directory as your "pa5" executable.
# If you are running on Ubuntu, just do:
#
#     ./gen-pa5-config.csh
#
# If you are running on nunki and the first port number that was assigned to you was XXX, please should do:
#
#     ./gen-pa5-config.csh XXX
#
# It will create a subdirectory called "homedirs" and in it, it will create 18 subdirectories, each to be
#     used by a node.  In each individual directory it will create a configuration file to be used by "pa5".
# After running this script, you can start 18 pa5 nodes in parallel where three of them ar famous nodes
#     and the rest are regular nodes.
# The first 8 nodes are regular nodes with num_starter_neighbors=1.
# Next 3 nodes are famous nodes.
# The last 7 nodes are regular nodes with num_starter_neighbors=2.
# 
# If "127.0.0.1" doesn't work for you as the hostname, please feel free to change it to anything that would work for you.
#     The example below show you that you can uncomment the 2nd "set host" statement and use "localhost" as your hostname.

set host="127.0.0.1"
# set host="localhost"

set os=`uname`
if ("x$1" == "x") then
    if ("$os" == "SunOS") then
        echo "Abort.  On nunki, you must use the first port number that was assigned to you when you run this program."
        exit 1
    endif
    set baseport="12000"
else
    if ("x$1" == "xXXX") then
        echo "Abort.  You must use the first port number that was assigned to you (and not XXX)."
        exit 1
    endif
    set baseport=$1
endif

set subdir="homedirs"
set progname="gen-config.csh"
set port_per_student="36";
set primes=(2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61)

if (-d ${subdir}) then
    echo -n "The directory '${subdir}' exists, do you want me to delete everything in '${subdir}' [yes/no]? "
    set input=$<
    if ("x${input}" == "x") then
        echo "You did not enter anything.  Please rerun this program."
        exit 1
    endif
    set firstchar=`echo ${input} | cut -c1`
    if (${firstchar} == "y" || ${firstchar} == "Y") then
        set rc=`rm -rf ${subdir}; mkdir ${subdir}`
    else
        if (${firstchar} == "n" || ${firstchar} == "N") then
            echo "Ok, bye."
            exit 1
        else
            echo "Abort.  You must enter either 'yes' or 'no'.  Please rerun this program."
            exit 1
        endif
    endif
else
    set rc=`mkdir ${subdir}`
endif

set famous0=`expr ${baseport} + 16`
set famous1=`expr ${baseport} + 18`
set famous2=`expr ${baseport} + 20`

set i=1

foreach n (`seq 0 2 14`)
    set port=`expr ${baseport} + ${n}`
    set appport=`expr ${port} + 1`
    set dirname="${subdir}/${port}"
    set filename="${subdir}/pa5-${port}.cfg"
    set rc=`mkdir ${dirname}; touch ${filename}`

    echo "[config]" >> ${filename}
    echo "host=${host}" >> ${filename}
    echo "control_port=${port}" >> ${filename}
    echo "app_port=${appport}" >> ${filename}
    echo "location=$primes[$i]" >> ${filename}
    echo "root=${dirname}" >> ${filename}
    echo "pid=pa5.pid" >> ${filename}
    echo "log=pa5.log" >> ${filename}
    echo "" >> ${filename}
    echo "[params]" >> ${filename}
    echo "ttl=20" >> ${filename}
    echo "num_startup_neighbors=1" >> ${filename}
    echo "msg_life_time=5" >> ${filename}
    echo "keep_alive_timeout=8" >> ${filename}
    echo "check_timeout=3" >> ${filename}
    echo "discovery_timeout=3" >> ${filename}
    echo "discovery_retry_interval=5" >> ${filename}
    echo "" >> ${filename}
    echo "[famous]" >> ${filename}
    echo "famous_retry_interval=5" >> ${filename}
    echo "count=3" >> ${filename}
    echo "0=${host}_${famous0}" >> ${filename}
    echo "1=${host}_${famous1}" >> ${filename}
    echo "2=${host}_${famous2}" >> ${filename}

    set i=`expr $i + 1`
end

foreach n (`seq 16 2 34`)
    set port=`expr ${baseport} + ${n}`
    set appport=`expr ${port} + 1`
    set dirname="${subdir}/${port}"
    set filename="${subdir}/pa5-${port}.cfg"
    set rc=`mkdir ${dirname}; touch ${filename}`

    echo "[config]" >> ${filename}
    echo "host=${host}" >> ${filename}
    echo "control_port=${port}" >> ${filename}
    echo "app_port=${appport}" >> ${filename}
    echo "location=$primes[$i]" >> ${filename}
    echo "root=${dirname}" >> ${filename}
    echo "pid=pa5.pid" >> ${filename}
    echo "log=pa5.log" >> ${filename}
    echo "" >> ${filename}
    echo "[params]" >> ${filename}
    echo "ttl=20" >> ${filename}
    echo "num_startup_neighbors=2" >> ${filename}
    echo "msg_life_time=5" >> ${filename}
    echo "keep_alive_timeout=8" >> ${filename}
    echo "check_timeout=3" >> ${filename}
    echo "discovery_timeout=3" >> ${filename}
    echo "discovery_retry_interval=5" >> ${filename}
    echo "" >> ${filename}
    echo "[famous]" >> ${filename}
    echo "famous_retry_interval=5" >> ${filename}
    echo "count=3" >> ${filename}
    echo "0=${host}_${famous0}" >> ${filename}
    echo "1=${host}_${famous1}" >> ${filename}
    echo "2=${host}_${famous2}" >> ${filename}

    set i=`expr $i + 1`
end
